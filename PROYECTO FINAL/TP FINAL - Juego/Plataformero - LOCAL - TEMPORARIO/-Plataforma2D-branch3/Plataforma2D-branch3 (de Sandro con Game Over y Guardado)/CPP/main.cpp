//#include <SFML/Graphics.hpp>
#include "../H/Game.h"
#include "../H/Scene_Menu.h"
//#include "Scene.h"
using namespace sf;
using namespace std;

int main(int argc, char *argv[]){
	
	
	Game the_game (new Scene_Menu());
	the_game.Run();
	
	/*
	RenderWindow win(VideoMode(640,480),"Prueba");
	
	win.setFramerateLimit(60);
	
	Texture t;
	Sprite s;
	
	t.loadFromFile("sfml.png");
	s.setTexture(t);
	s.setPosition(175, 130);
	*/
	/*
	while(win.isOpen()) {
		
		// procesar eventos
		Event evt;
		while(win.pollEvent(evt)) {
			if(evt.type == Event::Closed)
				win.close();	
		}
		
		// actualizar
		s.move(0.005,0.01);
		
		// redibujar todo
		win.clear(Color(255,255,255,255));
		win.draw(s);
		win.display();
	}
	*/
	return 0;
}

