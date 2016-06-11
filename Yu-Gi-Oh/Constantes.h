#pragma once
using namespace System::Windows::Forms;

namespace YuGiOh {
	//Dimensiones del Windows Form(cuantas coordenadas tendra), en unidades;
	extern const int MYFORM_WIDTH;
	extern const int MYFORM_HEIGHT;

	//Dimensiones de cada coordenada(el personaje), en pixeles
	extern const int RESOLUCION_X;
	extern const int RESOLUCION_Y;

	//Velocidad con la que Marco corre en pixeles
	extern const int VELOCIDAD_TIMER;
	
	//Controles
	extern const Keys CONTROLES_CAMBIO_ESCENA;

}