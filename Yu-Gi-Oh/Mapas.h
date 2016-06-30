#pragma once
#include "Objetos.h"

using namespace System::Collections::Generic;

namespace YuGiOh {

	public ref class Mapa {
	protected:
		void generarCapaTerreno();
	public:
		array<Terreno, 2> ^matriz_terreno;
		List<Objeto ^> ^objetos;
		
		BufferedGraphics ^capa_terreno;

		Objeto ^getObjeto(Posicion ^posicion);
		static Figura ^getProfesor(Posicion ^posicion);
		
		Terreno getTerrenoEnCoordenada(Posicion ^posicion);

		void mostrarTerreno(Graphics ^graphics);
		void mostrarObjetos(Graphics ^graphics);
		
		Mapa();
		
		static Mapa ^obtenerMapa(MapaTipo pabellon);
		static MapaTipo obtenerMapaTipo(Mapa ^pabellon);
		static String ^getNombre(Mapa ^mapa);
		static Mapa ^mapa_actual;
	};

	public ref class PlazuelaMapa : public Mapa{ public: PlazuelaMapa(); };
	public ref class PabellonAMapa : public Mapa{ public: PabellonAMapa(); };
	public ref class PabellonBMapa : public Mapa{ public: PabellonBMapa(); };
	public ref class JardinMapa : public Mapa{ public: JardinMapa(); };
	public ref class SotanoMapa : public Mapa{ public: SotanoMapa(); };

	public ref class Mapas abstract sealed {
	public:
		static PlazuelaMapa ^plazuela_mapa;
		static PabellonAMapa ^pabellonA_mapa;
		static PabellonBMapa ^pabellonB_mapa;
		static JardinMapa ^jardin_mapa;
		static SotanoMapa ^sotano_mapa;
	};
}