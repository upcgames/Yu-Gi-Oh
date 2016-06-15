#pragma once
#include "Constantes.h"
#include "Figuras.h"

using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System;

namespace YuGiOh {
	public ref class Escena	{
	public:
		int contador_timer;
		bool escena_activa;
		bool escena_dibujada;
		BufferedGraphics^ escena_buffer;
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

	public ref class IntroduccionEscena : public Escena	{
	public:
		IntroduccionEscena();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class CampusEscena : public Escena {
	public:
		int pabellon;
		CampusEscena();
		char cheatKey;
		void mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		void teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class EscenaDeMapa : public Escena {
	public:
		Direccion direccion_de_regreso;
		Pabellon pabellon_de_regreso;
		TipoEscena escena_a_mostrar;
		Posicion^ posicion_de_regreso;
	};

	public ref class TiendaEscena : public EscenaDeMapa	{
	public:
		TiendaEscena();
		bool modo_vender;
		bool modo_comprar;
		static Rectangle getBodyCartaNumero(int posicion_carta);
		void salirDeTienda();
		void mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class Escenas abstract sealed {
	public:
		static IntroduccionEscena^ introduccion;
		static CampusEscena^ campus;
		static TiendaEscena^ tienda;
	};
}