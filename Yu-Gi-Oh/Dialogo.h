#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace YuGiOh
{
	ref class Dialogo
	{
	public:
		int posicion;
		int numero_de_caracteres;
		int punto_de_comienzo;
		String^ mensaje;
		Font^ fuente;
		BufferedGraphics^ buffer;
		KeyEventHandler^ onKeyDown;
		EventHandler^ onTimerTick;
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		void EmpezarAEscribir();
		void TerminarDeEscribir();
		Dialogo(String^ mensaje);
	};
}