#include "TextureBloq.h"

TextureBloq::TextureBloq(vector<vector<TipoBloque>>M_Bloq, int altura_E, int ancho_E, int nivelcero_E, int resolucion_x,int resolucion_y) {
	
	altura = altura_E; /// minimo 200 /// la altura siempre tiene que tener minimo 2 ceros al final ej 100, 200, 500, 1000, 10000
	ancho = ancho_E; /// minimo 120 (por la resolucion de pantalla)
	nivelcero = nivelcero_E; /// nivel donde empiza el suelo
	altura_total = altura_E + nivelcero_E;
	
	res_x = resolucion_x;
	res_y = resolucion_y;
	
	Textu.resize(altura);
	Spri.resize(altura);
	for(int i=0;i<altura;i++) { 
		Textu[i].resize(ancho);
		Spri[i].resize(ancho);
	}
	for(int i=0;i<altura;i++) { 
		for(int j=0;j<ancho;j++) { 
			Textu[i][j].loadFromFile(M_Bloq[i][j].NomBloq());
			Spri[i][j].setTexture(Textu[i][j]);
		}
	}
}
Sprite TextureBloq::VerSpr(int a,int b, int x1, int y1){ 	/// a es el eje y, b es el eje x
	return Spri[a+y1][b+x1];
}
void TextureBloq::PosSpr(int a,int b, int x1, int y1){  		/// a es el eje y, b es el eje x
	Spri[a+y1][b+x1].setScale(4,4); 					/// los bloques ahora tienen 64*64
	
	int pto_medio_x = ((res_x/2) + (16*(12/2))); 	// int xp = ((res_x/2) -(16*(12/2)));
	int pto_medio_y = ((res_y/2) + (16*(8/2)));		//int yp = ((res_y/2) -(16*(8/2)));
	
	Spri[a+y1][b+x1].setPosition( (b) *(16*4), pto_medio_y + (a) *(16*4)); /// (16*4) = 64 pixeles
}
