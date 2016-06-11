#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;

namespace YuGiOh
{
	Imagenes::Imagenes()
	{
		//Personaje
		Imagenes::MARCO_SPRITE = Image::FromFile("Imagenes\\Personajes\\Bomberdog.png");

		//Objetos
		Imagenes::Suelo1 = Image::FromFile("Imagenes\\Objetos\\Piso1.png");
		Imagenes::Pared1 = Image::FromFile("Imagenes\\Objetos\\Bloque1.png");
		Imagenes::Money1 = Image::FromFile("Imagenes\\Objetos\\Caja1.png");
		Imagenes::Doors1 = Image::FromFile("Imagenes\\Objetos\\Portal.png");
		Imagenes::Extra1 = Image::FromFile("Imagenes\\Objetos\\Portal.png");
	}

	[STAThread]
	void main()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		MyForm^ my_form = gcnew MyForm();

		Application::Run(my_form);
	}
}