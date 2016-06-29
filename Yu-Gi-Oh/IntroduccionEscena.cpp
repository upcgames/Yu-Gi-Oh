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
				
				 Dialogo::mostarMensaje(
					"Bienvenido al mundo YuGiOh!!!",
					"Para moverte usa las flechas del teclado",
					"Estas en el Campus de la UPC!!",
					"Encontrarás monedas a lo largo del mapa",
					"O también podrás encontrar otros objetos...",
					"Tu objetivo es derrotar a 4 profesores",
					"Usaras tus cartas para derrotarlos a todos",
					"Para batallar utiliza el mouse",
					"Puedes intercambiar monedas por cartas",
					"Para intercambiar tendrás que ir a la tienda",
					"Y usar el mouse para comprar o vender cartas...",
					"Que empieze tu aventura!"
				);

				 Dialogo::dialogo->que_hacer_al_terminar = gcnew Action(this, &Escena::terminarDeDibujar);

				 if (Dialogo::getNumeroDeParrafo() == 0) {
					 IMAGENES::mostarFondo(IMAGENES::INTRODUCCION_FONDO_1, escena_buffer->Graphics);
				 }
				 else if (Dialogo::getNumeroDeParrafo() == 4) {
					 IMAGENES::mostarFondo(IMAGENES::INTRODUCCION_FONDO_2, escena_buffer->Graphics);
				 }

			}
		}
	}

	void IntroduccionEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		
		if (escena_activa) {

			if (e->KeyCode == CONTROLES::SALIR) {
				Dialogo::dialogo->terminarDeEscribir();
				DesactivarEscena(this);
				ActivarEscena(ESCENAS::campus);
			}

			if (escena_dibujada) {
				DesactivarEscena(this);
				ActivarEscena(ESCENAS::campus);
			}
		}
	}
}