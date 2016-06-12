#include "Juego.h"

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
		LOCETA = Image::FromFile("Imagenes\\Objetos\\Piso1.png");
		PUERTA = Image::FromFile("Imagenes\\Objetos\\Bloque1.png");
		MONEDA = Image::FromFile("Imagenes\\Objetos\\Caja1.png");
		AGUA = Image::FromFile("Imagenes\\Objetos\\Portal.png");
		MACETA = Image::FromFile("Imagenes\\Objetos\\Portal.png");
		PASTO = Image::FromFile("Imagenes\\Objetos\\Portal.png");
	
		Introduccion = Image::FromFile("Imagenes\\Interfaces\\Introduccion.png");
	}

	[STAThread]
	void main()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Juego^ my_form = gcnew Juego();

		Application::Run(my_form);
	}
}