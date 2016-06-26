#pragma once
#include "Figuras.h"
#include "Cartas.h"
#include "Mapas.h"

namespace YuGiOh {

	public ref class Duelista : public Animado {
	public:
		Baraja ^baraja;
	};

	public ref class Profesor : public Duelista {
	public:
		int nivel;
		bool ha_sido_derrotado;

		Mapa ^mapa;

		void Mostrarlo(Graphics^ graphics);
		Profesor ^anteriorProfesor();
		Profesor(int nivel, Mapa ^mapa, Posicion ^posicion);
	};

	public ref class PROFESORES abstract sealed {
	public:
		static Profesor ^Profesor1;
		static Profesor ^Profesor2;
		static Profesor ^Profesor3;
		static Profesor ^Profesor4;
		static Profesor ^Profesor5;

		static void Mostrarlos(Graphics^ graphics);
	};
}