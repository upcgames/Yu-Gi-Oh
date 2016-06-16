#pragma once
#include "Constantes.h"

namespace YuGiOh {

	public ref class Posicion {
	public:
		int x;
		int y;
		
		void igualarA(Posicion ^p);
		void igualarA(int x, int y);
		void Aumentar(Direccion direccion, int velocidad);

		Posicion ^toZero();
		Posicion ^toCoordenadas();

		Rectangle getCuerpo();
		Rectangle getCuerpo(int ancho, int alto);
		Posicion ^getSiguientePosicion(Direccion direccion, int velocidad);
		Posicion ^getPieIzquierdo(Direccion direccion);
		Posicion ^getPieDerecho(Direccion direccion);

		bool chocaCon(Rectangle cuerpo);

		Posicion(int x, int y);
		Posicion(int x, int y, bool multiplicar_automaticamente);
		
		static bool	operator == (const Posicion ^p1, const Posicion ^p2);
	};

	public ref class Figura {
	public:
		Image ^imagen;
		Posicion ^posicion;
		int alto;
		int ancho;
		Figura();
		Rectangle getCuerpo();
		static Rectangle crearCuerpo(int x, int y, int ancho, int alto);
	};

	public ref class Sprite {
	public:
		Image ^imagen;
		int indice;
		int subindice;
		int ancho;
		int alto;
		int numero_de_filas;
		int numero_de_columnas;

		void siguienteIndice();
		void cambiarSubindice(int subindice);
		
		Sprite(Image ^image);
	};

	public ref class Animado : Figura {
	public:
		Sprite ^sprite;

		//Ideal para verificar colisiones cuando algun personaje se esta moviendo
		bool colisionaConMapaActual(Posicion ^posicion, Direccion direccion);
	};

	public ref class Duelista : public Animado { };
}