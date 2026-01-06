#include <SFML/Graphics.hpp>
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(640,480),"Ejemplo de SFML");
	
	CircleShape c(50);
	c.setFillColor(Color(255,0,0));
	c.setPosition(100,100);
	
	RectangleShape r(Vector2f(175,100));
	r.setFillColor(Color(0,255,0));
	r.setPosition(350,250);
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		w.clear(Color(255,255,255,255));
		w.draw(c);
		w.draw(r);
		w.display();
	}
	return 0;
}

/// warning: This template will *dynamicaly* link against opencv, so yo'll need to copy some 
///          dll files from zinjai\mingw-gcc5\sfml2\bin in order to run this example

/// aviso: esta plantilla está configurada para enlazar *dinámicamente* con opencv, por lo
///        que necesitará copiar algunos archivos dll desde zinjai\mingw-gcc5\sfml2\bin
///        para ejecutar correctamente este ejemplo

