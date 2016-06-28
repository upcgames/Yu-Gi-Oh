#include "Escenas.h"
#include "Juego.h"

namespace YuGiOh {

	BatallaEscena::BatallaEscena() {
		onTimerTick = gcnew EventHandler(this, &BatallaEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &BatallaEscena::teclaDown);
		onMouseClick = gcnew MouseEventHandler(this, &BatallaEscena::mouseClick);
		
		cartas_activas_enemigo = gcnew List<Carta ^>(3);
		cartas_activas_marco = gcnew List<Carta ^>(3);
		movimientos_restantes = 4;
		turno_enemigo = false;
		turno_marco = true;
	}

	void BatallaEscena::empezarBatalla() {
		cartas_activas_enemigo->Add(enemigo->baraja->cartas[0]);
		cartas_activas_enemigo[0]->activa = true;
		cartas_activas_enemigo->Add(enemigo->baraja->cartas[1]);
		cartas_activas_enemigo[1]->activa = true;
		cartas_activas_enemigo->Add(enemigo->baraja->cartas[2]);
		cartas_activas_enemigo[2]->activa = true;

		cartas_activas_marco->Add(Marco::marco->baraja->cartas[0]);
		cartas_activas_marco[0]->activa = true;
		if (Marco::marco->baraja->cartas->Count > 1) {
			cartas_activas_marco->Add(Marco::marco->baraja->cartas[1]);
			cartas_activas_marco[1]->activa = true;
		}
		if (Marco::marco->baraja->cartas->Count > 2) {
			cartas_activas_marco->Add(Marco::marco->baraja->cartas[2]);
			cartas_activas_marco[2]->activa = true;
		}
	}

	void BatallaEscena::mostrarBatalla(Graphics ^graphics) {
		IMAGENES::mostarFondo(IMAGENES::BATALLA, graphics);
		mostrarCartasActivas(graphics);
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
				terminarBatalla();
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

	void BatallaEscena::terminarBatalla() {
		DesactivarEscena(this);
		cartas_activas_enemigo->Clear();
		cartas_activas_marco->Clear();

		Mapa::mapa_actual = Mapa::obtenerMapa(pabellon_de_regreso);
		Marco::marco->Detener();
		Marco::marco->posicion->igualarA(this->posicion_de_regreso);
		Marco::marco->direccion = this->direccion_de_regreso;
		ActivarEscena(ESCENAS::campus);
	}

	void BatallaEscena::mostrarCartasActivas(Graphics^ graphics) {
		for (int i = 0; i < cartas_activas_marco->Count; i++) {
			Carta ^carta = cartas_activas_marco[i];

			carta->mostrarCarta(graphics, Rectangle(192 + i *216,360,CARTAS_WIDTH,CARTAS_HEIGHT));

			graphics->DrawString(
				"Ataque: " + carta->nivel,
				FUENTES::NIVEL,
				gcnew SolidBrush(Color::White),
				(float)192 + i * 216,
				(float)360,
				StringFormat::GenericTypographic
				);
		}

		for (int i = 0; i < cartas_activas_enemigo->Count; i++) {
			Carta ^carta = cartas_activas_enemigo[i];

			carta->mostrarCarta(graphics, Rectangle(192 + i * 216, 120, CARTAS_WIDTH, CARTAS_HEIGHT));

			graphics->DrawString(
				"Ataque: " + carta->nivel,
				FUENTES::NIVEL,
				gcnew SolidBrush(Color::White),
				(float)192 + i * 216,
				(float)120,
				StringFormat::GenericTypographic
				);
		}
	}

}