#include "Constantes.h"
#include "Mapas.h"
#include "Juego.h"
#include "Objetos.h"

namespace YuGiOh {

	Mapa::Mapa() {
		capa_terreno = Juego::context->Allocate(Juego::graphics, Juego::myform->ClientRectangle);
	}

	void Mapa::generarCapaTerreno() {
		for (int y = 0; y < MYFORM_HEIGHT; y++) {
			for (int x = 0; x < MYFORM_WIDTH; x++) {

				Image ^imagen_terreno;
				int coordenada_x = x * RESOLUCION_X;
				int coordenada_y = y * RESOLUCION_Y;

				switch (matriz_terreno[y,x]) {
				case Loceta:
					imagen_terreno = IMAGENES::LOCETA;
					break;
				case Agua:
					imagen_terreno = IMAGENES::AGUA;
					break;
				case Arena:
					imagen_terreno = IMAGENES::ARENA;
					break;
				case Granito:
					imagen_terreno = IMAGENES::GRANITO;
					break;
				case Hielo:
					imagen_terreno = IMAGENES::HIELO;
					break;
				case Lava:
					imagen_terreno = IMAGENES::LAVA;
					break;
				case Lodo:
					imagen_terreno = IMAGENES::LODO;
					break;
				case Maceta:
					imagen_terreno = IMAGENES::MACETA;
					break;
				case Pasto:
					imagen_terreno = IMAGENES::PASTO;
					break;
				case Roca:
					imagen_terreno = IMAGENES::ROCA;
					break;
				case Tejado:
					imagen_terreno = IMAGENES::TEJADO;
					break;
				default:
					imagen_terreno = IMAGENES::TIERRA;
					break;
				
				}

				capa_terreno->Graphics->DrawImage(imagen_terreno, Rectangle(coordenada_x, coordenada_y, RESOLUCION_X, RESOLUCION_Y));
				
				if (DEBUG_MODE)
					capa_terreno->Graphics->DrawString(
						coordenada_x + "," + coordenada_y,
						gcnew Font("Arial", 8.0f),
						gcnew SolidBrush(Color::Black),
						(float)coordenada_x,
						(float)coordenada_y
					);
			}
		}
	}

	Objeto ^Mapa::getObjeto(Posicion ^posicion) {

		int numero_de_objetos = this->objetos->Count;
		
		for (int i = 0; i < numero_de_objetos; i++) {
			if (objetos[i]->getCuerpo().IntersectsWith(posicion->getCuerpo())) {
				return objetos[i];
			}
		}

		return nullptr;
	}

	Terreno Mapa::getTerrenoEnCoordenada(Posicion ^posicion) {
		
		// Se invierte, porque los mapas se guardan en forma x,y
		int y = posicion->y;
		int	x = posicion->x;

		if (x < 0 || x >= matriz_terreno->GetLength(1))
			return (Terreno)0;
		if (y < 0 || y >= matriz_terreno->GetLength(0))
			return Terreno(0);

		return matriz_terreno[y, x];
	}

	void Mapa::mostrarTerreno(Graphics ^graphics) {
		capa_terreno->Render(graphics);
	}

	void Mapa::mostrarObjetos(Graphics ^graphics) {

		int numero_de_objetos = this->objetos->Count;

		for (int i = 0; i < numero_de_objetos; i++)
			objetos[i]->mostrar(graphics);
	}

	Mapa ^Mapa::obtenerMapa(MapaTipo pabellon) {

		switch (pabellon)
		{
		case Plazuela:
			return Mapas::plazuela_mapa;
			break;
		case PabellonA:
			return Mapas::pabellonA_mapa;
			break;
		case PabellonB:
			return Mapas::pabellonB_mapa;
			break;
		case Sotano:
			return Mapas::sotano_mapa;
			break;
		case Jardin:
			return Mapas::jardin_mapa;
			break;
		default:
			return nullptr;
		}
	}

