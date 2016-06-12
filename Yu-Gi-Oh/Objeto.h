#pragma once
#include "Figura.h"

namespace YuGiOh {
	public ref class Objeto : public Figura
	{
	public:
		Objeto(Posicion^ posicion);
		Objetos tipo;
		Posicion^ posicion;
		void mostrar();
		virtual void accionar() abstract;
	};

	public ref class ObjetoStatico : public Objeto
	{
	public:
		ObjetoStatico(Posicion^ posicion);
	};

	public ref class PuertaObjeto : public ObjetoStatico
	{
	public:
		Direccion direccion_de_salida;
		Pabellon pabellon_de_salida;
		Posicion^ posicion_de_salida;
		PuertaObjeto(
			Posicion^ posicion,
			Pabellon pabellon_de_salida,
			Posicion^ posicion_de_salida,
			Direccion direccion_de_salida
		);
		virtual void accionar() override;
	};
}
	