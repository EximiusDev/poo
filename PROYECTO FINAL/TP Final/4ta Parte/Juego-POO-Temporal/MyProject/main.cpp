#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
			/**CREAR VENTANA**/
	VideoMode vm(1920,1080); ///Tamanio
	RenderWindow win(vm, "Super Juego"); ///Nombre de la pantalla
	Color color_fondo(255,255,255); ///COLOR DEL FONDO
	
			/**CARGAR IMAGEN**/
		Texture tex;
		if (! tex.loadFromFile("image.png") )
			cerr << "No se pudo cargar" << endl;
			
			/**DEFINIR POSICION INICIAL**/
	Sprite spr;
	spr.setTexture(tex); ///Le da a spr la textura q subi en texture
	///spr.setPosition(100, 1000); 	spr.setPosition(0,0);/// Lo ubica en tal posicion
	spr.setScale(1.0,1.0);///Escala
	spr.setRotation(0);///Rotacion
	spr.setColor(Color(255,255,255,255));///Color
	
	
	 /***PRUEBA***/
	Sprite V;
	vector<Texture>V1(3);
	
	V1[0].loadFromFile("2.png");
	V.setTexture(V1[0]);
	V.setPosition(0,0);
	bool a=true; bool b= true;
	V.setColor(Color(255,255,255,0));
			/**LOOP DE EVENTOS**/
	while(win.isOpen()) {
		
		Event evt; ///Creo un evento
		while(win.pollEvent(evt)) {
			if(evt.type == Event::Closed) ///Si se cierra cerrar la ventana
				win.close();
		}
			/**MOVIMIENTO**/
		///spr.move(1,1);
		
			/**REDIBUJAR TODO**/
		win.clear(color_fondo);///Vuelve a pintar el fondo
		win.draw(V);
		win.draw(spr);///Pega la imagen
		
		win.display();
		///spr.setPosition(100,100);///PUEDO MODIFCAR LA POSICION ASI XD
		
	
		
			while(b){
				while(win.pollEvent(evt)) {
					if(evt.type == Event::Closed) ///Si se cierra cerrar la ventana
						win.close();
				
				if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
					
					
					if (a){
						spr.setColor(Color(255,255,255,0));
						V.setColor(Color(255,255,255,255));
						a=false;
					}else{
						spr.setColor(Color(255,255,255,255));
						V.setColor(Color(255,255,255,0));
						a=true;
					}
					
					
				}
				}	
			}
			
		
		
		
	}
	
	
	
	
	
	
	
	return 0;
}

