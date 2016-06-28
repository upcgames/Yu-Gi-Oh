#include "Dialogo.h"
#include "Juego.h"
#include "string.h"

namespace YuGiOh {

	Dialogo::Dialogo(... array<String^>^ mensajes) {
		this->mensajes = mensajes;
		this->fuente = FUENTES::DIALOGOS;
		this->posicion_parrafo = 0;
		numero_de_oraciones = mensajes->Length;
		esperando_confirmacion = false;
		devolver_a_escena = true;
	}

	void Dialogo::mostarMensaje(... array<String^>^ mensajes) {

		if (dialogo == nullptr) {
			dialogo = gcnew Dialogo(mensajes);
			dialogo->pausar_anterior_escena = false;
			dialogo->empezarAEscribir();
		}
	}

	void Dialogo::pausarYMostarMensaje(... array<String^>^ mensajes) {

		if (dialogo == nullptr) {
			dialogo = gcnew Dialogo(mensajes);
			dialogo->pausar_anterior_escena = true;
			dialogo->empezarAEscribir();
		}
	}

	void Dialogo::empezarAEscribir() {

		this->escena_anterior = Escena::getEscenaActual();

		if (pausar_anterior_escena)
			Escena::DesactivarEscena(escena_anterior);
		
		escena_activa = true;
		onTimerTick = gcnew EventHandler(this, &Dialogo::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Dialogo::teclaDown);
		onMouseClick = gcnew MouseEventHandler(this, &Dialogo::mouseClick);

		Juego::myform->timer->Tick += this->onTimerTick;
		Juego::myform->KeyDown += this->onKeyDown;
		Juego::myform->MouseClick += this->onMouseClick;

	}

	void Dialogo::terminarDeEscribir() {
		Juego::myform->timer->Tick -= this->onTimerTick;
		Juego::myform->KeyDown -= this->onKeyDown;
		Juego::myform->MouseClick -= this->onMouseClick;
		
		if (Marco::marco != nullptr)
			Marco::marco->Detener();

		escena_anterior->escena_dibujada = true;

		dialogo = nullptr;

		if (callback != nullptr)
			callback();

		if (pausar_anterior_escena && devolver_a_escena)
			Escena::ActivarEscena(escena_anterior);

	}

	void Dialogo::escribirCaracter() {

		float ancho_de_caracter;

		if (posicion_oracion < numero_de_caracteres) {
			String^ caracter = oracion_actual->Substring(posicion_oracion, 1);

			if (caracter != " ")
				ancho_de_caracter = Juego::graphics->MeasureString(caracter, fuente, 0, StringFormat::GenericTypographic).Width;
			else
				ancho_de_caracter = TAMANIO_LETRAS / 2;

			escena_anterior->escena_buffer->Graphics->DrawString (
				caracter, fuente,
				gcnew SolidBrush(Color::Black),
				punto_de_comienzo, MYFORM_SIZE_HEIGHT * 7.5F / 9,
				StringFormat::GenericTypographic
			);
			punto_de_comienzo += ancho_de_caracter;
			posicion_oracion++;
		}
		else {
			esperando_confirmacion = true;
			posicion_oracion = 0;
			posicion_parrafo++;
		}
	}

	void Dialogo::timerTick(System::Object^  sender, System::EventArgs^  e) {
		if (posicion_parrafo < numero_de_oraciones) {

			if (esperando_confirmacion)
				return;

			if (posicion_oracion == 0) {
				escena_anterior->escena_buffer->Graphics->FillRectangle(gcnew SolidBrush(Color::White), 0, MYFORM_SIZE_HEIGHT * 2 / 3, MYFORM_SIZE_WIDTH, MYFORM_SIZE_HEIGHT / 3);

				oracion_actual = mensajes[posicion_parrafo];
				numero_de_caracteres = oracion_actual->Length;
				float ancho_de_texto = Juego::graphics->MeasureString(oracion_actual, this->fuente).Width;
				punto_de_comienzo = (MYFORM_SIZE_WIDTH - ancho_de_texto) / 2;
				punto_de_comienzo += TAMANIO_LETRAS;
			}

			escribirCaracter();
			escena_anterior->escena_buffer->Render(Juego::graphics);
		}
		else if (numero_de_oraciones != 1 || (numero_de_oraciones == 1 && !esperando_confirmacion))
			terminarDeEscribir();
	}

	void Dialogo::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (escena_activa && esperando_confirmacion) {
			esperando_confirmacion = false;
		}
	}

	void Dialogo::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (escena_activa && esperando_confirmacion) {
			esperando_confirmacion = false;
		}
	}

	int Dialogo::getNumeroDeParrafo() {
		if (dialogo->posicion_oracion == 0) {
			return dialogo->posicion_parrafo;
		}

		return -1;
	}
}