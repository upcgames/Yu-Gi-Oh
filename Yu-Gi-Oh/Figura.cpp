#include "Figura.h"

namespace YuGiOh
{
	Posicion::Posicion(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool Posicion::operator ==(const Posicion^ p1, const Posicion^ p2) {
		if (p1->x == p2->x && p1->y == p2->y)
			return true;
		else
			return false;
	}

	void Posicion::IgualarA(Posicion^ p)
	{
		this->x = p->x;
		this->y = p->y;
	}

	void Posicion::IgualarA(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void Posicion::Aumentar(Direcciones direccion, int velocidad)
	{
		if (direccion == Direcciones::Arriba)
			y -= velocidad;
		else if (direccion == Direcciones::Abajo)
			y += velocidad;
		if (direccion == Direcciones::Izquierda)
			x -= velocidad;
		else if (direccion == Direcciones::Derecha)
			x += velocidad;
	}

	void Posicion::ToZero()
	{
		this->x = 0;
		this->y = 0;
	}

	Rectangle Posicion::getBody(int ancho, int alto)
	{
		return Rectangle(x, y, ancho, alto);
	}

	Posicion^ Posicion::getPosicionIncrementada(Direcciones direccion, int velocidad)
	{
		int auxiliar_x = x;
		int auxiliar_y = y;

		if (direccion == Direcciones::Arriba)
			auxiliar_y -= velocidad;
		else if (direccion == Direcciones::Abajo)
			auxiliar_y += velocidad;
		else if (direccion == Direcciones::Izquierda)
			auxiliar_x -= velocidad;
		else if (direccion == Direcciones::Derecha)
			auxiliar_x += velocidad;

		return gcnew Posicion(auxiliar_x, auxiliar_y);
	}

	Sprite::Sprite(Image^ imagen)
	{
		this->imagen = imagen;
	}

	Figura::Figura() { ; }
	Rectangle Figura::getBody()
	{
		return Rectangle(posicion->x, posicion->y, ancho, alto);
	}

	Rectangle Figura::getBody(int x, int y, int ancho, int alto)
	{
		return Rectangle(x, y, ancho, alto);
	}
}