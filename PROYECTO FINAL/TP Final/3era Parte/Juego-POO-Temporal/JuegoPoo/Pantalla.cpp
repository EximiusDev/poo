#include "Pantalla.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include "TexturePer.h"
#include "TextureBloq.h"
#include "GeneracionMundo.h"
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
	int x1=0;int y1=0;
	
	int tam_bloq = 16*(4/2); /// tamanio de bloque y del personaje
	
	int xp = ((res_x/2) - tam_bloq ); int yp = ((res_y/2) - tam_bloq );
	///int xp = 960-(16*12); int yp=540-(16*8);
	
			/**Generacion del mundo**/
	int altura = 100;
	int ancho = 50;
	int nivelcero = 10;
	int altura_total = altura + nivelcero;
	
	GeneracionMundo Mundo1;
	Mundo1.Modificarmundo(altura, ancho, nivelcero);
	Mundo1.Ver_niveles();
	Mundo1.Ver_Matriz_azar();
	
	//TextureBloq Bloq(Mundo1.Ver_Matriz_Bloques(), altura, ancho, nivelcero, res_x, res_y, x, y);
	
	/// Generar limites de pantalla 
	
	int p_lim_x = res_x/(16*4);			int p_lim_y = res_y/(16*4); /// valores para Limites de pantalla
	p_lim_x = p_lim_x + 5;			p_lim_y = p_lim_y + 5;
	
	/*
	for(int i=0;i<altura;i++) { 
		for(int j=0;j<ancho;j++) { 
			Bloq.PosSpr(i,j,x1,y1);
		}
	}
	*/
	
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
	
	bool tecla_up 		= false;
	bool tecla_down 	= false;
	bool tecla_left 	= false;
	bool tecla_right 	= false;
	
	/// se procesan los eventos:
	/// recordar que w es un objeto de tipo renderizado de pentalla (pertene SFML/Graphics)
	
	w.setFramerateLimit(60); /// limita la cantidad de FPS a 60 (se mueve mas lento si no se define el clock)
	
	while(w.isOpen()) { /// mientras se renderice la pantalla 
		
		while(w.pollEvent(evt)) { /// no se puede omitir este loop. "eleccion" de eventos, es decir veo si se efectuan ciertos eventos o cambios (?)
			if(evt.type == Event::Closed) /// si el tipo del objeto evt (clase Event) es igual al metodo de Event cerrado
				w.close();/// cierra el renderizado de la pantalla w
		} /// en este loop se compara el tipo de evento con los eventos externos ej (mover el mouse, Joystick desconectado, entrada de texto(ver Event::))
		
		w.clear(color);/// borra el fondo de la ventana (el que es de un determ color)
		
		TextureBloq Bloq(Mundo1.Ver_Matriz_Bloques(), altura, ancho, nivelcero, res_x, res_y, x1, y1);
		
		/*
		for(int i= y ;i< (y + p_lim_y) ;i++) { 
			for(int j= x ;j< (p_lim_x) ;j++) { 
				Bloq.PosSpr(i,j,x1,y1);
			}
		}*/
		for(int i= 0 ;i< (p_lim_y) ;i++) { 
			for(int j= 0 ;j< (p_lim_x) ;j++) { 
				Bloq.PosSpr(i,j,x1,y1);
			}
		}
		
		
		w.draw(Fondo1.Vs()); /// Dibuja el sprite del objeto tipo  TexturePer  "Fondo1"(textura)
		w.draw(Fondo2.Vs());
		w.draw(Fondo3.Vs());
		w.draw(Fondo4.Vs());
		w.draw(Fondo5.Vs());
		
		
		for(int i=0;i<p_lim_y;i++) { /// simulo solo una parte de la matriz de bloques
			for(int j=0;j<p_lim_x;j++) {
				w.draw(Bloq.VerSpr(i,j,x1,y1));
			}
		}
		/*
		for(int i=0;i< p_lim_y ;i++) { /// simulo solo una parte de la matriz de bloques
			for(int j = (ancho/2) -  p_lim_x/2 ; j < (ancho/2) +  p_lim_x/2 ; j++) {
				w.draw(Bloq.VerSpr(i,j));
			}
		}*/
		
		w.draw(Per.Vs()); /// Dibuja el sprite del objeto tipo  TexturePer "Per"(textura), es decir dibuja al personaje
		w.display(); /// los ejecuta en el renderizado de la pantalla
		
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Down)){ /// Keyboard (clase de entrada de SFML)
			
			if(tecla_down == false) if(y1 != altura - 1 ) y1++;
			tecla_down = true;
			
			//if(y != altura - 1 ) y++;
			y++; /// aumento la distrancia verticalmente (recordar que el 0,0 es en la parte superior izquierda)
			
			Fondo1.Pos(-x*1.2,-y*1.2 );
			Fondo2.Pos(-x*1.4,-y*1.4 );
			Fondo3.Pos(-x*1.6,-y*1.6 );
			Fondo4.Pos(-x*1.8,-y*1.8);
			Fondo5.Pos(-x*2,-y*2 );
			
			Per.Pos(xp,yp); /// actualizo la posicion del personaje (TexturePer Per)
		}
		else tecla_down = false;
		if(Keyboard::isKeyPressed(Keyboard::Key::Up)){
			
			if(tecla_up == false) if(y1 != 0 ) y1--;
			tecla_up = true;
			
			//if(y != 0 ) y--;
			y--;
			
			Fondo1.Pos(-x*1.2,-y*1.2 );
			Fondo2.Pos(-x*1.4,-y*1.4 );
			Fondo3.Pos(-x*1.6,-y*1.6 );
			Fondo4.Pos(-x*1.8,-y*1.8);
			Fondo5.Pos(-x*2,-y*2 );
			
			Per.Pos(xp,yp);
		}
		else tecla_up = false; 
		if(Keyboard::isKeyPressed(Keyboard::Key::Left)){ /// veo si el teclado esta presionado y le paso de parametro el metodo Key de Keyboard
			
			if(tecla_left == false) if(x1 != 0 ) x1--;
			tecla_left = true;
			
			//if(x != 0 ) x--;
			x--;
			
			Fondo1.Pos(-x*1.2,0 ); /// cambio la posicion de los distintos fondos
			Fondo2.Pos(-x*1.4,0 ); /// cambio la posicion del fondo que va por delante mas que el que va por atras, sucesivamente 
			Fondo3.Pos(-x*1.6,0 );
			Fondo4.Pos(-x*1.8,0);
			Fondo5.Pos(-x*2,0 ); /// la variacion entre el cambio de posicion de los fondos brinda la sensacion de movimiento y tridimensionalidad
			
			
			Per.Pos(xp,yp);
			///if(tam_x < 0) Per.Tam(-tam_x, tam_y);
			Per.Tam(tam_x, tam_y);
		}
		else tecla_left = false;
		if(Keyboard::isKeyPressed(Keyboard::Key::Right)){
			
			if(tecla_right == false) if(x1 != ancho - 1 ) x1++;
			tecla_right = true;
			
			// if(x != ancho - 1 ) x++;
			x++;
			
			Fondo1.Pos(-x*1.2,0 );
			Fondo2.Pos(-x*1.4,0 );
			Fondo3.Pos(-x*1.6,0 );
			Fondo4.Pos(-x*1.8,0);
			Fondo5.Pos(-x*2,0 );
			
			/*for(int i=0;i<50;i++) { 
				for(int j=0;j<50;j++) { 
					Bloq.PosSpr(i*64,j);
				}
			}*/
			
			Per.Pos(xp,yp);
			if(tam_x > 0) Per.Tam(-tam_x, tam_y);
		}
		else tecla_right = false;
		/*
		if(x1 < 0 ) 				x1 = ancho - 1;
		if(y1 < 0 ) 				y1 = altura - 1;
		if(x1 > ancho - 1 ) 		x1 = 0;
		if(y1 > altura - 1 ) 		y1 = 0;
		*/
	}
}


/*while(w.isOpen()) {
while(w.pollEvent(evt)) {
if(evt.type == Event::Closed)
w.close();}

w.display();
}}*/
