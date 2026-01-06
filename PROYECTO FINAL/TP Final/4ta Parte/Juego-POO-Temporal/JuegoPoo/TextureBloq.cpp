#include "TextureBloq.h"
/*
TextureBloq::TextureBloq(TipoBloque bloq_de_mat) {
	
	textu_bloq.loadFromFile(bloq_de_mat.NomBloq());
	Spri_bloq.setTexture(textu_bloq);
	
}
*/
Sprite TextureBloq::GeneradorSpr(int a,int b){
	return Spri_bloq;
}
void TextureBloq::PosSpr(int a,int b){
	Spri_bloq.setScale(4,4);
	Spri_bloq.setPosition(b*64,600+a*64);
}
void TextureBloq::Mov(int a,int b,int c,int d){
	
	Spri_bloq.setPosition(b*64,600+a*64);
}
void TextureBloq::Inicializar(TipoBloque bloq_de_mat){
	
	textu_bloq.loadFromFile(bloq_de_mat.NomBloq());
	Spri_bloq.setTexture(textu_bloq);
}
/*

void TextureBloq::Inicializar(vector<vector<TipoBloque>>B){
	Text.resize(50);
	Spri.resize(50);
	for(int i=0;i<50;i++) { 
		Text[i].resize(50);
		Spri[i].resize(50);
	}
	for(int i=0;i<50;i++) { 
		for(int j=0;j<50;j++) { 
			Text[i][j].loadFromFile(B[i][j].NomBloq());
			Spri[i][j].setTexture(Text[i][j]);
		}
	}
}*/
