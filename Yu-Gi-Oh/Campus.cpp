#include "Escena.h"
#include "Marco.h"
#include "Juego.h"

namespace YuGiOh
{
	Campus::Campus()
	{
		Juego::marco = gcnew Marco(gcnew Posicion(0, 0));
		onTimerTick = gcnew EventHandler(this, &Campus::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Campus::teclaDown);
		onKeyUp = gcnew KeyEventHandler(this, &Campus::teclaUp);
		onMouseClick = gcnew MouseEventHandler(this, &Campus::mouseClick);

		Juego::marco = gcnew Marco(gcnew Posicion(0, 0));
		Juego::plazuela_mapa = gcnew PlazuelaMapa();
		Juego::pabellonA_mapa = gcnew PabellonAMapa();
		Juego::pabellonB_mapa = gcnew PabellonBMapa();

		Juego::mapa_actual = Juego::plazuela_mapa;
	}

	void Campus::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			contador++;
			Juego::mapa_actual->mostrarTerreno();
			Juego::marco->MostrarMarco(buffer->Graphics);
			buffer->Render(Juego::graphics);
			dibujado = true;
		}
	}

	void Campus::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up)
			{
				Juego::marco->moviendose = true;
				Juego::marco->direccion = Arriba;
			}
			else if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down)
			{
				Juego::marco->moviendose = true;
				Juego::marco->direccion = Abajo;
			}
			else if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left)
			{
				Juego::marco->moviendose = true;
				Juego::marco->direccion = Izquierda;
			}
			else if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right)
			{
				Juego::marco->moviendose = true;
				Juego::marco->direccion = Derecha;
			}
			/*else if (e->KeyCode == Keys::N)
			{
			cheatKey = 'n';
			}*/
			else if (e->KeyCode == Keys::P)
			{
				DesactivarEscena(this);
				//ActivarEscena(Juego::pausa);
			}
		}
	}

	void Campus::teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if ((e->KeyCode == Keys::W || e->KeyCode == Keys::Up) && Juego::marco->direccion == Arriba)
			Juego::marco->Detener();
		else if ((e->KeyCode == Keys::S || e->KeyCode == Keys::Down) && Juego::marco->direccion == Abajo)
			Juego::marco->Detener();
		else if ((e->KeyCode == Keys::A || e->KeyCode == Keys::Left) && Juego::marco->direccion == Izquierda)
			Juego::marco->Detener();
		else if ((e->KeyCode == Keys::D || e->KeyCode == Keys::Right) && Juego::marco->direccion == Derecha)
			Juego::marco->Detener();


		//if (e->KeyCode == Keys::N && cheatKey == 'n')
		//cheatKey = 'z';
	}

	void Campus::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		;
	}
}

