#pragma once
#include "Figuras.h"
#include "Cartas.h"
#include "Duelistas.h"

using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System;

namespace YuGiOh {

	public ref class Escena	{
	public:
		int contador_timer;
		bool escena_activa;
		bool escena_dibujada;
		
		BufferedGraphics ^escena_buffer;
		KeyEventHandler ^onKeyDown;
		KeyEventHandler ^onKeyUp;
		MouseEventHandler ^onMouseClick;
		EventHandler ^onTimerTick;
		
		Escena();
		
		void volverADibujar();

		static Escena ^getEscenaActual();
		static Escena ^getEscenaTipo(TipoEscena tipo);
		static void CambiarEscena(Escena ^escena);
		static void EmpezarConEscena(Escena ^escena);
		static void ActivarEscena(Escena ^escena);
		static void DesactivarEscena(Escena ^escena);
	};

	public ref class IntroduccionEscena : public Escena	{
	public:
		IntroduccionEscena();
		void timerTick(System::Object ^sender, System::EventArgs ^e);
		void teclaDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e);
	};

	public ref class CampusEscena : public Escena {
	public:
		int pabellon;
		CampusEscena();
		char cheatKey;
		void mouseClick(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		void timerTick(System::Object ^sender, System::EventArgs ^e);
		void teclaDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e);
		void teclaUp(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e);
	};

	public ref class EscenaDeMapa : public Escena {
	public:
		Direccion direccion_de_regreso;
		MapaTipo pabellon_de_regreso;
		TipoEscena escena_a_mostrar;
		Posicion ^posicion_de_regreso;
	};

	public ref class TiendaEscena : public EscenaDeMapa	{
	private:
		void mostrarTienda(Graphics ^graphics);

		void crearCartas();
		void venderCartas(int index);
		void comprarCartas(int index);
	public:
		TiendaEscena();
		Baraja ^baraja;

		bool modo_vender;
		bool modo_comprar;
		void salirDeTienda();
		void mouseClick(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		void timerTick(System::Object ^sender, System::EventArgs ^e);
		void teclaDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e);
	};

	public ref class BatallaEscena : public EscenaDeMapa {
	private:
		void mostrarBatalla(Graphics ^graphics);
		void mostrarCartasActivas(Graphics^ graphics);
	public:

		Duelista ^enemigo;
		List<Carta ^> ^cartas_activas_enemigo;
		List<Carta ^> ^cartas_activas_marco;

		int movimientos_restantes;
		bool turno_marco;
		bool turno_enemigo;

		void empezarBatalla();
		void terminarBatalla();

		void atacarEnemigoActivo(int posicion);
		void atacarAliadoActivo();

		void ingresarEnemigo();
		void ingresarAliado();

		BatallaEscena();
		void mouseClick(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		void timerTick(System::Object ^sender, System::EventArgs ^e);
		void teclaDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e);
	};

	public ref class ESCENAS abstract sealed {
	public:
		static IntroduccionEscena ^introduccion;
		static CampusEscena ^campus;
		static TiendaEscena ^tienda;
		static BatallaEscena ^batalla;
	};
}