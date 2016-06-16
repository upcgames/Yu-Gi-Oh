#pragma once
#include "Figuras.h"

namespace YuGiOh {

	public ref class Marco : public Duelista {
	public:
		static bool debe_avanzar;
		Direccion direccion;
		int velocidad;

		void intentarAvanzar(Direccion direccion);
		void avanzarUnPaso();
		void Detener();
		
		Marco(Posicion^ p);
		
		static void mostrarloEn(Graphics^ graphics);
		static Marco^ marco;
	};
}