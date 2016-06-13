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
		modo_comprar = true;
		modo_vender = false;

	}

	Rectangle TiendaEscena::getBodyCartaNumero(int posicion_carta) {
		
		if (posicion_carta < 5) {
			return Rectangle(192 * posicion_carta + 24, 228, 144, 192);
		}
		else {
			return Rectangle(192 * (posicion_carta - 5) + 24, 456, 144, 192);
		}
	}

	void TiendaEscena::salirDeTienda() {
		DesactivarEscena(this);
		Juego::mapa_actual = Mapa::obtenerMapa(pabellon_de_regreso);
		Juego::marco->Detener();
		Juego::marco->posicion->IgualarA(this->posicion_de_regreso);
		Juego::marco->direccion = this->direccion_de_regreso;
		ActivarEscena(Juego::campus);
	}

	void TiendaEscena::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				if (modo_comprar)
					buffer->Graphics->DrawImage(Imagenes::FONDO_TIENDA_COMPRAR, Rectangle(0, 0, MYFORM_SIZE_WIDTH, MYFORM_SIZE_HEIGHT));
				if (modo_vender)
					buffer->Graphics->DrawImage(Imagenes::FONDO_TIENDA_VENDER, Rectangle(0, 0, MYFORM_SIZE_WIDTH, MYFORM_SIZE_HEIGHT));
				
				buffer->Render(Juego::graphics);
				dibujado = true;
			}
		}
	}

	void TiendaEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Escape)
			{
				salirDeTienda();
			}

		}
	}

	void TiendaEscena::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (activo && dibujado)
		{

			Rectangle mouse_rectangle = Rectangle(e->X, e->Y, 1, 1);

			for (int i = 0; i < 10; i++)
			{
				if (getBodyCartaNumero(i).IntersectsWith(mouse_rectangle)) {
					if (modo_vender)
						Juego::dialogo = gcnew Dialogo(gcnew array<String^>{" Vendiste la carta!!!"});
					if (modo_comprar)
						Juego::dialogo = gcnew Dialogo(gcnew array<String^>{" Compraste la carta!!!"});
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
				dibujado = false;
				return;
			}

		}
	}
}