#include "Escena.h"
#include "Imagenes.h"
#include "MyForm.h"

namespace YuGiOh
{
	Introduccion::Introduccion()
	{
		onTimerTick = gcnew EventHandler(this, &Introduccion::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Introduccion::teclaDown);
	}

	void Introduccion::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			if (!dibujado)
			{
				buffer->Graphics->DrawImage(Imagenes::Introduccion, Rectangle(0, 0, 832, 577));
				buffer->Render(MyForm::graphics);
				dibujado = true;
			}
		}
	}

	void Introduccion::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				DesactivarEscena(this);
				ActivarEscena(MyForm::campus);
			}

		}
	}
}