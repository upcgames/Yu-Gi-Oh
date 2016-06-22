#pragma once
#include "Figuras.h"

namespace YuGiOh {

	public ref class Carta {
	public:
		Image^ imagen;
		TiposDeCarta tipo;
		int experiencia;
		int nivel;
		int ataque;
		int defensa;
		int vida;

		int getValor();
		void mostrarCarta(Graphics ^graphics, Rectangle rectangle_destino);

		Carta();
	};

	public ref class Baraja {
	public:
		List<Carta ^> ^cartas;

		void mostrarBaraja_10(Graphics^ graphics, bool mostrar_otros_atributos);

		Baraja();
		
		static Baraja ^crearBaraja(int nivel);
		static Posicion ^getCoordenadasCarta_10(int posicion_carta);
		static Rectangle getCuerpoDeCarta_10(int posicion_carta);
		static Rectangle getCuerpoDeCarta_10(Posicion ^posicion);
	};
}