#pragma once
#include "Figura.h"

namespace YuGiOh
{
	public ref class Marco : public Duelista
	{
	public:
		static bool moviendose;
		Direcciones direccion;
		int velocidad;
		Marco(Posicion^ p);
		void MostrarMarco(Graphics^ graphics);
		void Avanzar(Direcciones direccion);
		void Detener();
	};
}