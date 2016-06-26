#include "Escenas.h"
#include "Marco.h"
#include "Juego.h"
#include "Mapas.h"

namespace YuGiOh
{
	CampusEscena::CampusEscena()
	{
		onTimerTick = gcnew EventHandler(this, &CampusEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &CampusEscena::teclaDown);
		onKeyUp = gcnew KeyEventHandler(this, &CampusEscena::teclaUp);
		onMouseClick = gcnew MouseEventHandler(this, &CampusEscena::mouseClick);

		Mapas::plazuela_mapa = gcnew PlazuelaMapa();
		Mapas::pabellonA_mapa = gcnew PabellonAMapa();
		Mapas::pabellonB_mapa = gcnew PabellonBMapa();
		Mapas::sotano_mapa = gcnew SotanoMapa();
		Mapas::jardin_mapa = gcnew JardinMapa();
		Mapa::mapa_actual = Mapas::plazuela_mapa;

		Marco::marco = gcnew Marco(gcnew Posicion(9, 9, true));
		PROFESORES::Profesor1 = gcnew Profesor(1, Mapas::plazuela_mapa, gcnew Posicion(16, 3, true));
		PROFESORES::Profesor2 = gcnew Profesor(3, Mapas::pabellonB_mapa, gcnew Posicion(16, 11, true));
		PROFESORES::Profesor3 = gcnew Profesor(5, Mapas::sotano_mapa, gcnew Posicion(16, 6, true));
		PROFESORES::Profesor4 = gcnew Profesor(7, Mapas::jardin_mapa, gcnew Posicion(11, 4, true));
		PROFESORES::Profesor5 = gcnew Profesor(10, Mapas::pabellonA_mapa, gcnew Posicion(2, 10, true));
	}

	void CampusEscena::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (escena_activa)
		{
			contador_timer++;

			if (Marco::marco->debe_avanzar)
				Marco::marco->intentarAvanzar(Marco::marco->direccion);

			Mapa::mapa_actual->mostrarTerreno(escena_buffer->Graphics);
			Mapa::mapa_actual->mostrarObjetos(escena_buffer->Graphics);
			PROFESORES::Mostrarlos(escena_buffer->Graphics);
			Marco::mostrarloEn(escena_buffer->Graphics);

			escena_buffer->Render(Juego::graphics);
			escena_dibujada = true;
		}
	}

	void CampusEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (escena_activa && escena_dibujada)
		{
			if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up)
			{
				Marco::marco->debe_avanzar = true;
				Marco::marco->direccion = Arriba;
			}
			else if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down)
			{
				Marco::marco->debe_avanzar = true;
				Marco::marco->direccion = Abajo;
			}
			else if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left)
			{
				Marco::marco->debe_avanzar = true;
				Marco::marco->direccion = Izquierda;
			}
			else if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right)
			{
				Marco::marco->debe_avanzar = true;
				Marco::marco->direccion = Derecha;
			}
		}
	}

	void CampusEscena::teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if ((e->KeyCode == CONTROLES::MOVER_ARRIBA_1 || e->KeyCode == CONTROLES::MOVER_ARRIBA_2) && Marco::marco->direccion == Arriba)
			Marco::marco->Detener();
		else if ((e->KeyCode == CONTROLES::MOVER_ABAJO_1 || e->KeyCode == CONTROLES::MOVER_ABAJO_2) && Marco::marco->direccion == Abajo)
			Marco::marco->Detener();
		else if ((e->KeyCode == CONTROLES::MOVER_IZQUIERDA_1 || e->KeyCode == CONTROLES::MOVER_IZQUIERDA_2) && Marco::marco->direccion == Izquierda)
			Marco::marco->Detener();
		else if ((e->KeyCode == CONTROLES::MOVER_DERECHA_1 || e->KeyCode == CONTROLES::MOVER_DERECHA_2) && Marco::marco->direccion == Derecha)
			Marco::marco->Detener();
	}

	void CampusEscena::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		;
	}
}

