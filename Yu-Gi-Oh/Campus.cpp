#include "Escena.h"
#include "Marco.h"
#include "MyForm.h"

namespace YuGiOh
{
	Campus::Campus()
	{
		MyForm::marco = gcnew Marco(gcnew Posicion(0, 0));
		onTimerTick = gcnew EventHandler(this, &Campus::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Campus::teclaDown);
		onKeyUp = gcnew KeyEventHandler(this, &Campus::teclaUp);
		onMouseClick = gcnew MouseEventHandler(this, &Campus::mouseClick);

		cheatKey = 'z';

		MyForm::marco = gcnew Marco(gcnew Posicion(0, 0));
	}

	void Campus::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			contador++;
			//Mapa::MostrarMapa(buffer->Graphics);
			buffer->Graphics->Clear(Color::Black);
			MyForm::marco->MostrarMarco(buffer->Graphics);
			buffer->Render(MyForm::graphics);
			dibujado = true;
		}
	}

	void Campus::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up)
			{
				MyForm::marco->moviendose = true;
				MyForm::marco->direccion = Arriba;
			}
			else if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down)
			{
				MyForm::marco->moviendose = true;
				MyForm::marco->direccion = Abajo;
			}
			else if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left)
			{
				MyForm::marco->moviendose = true;
				MyForm::marco->direccion = Izquierda;
			}
			else if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right)
			{
				MyForm::marco->moviendose = true;
				MyForm::marco->direccion = Derecha;
			}
			/*else if (e->KeyCode == Keys::N)
			{
			cheatKey = 'n';
			}*/
			else if (e->KeyCode == Keys::P)
			{
				DesactivarEscena(this);
				//ActivarEscena(MyForm::pausa);
			}
		}
	}

	void Campus::teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if ((e->KeyCode == Keys::W || e->KeyCode == Keys::Up) && MyForm::marco->direccion == Arriba)
			MyForm::marco->Detener();
		else if ((e->KeyCode == Keys::S || e->KeyCode == Keys::Down) && MyForm::marco->direccion == Abajo)
			MyForm::marco->Detener();
		else if ((e->KeyCode == Keys::A || e->KeyCode == Keys::Left) && MyForm::marco->direccion == Izquierda)
			MyForm::marco->Detener();
		else if ((e->KeyCode == Keys::D || e->KeyCode == Keys::Right) && MyForm::marco->direccion == Derecha)
			MyForm::marco->Detener();


		//if (e->KeyCode == Keys::N && cheatKey == 'n')
		//cheatKey = 'z';
	}

	void Campus::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		;
	}
}

