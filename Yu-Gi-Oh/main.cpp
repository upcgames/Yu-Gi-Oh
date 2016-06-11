#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

namespace YuGiOh
{
	[STAThread]
	void main()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		MyForm^ my_form = gcnew MyForm();

		Application::Run(my_form);
	}
}