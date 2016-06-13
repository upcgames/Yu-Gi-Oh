#include "Juego.h"
#include "Constantes.h"
#include "Imagenes.h"

namespace YuGiOh
{

	//Definicion de las constantes
	const int MYFORM_WIDTH = 20;
	const int MYFORM_HEIGHT = 14;
	const int RESOLUCION_X = 48;
	const int RESOLUCION_Y = 48;
	const int MYFORM_SIZE_WIDTH = MYFORM_WIDTH * RESOLUCION_X;
	const int MYFORM_SIZE_HEIGHT = MYFORM_HEIGHT * RESOLUCION_Y;
	const float TAMANIO_LETRAS = 24.0f;
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

	Juego::Juego(void)
	{
		InitializeComponent();
		myform = this;

		graphics = this->CreateGraphics();
		context = BufferedGraphicsManager::Current;
		aleatorio = gcnew Random();

		imagenes = gcnew Imagenes();

		//Inicializamos las escenas
		introduccion = gcnew IntroduccionEscena();
		campus = gcnew CampusEscena();
		tienda = gcnew TiendaEscena();

		//Empezar el juego
		Escena::EmpezarConEscena(introduccion);
	}

	Juego::~Juego()
	{
		if (components)
		{
			delete components;
		}
	}

	void Juego::InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego::typeid));
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
		this->DoubleBuffered = true;
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X, MYFORM_HEIGHT * RESOLUCION_Y);
		this->MaximumSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X + 16, MYFORM_HEIGHT * RESOLUCION_Y + 39);
		this->MinimumSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X + 16, MYFORM_HEIGHT * RESOLUCION_Y + 39);
		this->Name = L"YuGiOh!";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"YuGiOh!";
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
		this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyUp);
		this->ResumeLayout(false);

	}

	System::Void Juego::Juego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		;
	}

	System::Void Juego::Juego_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		;
	}

	Direccion Utils::obtenerDireccionInvertida(Direccion direccion) {
		switch (direccion)
		{
		case Arriba:
			return Abajo;
			break;
		case Abajo:
			return Arriba;
			break;
		case Izquierda:
			return Derecha;
			break;
		case Derecha:
			return Izquierda;
			break;
		default:
			return Abajo;
		}
	}
}