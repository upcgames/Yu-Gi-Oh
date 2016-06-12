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
				MyForm::dialogo = gcnew Dialogo(gcnew array<String^> {
					"Bienvenido al mundo YuGiOh!!!",
					"Para moverte usa las flechas del teclado",
					"Estas en el Campus de la UPC!!",
					"Encontrarás monedas a lo largo del mapa",
					"O también puedes encontrar otras piezas..",
					"Tu objetivo es derrotar a 4 profesores",
					"Puedes intercambiar monedas por cartas",
					"Que empieze tu aventura!"
				});
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