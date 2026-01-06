#include "TextureBloq.h"
#include <vector>
using namespace std;

TextureBloq::TextureBloq(vector<vector<TipoBloque>>M_Bloq, int altura_E, int ancho_E, int nivelcero_E, int resolucion_x,int resolucion_y, int x1, int y1) {
	
	tam_bloq = 64; /// tamanio de bloque y del personaje
	pant_medio_x = ((res_x/2)  + tam_bloq/2  ); 	// int xp = ((res_x/2) -(16*(12/2)));
	pant_medio_y = ((res_y/2)  + tam_bloq/2  );		//int yp = ((res_y/2) -(16*(8/2)));
	
	altura = altura_E; /// minimo 200 /// la altura siempre tiene que tener minimo 2 ceros al final ej 100, 200, 500, 1000, 10000
	ancho = ancho_E; /// minimo 120 (por la resolucion de pantalla)
	nivelcero = nivelcero_E; /// nivel donde empiza el suelo
	altura_total = altura_E + nivelcero_E;
	
	res_x = resolucion_x;
	res_y = resolucion_y;
	
	int p_lim_x = res_x/(tam_bloq);			int p_lim_y = res_y/(tam_bloq); /// valores para Limites de pantalla
	p_lim_x = p_lim_x + 5;			p_lim_y = p_lim_y + 5;
	
	Textu.resize(p_lim_y);
	Spri.resize(p_lim_y);
	for(int i=0;i< p_lim_y ;i++) { 
		Textu[i].resize(p_lim_x);
		Spri[i].resize(p_lim_x);
	}
	
	
	vector<vector<string>>Bloq_aux;
	Bloq_aux.resize(p_lim_y);
	for(int i=0;i< p_lim_y ;i++) { 
		Bloq_aux[i].resize(p_lim_x);
	}
	
	
	for(int i=0;i<p_lim_y;i++) { 
		for(int j=0;j<p_lim_x;j++) { 
			Bloq_aux [i][j] = M_Bloq[y1 + i][x1 + j].NomBloq();
		}
	}
	
	for(int i=0;i<p_lim_y;i++) { 
		for(int j=0;j<p_lim_x;j++) { 
			Textu[i][j].loadFromFile(Bloq_aux [i][j]);
			Spri[i][j].setTexture(Textu[i][j]);
			
			if(M_Bloq[y1 + i][x1 + j].NomBloq() == "Tierra_prueba.png") Spri[i][j].setColor(Color(255,255,255,0));
			if(M_Bloq[y1 + i][x1 + j].NomBloq() == "Tierra_prueba1.png") Spri[i][j].setColor(Color(255,255,255,0));
			if(M_Bloq[y1 + i][x1 + j].NomBloq() == "Tierra_negra.png") Spri[i][j].setColor(Color(255,255,255,0));
		}
	}
}
Sprite TextureBloq::VerSpr(int a,int b, int x1, int y1){ 	/// a es el eje y, b es el eje x
	//return Spri[a+y1][b+x1];
	return Spri[a][b];
}
void TextureBloq::PosSpr(int a,int b, int x1, int y1){  		/// a es el eje y, b es el eje x
	
	//Spri[a+y1][b+x1].setScale(4,4); 					/// los bloques ahora tienen 64*64
	Spri[a][b].setScale(4,4); 					/// los bloques ahora tienen 64*64
	
	int pant_medio_x = ((res_x/2)  + tam_bloq/2  ); 	// int xp = ((res_x/2) -(16*(12/2)));
	int pant_medio_y = ((res_y/2)  + tam_bloq/2  );		//int yp = ((res_y/2) -(16*(8/2)));
	
	//Spri[a+y1][b+x1].setPosition( (b) *(16*4), pto_medio_y + (a) *(16*4)); /// (16*4) = 64 pixeles
	Spri[a][b].setPosition( (b) *(16*4) - tam_bloq/2,   (a) *(tam_bloq)); /// (16*4) = 64 pixeles
	//Spri[a][b].setPosition( (b) *(16*4) - tam_bloq, pant_medio_y + (a) *(16*4)); /// (16*4) = 64 pixeles
}
