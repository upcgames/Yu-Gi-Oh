#include "Escenas.h"
#include "Juego.h"

namespace YuGiOh {

	BatallaEscena::BatallaEscena() {
		onTimerTick = gcnew EventHandler(this, &BatallaEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &BatallaEscena::teclaDown);
		onMouseClick = gcnew MouseEventHandler(this, &BatallaEscena::mouseClick);
		movimientos_restantes = 4;
		turno_enemigo = false;
		turno_marco = true;
	}

	void BatallaEscena::mostrarBatalla(Graphics ^graphics) {

		IMAGENES::mostarFondo(IMAGENES::BATALLA, graphics);
		enemigo->baraja->mostrarBaraja_10line(graphics, true);
		Marco::marco->baraja->mostrarBaraja_10line(graphics, false);
	}

	void BatallaEscena::timerTick(System::Object^  sender, System::EventArgs^  e) {
		if (escena_activa) {
			if (!escena_dibujada) {
				mostrarBatalla(escena_buffer->Graphics);
				escena_buffer->Render(Juego::graphics);
				escena_dibujada = true;
			}
		}
	}

	void BatallaEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (escena_activa && escena_dibujada) {
			if (e->KeyCode == CONTROLES::SALIR) {
			}
			else if (e->KeyCode == CONTROLES::ACTIVAR_TRAMPA) {
				movimientos_restantes = 4;
				mostrarBatalla(escena_buffer->Graphics);
				escena_buffer->Render(Juego::graphics);
			}
		}
	}

	void BatallaEscena::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (escena_activa && escena_dibujada) {

			Rectangle mouse_rectangle = Rectangle(e->X, e->Y, 1, 1);

			for (int index = 0; index < 10; index++) {
				if (Baraja::getCuerpoDeCarta_10(index).IntersectsWith(mouse_rectangle)) {
					return;
				}
			}
		}

	}

}