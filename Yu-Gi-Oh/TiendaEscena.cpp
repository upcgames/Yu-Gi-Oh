#include "Escenas.h"
#include "Imagenes.h"
#include "Mapas.h"
#include "Juego.h"
#include "Dialogo.h"

namespace YuGiOh {

	TiendaEscena::TiendaEscena() {
		onTimerTick = gcnew EventHandler(this, &TiendaEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &TiendaEscena::teclaDown);
		onMouseClick = gcnew MouseEventHandler(this, &TiendaEscena::mouseClick);
		modo_comprar = false;
		modo_vender = true;
		crearCartas();
	}

	void TiendaEscena::crearCartas() {
		baraja = gcnew Baraja();
		
		Array ^tipo_de_cartas = Enum::GetValues(TiposDeCarta::typeid);

		for (int i = 0; i < 10; i++) {
			Carta ^carta = gcnew Carta();
			int nivel;

			if (i < 5)
				nivel = Juego::aleatorio->Next(1, 4);
			else
				nivel = 5;

			carta->ataque = nivel * 10;
			carta->defensa = nivel * 5;
			carta->nivel = nivel;
			carta->vida = 20 + nivel * 10;

			carta->tipo = (TiposDeCarta)Juego::aleatorio->Next(tipo_de_cartas->Length);
			carta->imagen = IMAGENES::CARTAS[Juego::aleatorio->Next(NUMERO_DE_CARTAS)];
			baraja->cartas->Add(carta);
		}
	}

	void TiendaEscena::salirDeTienda() {
		DesactivarEscena(this);
		Mapa::mapa_actual = Mapa::obtenerMapa(pabellon_de_regreso);
		Marco::marco->Detener();
		Marco::marco->posicion->igualarA(this->posicion_de_regreso);
		Marco::marco->direccion = this->direccion_de_regreso;
		ActivarEscena(ESCENAS::campus);
	}

	void TiendaEscena::mostrarTienda(Graphics ^graphics) {
		if (modo_comprar) {
			IMAGENES::mostarFondo(IMAGENES::FONDO_TIENDA_COMPRAR, graphics);
			baraja->mostrarBaraja_10(graphics, true);
		}
		else if (modo_vender) {
			IMAGENES::mostarFondo(IMAGENES::FONDO_TIENDA_VENDER, graphics);
			Marco::marco->baraja->mostrarBaraja_10(graphics, true);
		}
		graphics->DrawString(
			"Espacios Disponibles: " + (10 - Marco::marco->baraja->cartas->Count),
			FUENTES::SUBTITULOS,
			gcnew SolidBrush(Color::White),
			12,
			Baraja::getCoordenadasCarta_10(0)->y - 30 - TAMANIO_LETRAS,
			StringFormat::GenericTypographic
		);

		graphics->DrawString(
			"Dinero: S/ " + Marco::marco->dinero + ".00",
			FUENTES::SUBTITULOS,
			gcnew SolidBrush(Color::White),
			MYFORM_SIZE_WIDTH - 24 - TAMANIO_LETRAS * 9,
			Baraja::getCoordenadasCarta_10(0)->y - 30 - TAMANIO_LETRAS,
			StringFormat::GenericTypographic
		);
	}

	void TiendaEscena::venderCartas(int index) {
		if (Marco::marco->baraja->cartas->Count > index) {

			Marco::marco->dinero += Marco::marco->baraja->cartas[index]->getValor();
			Marco::marco->baraja->cartas->RemoveAt(index);

			mostrarTienda(escena_buffer->Graphics);
			escena_buffer->Render(Juego::graphics);
			
			Dialogo::pausarYMostarMensaje("Vendiste la carta!!!");
		}
		else {
			Dialogo::pausarYMostarMensaje("Este espacio esta vacío...");
		}
	}

	void TiendaEscena::comprarCartas(int index) {
		
		if (Marco::marco->baraja->estaLlena()) {
			Dialogo::pausarYMostarMensaje("Ya tienes tu inventario lleno");
			return;
		}

		int dinero_de_marco = Marco::marco->dinero;

		if (dinero_de_marco < baraja->cartas[index]->getValor()) {
			Dialogo::pausarYMostarMensaje("No tienes el dinero suficiente");
			return;
		}

		Marco::marco->dinero -= baraja->cartas[index]->getValor();
		Marco::marco->baraja->cartas->Add(this->baraja->cartas[index]);
		mostrarTienda(escena_buffer->Graphics);
		escena_buffer->Render(Juego::graphics);
		Dialogo::pausarYMostarMensaje("Compraste la carta!!!");
	}

	void TiendaEscena::timerTick(System::Object^  sender, System::EventArgs^  e) {
		if (escena_activa) {
			if (!escena_dibujada) {
				mostrarTienda(escena_buffer->Graphics);
				escena_buffer->Render(Juego::graphics);
				escena_dibujada = true;
			}
		}
	}

	void TiendaEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (escena_activa && escena_dibujada) {
			if (e->KeyCode == CONTROLES::SALIR) {
				salirDeTienda();
			}
			else if (e->KeyCode == CONTROLES::ACTIVAR_TRAMPA) {
				Marco::marco->dinero += 5;
				mostrarTienda(escena_buffer->Graphics);
				escena_buffer->Render(Juego::graphics);
			}
		}
	}

	void TiendaEscena::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (escena_activa && escena_dibujada) {

			Rectangle mouse_rectangle = Rectangle(e->X, e->Y, 1, 1);

			for (int index = 0; index < 10; index++) {
				if (Baraja::getCuerpoDeCarta_10(index).IntersectsWith(mouse_rectangle)) {
					if (modo_vender)
						venderCartas(index);
					else if (modo_comprar)
						comprarCartas(index);

					return;
				}
			}

			Rectangle salir_rectangle = Rectangle(828, 24, 108, 60);

			if (salir_rectangle.IntersectsWith(mouse_rectangle)) {
				salirDeTienda();
				return;
			}

			Rectangle switch_rectangle = Rectangle(12, 24, 108, 36);

		if (switch_rectangle.IntersectsWith(mouse_rectangle)) {
			modo_comprar = !modo_comprar;
			modo_vender = !modo_vender;
			escena_dibujada = false;
			return;
		}

		}
	}
}