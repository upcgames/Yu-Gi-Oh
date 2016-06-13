#include "Constantes.h"
#include "Mapa.h"
#include "Juego.h"
#include "Objetos.h"

namespace YuGiOh {

	Mapa::Mapa() {
		capa_terreno = Juego::context->Allocate(Juego::graphics, Juego::myform->ClientRectangle);
	}

	void Mapa::generarCapaTerreno() {
		for (int y = 0; y < MYFORM_HEIGHT; y++)
		{
			for (int x = 0; x < MYFORM_WIDTH; x++)
			{
				Image^ imagen_terreno;
				int coordenada_x = x * RESOLUCION_X;
				int coordenada_y = y * RESOLUCION_Y;

				switch (matriz_terreno[y,x])
				{
				case Loceta:
					imagen_terreno = Imagenes::LOCETA;
					break;
				case Pasto:
					imagen_terreno = Imagenes::PASTO;
					break;
				case Agua:
					imagen_terreno = Imagenes::AGUA;
					break;
				case Maceta:
					imagen_terreno = Imagenes::MACETA;
					break;
				}

				capa_terreno->Graphics->DrawImage(imagen_terreno, Rectangle(coordenada_x, coordenada_y, RESOLUCION_X, RESOLUCION_Y));

			}
		}
	}

	Objeto^ Mapa::getObjeto(Posicion^ posicion) {

		int numero_de_objetos = this->objetos-> Length;
		
		for (int i = 0; i < numero_de_objetos; i++)
		{
			if (objetos[i]->posicion == posicion) {
				return objetos[i];
			}
		}

		return nullptr;
	}


	void Mapa::mostrarTerreno() {
		capa_terreno->Render(Escena::getEscenaActual()->buffer->Graphics);
	}

	void Mapa::mostrarObjetos() {

		int numero_de_objetos = this->objetos->Length;

		for (int i = 0; i < numero_de_objetos; i++)
			objetos[i]->mostrar();
	}

	PlazuelaMapa::PlazuelaMapa() : Mapa() {
		this->matriz_terreno = gcnew array<Terreno,2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Loceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Loceta, Loceta, Loceta, Loceta, Loceta, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Loceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};

		this->objetos = gcnew array<Objeto^> {
			gcnew PuertaObjeto(gcnew Posicion(-1, 3, true), PabellonA, gcnew Posicion(19, 3, true), Izquierda),
			gcnew PuertaObjeto(gcnew Posicion(8, 14, true), PabellonB, gcnew Posicion(8, 0, true), Abajo),
			gcnew PuertaEscenaObjeto(Tienda, gcnew Posicion(0, 9, true), Plazuela, gcnew Posicion(1, 9, true), Derecha)
		};

		generarCapaTerreno();
	}

	PabellonAMapa::PabellonAMapa() : Mapa() {
		this->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};

		this->objetos = gcnew array<Objeto^> {
			gcnew PuertaObjeto(gcnew Posicion(20, 3, true), Plazuela, gcnew Posicion(0, 3, true), Derecha)
		};

		generarCapaTerreno();
	}

	PabellonBMapa::PabellonBMapa() : Mapa() {
		this->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Loceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};

		this->objetos = gcnew array<Objeto^> {
			gcnew PuertaObjeto(gcnew Posicion(8, -1, true), Plazuela, gcnew Posicion(8, 13, true), Arriba)
		};

		generarCapaTerreno();
	}

	Mapa^ Mapa::obtenerMapa(Pabellon pabellon) {
		
		switch (pabellon)
		{
		case Plazuela:
			return Juego::plazuela_mapa;
			break;
		case PabellonA:
			return Juego::pabellonA_mapa;
			break;
		case PabellonB:
			return Juego::pabellonB_mapa;
			break;
		default:
			return nullptr;
		}
	}

}
