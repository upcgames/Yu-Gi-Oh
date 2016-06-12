#include "Objeto.h"
#include "Juego.h"
#include "Mapa.h"

namespace YuGiOh {
	Objeto::Objeto(Posicion^ posicion) {
		this->posicion = posicion;
	}

	void Objeto::mostrar() {
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
}