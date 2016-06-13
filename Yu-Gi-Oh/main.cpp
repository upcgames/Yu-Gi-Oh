#include "Juego.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;

namespace YuGiOh
{
	Imagenes::Imagenes()
	{
		//Sprites
		MARCO_SPRITE = Image::FromFile("Imagenes\\Personajes\\Marco_Sprite.png");
		MONEDA_SPRITE = Image::FromFile("Imagenes\\Objetos\\Moneda_Sprite.png");

		//Objetos
		LOCETA = Image::FromFile("Imagenes\\Objetos\\Piso4.png");
		PUERTA = Image::FromFile("Imagenes\\Objetos\\Caja1.png");
		MONEDA = Image::FromFile("Imagenes\\Objetos\\Caja4.png");
		AGUA = Image::FromFile("Imagenes\\Objetos\\Piso3.png");
		MACETA = Image::FromFile("Imagenes\\Objetos\\Bloque5.png");
		PASTO = Image::FromFile("Imagenes\\Objetos\\Piso2.png");
	
		INTRODUCCION_FONDO = Image::FromFile("Imagenes\\Interfaces\\Introduccion.png");
		FONDO_TIENDA_VENDER = Image::FromFile("Imagenes\\Interfaces\\Tienda_Vender.png");
		FONDO_TIENDA_COMPRAR = Image::FromFile("Imagenes\\Interfaces\\Tienda_Comprar.png");
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