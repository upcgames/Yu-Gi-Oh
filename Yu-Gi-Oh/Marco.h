#pragma once
#include "Figuras.h"

namespace YuGiOh
{
	public ref class Marco : public Duelista
	{
	public:
		static bool moviendose;
		Direccion direccion;
		int velocidad;
		Marco(Posicion^ p);
		void MostrarMarco(Graphics^ graphics);
		void Avanzar(Direccion direccion);
		void Detener();
	};
}