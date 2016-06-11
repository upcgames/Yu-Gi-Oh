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

	void Escena::CambiarEscena(Escena^ escena)
	{
		if (MyForm::campus->activo)
			DesactivarEscena(MyForm::campus);

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
		if (escena->onTimerTick != nullptr)
			MyForm::myform->KeyDown += escena->onKeyDown;
		if (escena->onTimerTick != nullptr)
			MyForm::myform->KeyUp += escena->onKeyUp;
		if (escena->onMouseClick != nullptr)
			MyForm::myform->MouseClick += escena->onMouseClick;
	}

	void Escena::DesactivarEscena(Escena^ escena)
	{
		escena->activo = false;

		if (escena->onTimerTick != nullptr)
			MyForm::myform->timer->Tick -= escena->onTimerTick;
		if (escena->onTimerTick != nullptr)
			MyForm::myform->KeyDown -= escena->onKeyDown;
		if (escena->onTimerTick != nullptr)
			MyForm::myform->KeyUp -= escena->onKeyUp;
		if (escena->onMouseClick != nullptr)
			MyForm::myform->MouseClick -= escena->onMouseClick;

		escena->dibujado = false;
	}
}