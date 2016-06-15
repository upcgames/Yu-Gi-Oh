#include "Marco.h"
#include "Imagenes.h"
#include "Mapas.h"
#include "Objetos.h"

namespace YuGiOh
{
	Marco::Marco(Posicion^ p) {
		sprite = gcnew Sprite(Imagenes::MARCO_SPRITE);
		sprite->indice = 0;
		sprite->ancho = 24;
		sprite->alto = 24;
		sprite->numero_de_columnas = 8;
		sprite->numero_de_filas = 6;
		sprite->se_para_en_el_medio = true;

		direccion = Direccion::Abajo;
		velocidad = 8;
		posicion = p;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
		debe_avanzar = false;
	}

	void Marco::mostrarloEn(Graphics^ graphics)	{
		Marco^ marco = Marco::marco;
		Sprite^ marco_sprite = marco->sprite;

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
				marco_sprite->indice / 2 * marco_sprite->ancho,
				marco_sprite->subindice * marco_sprite->alto,
				marco_sprite->ancho,
				marco_sprite->alto
			),
			GraphicsUnit::Pixel
		);
	}

	void Marco::intentarAvanzar(Direccion direccion) {

		sprite->siguienteIndice();

		Posicion^ siguiente_posicion_de_marco = posicion->getSiguientePosicion(direccion, velocidad);
		Objeto^ siguiente_bloque = Mapa::mapa_actual->getObjeto(siguiente_posicion_de_marco);

		if (siguiente_bloque == nullptr) {
			this->avanzarUnPaso();
		}
		else {
			//Se choca con un objeto y se interactua con este
			Objeto^ objeto_dinamico = siguiente_bloque;
			bool debe_dar_un_paso_mas = objeto_dinamico->interactuarConMarco();
			
			//Algunos objetos detienen a marco por completo y otros no...
			if (debe_dar_un_paso_mas) {
				this->avanzarUnPaso();
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