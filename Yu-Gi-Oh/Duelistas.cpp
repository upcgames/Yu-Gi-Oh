#include "Duelistas.h"
#include "Imagenes.h"

namespace YuGiOh {

	Profesor::Profesor(int nivel, Mapa ^mapa, Posicion ^posicion) {

		baraja = Baraja::crearBaraja(nivel);
		this->mapa = mapa;
		this->posicion = posicion;
		this->nivel = nivel;
		ha_sido_derrotado = false;

		if (nivel == 9)
			this->sprite = gcnew Sprite(IMAGENES::RECTOR_SPRITE);
		else
			this->sprite = gcnew Sprite(IMAGENES::PROFESOR_SPRITE);

		sprite->indice = 0;
		sprite->ancho = 48;
		sprite->alto = 48;
		sprite->frecuencia = 2;
		sprite->numero_de_columnas = 7;
		sprite->numero_de_filas = 1;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
	}

	void Profesor::Mostrarlo(Graphics^ graphics) {
		graphics->DrawImage(
			sprite->imagen,
			Rectangle(
			ancho - sprite->ancho + posicion->x,
			alto - sprite->alto + posicion->y,
			sprite->ancho,
			sprite->alto
			),
			Rectangle(
			sprite->indice / sprite->frecuencia * sprite->ancho,
			sprite->subindice * sprite->alto,
			sprite->ancho - 1, // Normalemnte no se deberia quitar uno
			sprite->alto - 1 // Pero, se pinta un pixel mas
			),
			GraphicsUnit::Pixel
			);

		if (!ha_sido_derrotado)
			sprite->siguienteIndice();
	}

	Profesor ^Profesor::anteriorProfesor() {

		if (nivel == 3)
			return PROFESORES::Profesor1;
		else if (nivel == 5)
			return PROFESORES::Profesor2;
		else if (nivel == 7)
			return PROFESORES::Profesor3;
		else if (nivel == 9)
			return PROFESORES::Profesor4;
		else
			return nullptr;
	}

	Profesor ^Profesor::siguienteProfesor() {
		if (nivel == 1)
			return PROFESORES::Profesor2;
		else if (nivel == 3)
			return PROFESORES::Profesor3;
		else if (nivel == 5)
			return PROFESORES::Profesor4;
		else if (nivel == 7)
			return PROFESORES::Profesor5;
		else
			return nullptr;
	}

	Profesor ^Profesor::getProfesorActual() {

		int nivel = PROFESORES::profesor_actual;

		if (nivel == 1)
			return PROFESORES::Profesor1;
		else if (nivel == 3)
			return PROFESORES::Profesor2;
		else if (nivel == 5)
			return PROFESORES::Profesor3;
		else if (nivel == 7)
			return PROFESORES::Profesor4;
		else if (nivel == 9)
			return PROFESORES::Profesor5;
		else
			return nullptr;
	}

	void PROFESORES::Mostrarlos(Graphics^ graphics) {

		if (Mapa::mapa_actual == Mapas::plazuela_mapa)
			PROFESORES::Profesor1->Mostrarlo(graphics);
		else if (Mapa::mapa_actual == Mapas::pabellonA_mapa && Profesor4->ha_sido_derrotado)
			PROFESORES::Profesor5->Mostrarlo(graphics);
		else if (Mapa::mapa_actual == Mapas::pabellonB_mapa)
			PROFESORES::Profesor2->Mostrarlo(graphics);
		else if (Mapa::mapa_actual == Mapas::sotano_mapa)
			PROFESORES::Profesor3->Mostrarlo(graphics);
		else if (Mapa::mapa_actual == Mapas::jardin_mapa)
			PROFESORES::Profesor4->Mostrarlo(graphics);
	}
}