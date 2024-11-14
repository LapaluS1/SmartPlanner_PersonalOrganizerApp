#pragma once

using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms; // For MessageBox
using namespace System::Security::Cryptography; // For password hashing
using namespace System::Text; // For encoding strings
using namespace System::Data;
using namespace System::Collections::Generic;

namespace OOPP1 {


    public ref class DatabaseHelper {
    public:
        // Connection string to the database
        SqlConnection^ connection = gcnew SqlConnection("Data Source=localhost\\sqlexpress;Integrated Security=True");

        // Method to check if provided credentials are valid
        static bool CheckCredentials(String^ username, String^ password) {
            String^ connectionString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
            SqlConnection^ connection = nullptr;

            try {
                connection = gcnew SqlConnection(connectionString);
                connection->Open();
                String^ hashedPassword = HashPassword(password); // Hash the password
                String^ query = "SELECT COUNT(*) FROM Users WHERE Username = @username AND Password = @password";
                SqlCommand^ command = gcnew SqlCommand(query, connection);
                command->Parameters->AddWithValue("@username", username);
                command->Parameters->AddWithValue("@password", hashedPassword);

                int count = (int)command->ExecuteScalar();
                return count > 0; // Return true if there is at least one matching user
            }
            catch (SqlException^ sqlEx) {
                MessageBox::Show("SQL Error: " + sqlEx->Message);
                return false;
            }
            catch (Exception^ ex) {
                MessageBox::Show("An error occurred: " + ex->Message);
                return false;
            }
            finally {
                if (connection != nullptr && connection->State == ConnectionState::Open) {
                    connection->Close();
                }
            }
        }

        // Method to add a new user
        static bool AddUser(String^ username, String^ email, String^ password) {
            String^ connectionString = "Data Source=localhost\\sqlexpress;Integrated Security=True";
            SqlConnection^ connection = nullptr;

            try {
                connection = gcnew SqlConnection(connectionString);
                connection->Open();
                String^ hashedPassword = HashPassword(password); // Hash the password
                String^ query = "INSERT INTO Users (Username, Email, Password) VALUES (@username, @email, @password)";
                SqlCommand^ command = gcnew SqlCommand(query, connection);
                command->Parameters->AddWithValue("@username", username);
                command->Parameters->AddWithValue("@email", email);
                command->Parameters->AddWithValue("@password", hashedPassword);

                int result = command->ExecuteNonQuery();
                return result > 0; // Return true if a row was inserted
            }
            catch (SqlException^ sqlEx) {
                MessageBox::Show("SQL Error: " + sqlEx->Message);
                return false;
            }
            catch (Exception^ ex) {
                MessageBox::Show("An error occurred: " + ex->Message);
                return false;
            }
            finally {
                if (connection != nullptr && connection->State == ConnectionState::Open) {
                    connection->Close();
                }
            }
        }

        // Method to add an income or expense record
        bool addIncomeExpense(String^ incomeExpense, String^ date, String^ category, String^ source, String^ description, Decimal amount) {
            SqlTransaction^ transaction = nullptr;  // Declare transaction outside the try block
            try {
                // Open the connection
                connection->Open();

                // Begin a transaction
                transaction = connection->BeginTransaction();

                // Insert the income/expense record into the IncomeExpenses table
                String^ query = "INSERT INTO IncomeExpenses (IncomeExpense, Date, Category, Source, Description, Amount) VALUES (@incomeExpense, @date, @category, @source, @description, @amount)";
                SqlCommand^ command = gcnew SqlCommand(query, connection);
                command->Transaction = transaction;
                command->Parameters->AddWithValue("@incomeExpense", incomeExpense);
                command->Parameters->AddWithValue("@date", date);
                command->Parameters->AddWithValue("@category", category);
                command->Parameters->AddWithValue("@source", source);
                command->Parameters->AddWithValue("@description", description);
                command->Parameters->AddWithValue("@amount", amount);

                int rowsAffected = command->ExecuteNonQuery();

                if (rowsAffected > 0) {
                    // Check if the category exists in CategoryBudgets
                    String^ checkCategoryQuery = "SELECT COUNT(*) FROM CategoryBudgets WHERE Category = @Category";
                    SqlCommand^ checkCategoryCommand = gcnew SqlCommand(checkCategoryQuery, connection);
                    checkCategoryCommand->Transaction = transaction;
                    checkCategoryCommand->Parameters->AddWithValue("@Category", category);

                    int categoryCount = (int)checkCategoryCommand->ExecuteScalar();
                    if (categoryCount == 0) {
                        MessageBox::Show("Category '" + category + "' does not exist in the CategoryBudgets table.");
                        transaction->Rollback();
                        return false;
                    }

                    // Inserted successfully, now update the spent amount in CategoryBudgets
                    String^ updateQuery = "UPDATE CategoryBudgets SET SpentAmount = SpentAmount + @Amount WHERE Category = @Category";
                    SqlCommand^ updateCommand = gcnew SqlCommand(updateQuery, connection);
                    updateCommand->Transaction = transaction;
                    updateCommand->Parameters->AddWithValue("@Amount", amount);
                    updateCommand->Parameters->AddWithValue("@Category", category);

                    // Debugging output
                    MessageBox::Show("Updating category: " + category + " with amount: " + amount.ToString());

                    int rowsUpdated = updateCommand->ExecuteNonQuery();
                    if (rowsUpdated > 0) {
                        // Check if the new spent amount exceeds the budget limit
                        String^ checkQuery = "SELECT BudgetLimit, SpentAmount FROM CategoryBudgets WHERE Category = @Category";
                        SqlCommand^ checkCommand = gcnew SqlCommand(checkQuery, connection);
                        checkCommand->Transaction = transaction;
                        checkCommand->Parameters->AddWithValue("@Category", category);

                        SqlDataReader^ reader = checkCommand->ExecuteReader();
                        if (reader->Read()) {
                            Decimal budgetLimit = reader->GetDecimal(0); // BudgetLimit
                            Decimal spentAmount = reader->GetDecimal(1); // SpentAmount

                            // If the spent amount exceeds the budget limit, show an alert
                            if (spentAmount > budgetLimit) {
                                MessageBox::Show("Alert: The spent amount has exceeded the budget limit for the category '" + category + "'.");
                            }
                        }
                        reader->Close();

                        // Commit the transaction
                        transaction->Commit();
                        return true; // Successfully added expense and updated spent amount
                    }
                    else {
                        transaction->Rollback();
                        MessageBox::Show("Failed to update the spent amount for category: " + category);
                        return false;
                    }
                }
                else {
                    transaction->Rollback();
                    MessageBox::Show("Failed to add the expense.");
                    return false;
                }
            }
            catch (Exception^ e) {
                // If any exception occurs, rollback the transaction
                if (transaction != nullptr) {
                    transaction->Rollback();
                }
                MessageBox::Show("Error: " + e->Message);
                return false;
            }
            finally {
                connection->Close();
            }
        }


        // Method to set or update a category budget
        bool setCategoryBudget(String^ category, Decimal budgetLimit) {
            String^ query = "IF EXISTS (SELECT * FROM CategoryBudgets WHERE Category = @Category) "
                "UPDATE CategoryBudgets SET BudgetLimit = @BudgetLimit WHERE Category = @Category "
                "ELSE "
                "INSERT INTO CategoryBudgets (Category, BudgetLimit, SpentAmount) VALUES (@Category, @BudgetLimit, 0)";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            command->Parameters->AddWithValue("@Category", category);
            command->Parameters->AddWithValue("@BudgetLimit", budgetLimit);

            try {
                connection->Open();
                int result = command->ExecuteNonQuery();
                return result > 0;
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
                return false;
            }
            finally {
                connection->Close();
            }
        }

        // Method to update the spent amount and check if budget is exceeded
        bool updateSpentAmount(String^ category, Decimal amount, bool% isExceeded) {
            String^ query = "UPDATE CategoryBudgets SET SpentAmount = SpentAmount + @Amount WHERE Category = @Category; "
                "SELECT CASE WHEN SpentAmount + @Amount > BudgetLimit THEN 1 ELSE 0 END FROM CategoryBudgets WHERE Category = @Category";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            command->Parameters->AddWithValue("@Category", category);
            command->Parameters->AddWithValue("@Amount", amount);

            try {
                connection->Open();
                isExceeded = Convert::ToBoolean(command->ExecuteScalar());
                return true;
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
                return false;
            }
            finally {
                connection->Close();
            }
        }

        // Method to retrieve budget data for all categories
        DataTable^ getCategorySpendingProgress() {
            DataTable^ dt = gcnew DataTable();
            try {
                SqlDataAdapter^ adapter = gcnew SqlDataAdapter("SELECT Category, BudgetLimit, SpentAmount FROM CategoryBudgets", connection);
                adapter->Fill(dt);
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
            return dt;
        }

        public:
            // Method to get total income without month and year filter
            Decimal getTotalIncome() {
                // Query to get the sum of all incomes
                String^ query = "SELECT SUM(Amount) FROM IncomeExpenses WHERE IncomeExpense = 'income'";
                SqlCommand^ command = gcnew SqlCommand(query, connection);

                try {
                    connection->Open();
                    Object^ result = command->ExecuteScalar();
                    return result != DBNull::Value ? Convert::ToDecimal(result) : 0;
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error retrieving income: " + ex->Message);
                    return 0;
                }
                finally {
                    connection->Close();
                }
            }

            // Method to get total expenses without month and year filter
            Decimal getTotalExpenses() {
                // Query to get the sum of all expenses
                String^ query = "SELECT SUM(Amount) FROM IncomeExpenses WHERE IncomeExpense = 'expenses'";
                SqlCommand^ command = gcnew SqlCommand(query, connection);

                try {
                    connection->Open();
                    Object^ result = command->ExecuteScalar();
                    return result != DBNull::Value ? Convert::ToDecimal(result) : 0;
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error retrieving expenses: " + ex->Message);
                    return 0;
                }
                finally {
                    connection->Close();
                }
            }
         
    private:
        // Method to hash a password using SHA256
        static String^ HashPassword(String^ password) {
            // Convert the password to a byte array
            array<Byte>^ passwordBytes = Encoding::UTF8->GetBytes(password);

            // Create a SHA256 hash object
            SHA256^ sha256 = SHA256::Create();

            // Compute the hash
            array<Byte>^ hashBytes = sha256->ComputeHash(passwordBytes);

            // Convert the byte array to a hex string
            StringBuilder^ sb = gcnew StringBuilder();
            for (int i = 0; i < hashBytes->Length; i++) {
                sb->Append(hashBytes[i].ToString("x2"));
            }

            return sb->ToString(); // Return the hashed password
        }
    };
}

