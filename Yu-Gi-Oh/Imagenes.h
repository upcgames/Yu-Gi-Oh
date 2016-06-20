#pragma once

namespace YuGiOh {

	public ref class IMAGENES abstract sealed {
	public:
		static void mostarFondo(Image ^imagen, Graphics ^graphics);

		static Image ^MARCO_SPRITE;
		static Image ^MONEDA_SPRITE;
					 
		static Image ^LOCETA;
		static Image ^PUERTA;
		static Image ^MONEDA;
		static Image ^AGUA;
		static Image ^MACETA;
		static Image ^PASTO;
					 
		static Image ^INTRODUCCION_FONDO_1;
		static Image ^INTRODUCCION_FONDO_2;
		static Image ^FONDO_TIENDA_VENDER;
		static Image ^FONDO_TIENDA_COMPRAR;
	};
}