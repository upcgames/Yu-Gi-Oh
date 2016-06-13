#pragma once
#include "Constantes.h"

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
		static Escena^ getEscenaActual();
		static Escena^ getEscenaTipo(TipoEscena tipo);
		static void CambiarEscena(Escena^ escena);
		static void EmpezarConEscena(Escena^ escena);
		static void ActivarEscena(Escena^ escena);
		static void DesactivarEscena(Escena^ escena);
	};

	public ref class IntroduccionEscena : public Escena
	{
	public:
		IntroduccionEscena();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class CampusEscena : public Escena
	{
	public:
		int pabellon;
		CampusEscena();
		char cheatKey;
		void mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		void teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class TiendaEscena : public Escena
	{
	public:
		TiendaEscena();
		char cheatKey;
		void mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};
}