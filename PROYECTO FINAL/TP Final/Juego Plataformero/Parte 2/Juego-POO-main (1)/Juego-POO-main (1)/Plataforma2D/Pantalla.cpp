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
#include "Colision.h"




using namespace sf;
using namespace std;
Pantalla::Pantalla():wind(VideoMode(1920,1080),"Plataforma2D"){}

void Pantalla::Start(){
	int k;
	int Cont=3;
	int n;
	int x=0;
	int y=300;
	int limSalto=300;
	int Piso=-1;
		
	
		/**CREACION PERSONAJE**/
	CrearSprite Spr;
		
		/**CREACION DEL MUNDO**/
	int cantBloques =100;
	CrearMundo Mundo(cantBloques);
	
	
	
		/**CREACION DEL FONDO**/
	CrearFondo Fondo;
	
	Colision Col;
	
	
	bool Cayendo=false;
	bool Flip =false;
	bool Left =false;
	bool Right =false;
	bool AirMov =false;
	bool Saltando;
	bool inicioSalto=false;
	bool Colisiona=false;
	///Rect<int> a(x,y,w,h);
	
	

	

	
	Rect<int>HitBox(0,804,1920,96); ///(posicion en x, y , tamaño en x, y)
	vector<Rect<int>>HitB;
	HitB.resize(100);
	for(int i=0;i<100;i++) { 
		Rect<int>A(i*96,604,96,96);
		HitB.push_back(A);
	}
	
	
	
	
	
	
	
	
	
	
	
	//Rect<int>HitBoxPer(175,120+yper,340-175,400-120);

	//if(HitBox.contains(HitBoxPer.top,HitBoxPer.left)){chocaPiso=true;}
	
	wind.setFramerateLimit(30);

	
	/**Comienza el while**/
	while(wind.isOpen()) {
	
		
		
		/**LOOP DE EVENTOS**/
		Event evt;
		while(wind.pollEvent(evt)) {
			if(evt.type == Event::Closed)wind.close();}
		
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){wind.close();}

				/**Si presiono hacia la izquier**/
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)&&AirMov) {
				Left=true;
				Flip=true;
				/**Movimientos**/
				n=21;Cont =1;if(x <= 0){x++;Fondo.setMov(x);Mundo.setMov(x);}
				
				/**SI PRESIONO A LA DERECHA**/
				}else{if (Keyboard::isKeyPressed(Keyboard::Key::Right)&&AirMov) {
				Flip=false;
				Left=false;
				Right=true;
				
					
				/**Movimientos**/
				n=21;Cont =1;x--;Fondo.setMov(x);Mundo.setMov(x);}else{Left=false;Right=false;n=21;Cont =3;}}
			
			if(Keyboard::isKeyPressed(Keyboard::Key::Space)&&!Cayendo){
				if(inicioSalto==false){
					inicioSalto=true;
					Piso=y;
				}
				if(limSalto>-y+Piso){
					if (Keyboard::isKeyPressed(Keyboard::Key::Right)){Flip=false;}
					if (Keyboard::isKeyPressed(Keyboard::Key::Left)){Flip=true;}
					if(!Left&&!Right){AirMov =false;}
					n=8;Cont =2;
					y=y-10;Spr.setPos(300,y);
					Cayendo=false;
					
				}else{Cayendo=true;};
				}else{Cayendo=true;Saltando=false;}if(Cayendo){inicioSalto=false;}
				Colisiona=false;
			for(int i=0;i<100;i++) {if(Mundo.Colide(i).contains(Spr.getxR()+130,Spr.gety()+200)){Colisiona=true;}  }
			if(!Colisiona&&Cayendo){
				n=8;Cont =2;
				y=y+10;Spr.setPos(300,y);
				if (Keyboard::isKeyPressed(Keyboard::Key::Right)){Flip=false;}
				if (Keyboard::isKeyPressed(Keyboard::Key::Left)){Flip=true;}
				if(!Left&&!Right){AirMov =false;}
				Cayendo=true;}else{Cayendo=false;}
			if(!Cayendo&&!Saltando){AirMov=true;}
				/** DIBUJO LA PESTANIA**/
			wind.clear(Color(255,255,255,255));
			for(int i=1;i<6;i++) { 	wind.draw(Fondo.getSpr(i)); }
			for(int i=0;i<cantBloques;i++) { wind.draw(Mundo.getSpr1(i));wind.draw(Mundo.getSpr2(i));}
			k++ ;if(k>=n){k=1;};
			switch(Cont){
			case 1:
				wind.draw(Spr.getSprW(k,Flip));
				break;
			case 2:
				wind.draw(Spr.getSprJ(k,Flip));
				break;
			case 3:
				wind.draw(Spr.getSprI(k,Flip));
				break;}
			
			
			wind.display();}
			
	
		
		
		

	






}
