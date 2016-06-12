#include "Escena.h"
#include "MyForm.h"

namespace YuGiOh
{
	Escena::Escena()
	{
		buffer = MyForm::context->Allocate(MyForm::graphics, MyForm::myform->ClientRectangle);
		activo = false;
		dibujado = false;
		contador = 0;
	}

	Escena^ Escena::getEscenaActual() {
		if (MyForm::campus->activo)
			return MyForm::campus;

		if (MyForm::introduccion->activo)
			return MyForm::introduccion;
		
		return nullptr;
	}

	void Escena::CambiarEscena(Escena^ escena)
	{
		Escena^ escena_actual = getEscenaActual();
		DesactivarEscena(escena_actual);

		ActivarEscena(escena);
	}

	void Escena::EmpezarConEscena(Escena^ escena)
	{
		ActivarEscena(escena);
	}


	void Escena::ActivarEscena(Escena^ escena)
	{
		escena->activo = true;

		if (escena->onTimerTick != nullptr)
			MyForm::myform->timer->Tick += escena->onTimerTick;
		if (escena->onKeyDown != nullptr)
			MyForm::myform->KeyDown += escena->onKeyDown;
		if (escena->onKeyUp != nullptr)
			MyForm::myform->KeyUp += escena->onKeyUp;
		if (escena->onMouseClick != nullptr)
			MyForm::myform->MouseClick += escena->onMouseClick;
	}

	void Escena::DesactivarEscena(Escena^ escena)
	{
		escena->activo = false;

		if (escena->onTimerTick != nullptr)
			MyForm::myform->timer->Tick -= escena->onTimerTick;
		if (escena->onKeyDown != nullptr)
			MyForm::myform->KeyDown -= escena->onKeyDown;
		if (escena->onKeyUp != nullptr)
			MyForm::myform->KeyUp -= escena->onKeyUp;
		if (escena->onMouseClick != nullptr)
			MyForm::myform->MouseClick -= escena->onMouseClick;

		escena->dibujado = false;
	}
}