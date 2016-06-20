#pragma once
#include "Figuras.h"

namespace YuGiOh {

	public ref class Carta {
	public:
		Image^ imagen;
		TiposDeCarta tipo;
		int nivel;
		int ataque;
		int defensa;
		int vida;

		Carta();
	};

	public ref class Baraja {
	public:
		List<Carta ^> ^cartas;

		void mostrarTodaLaBaraja(Graphics^ graphics);

		Baraja();
		
		static Baraja ^crearBaraja(int nivel);
		static Posicion ^getCoordenadasCarta(int posicion_carta);
		static Rectangle getCuerpoDeCarta(int posicion_carta);
	};
}