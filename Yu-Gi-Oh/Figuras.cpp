#include "Figuras.h"

namespace YuGiOh
{
	Posicion::Posicion(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Posicion::Posicion(int x, int y, bool multiplicar_automaticamente) {
		this->x = x * RESOLUCION_X;
		this->y = y * RESOLUCION_Y;
	}

	bool Posicion::operator ==(const Posicion^ p1, const Posicion^ p2) {
		if (p1->x == p2->x && p1->y == p2->y)
			return true;
		else
			return false;
	}

	void Posicion::igualarA(Posicion^ p) {
		this->x = p->x;
		this->y = p->y;
	}

	void Posicion::igualarA(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Posicion::Aumentar(Direccion direccion, int velocidad) {
		if (direccion == Direccion::Arriba)
			y -= velocidad;
		else if (direccion == Direccion::Abajo)
			y += velocidad;
		if (direccion == Direccion::Izquierda)
			x -= velocidad;
		else if (direccion == Direccion::Derecha)
			x += velocidad;
	}

	void Posicion::toZero() {
		this->x = 0;
		this->y = 0;
	}

	Rectangle Posicion::getCuerpo(int ancho, int alto) {
		return Rectangle(x, y, ancho, alto);
	}

	Posicion^ Posicion::getSiguientePosicion(Direccion direccion, int velocidad) {
		int auxiliar_x = x;
		int auxiliar_y = y;

		if (direccion == Direccion::Arriba)
			auxiliar_y -= velocidad;
		else if (direccion == Direccion::Abajo)
			auxiliar_y += velocidad;
		else if (direccion == Direccion::Izquierda)
			auxiliar_x -= velocidad;
		else if (direccion == Direccion::Derecha)
			auxiliar_x += velocidad;

		return gcnew Posicion(auxiliar_x, auxiliar_y);
	}

	Sprite::Sprite(Image^ imagen) {
		this->imagen = imagen;
	}

	void Sprite::siguienteIndice() {
		indice++;

		if (se_para_en_el_medio && indice == numero_de_columnas)
			indice += 2;

		else if (indice == numero_de_columnas * 2)
			indice = 0;
	}

	void Sprite::cambiarSubindice(int subindice) {
		this->subindice = subindice;
	}

	Figura::Figura() { ; }

	Rectangle Figura::getCuerpo()
	{
		return Rectangle(posicion->x, posicion->y, ancho, alto);
	}

	Rectangle Figura::getCuerpo(int x, int y, int ancho, int alto)
	{
		return Rectangle(x, y, ancho, alto);
	}
}