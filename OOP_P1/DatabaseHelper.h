#pragma once
#pragma once

using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms; // Include this for MessageBox
using namespace System::Security::Cryptography; // For hashing
using namespace System::Text; // For encoding

public ref class DatabaseHelper
{
public:
    static bool CheckCredentials(String^ username, String^ password)
    {
        String^ connectionString = "Data Source=localhost\\sqlexpress;Integrated Security=True"; // Adjust as necessary
        SqlConnection^ connection = nullptr;

        try
        {
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
        catch (SqlException^ sqlEx)
        {
            MessageBox::Show(String::Concat("SQL Error: ", sqlEx->Message));
            return false;
        }
        catch (Exception^ ex)
        {
            MessageBox::Show(String::Concat("An error occurred: ", ex->Message));
            return false;
        }
        finally
        {
            if (connection != nullptr && connection->State == System::Data::ConnectionState::Open)
            {
                connection->Close(); // Ensure the connection is closed
            }
        }
    }

    static bool AddUser(String^ username, String^ email, String^ password)
    {
        String^ connectionString = "Data Source=localhost\\sqlexpress;Integrated Security=True"; // Adjust as necessary
        SqlConnection^ connection = nullptr;

        try
        {
            connection = gcnew SqlConnection(connectionString);
            connection->Open();
            String^ hashedPassword = HashPassword(password); // Hash the password
            String^ query = "INSERT INTO Users (Username, Email, Password) VALUES (@username, @email, @password)";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            command->Parameters->AddWithValue("@username", username);
            command->Parameters->AddWithValue("@email", email);
            command->Parameters->AddWithValue("@password", hashedPassword);

            int result = command->ExecuteNonQuery(); // Execute the insert command
            return result > 0; // Return true if a row was inserted
        }
        catch (SqlException^ sqlEx)
        {
            MessageBox::Show(String::Concat("SQL Error: ", sqlEx->Message));
            return false;
        }
        catch (Exception^ ex)
        {
            MessageBox::Show(String::Concat("An error occurred: ", ex->Message));
            return false;
        }
        finally
        {
            if (connection != nullptr && connection->State == System::Data::ConnectionState::Open)
            {
                connection->Close(); // Ensure the connection is closed
            }
        }
    }

    bool addIncomeExpense(String^ incomeExpense, String^ date, String^ category, String^ source, String^ description, Decimal amount)
    {
        SqlConnection^ conn = gcnew SqlConnection("Data Source=localhost\\sqlexpress;Integrated Security=True");
        try
        {
            conn->Open();

            String^ query = "INSERT INTO IncomeExpenses (IncomeExpense, Date, Category, Source, Description, Amount) VALUES (@incomeExpense, @date, @category, @source, @description, @amount)";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@incomeExpense", incomeExpense);
            cmd->Parameters->AddWithValue("@date", date);
            cmd->Parameters->AddWithValue("@category", category);
            cmd->Parameters->AddWithValue("@source", source);
            cmd->Parameters->AddWithValue("@description", description);
            cmd->Parameters->AddWithValue("@amount", amount);

            int rowsAffected = cmd->ExecuteNonQuery();

            return rowsAffected > 0;  // Return true if the record was added successfully
        }
        catch (Exception^ e)
        {
            MessageBox::Show("Error: " + e->Message);
            return false;  // Return false if there was an error
        }
        finally
        {
            conn->Close();
        }
    }



private:
    // Method to hash a password using SHA256
    static String^ HashPassword(String^ password)
    {
        // Convert the password to a byte array
        array<Byte>^ passwordBytes = Encoding::UTF8->GetBytes(password);

        // Create a SHA256 hash object
        SHA256^ sha256 = SHA256::Create();

        // Compute the hash
        array<Byte>^ hashBytes = sha256->ComputeHash(passwordBytes);

        // Convert the byte array to a hex string
        StringBuilder^ sb = gcnew StringBuilder();
        for (int i = 0; i < hashBytes->Length; i++)
        {
            sb->Append(hashBytes[i].ToString("x2")); // Append each byte as a hex value
        }

        return sb->ToString(); // Return the hashed password
    }
};

