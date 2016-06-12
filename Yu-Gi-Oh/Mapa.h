#pragma once
#include "Objeto.h"

namespace YuGiOh {
	public ref class Mapa
	{
	protected:
		void generarCapaTerreno();
	public:
		Mapa();
		array<Terreno, 2>^ matriz_terreno;
		array<Objeto^>^ objetos;

		BufferedGraphics^ capa_terreno;

		Objeto^ getObjeto(Posicion^ posicion);
		static Mapa^ obtenerMapa(Pabellon pabellon);

		void mostrarTerreno();
	};

	public ref class PlazuelaMapa : public Mapa{ public: PlazuelaMapa(); };
	public ref class PabellonAMapa : public Mapa{ public: PabellonAMapa(); };
	public ref class PabellonBMapa : public Mapa{ public: PabellonBMapa(); };
}