#pragma once
#include "Escenas.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace YuGiOh {

	public ref class Dialogo : public Escena {
	private:
		array<String ^> ^mensajes;
		String ^oracion_actual;
		Font ^fuente;

		int posicion_oracion;
		bool esperando_confirmacion;
		bool pausar_anterior_escena;

		float punto_de_comienzo;
		int numero_de_caracteres;
		int numero_de_oraciones;
	public:
		Escena ^escena_anterior;
		int posicion_parrafo;
		bool devolver_a_escena;
		Action ^callback;

		static Dialogo ^dialogo;
		
		void timerTick(System::Object  ^sender, System::EventArgs ^e);
		void teclaDown(System::Object  ^sender, System::Windows::Forms::KeyEventArgs ^e);
		void mouseClick(System::Object  ^sender, System::Windows::Forms::MouseEventArgs ^e);
		
		void empezarAEscribir();
		void escribirCaracter();
		void terminarDeEscribir();
		
		Dialogo(... array<String ^> ^mensajes);

		static void mostarMensaje(... array<String ^> ^mensajes);
		static void pausarYMostarMensaje(... array<String ^> ^mensajes);
		static int getNumeroDeParrafo();
	};
}