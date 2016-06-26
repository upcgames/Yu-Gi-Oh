#include <algorithm>
#include <iterator>

#include "Juego.h"
#include "Constantes.h"
#include "Imagenes.h"
#include "Escenas.h"
#include "Mapas.h"

namespace YuGiOh {

	//Definicion de las constantes
	const int MYFORM_WIDTH = 20;
	const int MYFORM_HEIGHT = 14;
	const int RESOLUCION_X = 48;
	const int RESOLUCION_Y = 48;
	const int MYFORM_SIZE_WIDTH = MYFORM_WIDTH * RESOLUCION_X;
	const int MYFORM_SIZE_HEIGHT = MYFORM_HEIGHT * RESOLUCION_Y;
	const float TAMANIO_LETRAS = 20.0f;
	const int VELOCIDAD_TIMER = 50;
	const int NUMERO_DE_CARTAS = 30;
	const int CARTAS_WIDTH = 144;
	const int CARTAS_HEIGHT = 192;
	const int CARTAS_WIDTH_LINE = 48;
	const int CARTAS_HEIGHT_LINE = 72;

	Terreno TERRENOS_COLISIONANTES[] = { Maceta, Agua, Roca, Lava, Tejado, Granito };

	Juego::Juego(void) {

		aleatorio = gcnew Random();

		inicializarComponentes();
		InitializeComponent();
		myform = this;

		graphics = this->CreateGraphics();
		context = BufferedGraphicsManager::Current;

		PROFESORES::profesor_actual = 1;

		//Inicializamos las escenas
		ESCENAS::introduccion = gcnew IntroduccionEscena();
		ESCENAS::campus = gcnew CampusEscena();
		ESCENAS::tienda = gcnew TiendaEscena();
		ESCENAS::batalla = gcnew BatallaEscena();

		//Empezar el juego
		Escena::EmpezarConEscena(ESCENAS::campus);
	}

	Juego::~Juego() {
		if (components)	{
			delete components;
		}
	}

	void Juego::InitializeComponent(void) {
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

	System::Void Juego::Juego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		;
	}

	System::Void Juego::Juego_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		;
	}

	void Juego::inicializarComponentes() {
		//Sprites
		IMAGENES::MARCO_SPRITE = Image::FromFile("Imagenes\\Personajes\\MARCO_SPRITE.png");
		IMAGENES::PROFESOR_SPRITE = Image::FromFile("Imagenes\\Personajes\\PROFESOR_SPRITE.png");
		IMAGENES::RECTOR_SPRITE = Image::FromFile("Imagenes\\Personajes\\RECTOR_SPRITE.png");
		IMAGENES::MARCO_SPRITE = Image::FromFile("Imagenes\\Personajes\\MARCO_SPRITE.png");
		IMAGENES::MONEDA_SPRITE = Image::FromFile("Imagenes\\Objetos\\Moneda_Sprite.png");

		IMAGENES::PUERTA = Image::FromFile("Imagenes\\Objetos\\PUERTA.png");

		//Objetos
		IMAGENES::LOCETA = Image::FromFile("Imagenes\\Objetos\\LOCETA.png");
		IMAGENES::AGUA = Image::FromFile("Imagenes\\Objetos\\AGUA.png");
		IMAGENES::ARENA = Image::FromFile("Imagenes\\Objetos\\ARENA.png");
		IMAGENES::GRANITO = Image::FromFile("Imagenes\\Objetos\\GRANITO.png");
		IMAGENES::HIELO = Image::FromFile("Imagenes\\Objetos\\HIELO.png");
		IMAGENES::LAVA = Image::FromFile("Imagenes\\Objetos\\LAVA.png");
		IMAGENES::LODO = Image::FromFile("Imagenes\\Objetos\\LODO.png");
		IMAGENES::MACETA = Image::FromFile("Imagenes\\Objetos\\MACETA.png");
		IMAGENES::PASTO = Image::FromFile("Imagenes\\Objetos\\PASTO.png");
		IMAGENES::ROCA = Image::FromFile("Imagenes\\Objetos\\ROCA.png");
		IMAGENES::TEJADO = Image::FromFile("Imagenes\\Objetos\\TEJADO.png");
		IMAGENES::TIERRA = Image::FromFile("Imagenes\\Objetos\\TIERRA.png");

		IMAGENES::CARTAS = gcnew List<Image ^>();

		for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
			IMAGENES::CARTAS->Add(Image::FromFile("Imagenes\\Cartas\\Carta_" + i + ".jpg"));
		}

		IMAGENES::INTRODUCCION_FONDO_1 = Image::FromFile("Imagenes\\Interfaces\\Introduccion_1.png");
		IMAGENES::INTRODUCCION_FONDO_2 = Image::FromFile("Imagenes\\Interfaces\\Introduccion_2.png");
		IMAGENES::FONDO_TIENDA_VENDER = Image::FromFile("Imagenes\\Interfaces\\Tienda_Vender.png");
		IMAGENES::FONDO_TIENDA_COMPRAR = Image::FromFile("Imagenes\\Interfaces\\Tienda_Comprar.png");
		IMAGENES::BATALLA = Image::FromFile("Imagenes\\Interfaces\\Batalla.png");

		CONTROLES::CAMBIO_ESCENA = Keys::E;
		CONTROLES::SALIR = Keys::Escape;
		CONTROLES::MOVER_ARRIBA_1 = Keys::W;
		CONTROLES::MOVER_ABAJO_1 = Keys::S;
		CONTROLES::MOVER_IZQUIERDA_1 = Keys::A;
		CONTROLES::MOVER_DERECHA_1 = Keys::D;
		CONTROLES::MOVER_ARRIBA_2 = Keys::Up;
		CONTROLES::MOVER_ABAJO_2 = Keys::Down;
		CONTROLES::MOVER_IZQUIERDA_2 = Keys::Left;
		CONTROLES::MOVER_DERECHA_2 = Keys::Right;
		CONTROLES::ACTIVAR_TRAMPA = Keys::Z;
	
		FUENTES::SUBTITULOS = gcnew System::Drawing::Font("ARIAL", TAMANIO_LETRAS - 2, FontStyle::Regular, GraphicsUnit::Point);
		FUENTES::DIALOGOS = gcnew System::Drawing::Font("Lucida Console", TAMANIO_LETRAS, FontStyle::Regular, GraphicsUnit::Point);
		FUENTES::DINERO = gcnew System::Drawing::Font("Lucida Console", TAMANIO_LETRAS - 8, FontStyle::Regular, GraphicsUnit::Point);
		FUENTES::NIVEL = gcnew System::Drawing::Font("Lucida Console", TAMANIO_LETRAS - 8, FontStyle::Regular, GraphicsUnit::Point);
	}

	void IMAGENES::mostarFondo(Image^ imagen, Graphics^ graphics) {
		graphics->DrawImage(imagen, Rectangle(0, 0, MYFORM_SIZE_WIDTH, MYFORM_SIZE_HEIGHT));
	}

	Direccion obtenerDireccionInvertida(Direccion direccion) {
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

	bool noHayONoExsite(Object^ objeto) {
		if (objeto == nullptr)
			return true;
		else
			return false;
	}

	bool Colisiona(Terreno terreno) {
		Terreno* indice_terreno = std::find(
			std::begin(TERRENOS_COLISIONANTES),
			std::end(TERRENOS_COLISIONANTES),
			terreno
		);

		bool impide = indice_terreno != std::end(TERRENOS_COLISIONANTES);

		return impide;
	}
}