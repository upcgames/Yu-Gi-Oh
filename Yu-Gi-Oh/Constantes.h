#pragma once
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace YuGiOh
{
	//Dimensiones del Windows Form(cuantas coordenadas tendra), en unidades;
	extern const int MYFORM_WIDTH;
	extern const int MYFORM_HEIGHT;

	//Dimensiones de cada coordenada(el personaje), en pixeles
	extern const int RESOLUCION_X;
	extern const int RESOLUCION_Y;

	extern const int MYFORM_SIZE_WIDTH;
	extern const int MYFORM_SIZE_HEIGHT;

	extern const float TAMANIO_LETRAS;

	//Velocidad con la que Marco corre en pixeles
	extern const int VELOCIDAD_TIMER;
	
	//Controles
	extern const Keys CONTROLES_CAMBIO_ESCENA;
	extern const Keys CONTROLES_MOVER_ARRIBA_1;
	extern const Keys CONTROLES_MOVER_ABAJO_1;
	extern const Keys CONTROLES_MOVER_IZQUIERDA_1;
	extern const Keys CONTROLES_MOVER_DERECHA_1;
	extern const Keys CONTROLES_MOVER_ARRIBA_2;
	extern const Keys CONTROLES_MOVER_ABAJO_2;
	extern const Keys CONTROLES_MOVER_IZQUIERDA_2;
	extern const Keys CONTROLES_MOVER_DERECHA_2;

	//Enums
	public enum Direcciones { Arriba, Abajo, Izquierda, Derecha };
	public enum TiposDeCartaS { Criticos, Basicos, Extra, Electivos };
	public enum Pertenencia { Tienda, DeMarco, DeProfesor };
	public enum ModoBatalla { Defensa, Ataque };
	public enum Objetos { Piso__, Puerta, Moneda, Pared_ };
}