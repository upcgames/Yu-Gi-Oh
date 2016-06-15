#include "Juego.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;

namespace YuGiOh {

	const bool DEBUG_MODE = false;

	[STAThread]
	void main() {

		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Juego^ my_form = gcnew Juego();
		Application::Run(my_form);
	}
}