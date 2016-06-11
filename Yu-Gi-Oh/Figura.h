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
		static bool	operator ==(const Posicion^ p1, const Posicion^ p2);
		void IgualarA(Posicion^ p);
		void IgualarA(int x, int y);
		void Aumentar(Direcciones direccion, int velocidad);
		void ToZero();
		Rectangle getBody(int ancho, int alto);
		Posicion^ getPosicionIncrementada(Direcciones direccion, int velocidad);
	};

	public ref class Figura
	{
	public:
		Image^ imagen;
		Posicion^ posicion;
		int alto;
		int ancho;
		Figura();
		Rectangle getBody();
		static Rectangle getBody(int x, int y, int ancho, int alto);
	};

	public ref class Sprite
	{
	public:
		Sprite(Image^ image);
		Image^ imagen;
		int indice;
		int subindice;
		int ancho;
		int alto;
		int numero_de_filas;
		int numero_de_columnas;
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