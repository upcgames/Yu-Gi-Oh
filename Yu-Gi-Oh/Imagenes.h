#pragma once

namespace YuGiOh {

	public ref class IMAGENES abstract sealed {
	public:
		static void mostarFondo(Image ^imagen, Graphics ^graphics);

		static Image ^MARCO_SPRITE;
		static Image ^PROFESOR_SPRITE;
		static Image ^RECTOR_SPRITE;
		static Image ^MONEDA_SPRITE;
					 
		static Image ^LOCETA;
		static Image ^AGUA;
		static Image ^ARENA;
		static Image ^GRANITO;
		static Image ^HIELO;
		static Image ^LAVA;
		static Image ^LODO;
		static Image ^MACETA;
		static Image ^PASTO;
		static Image ^PUERTA;
		static Image ^ROCA;
		static Image ^TEJADO;
		static Image ^TIERRA;
					 
		static Image ^INTRODUCCION_FONDO_1;
		static Image ^INTRODUCCION_FONDO_2;
		static Image ^FONDO_TIENDA_VENDER;
		static Image ^FONDO_TIENDA_COMPRAR;

		static List<Image ^> ^CARTAS;
	};
}