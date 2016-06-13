#include "Escenas.h"
#include "Imagenes.h"
#include "Juego.h"
#include "Dialogo.h"

namespace YuGiOh
{
	IntroduccionEscena::IntroduccionEscena()
	{
		onTimerTick = gcnew EventHandler(this, &IntroduccionEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &IntroduccionEscena::teclaDown);
	}

	void IntroduccionEscena::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->DrawImage(Imagenes::IntroduccionEscena, Rectangle(0, 0, MYFORM_SIZE_WIDTH, MYFORM_SIZE_HEIGHT));
				buffer->Render(Juego::graphics);
				Juego::dialogo = gcnew Dialogo(gcnew array<String^> {
					"Bienvenido al mundo YuGiOh!!!",
					"Para moverte usa las flechas del teclado",
					"Estas en el Campus de la UPC!!",
					"Encontrarás monedas a lo largo del mapa",
					"O también puedes encontrar otras piezas..",
					"Tu objetivo es derrotar a 4 profesores",
					"Puedes intercambiar monedas por cartas",
					"Que empieze tu aventura!"
				});
				dibujado = true;
			}
		}
	}

	void IntroduccionEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				DesactivarEscena(this);
				ActivarEscena(Juego::campus);
			}

		}
	}
}