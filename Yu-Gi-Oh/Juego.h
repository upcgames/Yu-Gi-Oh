#pragma once
#include "Constantes.h"
#include "Imagenes.h"
#include "Marco.h"
#include "Escenas.h"
#include "Dialogo.h"
#include "Objetos.h"

using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;

namespace YuGiOh {
	public ref class Juego : public System::Windows::Forms::Form {
	public:
		//aleatorio generara todos los numeros random en el futuro
		static Random^ aleatorio;

		static array<Objeto^>^ objetos;

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
		void inicializarComponentes();
		private: System::Void Juego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		private: System::Void Juego_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};
}