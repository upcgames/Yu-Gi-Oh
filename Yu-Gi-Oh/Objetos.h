#pragma once
#include "Figuras.h"

namespace YuGiOh {
	public ref class Objeto: public Figura
	{
	public:
		Objeto(Posicion^ posicion);
		Objetos tipo;
		Posicion^ posicion;
		virtual void mostrar();
		virtual void accionar();
	};

	public ref class ObjetoStatico: public Objeto
	{
	public:
		ObjetoStatico(Posicion^ posicion);
	};

	public ref class PuertaObjeto: public ObjetoStatico
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

	public ref class PuertaEscenaObjeto : public ObjetoStatico
	{
	public:
		Direccion direccion_de_regreso;
		Pabellon pabellon_de_regreso;
		TipoEscena escena_a_mostrar;
		Posicion^ posicion_de_regreso;
		PuertaEscenaObjeto(
			TipoEscena escena_a_mostrar,
			Posicion^ posicion,
			Pabellon pabellon_de_regreso,
			Posicion^ posicion_de_regreso,
			Direccion direccion_de_regreso
			);
		virtual void accionar() override;
		virtual void mostrar() override;
	};
}
	