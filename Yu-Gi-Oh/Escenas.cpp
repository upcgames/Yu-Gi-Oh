#include "Escenas.h"
#include "Juego.h"

namespace YuGiOh {

	Escena::Escena() {
		escena_buffer = Juego::context->Allocate(Juego::graphics, Juego::myform->ClientRectangle);
		escena_activa = false;
		escena_dibujada = false;
		contador_timer = 0;
	}

	Escena^ Escena::getEscenaActual() {
		if (ESCENAS::campus->escena_activa)
			return ESCENAS::campus;

		else if (ESCENAS::introduccion->escena_activa)
			return ESCENAS::introduccion;

		else if (ESCENAS::tienda->escena_activa)
			return ESCENAS::tienda;

		else if (ESCENAS::batalla->escena_activa)
			return ESCENAS::batalla;
		
		return nullptr;
	}

	void Escena::CambiarEscena(Escena ^escena) {
		Escena^ escena_actual = getEscenaActual();
		DesactivarEscena(escena_actual);

		ActivarEscena(escena);
	}

	void Escena::EmpezarConEscena(Escena ^escena) {
		ActivarEscena(escena);
	}


	void Escena::ActivarEscena(Escena ^escena) {
		escena->escena_activa = true;

		if (escena->onTimerTick != nullptr)
			Juego::myform->timer->Tick += escena->onTimerTick;
		if (escena->onKeyDown != nullptr)
			Juego::myform->KeyDown += escena->onKeyDown;
		if (escena->onKeyUp != nullptr)
			Juego::myform->KeyUp += escena->onKeyUp;
		if (escena->onMouseClick != nullptr)
			Juego::myform->MouseClick += escena->onMouseClick;
	}

	void Escena::DesactivarEscena(Escena ^escena) {
		escena->escena_activa = false;

		if (escena->onTimerTick != nullptr)
			Juego::myform->timer->Tick -= escena->onTimerTick;
		if (escena->onKeyDown != nullptr)
			Juego::myform->KeyDown -= escena->onKeyDown;
		if (escena->onKeyUp != nullptr)
			Juego::myform->KeyUp -= escena->onKeyUp;
		if (escena->onMouseClick != nullptr)
			Juego::myform->MouseClick -= escena->onMouseClick;

		escena->escena_dibujada = false;
	}

	Escena^ Escena::getEscenaTipo(TipoEscena tipo) {
		switch (tipo) {
		case Introduccion:
			return ESCENAS::introduccion;
			break;
		case Campus:
			return ESCENAS::campus;
			break;
		case Tienda:
			return ESCENAS::tienda;
			break;
		case Batalla:
			return ESCENAS::tienda;
			break;
		default:
			return nullptr;
		}
	}
}