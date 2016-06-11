#pragma once
#include "Constantes.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;

namespace YuGiOh
{
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		//aleatorio generara todos los numeros random en el futuro
		static Random^ aleatorio;
		//static Imagenes^ imagenes;
		//static Marco^ marco;

		//static MatrizObjetos^ objetos;
		//static ArrBombas^ bombas;
		//static ArrMalignos^ malignos;

		//static Introduccion^ introduccion;
		//static Inicio^ inicio;
		//static Instrucciones^ instrucciones;
		//static Juego^ juego;
		//static Pausa^ pausa;
		//static YouWin^ youWin;
		//static Congratulations^ congratulations;
		//static GameOver^ gameOver;
		//static Creditos^ creditos;

		//static Mapa1^ mapa1;
		//static Mapa2^ mapa2;
		//static Mapa3^ mapa3;
		//static Mapa4^ mapa4;
		//static Mapa5^ mapa5;
		bool se_cambiara_de_escena;

		//myform, graphics y context serviran para mostar los graficos.
		static MyForm^ myform;
		static Graphics^ graphics;
		static BufferedGraphicsContext^ context;
		static System::Windows::Forms::Timer^  timer;
		System::ComponentModel::IContainer^  components;

		//Funciones del MyForm
		MyForm(void);
		~MyForm();
		void InitializeComponent(void);
		private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);

	};
}