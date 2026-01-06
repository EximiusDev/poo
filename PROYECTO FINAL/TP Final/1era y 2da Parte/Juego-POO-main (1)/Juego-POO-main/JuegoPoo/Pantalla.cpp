#include "Pantalla.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include "TexturePer.h"
using namespace std;

Pantalla::Pantalla(int resolucion_x,int resolucion_y):w(VideoMode(resolucion_x,resolucion_y),"Juego De P.O.O") {
	res_x = resolucion_x;
	res_y = resolucion_y;
};///Al usar el constructo de la clase genero la pantalla con un tamanio q no se cambiara 
/// w es un objeto de tipo RenderWindow y VideoMode pertenece a SFML/Window

void Pantalla::Run(string Nom){ ///Con este metodo empiezo a correr el juego
	Event evt; ///Clase Event
	TexturePer Per(Nom);///Genero el personaje Per (inicializo la imagen del personaje como una textura)
	Color color(255,255,255,255);///Color y transparencia del fondo (blanco y completamente opaco)(Color pertene SFML/Graphics)
	int x=0;int y=0;
	///int xp = 960-(16*12); int yp=540-(16*8);
	int xp = ((res_x/2) -(16*(12/2))); int yp = ((res_y/2) -(16*(8/2)));
	
	Per.Pos(xp,yp); /// seteo la posicion de la textura del Personaje
	float tam_x = 0.5, tam_y = 0.5; /// pongo el tamño del personaje a la mitad (por eso el 16*(12/2) y el 16*(8/2) en la posicion del personaje)
	Per.Tam(tam_x, tam_y);
	TexturePer Fondo1("1.png"); /// Cargo las imagenes para el fondo
	TexturePer Fondo2("2.png");
	TexturePer Fondo3("3.png");
	TexturePer Fondo4("4.png");
	TexturePer Fondo5("5.png");
	Fondo1.Tam(3.5,3.5); /// llamo al metodo Tam de TexturePer(equivalente a setScale para los sprites) para cada fondo
	Fondo2.Tam(3.5,3.5);
	Fondo3.Tam(3.5,3.5);
	Fondo4.Tam(3.5,3.5);
	Fondo5.Tam(3.5,3.5);
	/// se procesan los eventos:
	/// recordar que w es un objeto de tipo renderizado de pentalla (pertene SFML/Graphics)
	
	w.setFramerateLimit(60); /// limita la cantidad de FPS a 60 (se mueve mas lento si no se define el clock)
	
	while(w.isOpen()) { /// mientras se renderice la pantalla 
		
		while(w.pollEvent(evt)) { /// no se puede omitir este loop. "eleccion" de eventos, es decir veo si se efectuan ciertos eventos o cambios (?)
			if(evt.type == Event::Closed) /// si el tipo del objeto evt (clase Event) es igual al metodo de Event cerrado
				w.close();/// cierra el renderizado de la pantalla w
		} /// en este loop se compara el tipo de evento con los eventos externos ej (mover el mouse, Joystick desconectado, entrada de texto(ver Event::))
		
		w.clear(color); /// borra el fondo de la ventana (el que es de un determ color)
		w.draw(Fondo1.Vs()); /// Dibuja el sprite del objeto tipo  TexturePer  "Fondo1"(textura)
		w.draw(Fondo2.Vs());
		w.draw(Fondo3.Vs());
		w.draw(Fondo4.Vs());
		w.draw(Fondo5.Vs());
		w.draw(Per.Vs()); /// Dibuja el sprite del objeto tipo  TexturePer "Per"(textura), es decir dibuja al personaje
		w.display(); /// los ejecuta en el renderizado de la pantalla
		
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Down)){ /// Keyboard (clase de entrada de SFML)
			y++; /// aumento la distrancia verticalmente (recordar que el 0,0 es en la parte superior izquierda)
			Per.Pos(xp,yp);} /// actualizo la posicion del personaje (TexturePer Per)
		if(Keyboard::isKeyPressed(Keyboard::Key::Left)){ /// veo si el teclado esta presionado y le paso de parametro el metodo Key de Keyboard
			x--;
			Fondo1.Pos(-x*1.2,0 ); /// cambio la posicion de los distintos fondos
			Fondo2.Pos(-x*1.4,0 ); /// cambio la posicion del fondo que va por delante mas que el que va por atras, sucesivamente 
			Fondo3.Pos(-x*1.6,0 );
			Fondo4.Pos(-x*1.8,0);
			Fondo5.Pos(-x*2,0 ); /// la variacion entre el cambio de posicion de los fondos brinda la sensacion de movimiento y tridimensionalidad
			
			xp = ((res_x/2) -(16*(12/2))); yp = ((res_y/2) -(16*(8/2)));
			Per.Pos(xp,yp);
			///if(tam_x < 0) Per.Tam(-tam_x, tam_y);
			Per.Tam(tam_x, tam_y);
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Right)){
			x++;
			Fondo1.Pos(-x*1.2,0 );
			Fondo2.Pos(-x*1.4,0 );
			Fondo3.Pos(-x*1.6,0 );
			Fondo4.Pos(-x*1.8,0);
			Fondo5.Pos(-x*2,0 );
			
			xp = ((res_x/2) + (16*(12/2))); yp = ((res_y/2) - (16*(8/2)));
			Per.Pos(xp,yp);
			if(tam_x > 0) Per.Tam(-tam_x, tam_y);
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Up)){
			y--;
			Per.Pos(xp,yp);}
	}}


/*while(w.isOpen()) {
while(w.pollEvent(evt)) {
if(evt.type == Event::Closed)
w.close();}

w.display();
}}*/
