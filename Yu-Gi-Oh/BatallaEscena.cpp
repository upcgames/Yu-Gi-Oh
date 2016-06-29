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

		for (int i = 0; i < Marco::marco->baraja->cartas->Count; i++) {
			int nivel = Marco::marco->baraja->cartas[i]->nivel;
			Marco::marco->baraja->cartas[i]->ataque = nivel * 10;
			Marco::marco->baraja->cartas[i]->defensa = nivel * 5;
			Marco::marco->baraja->cartas[i]->nivel = nivel;
			Marco::marco->baraja->cartas[i]->activa = false;
			Marco::marco->baraja->cartas[i]->vida = 20 + nivel * 10;
		}
			

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
	
	void BatallaEscena::ingresarEnemigo() {

		if (cartas_activas_enemigo->Count == 3) {
			atacarAliadoActivo();
			return;
		}

		for (int i = 0; i < enemigo->baraja->cartas->Count; i++)  {
			if (enemigo->baraja->cartas[i]->vida > 0 && !enemigo->baraja->cartas[i]->activa) {
				enemigo->baraja->cartas[i]->activa = true;
				cartas_activas_enemigo->Add(enemigo->baraja->cartas[i]);
				atacarAliadoActivo();
				return;
			}
		}

		if (cartas_activas_enemigo->Count == 0) {
			mostrarBatalla(escena_buffer->Graphics);
			escena_buffer->Render(Juego::graphics);
			Dialogo::pausarYMostarMensaje("Ganaste este duelo!!!");
			for (int i = 0; i < Marco::marco->baraja->cartas->Count; i++)
				Marco::marco->baraja->cartas[i]->nivel += 1;

			Dialogo::dialogo->devolver_a_escena = false;
			Dialogo::dialogo->que_hacer_al_terminar = gcnew Action(this, &BatallaEscena::terminarBatalla);
			return;
		}
	}

	void BatallaEscena::ingresarAliado() {
		if (cartas_activas_marco->Count == 3) {
			return;
		}

		for (int i = 0; i < Marco::marco->baraja->cartas->Count; i++)  {
			if (Marco::marco->baraja->cartas[i]->vida > 0 && !Marco::marco->baraja->cartas[i]->activa) {
				cartas_activas_marco->Add(Marco::marco->baraja->cartas[i]);
				Marco::marco->baraja->cartas[i]->activa = true;
				return;
			}
		}

		if (cartas_activas_marco->Count == 0) {
			mostrarBatalla(escena_buffer->Graphics);
			escena_buffer->Render(Juego::graphics);
			Dialogo::pausarYMostarMensaje("Perdiste este duelo!!!");
			Dialogo::dialogo->devolver_a_escena = false;
			Dialogo::dialogo->que_hacer_al_terminar = gcnew Action(this, &BatallaEscena::terminarBatalla);
			return;
		}
	}

	void BatallaEscena::atacarEnemigoActivo(int posicion) {
		int ataque_total = 0;
		escena_dibujada = false;

		for (int i = 0; i < cartas_activas_marco->Count; i++)  {
				ataque_total += cartas_activas_marco[i]->ataque;
		}

		int vida_final = cartas_activas_enemigo[posicion]->vida - ataque_total;

		if (vida_final <= 0){
			cartas_activas_enemigo[posicion]->vida = 0;
			cartas_activas_enemigo[posicion]->activa = false;

			cartas_activas_enemigo->RemoveAt(posicion);

			ingresarEnemigo();
			return;
		}

		atacarAliadoActivo();
		cartas_activas_enemigo[posicion]->vida = vida_final;
	}

	void BatallaEscena::atacarAliadoActivo() {
		int ataque_total = 0;
		escena_dibujada = false;

		for (int i = 0; i < cartas_activas_enemigo->Count; i++)  {
				ataque_total += cartas_activas_enemigo[i]->ataque;
		}

		int vida_final = cartas_activas_marco[0]->vida - ataque_total;

		if (vida_final <= 0){
			cartas_activas_marco[0]->vida = 0;
			cartas_activas_marco[0]->activa = false;

			cartas_activas_marco->RemoveAt(0);

			ingresarAliado();
			return;
		}

		cartas_activas_marco[0]->vida = vida_final;
		mostrarBatalla(escena_buffer->Graphics);
		escena_buffer->Render(Juego::graphics);
	}

	void BatallaEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (escena_activa && escena_dibujada) {
			if (e->KeyCode == CONTROLES::SALIR) {
				terminarBatalla();
			}
			else if (e->KeyCode == CONTROLES::ACTIVAR_TRAMPA) {
				for (int i = 0; i < Marco::marco->baraja->cartas->Count; i++) {
					Marco::marco->baraja->cartas[i]->nivel += 1;
					int nivel = Marco::marco->baraja->cartas[i]->nivel;
					Marco::marco->baraja->cartas[i]->ataque = nivel * 10;
					Marco::marco->baraja->cartas[i]->defensa = nivel * 5;
					Marco::marco->baraja->cartas[i]->nivel = nivel;
					Marco::marco->baraja->cartas[i]->vida = 20 + nivel * 10;
				}
				mostrarBatalla(escena_buffer->Graphics);
				escena_buffer->Render(Juego::graphics);
			}
		}
	}

	void BatallaEscena::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (escena_activa && escena_dibujada) {

			Rectangle mouse_rectangle = Rectangle(e->X, e->Y, 1, 1);
			int x = mouse_rectangle.X;
			int y = mouse_rectangle.Y;
			
			Rectangle enemigos_activos_rectangle = Rectangle(192, 120, 576, 192);

			if (mouse_rectangle.IntersectsWith(enemigos_activos_rectangle)) {

				if ((x >= 336 && x < 408) || (x >= 552 && x < 624))
					return;
				
				int posicion = (x - 192) / 216;

				if (cartas_activas_enemigo->Count <= posicion) {
					Dialogo::pausarYMostarMensaje("No hay ningun enemigo en esta posicion!");
					return;
				}

				atacarEnemigoActivo(posicion);
			}

			Rectangle aliados_activos_rectangle = Rectangle(192, 360, 576, 192);

			if (mouse_rectangle.IntersectsWith(aliados_activos_rectangle)) {

				if ((x >= 336 && x < 408) || (x >= 552 && x < 624))
					return;

				int posicion = (x - 192) / 216;
				
				cartas_activas_marco[posicion]->modo = cartas_activas_marco[posicion]->modo == Ataque ? Defensa : Ataque;

				atacarAliadoActivo();
			}
		}

	}

	void BatallaEscena::terminarBatalla() {
		DesactivarEscena(this);
		cartas_activas_enemigo->Clear();
		cartas_activas_marco->Clear();
		dynamic_cast<Profesor ^>(enemigo)->ha_sido_derrotado = true;

		Mapa::mapa_actual = Mapa::obtenerMapa(pabellon_de_regreso);
		Marco::marco->Detener();
		Marco::marco->posicion->igualarA(this->posicion_de_regreso);
		Marco::marco->direccion = this->direccion_de_regreso;
		ActivarEscena(ESCENAS::campus);
	}

	void BatallaEscena::mostrarCartasActivas(Graphics^ graphics) {
		for (int i = 0; i < cartas_activas_marco->Count; i++) {
			Carta ^carta = cartas_activas_marco[i];

			carta->mostrarCarta(graphics, Rectangle(192 + i * 216, 360, CARTAS_WIDTH, CARTAS_HEIGHT));

			graphics->DrawString(
				"Ataque: " + carta->ataque,
				FUENTES::NIVEL,
				gcnew SolidBrush(Color::White),
				(float)192 + i * 216,
				(float)360,
				StringFormat::GenericTypographic
				);
			graphics->DrawString(
				"Vida: " + carta->vida,
				FUENTES::NIVEL,
				gcnew SolidBrush(Color::White),
				(float)192 + i * 216,
				(float)360 + TAMANIO_LETRAS + 6,
				StringFormat::GenericTypographic
				);

			String ^modo = carta->modo == Defensa ? "Defensa" : "Ataque";

			graphics->DrawString(
				"Modo: " + modo,
				FUENTES::NIVEL,
				gcnew SolidBrush(Color::White),
				(float)192 + i * 216,
				(float)360 + 2 * TAMANIO_LETRAS + 6,
				StringFormat::GenericTypographic
				);
		}

		for (int i = 0; i < cartas_activas_enemigo->Count; i++) {
			Carta ^carta = cartas_activas_enemigo[i];

			carta->mostrarCarta(graphics, Rectangle(192 + i * 216, 120, CARTAS_WIDTH, CARTAS_HEIGHT));

			graphics->DrawString(
				"Ataque: " + carta->ataque,
				FUENTES::NIVEL,
				gcnew SolidBrush(Color::White),
				(float)192 + i * 216,
				(float)120,
				StringFormat::GenericTypographic
				);
			graphics->DrawString(
				"Vida: " + carta->vida,
				FUENTES::NIVEL,
				gcnew SolidBrush(Color::White),
				(float)192 + i * 216,
				(float)120 + TAMANIO_LETRAS + 6,
				StringFormat::GenericTypographic
				);
			String ^modo = carta->modo == Defensa ? "Defensa" : "Ataque";

			graphics->DrawString(
				"Modo: " + modo,
				FUENTES::NIVEL,
				gcnew SolidBrush(Color::White),
				(float)192 + i * 216,
				(float)120 + 2 * TAMANIO_LETRAS + 6,
				StringFormat::GenericTypographic
				);
		}
	}

}