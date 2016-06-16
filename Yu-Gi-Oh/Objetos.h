#pragma once
#include "Figuras.h"

namespace YuGiOh {

	public ref class Objeto: public Figura {
	public:
		Objetos tipo;
		
		Objeto(Posicion ^posicion);

		virtual void mostrar(Graphics ^graphics);
		virtual bool interactuarConMarco();
	};

	public ref class ObjetoStatico: public Objeto {
	public:
		ObjetoStatico(Posicion ^posicion);
	};

	public ref class ObjetoAnimado : public Objeto {
	public:
		Sprite ^sprite;
		
		virtual void mostrar(Graphics ^graphics) override;
		
		ObjetoAnimado(Posicion ^posicion);
	};

	public ref class PuertaObjeto: public ObjetoStatico {
	public:
		Direccion direccion_de_salida;
		MapaTipo pabellon_de_salida;
		Posicion ^posicion_de_salida;

		PuertaObjeto(
			MapaTipo pabellon_de_salida,
			Posicion  ^posicion,
			Posicion ^posicion_de_salida,
			Direccion direccion_de_salida
		);

		virtual bool interactuarConMarco() override;
	};

	public ref class MonedaObjeto : public ObjetoAnimado {
	public:
		int dinero_sorpresa;
		
		virtual bool interactuarConMarco() override;
		
		MonedaObjeto(Posicion ^posicion);
	};

	public ref class PuertaEscenaObjeto : public ObjetoStatico {
	public:
		Direccion direccion_de_regreso;
		MapaTipo pabellon_de_regreso;
		TipoEscena escena_a_mostrar;
		Posicion ^posicion_de_regreso;

		PuertaEscenaObjeto(
			TipoEscena escena_a_mostrar,
			Posicion ^posicion,
			MapaTipo pabellon_de_regreso,
			Posicion ^posicion_de_regreso,
			Direccion direccion_de_regreso
		);

		virtual void mostrar(Graphics ^graphics) override;
		virtual bool interactuarConMarco() override;
	};
}
	