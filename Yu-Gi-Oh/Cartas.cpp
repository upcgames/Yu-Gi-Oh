#pragma once
#include "Cartas.h"
#include "Juego.h"

namespace YuGiOh {

	Carta::Carta() {
		;
	}

	Baraja::Baraja() {
		cartas = gcnew List<Carta ^>(10);
	}

	Baraja ^Baraja::crearBaraja(int nivel) {
		Baraja ^baraja = gcnew Baraja();
		Array ^tipo_de_cartas = Enum::GetValues(TiposDeCarta::typeid);

		for (int i = 0; i < 10; i++) {
			Carta ^carta = gcnew Carta();
			carta->ataque = nivel * 10;
			carta->defensa = nivel * 5;
			carta->nivel = nivel;
			carta->vida = 20 + nivel * 10;

			carta->tipo = (TiposDeCarta)Juego::aleatorio->Next(tipo_de_cartas->Length);
			baraja->cartas->Add(carta);
		}

		return baraja;
	}


	Posicion^ Baraja::getCoordenadasCarta(int posicion_carta) {
		if (posicion_carta < 5) {
			return gcnew Posicion(192 * posicion_carta + 24, 228);
		}
		else {
			return gcnew Posicion(192 * (posicion_carta - 5) + 24, 456);
		}
	}

	Rectangle Baraja::getCuerpoDeCarta(int posicion_carta) {

		Posicion ^posicion = getCoordenadasCarta(posicion_carta);

		return Rectangle(posicion->x, posicion->y, 144, 192);
	}

	void Baraja::mostrarTodaLaBaraja(Graphics^ graphics) {

		for (int i = 0; i < 10; i++) {
			Carta ^carta = cartas[i];
			
			if (carta != nullptr) {
				graphics->DrawImage(carta->imagen, getCuerpoDeCarta(i)));
			}

		}
	}
}