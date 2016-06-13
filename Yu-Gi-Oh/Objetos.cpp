#include "Objetos.h"
#include "Juego.h"
#include "Mapa.h"

namespace YuGiOh {
	Objeto::Objeto(Posicion^ posicion) {
		this->posicion = posicion;
	}

	void Objeto::mostrar() {
		;
	}

	void Objeto::accionar() {
		;
	}

	ObjetoStatico::ObjetoStatico(Posicion^ posicion) : Objeto(posicion) {
		;
	}

	PuertaObjeto::PuertaObjeto(
		Posicion^ posicion,
		Pabellon pabellon_de_salida,
		Posicion^ posicion_de_salida,
		Direccion direccion_de_salida
		) : ObjetoStatico(posicion) {

		tipo = Puerta;
		this->pabellon_de_salida = pabellon_de_salida;
		this->posicion_de_salida = posicion_de_salida;
		this->direccion_de_salida = direccion_de_salida;
	}

	void PuertaObjeto::accionar() {
		Juego::marco->posicion->IgualarA(this->posicion_de_salida);
		Juego::marco->direccion = this->direccion_de_salida;
		Juego::mapa_actual = Mapa::obtenerMapa(pabellon_de_salida);
	}

	PuertaEscenaObjeto::PuertaEscenaObjeto(
		TipoEscena escena_a_mostrar,
		Posicion^ posicion,
		Pabellon pabellon_de_regreso,
		Posicion^ posicion_de_regreso,
		Direccion direccion_de_regreso
		) : ObjetoStatico(posicion) {
		
		imagen = Imagenes::PUERTA;
		tipo = PuertaEscena;
		this->escena_a_mostrar = escena_a_mostrar;
		this->pabellon_de_regreso = pabellon_de_regreso;
		this->posicion_de_regreso = posicion_de_regreso;
		this->direccion_de_regreso = direccion_de_regreso;
		
	}
	
	void PuertaEscenaObjeto::accionar() {
		Escena::CambiarEscena(Escena::getEscenaTipo(escena_a_mostrar));
		Escena^ escena = Escena::getEscenaTipo(escena_a_mostrar);
		EscenaDeMapa^ escena_de_mapa = dynamic_cast<EscenaDeMapa^>(escena);

		escena_de_mapa->escena_a_mostrar = escena_a_mostrar;
		escena_de_mapa->pabellon_de_regreso = pabellon_de_regreso;
		escena_de_mapa->posicion_de_regreso = posicion_de_regreso;
		escena_de_mapa->direccion_de_regreso = direccion_de_regreso;
	}

	void PuertaEscenaObjeto::mostrar() {
		Graphics^ graphics_actual = Escena::getEscenaActual()->buffer->Graphics;
		graphics_actual->DrawImage(imagen, Rectangle(posicion->x, posicion->y, RESOLUCION_X, RESOLUCION_Y));;
	}
}