	PlazuelaMapa::PlazuelaMapa() : Mapa() {
		this->matriz_terreno = gcnew array<Terreno,2> {
			{ Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Pasto, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado},
			{ Granito, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Granito, Hielo, Hielo, Hielo, Hielo, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Maceta },
			{ Hielo, Hielo, Hielo, Hielo, Hielo, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Maceta },
			{ Granito, Hielo, Hielo, Hielo, Hielo, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Maceta },
			{ Granito, Hielo, Hielo, Hielo, Hielo, Agua, Agua, Agua, Agua, Agua, Agua, Agua, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Maceta },
			{ Granito, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Loceta, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Granito, Hielo, Hielo, Hielo, Hielo, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Granito, Granito, Granito, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Granito, Granito, Granito, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Granito, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Granito, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Hielo, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito }
		};

		this->objetos = gcnew List<Objeto ^>();
		this->objetos->AddRange(gcnew array<Objeto ^>{
			gcnew PuertaObjeto(PabellonA, gcnew Posicion(-1, 3, true), gcnew Posicion(19, 3, true), Izquierda),
			gcnew PuertaObjeto(PabellonB, gcnew Posicion(8, 14, true), gcnew Posicion(8, 0, true), Abajo),
			gcnew PuertaObjeto(Jardin, gcnew Posicion(8, -1, true), gcnew Posicion(8, 13, true), Arriba),
			gcnew PuertaEscenaObjeto(Tienda, gcnew Posicion(0, 9, true), Plazuela, gcnew Posicion(1, 9, true), Derecha),
			gcnew MonedaObjeto(gcnew Posicion(1, 1, true)),
			gcnew MonedaObjeto(gcnew Posicion(1, 12, true)),
			gcnew MonedaObjeto(gcnew Posicion(11, 9, true)),
			gcnew MonedaObjeto(gcnew Posicion(12, 11, true)),
			gcnew MonedaObjeto(gcnew Posicion(17, 2, true)),
			gcnew MonedaObjeto(gcnew Posicion(18, 7, true)),
			gcnew MonedaObjeto(gcnew Posicion(18, 12, true))
		});

		generarCapaTerreno();
	}

	PabellonAMapa::PabellonAMapa() : Mapa() {
		this->matriz_terreno = gcnew array<Terreno, 2> {
			{ Lava, Lava, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo },
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Lava, Lava, Loceta, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Loceta, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Lava, Lava, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Maceta },
			{ Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Lava, Maceta }
		};

		this->objetos = gcnew List<Objeto ^>();
		this->objetos->AddRange(gcnew array<Objeto ^>{
			gcnew PuertaObjeto(Plazuela, gcnew Posicion(20, 3, true), gcnew Posicion(0, 3, true), Derecha),
			gcnew MonedaObjeto(gcnew Posicion(3, 2, true)),
			gcnew MonedaObjeto(gcnew Posicion(7, 8, true)),
			gcnew MonedaObjeto(gcnew Posicion(18, 1, true))
		});

