#include "Pantalla.h"
#include "Character.h"
#include <SFML/Window/Event.hpp>
#include <windows.h>
#include <iostream>
#include "Background.h"
#include "Bloques.h"
#include <SFML/Graphics/Rect.hpp>
#include "CrearMundo.h"
#include "CrearFondo.h"
#include "CrearSprite.h"


/**ERRORES E CORREGIR: AL SALTAR NO VOLTEA,AL SALTAR TE PODE MOVER**/

using namespace sf;
using namespace std;
Pantalla::Pantalla():wind(VideoMode(1920,1080),"Plataforma2D"){}

void Pantalla::Start(){
	int k;
	int Cont;
	int n;
	int x=0;
	int y=100; // no importa la variable de entrada
	int lim_salto = 200;
	int piso = -1;
	bool inicio_salto = false;
	
		/**CREACION PERSONAJE**/
	CrearSprite Spr;
	
		/**CREACION DEL MUNDO**/
	int cantBloques =100;
	CrearMundo Mundo(cantBloques);
	
	
	
		/**CREACION DEL FONDO**/
	CrearFondo Fondo;
	
	
	
	
	bool Cayendo=false;
	
	
	
	///Rect<int> a(x,y,w,h);
	
	

	

	
	Rect<int>HitBox(0,804,1920,96);
	
	
	
	
	
	
	
	
	
	
	
	
	
	//Rect<int>HitBoxPer(175,120+yper,340-175,400-120);

	//if(HitBox.contains(HitBoxPer.top,HitBoxPer.left)){chocaPiso=true;}
	
	wind.setFramerateLimit(30);

	
	/**Comienza el while**/
	while(wind.isOpen()) {
		
		/**LOOP DE EVENTOS**/
		Event evt;
		while(wind.pollEvent(evt)) {
			if(evt.type == Event::Closed)wind.close();}
		
		
		
			
		
			/*chocaPiso=false;
		
		
		
			
			/*for(int i=0;i<cantBloques;i++) { 
		
		
				FloatRect r1 = Per.getSpr().getGlobalBounds();
				FloatRect r2 = Mundo.getSpr1(i).getGlobalBounds();
				if(r1.intersects(r2)){
					chocaPiso=true;
				}
				
			}
		
			/*if(!chocaPiso&&!Space){
				yper=yper+30;
				Caida=true;}
			else{Caida=false;}
			
			if (Keyboard::isKeyPressed(Keyboard::Key::Z)&&!Caida) {
				
				n=8;
				
				yper=yper-15;
				Per.setPos(xpos,yper);
				Space=true;
				if(auxyper*2-yper>=200){
					Space=false;
				}
				
			}else{Space=false;} 
			
			/*if (Keyboard::isKeyPressed(Keyboard::Key::Z)) {
				xpos=xpos+100;
				Per.setPos(xpos,yper);
			}*/
				
				
				/**Si presiono hacia la izquier**/
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
				
				/*/**SALTO*
				if (Keyboard::isKeyPressed(Keyboard::Key::Z)&&!Caida) {
					yper=yper-15;
					Per.setPos(xpos,yper);
					Space=true;
					if(auxyper*2-yper>=200){
						Space=false;
					}
					
				}else{Space=false;}*/
				
			
				
				/**Movimientos**/
				n=21;Cont =1;if(x <= 0){x++;Fondo.setMov(x);Mundo.setMov(x);}
				
				/**SI PRESIONO A LA DERECHA**/
			}
			else{
				if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
				
				/*SALTO*
				if (Keyboard::isKeyPressed(Keyboard::Key::Z)&&!Caida) {
					yper=yper-15;
					Per.setPos(xpos,yper);
					Space=true;
					if(auxyper*2-yper>=200){
						Space=false;
					}
					
				}else{Space=false;} */
				
			
				
				
					
				/**Movimientos**/
				n=21;Cont =2;x--;Fondo.setMov(x);Mundo.setMov(x);}
				else{n=21;Cont =4;}
			}
			
			if(Keyboard::isKeyPressed(Keyboard::Key::Space)&&!Cayendo){
				if(inicio_salto == false){
					inicio_salto = true;
					piso = y;
				}
				
				if (lim_salto > - y + piso){
					n=8;Cont =3;
					y=y-10;Spr.setPos(300,y);
					Cayendo=false;
				}
				else{Cayendo=true;}
			}
			else{Cayendo=true;}
			if(Cayendo==true){
				inicio_salto = false;
			}
			
			if(!HitBox.contains(Spr.getxR()+170,Spr.gety()+200)&&Cayendo){
				n=8;Cont =3;
				y=y+10;Spr.setPos(300,y);
				
				Cayendo=true;
			}
			else{Cayendo=false;}
			
				/** DIBUJO LA PESTANIA**/
			wind.clear(Color(255,255,255,255));
			for(int i=1;i<6;i++) { 	wind.draw(Fondo.getSpr(i)); }
			for(int i=0;i<cantBloques;i++) { wind.draw(Mundo.getSpr1(i));wind.draw(Mundo.getSpr2(i));}
			k++ ;if(k>=n){k=1;};
			switch(Cont){
			case 1:
				wind.draw(Spr.getSprWL(k));
				break;
			case 2:
				wind.draw(Spr.getSprWR(k));
				break;
			case 3:
				wind.draw(Spr.getSprJ(k));
				break;
			case 4:
				wind.draw(Spr.getSprI(k));
				break;}
			
			
			wind.display();}
			
	
		
		
		

	






}
