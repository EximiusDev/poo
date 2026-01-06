#include "Pantalla.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include "TexturePer.h"
#include "TextureBloq.h"
#include "GeneracionMundo.h"
using namespace std;
Pantalla::Pantalla():w(VideoMode(1920,1080),"Juego De P.O.O") {};///Al usar el constructo de la clase genero la pantalla con un tamanio q no se cambiara 
/// w es un objeto de tipo RenderWindow y VideoMode pertenece a SFML/Window

void Pantalla::Run(string Nom){ ///Con este metodo empiezo a correr el juego
	Event evt; ///Clase Event
	TexturePer Per(Nom);///Genero el personaje Per (inicializo la imagen del personaje como una textura)
	Color color(255,255,255,255);///Color y transparencia del fondo (blanco y completamente opaco)(Color pertene SFML/Graphics)
	int x=0;int y=0;
	int xp=960-(16*12); int yp=540-(16*8);
	
	
			/**Generacion del mundo**/
	GeneracionMundo a;
	a.Modificardatos(50,50,0);
	a.Ver_niveles();
	a.Ver_Matriz_azar();
	
	//TextureBloq Bloq(a.Ver_Matriz_Bloques());
	/*
	for(int i=0;i<50;i++) { 
		for(int j=0;j<50;j++) { 
			Bloq.PosSpr(i,j);}}
	*/
	
	
	Per.Pos(xp,yp); /// seteo la posicion de la textura del Personaje
	float tam_x = 0.5, tam_y = 0.5;
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
	
	
	vector<vector<TextureBloq>>Mat_Bloq;
	Mat_Bloq.resize(30);
	for(int i= 0 ;i< (30) ;i++) { 
		Mat_Bloq[i].resize(40);
	}
	
	
	
	
	/// se procesan los eventos:
	/// recordar que w es un objeto de tipo renderizado de pentalla (pertene SFML/Graphics)
	
	w.setFramerateLimit(60); /// limita la cantidad de FPS a 60 (se mueve mas lento si no se define el clock)
	
	int yBloq=0;/////////////////////////////////////////////////////////////////////////////////////////////////////////////CON ESTOS PONGO LA POSICION DE LOS BLOQUES SEPARANDOLO DEL FONDO
	int xBloq=0;
	while(w.isOpen()) { /// mientras se renderice la pantalla 
		
		while(w.pollEvent(evt)) { /// no se puede omitir este loop. "eleccion" de eventos, es decir veo si se efectuan ciertos eventos o cambios (?)
			if(evt.type == Event::Closed) /// si el tipo del objeto evt (clase Event) es igual al metodo de Event cerrado
				w.close();/// cierra el renderizado de la pantalla w
		} /// en este loop se compara el tipo de evento con los eventos externos ej (mover el mouse, Joystick desconectado, entrada de texto(ver Event::))
		
		w.clear(color);/// borra el fondo de la ventana (el que es de un determ color)
		
		
		
		for(int i= 0 ;i< (30) ;i++) { 
			for(int j= 0 ;j< (40) ;j++) { 
				//TextureBloq Bloq(a.Ver_Matriz_Bloques()[i][j]);
				//Mat_Bloq[i][j] = M_Bloq[y1 + i][x1 + j].NomBloq();
				//Mat_Bloq[i][j] = a.Ver_Matriz_Bloques()[y1 + i][x1 + j]);
				
				//Mat_Bloq[i][j] = a.Ver_Matriz_Bloques()[i][j];
				
				//Mat_Bloq[i][j].Inicializar(a.Ver_Matriz_Bloques()[i+y][j+10+x]);
				Mat_Bloq[i][j].Inicializar(a.Ver_Matriz_Bloques()[i][j]);
			}
		}
		
		for(int i= 0 ;i< (30) ;i++) { 
			for(int j= 0 ;j< (40) ;j++) { 
				Mat_Bloq[i][j].PosSpr(i,j);
				//TextureBloq Tex_Bl(Mat_Bloq[i][j]);
			}
		}
		
		
			/**FONDO**/
		w.draw(Fondo1.Vs()); /// Dibuja el sprite del objeto tipo  TexturePer  "Fondo1"(textura)
		w.draw(Fondo2.Vs());
		w.draw(Fondo3.Vs());
		w.draw(Fondo4.Vs());
		w.draw(Fondo5.Vs());
		
		for(int i= 0 ;i< (30) ;i++) { 
			for(int j= 0 ;j< (40) ;j++) { 
				//Mat_Bloq[i][j].PosSpr(i,j);
				//TextureBloq Tex_Bl(Mat_Bloq[i][j]);
				w.draw(Mat_Bloq[i][j].GeneradorSpr(i,j));
			}
		}
		/*
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
			w.draw(Mat_Bloq[i][j].GeneradorSpr(i,j));
		}};
		*/
		
		w.draw(Per.Vs()); /// Dibuja el sprite del objeto tipo  TexturePer "Per"(textura), es decir dibuja al personaje
		w.display(); /// los ejecuta en el renderizado de la pantalla
		
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Left)){ /// veo si el teclado esta presionado y le paso de parametro el metodo Key de Keyboard
			x++;
			Fondo1.Pos(x*1.2,0 ); /// cambio la posicion de los distintos fondos
			Fondo2.Pos(x*1.4,0 ); /// cambio la posicion del fondo que va por delante mas que el que va por atras, sucesivamente 
			Fondo3.Pos(x*1.6,0 );
			Fondo4.Pos(x*1.8,0);
			Fondo5.Pos(x*2,0 ); /// la variacion entre el cambio de posicion de los fondos brinda la sensacion de movimiento y tridimensionalidad
			
		/*	Per.Pos(xp,yp);
			///if(tam_x < 0) Per.Tam(-tam_x, tam_y);
			Per.Tam(tam_x, tam_y);*/
			
			for(int i=0;i<50;i++) { 
				for(int j=0;j<50;j++) { 
					Mat_Bloq[i][j].Mov(i,-j+x,i,j);
				}
			}
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Right)){ /// Keyboard (clase de entrada de SFML)
			x--;
			Fondo1.Pos(x*1.2,0 );/// actualizo la posicion del Fondo
			Fondo2.Pos(x*1.4,0 );
			Fondo3.Pos(x*1.6,0 );
			Fondo4.Pos(x*1.8,0);
			Fondo5.Pos(x*2,0 );
	
			for(int i=0;i<50;i++) { 
				for(int j=0;j<50;j++) { 
					Mat_Bloq[i][j].Mov(i,j+x,i,j);
				}
			}
			
			
			/*Per.Pos(xp,yp);
			if(tam_x > 0) Per.Tam(-tam_x, tam_y);*/
		}
	}}


/*while(w.isOpen()) {
while(w.pollEvent(evt)) {
if(evt.type == Event::Closed)
w.close();}

w.display();
}}*/
