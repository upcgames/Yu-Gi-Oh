#pragma once

using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System;

namespace YuGiOh
{
	public ref class Escena
	{
	public:
		int contador;
		bool activo;
		bool dibujado;
		BufferedGraphics^ buffer;
		KeyEventHandler^ onKeyDown;
		KeyEventHandler^ onKeyUp;
		MouseEventHandler^ onMouseClick;
		EventHandler^ onTimerTick;
		Escena();
		static void CambiarEscena(Escena^ escena);
		static void EmpezarConEscena(Escena^ escena);
		static void ActivarEscena(Escena^ escena);
		static void DesactivarEscena(Escena^ escena);
	};

	public ref class Campus : public Escena
	{
	public:
		int mapa;
		Campus();
		char cheatKey;
		void mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		void teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};
}