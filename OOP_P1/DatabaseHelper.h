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
        // Get income data from the database
        DataTable^ DatabaseHelper::GetIncomeData() {
            DataTable^ dt = gcnew DataTable();

            // Correct the column name: use 'IncomeExpense' instead of 'Type'
            String^ query = "SELECT * FROM IncomeExpenses WHERE IncomeExpense = 'Income'";
            SqlConnection^ connection = gcnew SqlConnection("Data Source=localhost\\sqlexpress;Integrated Security=True");

            try {
                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, connection);
                adapter->Fill(dt);
            }
            catch (Exception^ ex) {
                // Handle any database errors here (you can log it or show a message to the user)
                Console::WriteLine("Error: " + ex->Message);
            }

            return dt;
        }

        // Get expense data from the database
        DataTable^ DatabaseHelper::GetExpenseData() {
            DataTable^ dt = gcnew DataTable();

            // Correct the column name: use 'IncomeExpense' instead of 'Type'
            String^ query = "SELECT * FROM IncomeExpenses WHERE IncomeExpense = 'Expenses'";
            SqlConnection^ connection = gcnew SqlConnection("Data Source=localhost\\sqlexpress;Integrated Security=True");

            try {
                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, connection);
                adapter->Fill(dt);
            }
            catch (Exception^ ex) {
                // Handle any database errors here
                Console::WriteLine("Error: " + ex->Message);
            }

            return dt;
        }
        DataTable^ DatabaseHelper::GetAssignmentsNearDeadline(DateTime today, DateTime threshold)
        {
            // SQL Query to fetch assignments with deadlines approaching
            String^ query = "SELECT AssignmentName, EndDate FROM Assignments WHERE EndDate BETWEEN @today AND @threshold";

            SqlCommand^ cmd = gcnew SqlCommand(query, connection);
            cmd->Parameters->AddWithValue("@today", today);
            cmd->Parameters->AddWithValue("@threshold", threshold);

            SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
            DataTable^ result = gcnew DataTable();
            adapter->Fill(result);

            return result;
        }


        void DatabaseHelper::UpdateIncomeExpense(int entryID, String^ incomeExpense, String^ date, String^ category, String^ description, String^ source, Decimal amount) {
            String^ query = "UPDATE IncomeExpenses SET IncomeExpense = @IncomeExpense, Date = @Date, Category = @Category, Description = @Description, Source = @Source, Amount = @Amount WHERE EntryID = @EntryID";

            SqlConnection^ connection = gcnew SqlConnection("Data Source=localhost\\sqlexpress;Integrated Security=True");

            try {
                // Open the connection to the database
                connection->Open();

                SqlCommand^ command = gcnew SqlCommand(query, connection);

                // Add parameters to prevent SQL injection
                command->Parameters->AddWithValue("@EntryID", entryID);
                command->Parameters->AddWithValue("@IncomeExpense", incomeExpense);
                command->Parameters->AddWithValue("@Date", date);
                command->Parameters->AddWithValue("@Category", category);
                command->Parameters->AddWithValue("@Description", description);
                command->Parameters->AddWithValue("@Source", source);
                command->Parameters->AddWithValue("@Amount", amount);

                // Execute the query to update the record
                command->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                // Handle errors
                MessageBox::Show("Error: " + ex->Message);
            }
            finally {
                // Close the connection
                connection->Close();
            }
        }

        void DatabaseHelper::AddAcademicSchedule(String^ subject, String^ subjectCode, DateTime date, DateTime startTime)
        {
            SqlConnection^ connection = gcnew SqlConnection("Data Source=localhost\\sqlexpress;Integrated Security=True");
            SqlCommand^ command = gcnew SqlCommand(
                "INSERT INTO AcademicSchedule (Subject, SubjectCode, Date, StartTime) VALUES (@Subject, @SubjectCode, @Date, @StartTime)",
                connection
            );

            // Parameters for the SQL query
            command->Parameters->AddWithValue("@Subject", subject);
            command->Parameters->AddWithValue("@SubjectCode", subjectCode);
            command->Parameters->AddWithValue("@Date", date);
            command->Parameters->AddWithValue("@StartTime", startTime.TimeOfDay); // Use TimeOfDay to store only the time part.

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Academic Schedule Added Successfully!");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message);
            }
            finally
            {
                connection->Close();
            }
        }

        // Method to add an assignment record
        void AddAssignment(String^ assignmentName, String^ subjectCode, DateTime startDate, DateTime endDate)
        {
            SqlConnection^ connection = gcnew SqlConnection("Data Source=localhost\\sqlexpress;Integrated Security=True");
            SqlCommand^ command = gcnew SqlCommand("INSERT INTO Assignments (AssignmentName, SubjectCode, StartDate, EndDate) VALUES (@AssignmentName, @SubjectCode, @StartDate, @EndDate)", connection);

            // Parameters for the SQL query
            command->Parameters->AddWithValue("@AssignmentName", assignmentName);
            command->Parameters->AddWithValue("@SubjectCode", subjectCode);
            command->Parameters->AddWithValue("@StartDate", startDate);
            command->Parameters->AddWithValue("@EndDate", endDate);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Assignment Added Successfully!");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message);
            }
            finally
            {
                connection->Close();
            }
        }

   


        DataTable^ DatabaseHelper::GetDailyIncome() {
            // Query to fetch daily income, filtering by 'Income' in the IncomeExpense column
            String^ query = "SELECT Date, SUM(Amount) AS Amount FROM dbo.IncomeExpenses WHERE IncomeExpense = 'Income' GROUP BY Date ORDER BY Date ASC";

            // Execute the query and return the results as DataTable
            return ExecuteQuery(query);
        }

        // Query to fetch daily expenses
        DataTable^ DatabaseHelper::GetDailyExpenses() {
            // Query to fetch daily expenses, filtering by 'Expense' in the IncomeExpense column
            String^ query = "SELECT Date, SUM(Amount) AS Amount FROM dbo.IncomeExpenses WHERE IncomeExpense = 'Expenses' GROUP BY Date ORDER BY Date ASC";

            // Execute the query and return the results as DataTable
            return ExecuteQuery(query);
        }



        

        DataTable^ GetAcademicSchedule(DateTime selectedDate) {
            DataTable^ dt = gcnew DataTable();

            // Assuming a connection and SQL command to retrieve schedule data
            SqlConnection^ conn = gcnew SqlConnection("Data Source=localhost\\sqlexpress;Integrated Security=True");

            // SQL query to compare only the date part (ignore time part)
            String^ query = "SELECT * FROM AcademicSchedule WHERE CAST(Date AS DATE) = @date";

            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            // Convert the selectedDate to just the date part to remove the time
            cmd->Parameters->AddWithValue("@date", selectedDate.Date);

            try {
                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
                adapter->Fill(dt);
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error retrieving data: " + ex->Message);
            }
            return dt;
        }

        // Method to retrieve assignments for a specific date range
        DataTable^ GetAssignments(DateTime selectedDate) {
            DataTable^ dt = gcnew DataTable();

            SqlConnection^ conn = gcnew SqlConnection("Data Source=localhost\\sqlexpress;Integrated Security=True");
            String^ query = "SELECT * FROM Assignments WHERE StartDate <= @date AND EndDate >= @date";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@date", selectedDate);

            try {
                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
                adapter->Fill(dt);
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error retrieving data: " + ex->Message);
            }
            return dt;
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

                // Check if category is empty or null, and insert DBNull for NULL category
                if (category == nullptr || category->Trim()->Length == 0) {
                    command->Parameters->AddWithValue("@category", DBNull::Value);  // Handle NULL category
                }
                else {
                    command->Parameters->AddWithValue("@category", category);
                }

                command->Parameters->AddWithValue("@source", source);
                command->Parameters->AddWithValue("@description", description);
                command->Parameters->AddWithValue("@amount", amount);

                int rowsAffected = command->ExecuteNonQuery();

                if (rowsAffected > 0) {
                    // Check if the category exists in CategoryBudgets (only if category is not null)
                    if (category != nullptr && category->Trim()->Length > 0) {
                        String^ checkCategoryQuery = "SELECT COUNT(*) FROM CategoryBudgets WHERE Category = @Category";
                        SqlCommand^ checkCategoryCommand = gcnew SqlCommand(checkCategoryQuery, connection);
                        checkCategoryCommand->Transaction = transaction;
                        checkCategoryCommand->Parameters->AddWithValue("@Category", category);

                        int categoryCount = (int)checkCategoryCommand->ExecuteScalar();
                        if (categoryCount == 0) {
                            MessageBox::Show("Category '" + category + "' Buget is not set to the this category.Please firstly set budget in the CategoryBudeting Section.");
                            transaction->Rollback();
                            return false;
                        }

                        // Inserted successfully, now update the spent amount in CategoryBudgets
                        String^ updateQuery = "UPDATE CategoryBudgets SET SpentAmount = SpentAmount + @Amount WHERE Category = @Category";
                        SqlCommand^ updateCommand = gcnew SqlCommand(updateQuery, connection);
                        updateCommand->Transaction = transaction;
                        updateCommand->Parameters->AddWithValue("@Amount", amount);
                        updateCommand->Parameters->AddWithValue("@Category", category);

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
                        // If no category is provided (income case), commit the transaction
                        transaction->Commit();
                        return true; // Successfully added income without category
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
            DataTable^ GetCategoryBudgetData() {
                DataTable^ dt = gcnew DataTable();
                try {
                    // SQL query to retrieve category, budget limit, and spent amount
                    String^ query = "SELECT Category, BudgetLimit, SpentAmount FROM CategoryBudgets";
                    SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(query, connection);
                    dataAdapter->Fill(dt);
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error: " + ex->Message);
                }
                return dt;
            }

         public: bool DeleteAllData() {
             try {
                 // Open the database connection
                 if (connection->State != ConnectionState::Open) {
                     connection->Open();
                 }

                 // Delete all records from the CategoryBudgets table
                 String^ deleteCategoryBudgetsQuery = "DELETE FROM CategoryBudgets";
                 ExecuteNonQuery(deleteCategoryBudgetsQuery, connection);

                 // Reset the identity value for CategoryBudgets table
                 String^ resetCategoryBudgetsIdentity = "DBCC CHECKIDENT ('CategoryBudgets', RESEED, 0)";
                 ExecuteNonQuery(resetCategoryBudgetsIdentity, connection);

                 // Delete all records from the IncomeExpenses table
                 String^ deleteIncomeExpensesQuery = "DELETE FROM IncomeExpenses";
                 ExecuteNonQuery(deleteIncomeExpensesQuery, connection);

                 // Reset the identity value for IncomeExpenses table
                 String^ resetIncomeExpensesIdentity = "DBCC CHECKIDENT ('IncomeExpenses', RESEED, 0)";
                 ExecuteNonQuery(resetIncomeExpensesIdentity, connection);

                 // Success message box after completing all operations
                 MessageBox::Show("Database has been reset successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                 return true;  // Return true if all queries were successful
             }
             catch (Exception^ e) {
                 // Log the error and return false if something goes wrong
                 MessageBox::Show("Error: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                 return false;
             }
             finally {
                 // Ensure the connection is closed
                 if (connection->State == ConnectionState::Open) {
                     connection->Close();
                 }
             }
         }
        
    private: void ExecuteNonQuery(String^ query, SqlConnection^ connection) {
        try {
            SqlCommand^ cmd = gcnew SqlCommand(query, connection);
            cmd->ExecuteNonQuery();  // Execute the query (no results expected)
        }
        catch (Exception^ ex) {
            // Handle exceptions here
            MessageBox::Show("Error executing query: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
           


public:
    DataTable^ ExecuteQuery(String^ query)
    {
        // Create connection string (adjust it to your database)
        String^ connectionString = "Data Source=localhost\\sqlexpress;Integrated Security=True";

        // Create the connection and command objects
        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlCommand^ command = gcnew SqlCommand(query, connection);
        SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);

        // Create a DataTable to hold the result
        DataTable^ result = gcnew DataTable();

        try
        {
            // Open the connection
            connection->Open();

            // Fill the DataTable with the results of the query
            dataAdapter->Fill(result);
        }
        catch (Exception^ e)
        {
            MessageBox::Show("Error: " + e->Message);
        }
        finally
        {
            // Close the connection
            connection->Close();
        }

        return result;
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


