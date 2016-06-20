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
		modo_comprar = true;
		modo_vender = false;
	}

	Rectangle TiendaEscena::getCuerpoDeCarta(int posicion_carta) {
		
		if (posicion_carta < 5) {
			return Rectangle(192 * posicion_carta + 24, 228, 144, 192);
		}
		else {
			return Rectangle(192 * (posicion_carta - 5) + 24, 456, 144, 192);
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

	void TiendaEscena::timerTick(System::Object^  sender, System::EventArgs^  e) {
		if (escena_activa) {
			if (!escena_dibujada) {
				if (modo_comprar)
					IMAGENES::mostarFondo(IMAGENES::FONDO_TIENDA_COMPRAR, escena_buffer->Graphics);
				if (modo_vender)
					IMAGENES::mostarFondo(IMAGENES::FONDO_TIENDA_VENDER, escena_buffer->Graphics);
				
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
		}
	}

	void TiendaEscena::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (escena_activa && escena_dibujada) {

			Rectangle mouse_rectangle = Rectangle(e->X, e->Y, 1, 1);

			for (int i = 0; i < 10; i++) {
				if (getCuerpoDeCarta(i).IntersectsWith(mouse_rectangle)) {
					if (modo_vender)
						Dialogo::pausarYMostarMensaje("Vendiste la carta!!!");
					if (modo_comprar)
						Dialogo::pausarYMostarMensaje("Compraste la carta!!!");
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