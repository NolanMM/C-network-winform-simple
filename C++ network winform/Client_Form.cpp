#include "Client_Form.h"
using namespace System;

using namespace System::Windows::Forms;

[STAThread]

void main()

{
    // Start to run the GUI of the program of Client
    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    Cnetworkwinform::Client_Form form;

    Application::Run(% form);

}