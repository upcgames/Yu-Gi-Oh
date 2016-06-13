#pragma once
#include "Objetos.h"

using namespace System::Collections::Generic;

namespace YuGiOh {
	public ref class Mapa
	{
	protected:
		void generarCapaTerreno();
	public:
		Mapa();
		array<Terreno, 2>^ matriz_terreno;
		List<Objeto^>^ objetos;

		BufferedGraphics^ capa_terreno;

		Objeto^ getObjeto(Posicion^ posicion);
		static Mapa^ obtenerMapa(Pabellon pabellon);

		void mostrarTerreno();
		void mostrarObjetos();
	};

	public ref class PlazuelaMapa : public Mapa{ public: PlazuelaMapa(); };
	public ref class PabellonAMapa : public Mapa{ public: PabellonAMapa(); };
	public ref class PabellonBMapa : public Mapa{ public: PabellonBMapa(); };
}