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
		LOCETA = Image::FromFile("Imagenes\\Objetos\\Piso4.png");
		PUERTA = Image::FromFile("Imagenes\\Objetos\\Caja1.png");
		MONEDA = Image::FromFile("Imagenes\\Objetos\\Caja4.png");
		AGUA = Image::FromFile("Imagenes\\Objetos\\Piso3.png");
		MACETA = Image::FromFile("Imagenes\\Objetos\\Bloque5.png");
		PASTO = Image::FromFile("Imagenes\\Objetos\\Piso2.png");
	
		IntroduccionEscena = Image::FromFile("Imagenes\\Interfaces\\Introduccion.png");
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