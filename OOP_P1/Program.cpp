#include "LoginForm.h" // Include the login form's header file

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    // Enables visual styles and sets text rendering compatibility for Windows Forms
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Run the login form
    Application::Run(gcnew OOPP1::LoginForm());
    return 0;
}
