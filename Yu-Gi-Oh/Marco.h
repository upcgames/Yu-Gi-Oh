#pragma once
#include "Duelistas.h"

namespace YuGiOh {

	public ref class Marco : public Duelista {
	public:
		static bool debe_avanzar;
		int dinero;

		void intentarAvanzar(Direccion direccion);
		void avanzarUnPaso();
		void Detener();
		
		Marco(Posicion ^p);
		
		static void mostrarloEn(Graphics ^graphics);
		static Marco ^marco;
	};
}