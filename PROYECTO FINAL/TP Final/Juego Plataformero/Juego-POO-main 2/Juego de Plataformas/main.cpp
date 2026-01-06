#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

//#include<iostream>
//using namespace std;
using namespace sf;

int main (int argc, char *argv[]) {
	
	RenderWindow w(VideoMode(640,480),"Ejemplo de SFML");
	
	m_window.setFramerateLimit(60);
	
	/*
	Texture t;
	Sprite s;
	*/
	
	int x1 = 0, y1 = 0, altura = 1, ancho = 1;
	string tipo_plat;
	
	
	while(w.isOpen()) {
		
		// procesar eventos
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		
		//Texture_Platform T_Platform( x1, y1, altura, ancho, tipo_plat);
		Texture_Platform T_Platform( altura, ancho, tipo_plat);
		
		for(int i= 0 ;i< (altura) ;i++) { 
		for(int j= 0 ;j< (ancho) ;j++) { 
			T_Platform.PosSpr(i,j,x1,y1);
		}
	}
		
		// actualizar
		//s.move(0.005,0.01);
		
		// redibujar todo
		w.clear(Color(255,255,255,255));
		
		for(int i=0;i<altura;i++) { /// simulo solo una parte de la matriz de bloques
			for(int j=0;j<ancho;j++) {
				w.draw(T_Platform.VerSpr(i,j,x1,y1));
			}
		}
		
		w.draw(s);
		w.display();
		
	}
	
	
	return 0;
}

