#include "Dialogo.h"
#include "MyForm.h"
#include "string.h"
#include<vcclr.h>

namespace YuGiOh
{
	Dialogo::Dialogo(String^ mensaje) {
		this->mensaje = mensaje;
		this->fuente = gcnew Font("Lucida Console", TAMANIO_LETRAS, FontStyle::Regular, GraphicsUnit::Point);
		this->numero_de_caracteres = this->mensaje->Length;
		this->posicion = 0;

		float ancho_de_texto = MyForm::graphics->MeasureString(mensaje, this->fuente).Width;
		this->punto_de_comienzo = (MYFORM_SIZE_WIDTH - ancho_de_texto) / 2;

		buffer = MyForm::context->Allocate(MyForm::graphics, MyForm::myform->ClientRectangle);
		onTimerTick = gcnew EventHandler(this, &Dialogo::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Dialogo::teclaDown);

		this->EmpezarAEscribir();
	}

	void Dialogo::EmpezarAEscribir() {
		MyForm::myform->timer->Tick += this->onTimerTick;
	}
	void Dialogo::TerminarDeEscribir() {
		MyForm::myform->timer->Tick -= this->onTimerTick;
	}

	void Dialogo::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		String^ caracter;
		float ancho_de_caracter;
		float y = 403.0F;

		if (posicion < numero_de_caracteres) {
			caracter = mensaje->Substring(posicion, 1);

			if (caracter != " ")
				ancho_de_caracter = buffer->Graphics->MeasureString(caracter, fuente, 0, StringFormat::GenericTypographic).Width;
			else
				ancho_de_caracter = TAMANIO_LETRAS / 2;
			buffer->Graphics->DrawString(caracter, fuente, gcnew SolidBrush(Color::White), punto_de_comienzo, y, StringFormat::GenericTypographic);
			buffer->Render(MyForm::graphics);
			punto_de_comienzo += ancho_de_caracter;
			posicion++;
		}
		else {
			TerminarDeEscribir();
		}
			
	}

	void Dialogo::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		;
	}
}