#include "Escena.h"
#include "Imagenes.h"
#include "MyForm.h"
#include "Dialogo.h"

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
				MyForm::dialogo = gcnew Dialogo("Bienvenido al mundo YuGiOh!!!");
				//MyForm::dialogo = gcnew Dialogo("Para moverte usa las flechas del teclado");
				//MyForm::dialogo = gcnew Dialogo("Estas en el Campus de la UPC!!");
				//MyForm::dialogo = gcnew Dialogo("Encontraras monedas a lo largo del mapa");
				//MyForm::dialogo = gcnew Dialogo("O tambmién puedes encontrar otras piezas...");
				//MyForm::dialogo = gcnew Dialogo("Tu objetivo es derrotar a tus 4 profesores");
				//MyForm::dialogo = gcnew Dialogo("Puedes intercambiar monedas por cartas");
				//MyForm::dialogo = gcnew Dialogo("Que empieze tu aventura!");


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