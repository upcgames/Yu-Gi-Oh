#include "Figuras.h"

namespace YuGiOh {
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

	Posicion^ Posicion::toZero() {
		x = 0;
		y = 0;

		return this;
	}

	Posicion^ Posicion::getPieIzquierdo(Direccion direccion) {
		if (direccion == Arriba)
			return gcnew Posicion(x, y);
		else if (direccion == Abajo)
			return gcnew Posicion(x + RESOLUCION_X - 1, y + RESOLUCION_Y - 1);
		else if (direccion == Izquierda)
			return gcnew Posicion(x, y + RESOLUCION_Y - 1);
		else // if (direccion == Derecha)
			return gcnew Posicion(x +  RESOLUCION_X - 1, y);
	}

	Posicion^ Posicion::getPieDerecho(Direccion direccion) {
		if (direccion == Arriba)
			return gcnew Posicion(x + RESOLUCION_X - 1, y);
		else if (direccion == Abajo)
			return gcnew Posicion(x, y + RESOLUCION_Y - 1);
		else if (direccion == Izquierda)
			return gcnew Posicion(x, y);
		else // if (direccion == Derecha)
			return gcnew Posicion(x + RESOLUCION_X - 1, y + RESOLUCION_Y - 1);
	}

	bool Posicion::chocaCon(Rectangle cuerpo) {
		return cuerpo.Contains(x, y);
	}

	Posicion^ Posicion::toCoordenadas() {
		x /= RESOLUCION_X;
		y /= RESOLUCION_Y;

		return this;
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

	Rectangle Figura::getCuerpo() {
		return Rectangle(posicion->x, posicion->y, ancho, alto);
	}

	Rectangle Figura::crearCuerpo(int x, int y, int ancho, int alto) {
		return Rectangle(x, y, ancho, alto);
	}
}