#include "Escenas.h"
#include "Imagenes.h"
#include "Juego.h"
#include "Dialogo.h"

namespace YuGiOh {

	IntroduccionEscena::IntroduccionEscena() {
		onTimerTick = gcnew EventHandler(this, &IntroduccionEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &IntroduccionEscena::teclaDown);
	}

	void IntroduccionEscena::timerTick(System::Object^  sender, System::EventArgs^  e) {
		if (escena_activa) {
			if (!escena_dibujada) {
				IMAGENES::mostarFondo(IMAGENES::INTRODUCCION_FONDO, escena_buffer->Graphics);
				escena_buffer->Render(Juego::graphics);
				
				 Dialogo::mostarMensaje(
					"Bienvenido al mundo YuGiOh!!!",
					"Para moverte usa las flechas del teclado",
					"Estas en el Campus de la UPC!!",
					"Encontrarás monedas a lo largo del mapa",
					"O también puedes encontrar otras piezas..",
					"Tu objetivo es derrotar a 4 profesores",
					"Puedes intercambiar monedas por cartas",
					"Que empieze tu aventura!"
				);

				escena_dibujada = true;
			}
		}
	}

	void IntroduccionEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (escena_activa && escena_dibujada) {
				DesactivarEscena(this);
				ActivarEscena(ESCENAS::campus);
		}
	}
}