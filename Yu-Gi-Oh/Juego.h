#pragma once
#include "Constantes.h"
#include "Imagenes.h"
#include "Marco.h"
#include "Escena.h"
#include "Dialogo.h"
#include "Objeto.h"
#include "Mapa.h"

using namespace System;
using namespace System::Drawing;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;

namespace YuGiOh
{
	public ref class Juego : public System::Windows::Forms::Form
	{
	public:
		//aleatorio generara todos los numeros random en el futuro
		static Random^ aleatorio;
		static Imagenes^ imagenes;
		static Dialogo^ dialogo;
		
		static Marco^ marco;
		
		//static ArrBombas^ bombas;
		//static ArrMalignos^ malignos;

		//static Menu^ menu;
		//static Instrucciones^ instrucciones;
		static Introduccion^ introduccion;
		static Campus^ campus;
		//static Pausa^ pausa;
		//static YouWin^ youWin;
		//static Congratulations^ congratulations;
		//static GameOver^ gameOver;
		//static Creditos^ creditos;

		static Mapa^ mapa_actual;
		static array<Objeto^>^ objetos;

		static PlazuelaMapa^ plazuela_mapa;
		static PabellonAMapa^ pabellonA_mapa;
		static PabellonBMapa^ pabellonB_mapa;
		//static Mapa2^ mapa2;
		//static Mapa3^ mapa3;
		//static Mapa4^ mapa4;
		//static Mapa5^ mapa5;
		bool se_cambiara_de_escena;

		//myform, graphics y context serviran para mostar los graficos.
		static Juego^ myform;
		static Graphics^ graphics;
		static BufferedGraphicsContext^ context;
		static System::Windows::Forms::Timer^  timer;
		System::ComponentModel::IContainer^  components;

		//Funciones del Juego
		Juego(void);
		~Juego();
		void InitializeComponent(void);
		private: System::Void Juego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		private: System::Void Juego_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);

	};

	public ref class Utils
	{
	public:
		static Direccion obtenerDireccionInvertida(Direccion direccion);
	};
}