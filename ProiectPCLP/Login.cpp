#include "StartPage.h"
#include "Login.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ProiectPCLP::MyForm form;
	Application::Run(%form);
}
