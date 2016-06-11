#include "Marco.h"
#include "Imagenes.h"

namespace YuGiOh
{
	Marco::Marco(Posicion^ p)
	{
		sprite = gcnew Sprite(Imagenes::MARCO_SPRITE);
		sprite->indice = 0;
		sprite->ancho = 24;
		sprite->alto = 24;
		sprite->numero_de_columnas = 8;
		sprite->numero_de_filas = 6;

		direccion = Direcciones::Abajo;
		velocidad = 8;
		posicion = p;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
		moviendose = false;
	}

	void Marco::MostrarMarco(Graphics^ graphics)
	{
		if (direccion == Arriba)
			sprite->subindice = 0;
		else if (direccion == Abajo)
			sprite->subindice = 1;
		else if (direccion == Izquierda)
			sprite->subindice = 2;
		else if (direccion == Derecha)
			sprite->subindice = 3;

		if (moviendose)
			Avanzar(direccion);

		graphics->DrawImage(sprite->imagen, Rectangle(posicion->x, posicion->y, ancho, alto), Rectangle(sprite->indice / 2 * sprite->ancho, sprite->subindice * sprite->alto, sprite->ancho, sprite->alto), GraphicsUnit::Pixel);
	}

	void Marco::Avanzar(Direcciones pDireccion)
	{
		direccion = pDireccion;

		sprite->indice++;

		if (sprite->indice == 3)
			sprite->indice = 4;

		else if (sprite->indice == 6)
			sprite->indice = 0;

		posicion->Aumentar(direccion, velocidad);
	}

	void Marco::Detener()
	{
		sprite->indice = 0;
		moviendose = false;
	}
}