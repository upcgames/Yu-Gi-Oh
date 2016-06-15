#include "Juego.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;

namespace YuGiOh
{
	[STAThread]
	void main()
	{
		//Sprites
		Imagenes::MARCO_SPRITE = Image::FromFile("Imagenes\\Personajes\\Marco_Sprite.png");
		Imagenes::MONEDA_SPRITE = Image::FromFile("Imagenes\\Objetos\\Moneda_Sprite.png");

		//Objetos
		Imagenes::LOCETA = Image::FromFile("Imagenes\\Objetos\\Piso4.png");
		Imagenes::PUERTA = Image::FromFile("Imagenes\\Objetos\\Caja1.png");
		Imagenes::MONEDA = Image::FromFile("Imagenes\\Objetos\\Caja4.png");
		Imagenes::AGUA = Image::FromFile("Imagenes\\Objetos\\Piso3.png");
		Imagenes::MACETA = Image::FromFile("Imagenes\\Objetos\\Bloque5.png");
		Imagenes::PASTO = Image::FromFile("Imagenes\\Objetos\\Piso2.png");

		Imagenes::INTRODUCCION_FONDO = Image::FromFile("Imagenes\\Interfaces\\Introduccion.png");
		Imagenes::FONDO_TIENDA_VENDER = Image::FromFile("Imagenes\\Interfaces\\Tienda_Vender.png");
		Imagenes::FONDO_TIENDA_COMPRAR = Image::FromFile("Imagenes\\Interfaces\\Tienda_Comprar.png");

		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Juego^ my_form = gcnew Juego();
		Application::Run(my_form);
	}
}