#pragma once
using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms; // Include this for MessageBox
using namespace System::Security::Cryptography; // For hashing
using namespace System::Text; // For encoding

public ref class BudgetHelper
{
public:
    static void CheckAndAlertBudget(int userID, Label^ alertLabel)
    {
        // Step 1: Get the list of categories and their budgets
        String^ connectionString = "Data Source=localhost\\sqlexpress;Integrated Security=True"; // Adjust as needed
        SqlConnection^ connection = nullptr;

        try
        {
            connection = gcnew SqlConnection(connectionString);
            connection->Open();

            // Step 2: Query to get the list of budgets set by the user
            String^ query = "SELECT Category, BudgetAmount FROM BudgetLimits WHERE UserID = @UserID";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            command->Parameters->AddWithValue("@UserID", userID);

            SqlDataReader^ reader = command->ExecuteReader();

            bool alertShown = false; // Track if any alert has been shown

            while (reader->Read())
            {
                String^ category = reader["Category"]->ToString();
                double budgetAmount = Convert::ToDouble(reader["BudgetAmount"]);

                // Step 3: Get the actual amount spent in this category for the current month
                double actualAmountSpent = GetActualAmountSpent(userID, category);

                // Step 4: Check for the conditions - Budget nearing and Budget exceeded
                if (actualAmountSpent > budgetAmount)
                {
                    // Over-exceeding budget alert
                    String^ alertMessage = "You have exceeded your budget for the category: " + category + ". " +
                        "Budget: Rs. " + budgetAmount + " Spent: Rs. " + actualAmountSpent;
                    alertLabel->Text = alertMessage; // Display alert on the dashboard label
                    alertLabel->ForeColor = System::Drawing::Color::Red; // Change text color to red for over-exceeding
                    alertShown = true;
                }
                else if (budgetAmount - actualAmountSpent <= 1000)
                {
                    // Budget nearing target (Rs. 1000 remaining)
                    String^ alertMessage = "You have Rs. " + (budgetAmount - actualAmountSpent) + " left to reach your budget for category: " + category;
                    alertLabel->Text = alertMessage; // Display alert on the dashboard label
                    alertLabel->ForeColor = System::Drawing::Color::Orange; // Change text color to orange for nearing budget
                    alertShown = true;
                }
            }

            // If no alert has been triggered, reset the label (optional)
            if (!alertShown)
            {
                alertLabel->Text = "Your budgets are on track!";
                alertLabel->ForeColor = System::Drawing::Color::Green;
            }
        }
        catch (SqlException^ sqlEx)
        {
            MessageBox::Show("SQL Error: " + sqlEx->Message);
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally
        {
            if (connection != nullptr && connection->State == System::Data::ConnectionState::Open)
            {
                connection->Close();
            }
        }
    }

private:
    // Helper method to get the actual amount spent by the user in a given category for the current month
    static double GetActualAmountSpent(int userID, String^ category)
    {
        double totalSpent = 0;

        String^ connectionString = "Data Source=localhost\\sqlexpress;Integrated Security=True"; // Adjust as needed
        SqlConnection^ connection = nullptr;

        try
        {
            connection = gcnew SqlConnection(connectionString);
            connection->Open();

            // Get the actual amount spent in the category for the current month
            String^ query = "SELECT SUM(Amount) AS TotalSpent FROM IncomeExpenses WHERE UserID = @UserID AND Category = @Category";
            SqlCommand^ command = gcnew SqlCommand(query, connection);
            command->Parameters->AddWithValue("@UserID", userID);
            command->Parameters->AddWithValue("@Category", category);

            SqlDataReader^ reader = command->ExecuteReader();

            if (reader->Read())
            {
                totalSpent = Convert::ToDouble(reader["TotalSpent"]);
            }
        }
        catch (SqlException^ sqlEx)
        {
            MessageBox::Show("SQL Error: " + sqlEx->Message);
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally
        {
            if (connection != nullptr && connection->State == System::Data::ConnectionState::Open)
            {
                connection->Close();
            }
        }

        return totalSpent;
    }
};
