#include "TexturePer.h"

TexturePer::TexturePer(string Nom) {
	t.loadFromFile(Nom);
	s.setTexture(t);
}
void TexturePer::Pos(int x,int y){
	s.setPosition(x,y);
}
