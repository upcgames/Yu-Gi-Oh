#include "Marco.h"
#include "Imagenes.h"
#include "Mapas.h"
#include "Objetos.h"

namespace YuGiOh {

	Marco::Marco(Posicion ^p) {
		sprite = gcnew Sprite(IMAGENES::MARCO_SPRITE);
		sprite->indice = 0;
		sprite->ancho = 24;
		sprite->alto = 24;
		sprite->numero_de_columnas = 8;
		sprite->numero_de_filas = 6;

		direccion = Direccion::Abajo;
		velocidad = 8;
		posicion = p;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
		debe_avanzar = false;
	}

	void Marco::mostrarloEn(Graphics ^graphics)	{
		Marco ^marco = Marco::marco;
		Sprite ^marco_sprite = marco->sprite;

		marco_sprite->cambiarSubindice((int)marco->direccion);

		graphics->DrawImage(
			marco_sprite->imagen,
			Rectangle(
				marco->posicion->x,
				marco->posicion->y,
				marco->ancho, 
				marco->alto
			),
			Rectangle(
				marco_sprite->indice * marco_sprite->ancho,
				marco_sprite->subindice * marco_sprite->alto,
				marco_sprite->ancho - 1, // Normalemnte no se deberia quitar uno
				marco_sprite->alto - 1 // Pero, se pinta un pixel mas
			),
			GraphicsUnit::Pixel
		);
	}

	void Marco::intentarAvanzar(Direccion direccion) {

		sprite->siguienteIndice();
		Posicion ^siguiente_posicion = posicion->getSiguientePosicion(direccion, velocidad);
		
		if (marco->colisionaConMapaActual(siguiente_posicion, direccion))
			return; // No avanza 

		Objeto ^siguiente_bloque = Mapa::mapa_actual->getObjeto(siguiente_posicion);

		if (noHayONoExsite(siguiente_bloque)) {
			marco->avanzarUnPaso();
		}
		else {
			//Se choca con un objeto y se interactua con este
			Objeto ^objeto_dinamico = siguiente_bloque;
			bool debe_dar_un_paso_mas = objeto_dinamico->interactuarConMarco();
			
			//Algunos objetos detienen a marco por completo y otros no...
			if (debe_dar_un_paso_mas) {
				marco->avanzarUnPaso();
			}
		}
	}

	void Marco::avanzarUnPaso() {
		posicion->Aumentar(this->direccion, this->velocidad);
	}

	void Marco::Detener() {
		sprite->indice = 0;
		debe_avanzar = false;
	}
}