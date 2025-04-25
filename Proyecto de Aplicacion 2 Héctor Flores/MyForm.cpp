#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProyectodeAplicacion2VERSION2HéctorFlores::MyForm form;
	Application::Run(% form);
	return 0;
}
