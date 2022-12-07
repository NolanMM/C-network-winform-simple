#include "Client_Form.h"
using namespace System;

using namespace System::Windows::Forms;

[STAThread]

void main()

{

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    Cnetworkwinform::Client_Form form;

    Application::Run(% form);

}