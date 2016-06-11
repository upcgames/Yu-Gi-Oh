#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;

namespace YuGiOh
{
	Imagenes::Imagenes()
	{
		//Personaje
		MARCO_SPRITE = Image::FromFile("Imagenes\\Personajes\\Bomberdog.png");

		//Objetos
		Suelo1 = Image::FromFile("Imagenes\\Objetos\\Piso1.png");
		Pared1 = Image::FromFile("Imagenes\\Objetos\\Bloque1.png");
		Money1 = Image::FromFile("Imagenes\\Objetos\\Caja1.png");
		Doors1 = Image::FromFile("Imagenes\\Objetos\\Portal.png");
		Extra1 = Image::FromFile("Imagenes\\Objetos\\Portal.png");
	
		Introduccion = Image::FromFile("Imagenes\\Interfaces\\Introduccion.png");
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