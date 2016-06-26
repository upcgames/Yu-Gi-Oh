#pragma once
#include "Cartas.h"
#include "Juego.h"

namespace YuGiOh {

	Carta::Carta() {
		experiencia = 0;
	}

	int Carta::getValor() {
		return nivel * 5;
	}

	void Carta::mostrarCarta(Graphics ^graphics, Rectangle rectangle_destino) {
		graphics->DrawImage(imagen, rectangle_destino);
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
			carta->imagen = IMAGENES::CARTAS[Juego::aleatorio->Next(NUMERO_DE_CARTAS)];
			baraja->cartas->Add(carta);
		}

		return baraja;
	}


	Posicion^ Baraja::getCoordenadasCarta_10(int posicion_carta) {
		if (posicion_carta < 5) {
			return gcnew Posicion(192 * posicion_carta + 24, MYFORM_SIZE_HEIGHT - 60 - 2 * CARTAS_HEIGHT);
		}
		else {
			return gcnew Posicion(192 * (posicion_carta - 5) + 24, MYFORM_SIZE_HEIGHT - 24 - CARTAS_HEIGHT);
		}
	}

	Rectangle Baraja::getCuerpoDeCarta_10(int posicion_carta) {

		Posicion ^posicion = getCoordenadasCarta_10(posicion_carta);
		return getCuerpoDeCarta_10(posicion);
	}

	Rectangle Baraja::getCuerpoDeCarta_10(Posicion ^posicion) {
		return Rectangle(posicion->x, posicion->y, CARTAS_WIDTH, CARTAS_HEIGHT);
	}

	bool Baraja::estaVacia() {
		if (cartas->Count == 0)
			return true;
		return false;
	}

	bool Baraja::estaLlena() {
		if (cartas->Count == 10)
			return true;
		return false;
	}

	void Baraja::mostrarBaraja_10(Graphics ^graphics, bool mostrar_otros_atributos) {

		for (int i = 0; i < cartas->Count; i++) {
			Carta ^carta = cartas[i];
			
			Posicion ^posicion_carta = getCoordenadasCarta_10(i);
			carta->mostrarCarta(graphics, getCuerpoDeCarta_10(posicion_carta));

			if (mostrar_otros_atributos) {

				graphics->DrawString(
					"Nivel " + carta->nivel,
					FUENTES::NIVEL,
					gcnew SolidBrush(Color::White),
					(float)posicion_carta->x - 10,
					(float)posicion_carta->y - 14,
					StringFormat::GenericTypographic
				);

				graphics->DrawString(
					"S/ " + carta->getValor() + ".00",
					FUENTES::DINERO,
					gcnew SolidBrush(Color::White),
					(float)posicion_carta->x - 10,
					(float)posicion_carta->y + CARTAS_HEIGHT,
					StringFormat::GenericTypographic
				);
			}
		}
	}
}