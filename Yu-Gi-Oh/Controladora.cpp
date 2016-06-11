#include "MyForm.h"
#include "Constantes.h"
#include "Imagenes.h"

namespace YuGiOh
{

	//Definicion de las constantes
	const int MYFORM_WIDTH = 15;
	const int MYFORM_HEIGHT = 9;
	const int RESOLUCION_X = 56;
	const int RESOLUCION_Y = 56;
	const int VELOCIDAD_TIMER = 50;
	
	//Controles
	const Keys CONTROLES_CAMBIO_ESCENA = Keys::E;
	
	const Keys CONTROLES_MOVER_ARRIBA_1 = Keys::W;
	const Keys CONTROLES_MOVER_ABAJO_1 = Keys::S;
	const Keys CONTROLES_MOVER_IZQUIERDA_1 = Keys::A;
	const Keys CONTROLES_MOVER_DERECHA_1 = Keys::D;

	const Keys CONTROLES_MOVER_ARRIBA_2 = Keys::Up;
	const Keys CONTROLES_MOVER_ABAJO_2 = Keys::Down;
	const Keys CONTROLES_MOVER_IZQUIERDA_2 = Keys::Left;
	const Keys CONTROLES_MOVER_DERECHA_2 = Keys::Right;

	MyForm::MyForm(void)
	{
		InitializeComponent();
		myform = this;

		graphics = this->CreateGraphics();
		context = BufferedGraphicsManager::Current;
		aleatorio = gcnew Random();

		imagenes = gcnew Imagenes();

		//Inicializamos las escenas
		//menu = gcnew Menu();
		introduccion = gcnew Introduccion();
		campus = gcnew Campus();
		//instrucciones = gcnew Instrucciones();
		//pausa = gcnew Pausa();
		//youWin = gcnew YouWin();
		//congratulations = gcnew Congratulations();
		//gameOver = gcnew GameOver();
		//creditos = gcnew Creditos();

		se_cambiara_de_escena = false;

		//Empezar el juego
		Escena::EmpezarConEscena(introduccion);
		//Nivel::PasarANivel(1);
	}

	MyForm::~MyForm()
	{
		if (components)
		{
			delete components;
		}
	}

	void MyForm::InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		this->timer = (gcnew System::Windows::Forms::Timer(this->components));
		this->SuspendLayout();
		// 
		// timer
		// 
		this->timer->Enabled = true;
		this->timer->Interval = VELOCIDAD_TIMER;
		// 
		// Myform
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X, MYFORM_HEIGHT * RESOLUCION_Y);
		this->MaximumSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X + 16, MYFORM_HEIGHT * RESOLUCION_Y + 39);
		this->MinimumSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X + 16, MYFORM_HEIGHT * RESOLUCION_Y + 39);
		this->Name = L"YuGiOh!";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"YuGiOh!";
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
		this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
		this->ResumeLayout(false);

	}

	System::Void MyForm::MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyCode == CONTROLES_CAMBIO_ESCENA)
			se_cambiara_de_escena = true;
		//else if (e->KeyCode == Keys::D1)
		//{
		//	if (se_cambiara_de_escena)
		//		Escena::CambiarEscena(introduccion);
		//}
		//else if (e->KeyCode == Keys::D2)
		//{
		//	if (se_cambiara_de_escena)
		//		Escena::CambiarEscena(inicio);
		//}
		//else if (e->KeyCode == Keys::D3)
		//{
		//	if (se_cambiara_de_escena)
		//		Escena::CambiarEscena(instrucciones);
		//}
		//else if (e->KeyCode == Keys::D4)
		//{
		//	if (se_cambiara_de_escena)
		//		Escena::CambiarEscena(juego);
		//}
		//else if (e->KeyCode == Keys::D5)
		//{
		//	if (se_cambiara_de_escena)
		//		Escena::CambiarEscena(pausa);
		//}
		//else if (e->KeyCode == Keys::D6)
		//{
		//	if (se_cambiara_de_escena)
		//		Escena::CambiarEscena(youWin);
		//}
		//else if (e->KeyCode == Keys::D7)
		//{
		//	if (se_cambiara_de_escena)
		//		Escena::CambiarEscena(gameOver);
		//}
		//else if (e->KeyCode == Keys::D8)
		//{
		//	if (se_cambiara_de_escena)
		//		Escena::CambiarEscena(congratulations);
		//}
		//else if (e->KeyCode == Keys::D9)
		//{
		//	if (se_cambiara_de_escena)
		//		Escena::CambiarEscena(creditos);
		//}
	}

	System::Void MyForm::MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyCode == CONTROLES_CAMBIO_ESCENA && this->se_cambiara_de_escena)
			se_cambiara_de_escena = false;
	}
}