#include "Texture_Platform.h"

Texture_Platform::Texture_Platform(int posicion_x, int posicion_y, int largo, int alto, string nomBloque) {
	
	pos_x = posicion_x;
	pos_y = posicion_y;
	tamanio_x = largo;
	tamanio_y = alto;
	
	string nomBloq = nomBloque;
	
	// deslizamiento = ;
	
	mat_textu.resize(tamanio_y);
	mat_spri.resize(tamanio_y);
	
	for(int i=0;i< tamanio_y ;i++) { 
		mat_textu[i].resize(tamanio_x);
		mat_spri[i].resize(tamanio_x);
	}
	for(int i=0;i<tamanio_y;i++) { 
		for(int j=0;j<tamanio_x;j++) { 
			mat_textu[i][j].loadFromFile(nomBloq);
			mat_spri[i][j].setTexture(mat_textu[i][j]);
		}
	}
}

Texture_Platform::Texture_Platform(int largo, int alto, string nomBloque) {
	
	pos_x = posicion_x;
	pos_y = posicion_y;
	tamanio_x = largo;
	tamanio_y = alto;
	
	string nomBloq = nomBloque;
	
	// deslizamiento = ;
	
	mat_textu.resize(tamanio_y);
	mat_spri.resize(tamanio_y);
	
	for(int i=0;i< tamanio_y ;i++) { 
		mat_textu[i].resize(tamanio_x);
		mat_spri[i].resize(tamanio_x);
	}
	for(int i=0;i<tamanio_y;i++) { 
		for(int j=0;j<tamanio_x;j++) { 
			mat_textu[i][j].loadFromFile(nomBloq);
			mat_spri[i][j].setTexture(mat_textu[i][j]);
		}
	}
}

Sprite Texture_Platform::VerSpr(int a,int b, int x1, int y1){ 	///  a, b son i, j
	//return mat_spri[a+y1][b+x1];
	return mat_spri[a][b];
}
void Texture_Platform::PosSpr(int a,int b, int x1, int y1){  		/// a es el eje y, b es el eje x
	
	//mat_spri[a+y1][b+x1].setScale(4,4); 					/// los bloques ahora tienen 64*64
	mat_spri[a][b].setScale(4,4); 					/// los bloques ahora tienen 64*64
	
	
	mat_spri[a][b].setPosition( (b + x1) *(64),   (a + y1) *(64)); ///  a, b son i, j
}

int Texture_Platform::VerLargo() return tamanio_x;
int Texture_Platform::VerAlto() return tamanio_y;
