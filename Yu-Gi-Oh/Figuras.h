#pragma once
#include "Constantes.h"

namespace YuGiOh
{
	public ref class Posicion
	{
	public:
		int x;
		int y;
		Posicion(int x, int y);
		Posicion(int x, int y, bool multiplicar_automaticamente);
		static bool	operator ==(const Posicion^ p1, const Posicion^ p2);
		void igualarA(Posicion^ p);
		void igualarA(int x, int y);
		void Aumentar(Direccion direccion, int velocidad);
		void toZero();
		Rectangle getCuerpo(int ancho, int alto);
		Posicion^ getSiguientePosicion(Direccion direccion, int velocidad);
	};

	public ref class Figura
	{
	public:
		Image^ imagen;
		Posicion^ posicion;
		int alto;
		int ancho;
		Figura();
		Rectangle getCuerpo();
		static Rectangle getCuerpo(int x, int y, int ancho, int alto);
	};

	public ref class Sprite
	{
	public:
		Image^ imagen;
		int indice;
		int subindice;
		int ancho;
		int alto;
		int numero_de_filas;
		int numero_de_columnas;
		bool se_para_en_el_medio;

		Sprite(Image^ image);
		void siguienteIndice();
		void cambiarSubindice(int subindice);
	};

	public ref class Animado : Figura
	{
	public:
		Sprite^ sprite;
	};

	public ref class Duelista : public Animado
	{
		public:
	};
}