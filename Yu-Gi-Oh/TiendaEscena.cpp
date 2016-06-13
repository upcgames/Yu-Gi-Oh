#include "Escenas.h"
#include "Imagenes.h"
#include "Juego.h"
#include "Dialogo.h"

namespace YuGiOh
{
	TiendaEscena::TiendaEscena()
	{
		onTimerTick = gcnew EventHandler(this, &TiendaEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &TiendaEscena::teclaDown);
		onMouseClick = gcnew MouseEventHandler(this, &TiendaEscena::mouseClick);

	}

	void TiendaEscena::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->DrawImage(Imagenes::IntroduccionEscena, Rectangle(0, 0, 832, 577));
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

	void TiendaEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
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

	void TiendaEscena::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (activo && dibujado)
		{
			;
		}
	}
}