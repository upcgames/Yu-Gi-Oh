#pragma once
#include "Figuras.h"

namespace YuGiOh
{
	public ref class Marco : public Duelista
	{
	public:
		static bool debe_avanzar;
		Direccion direccion;
		int velocidad;
		Marco(Posicion^ p);

		static Marco^ marco;
		static void mostrarloEn(Graphics^ graphics);

		void intentarAvanzar(Direccion direccion);
		void avanzarUnPaso();
		void Detener();
	};
}