		generarCapaTerreno();
	}

	PabellonBMapa::PabellonBMapa() : Mapa() {
		this->matriz_terreno = gcnew array<Terreno, 2> {
			{ Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Hielo, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito},
			{ Granito, Loceta, Loceta, Granito, Loceta, Loceta, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Granito },
			{ Granito, Loceta, Granito, Granito, Loceta, Granito, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Granito, Loceta, Granito, Loceta, Granito, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Granito, Loceta, Granito, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Granito, Loceta, Granito, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Granito, Loceta, Granito, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Granito, Loceta, Granito, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Granito, Loceta, Granito, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Granito, Loceta, Granito, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Granito, Loceta, Granito, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Hielo, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Granito, Loceta, Granito, Loceta, Granito, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Granito },
			{ Granito, Loceta, Loceta, Loceta, Loceta, Granito, Loceta, Loceta, Hielo, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Granito },
			{ Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Hielo, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito }
		};

		this->objetos = gcnew List<Objeto ^>();
		this->objetos->AddRange(gcnew array<Objeto ^>{
			gcnew PuertaObjeto(Plazuela, gcnew Posicion(8, -1, true), gcnew Posicion(8, 13, true), Arriba),
			gcnew PuertaObjeto(Sotano, gcnew Posicion(8, 14, true), gcnew Posicion(8, 0, true), Abajo),
			gcnew MonedaObjeto(gcnew Posicion(2, 1, true)),
			gcnew MonedaObjeto(gcnew Posicion(12, 10, true)),
			gcnew MonedaObjeto(gcnew Posicion(16, 1, true))
		});

		generarCapaTerreno();
	}

	JardinMapa::JardinMapa() : Mapa() {
		this->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Agua, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Agua, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Agua, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Agua, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Agua, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Pasto, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Maceta }
		};

		this->objetos = gcnew List<Objeto ^>();
		this->objetos->AddRange(gcnew array<Objeto ^>{
			gcnew PuertaObjeto(Plazuela, gcnew Posicion(8, 14, true), gcnew Posicion(8, 0, true), Abajo),
			gcnew MonedaObjeto(gcnew Posicion(3, 2, true)),
			gcnew MonedaObjeto(gcnew Posicion(16, 2, true)),
			gcnew MonedaObjeto(gcnew Posicion(14, 11, true))
		});

		generarCapaTerreno();
	}

	SotanoMapa::SotanoMapa() : Mapa() {
		this->matriz_terreno = gcnew array<Terreno, 2> {
			{ Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Hielo, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado},
			{ Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado },
			{ Tejado, Hielo, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Hielo, Hielo, Hielo, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado },
			{ Tejado, Hielo, Tejado, Hielo, Hielo, Hielo, Tejado, Hielo, Tejado, Tejado, Hielo, Hielo, Hielo, Tejado, Hielo, Hielo, Hielo, Tejado, Hielo, Tejado },
			{ Tejado, Hielo, Hielo, Hielo, Tejado, Hielo, Hielo, Hielo, Tejado, Hielo, Tejado, Tejado, Hielo, Hielo, Hielo, Tejado, Hielo, Hielo, Hielo, Tejado },
			{ Tejado, Tejado, Hielo, Tejado, Tejado, Tejado, Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Hielo, Tejado },
			{ Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Hielo, Tejado, Tejado, Tejado, Tejado, Tejado, Hielo, Hielo, Hielo, Hielo, Tejado, Hielo, Tejado },
			{ Tejado, Hielo, Tejado, Hielo, Tejado, Hielo, Tejado, Hielo, Hielo, Hielo, Tejado, Hielo, Hielo, Hielo, Tejado, Tejado, Tejado, Tejado, Hielo, Tejado },
			{ Tejado, Hielo, Tejado, Hielo, Tejado, Hielo, Tejado, Hielo, Tejado, Tejado, Hielo, Hielo, Tejado, Hielo, Tejado, Hielo, Hielo, Hielo, Hielo, Tejado },
			{ Tejado, Hielo, Tejado, Hielo, Tejado, Tejado, Tejado, Hielo, Tejado, Hielo, Hielo, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Hielo, Tejado },
			{ Tejado, Hielo, Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Hielo, Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Hielo, Tejado },
			{ Tejado, Hielo, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Hielo, Tejado, Hielo, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Hielo, Tejado },
			{ Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Hielo, Tejado },
			{ Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado, Tejado }
		};

		this->objetos = gcnew List<Objeto ^>();
		this->objetos->AddRange(gcnew array<Objeto ^>{
			gcnew PuertaObjeto(PabellonB, gcnew Posicion(8, -1, true), gcnew Posicion(8, 13, true), Arriba),
			gcnew MonedaObjeto(gcnew Posicion(5, 8, true)),
			gcnew MonedaObjeto(gcnew Posicion(11, 5, true)),
			gcnew MonedaObjeto(gcnew Posicion(13, 8, true)),
			gcnew MonedaObjeto(gcnew Posicion(18, 1, true)),
			gcnew MonedaObjeto(gcnew Posicion(16, 10, true))
		});

		generarCapaTerreno();
	}
}
