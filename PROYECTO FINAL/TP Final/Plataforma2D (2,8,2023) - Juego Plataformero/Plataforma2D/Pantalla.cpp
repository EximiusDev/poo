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
#include "Vida.h"
#include "GameOver.h"
#include "Menu.h"
#include "Teclado.h"
using namespace sf;
using namespace std;


Pantalla::Pantalla():wind(VideoMode(1280,720),"GoodWizard"){}

void Pantalla::Start(){

	int SpriteActual;						///Sirve para el Sprite
	int TeclaPresionada=3;					///Sirve para saber y enviar que tecla se apreto
	int LimitSprPAnim;						///Limites de Assets por animacion 
	int x=0;								///Posicion Inicial x
	int y=300;								///Posicion Inicial x
	int limSalto=300;
	int Piso=-1;
	int TeclaPress;	
	
		/**CREACION PERSONAJE**/
	CrearSprite Spr;
		
		/**CREACION DEL MUNDO**/
	int cantBloques =100;
	CrearMundo Mundo(cantBloques);
	
	
	
		/**CREACION DEL FONDO**/
	CrearFondo Fondo;
	
	Colision Col;
	
	Vida Vid;
	
	GameOver GO;
	
	Menu Men;
	
	Mouse Mus;
	
	Keyboard KeyB;
	
	Teclado TecL;
	
	bool Cayendo=false;
	bool Flip =false;

	bool Saltando;
	bool inicioSalto=false;
	bool Colisiona=false;
	bool Perdio=false;
	bool Click;
	bool HoverSalir;
	bool HoverNuevoJuego;
	bool HoverContinuar;
	bool HoverReiniciar;
	///Rect<int> a(x,y,w,h);
	
	
	Vector2i r1 = Mus.getPosition(wind);
	
	Rect<int>Boton1(329,411,544,63);
	
	Rect<int>HitBox(0,1100,1920,96);
	
	vector<Rect<int>>HitB;
	
	HitB.resize(100);
	
	for(int i=0;i<100;i++) { 
		Rect<int>A(i*96,604,96,96);
		HitB.push_back(A);
	}
	///Proximo paso, guardar ubicacion y terminar mapa, poner pinchos pa que sea obligatorio saltar
	
	
	
	
	
	
	
	
	
	
	//Rect<int>HitBoxPer(175,120+yper,340-175,400-120);

	//if(HitBox.Contains(HitBoxPer.top,HitBoxPer.left)){chocaPiso=true;}
	
	wind.setFramerateLimit(30);

	
	/**Comienza el while**/
	while(wind.isOpen()) {
	Vector2i r1 = Mus.getPosition(wind);

		
		/**LOOP DE EVENTOS**/
		Event evt;

		while(wind.pollEvent(evt)) {
			if(evt.type == Event::Closed)wind.close();}
		wind.clear(Color(255,255,255,255));
		wind.draw(Men.Men());
		wind.draw(Men.NuevoJuego());
		wind.draw(Men.Continuar());
		wind.draw(Men.Salir());
		HoverSalir = false;
		HoverNuevoJuego= false;
		
		
	TeclaPress=TecL.Tecla(KeyB);
		
	if(Men.NuevoJuego().getGlobalBounds().contains(r1.x,r1.y)){HoverNuevoJuego= true;
				if(Mus.isButtonPressed(Mus.Left))Click= true;
			}
						
			
			if(Men.Salir().getGlobalBounds().contains(r1.x,r1.y)){
				HoverSalir = true;
				if(Mus.isButtonPressed(Mus.Left)){wind.close();}}
			if(HoverSalir){Men.ColS(200,200,200);}else{Men.ColS(255,255,255);}
			if(HoverNuevoJuego){Men.ColNJ(200,200,200);}else{Men.ColNJ(255,255,255);}
			
		if(Click){
		//if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){wind.close();}
				
			
				if(!Perdio){
				
				switch(TeclaPress){
				case 3:Flip=true;LimitSprPAnim=21;TeclaPresionada =1;if(x <= 0){x++;Fondo.setMov(x);Mundo.setMov(x);}break;
				case 4:Flip=false;LimitSprPAnim=21;TeclaPresionada =1;x--;Fondo.setMov(x);Mundo.setMov(x);break;
				case 0:LimitSprPAnim=21;TeclaPresionada =3;break;}
		
				
				
				
		
		
			
			
			
			if(HitBox.contains(Spr.getxR()+130,Spr.gety()+200)){
				if(!Vid.pierdeVida()){
					x=0;
					y=300;
					Fondo.setMov(x);Mundo.setMov(x);
				}else{
					
					Perdio=true;
				}
			}
			
			
			
			if(Keyboard::isKeyPressed(Keyboard::Key::Space) && !Cayendo){
				if(inicioSalto==false){
					inicioSalto=true;
					Piso=y;
				}
				
				if(limSalto>-y+Piso){
					if (Keyboard::isKeyPressed(Keyboard::Key::Right)){Flip=false;}
					if (Keyboard::isKeyPressed(Keyboard::Key::Left)){Flip=true;}
					
					LimitSprPAnim=8;TeclaPresionada =2;
					y=y-10;Spr.setPos(300,y);
					Cayendo=false;
					
				}else{Cayendo=true;};
			}else{Cayendo=true;Saltando=false;}if(Cayendo){inicioSalto=false;}
			Colisiona=false;
			for(int i=0;i<100;i++) {if(Mundo.Colide(i).contains(Spr.getxR()+130,Spr.gety()+200)){Colisiona=true;}  }
			if(!Colisiona&&Cayendo){
				LimitSprPAnim=8;TeclaPresionada =2;
				y=y+10;Spr.setPos(300,y);
				if (Keyboard::isKeyPressed(Keyboard::Key::Right)){Flip=false;}
				if (Keyboard::isKeyPressed(Keyboard::Key::Left)){Flip=true;}
			
				Cayendo=true;}else{Cayendo=false;}

			/** DIBUJO LA PESTANIA**/
			
			for(int i=1;i<6;i++) { 	wind.draw(Fondo.getSpr(i)); }
			
			for(int i=0;i<cantBloques;i++) {wind.draw(Mundo.getSpr2(i));}
		
			if(Vid.getVida()==3){
				wind.draw(Vid.sgSpriteFull(1));
				wind.draw(Vid.sgSpriteFull(2));
				wind.draw(Vid.sgSpriteFull(3));
			}else{
				  if(Vid.getVida()==2){
			wind.draw(Vid.sgSpriteFull(1));
			wind.draw(Vid.sgSpriteFull(2));
			wind.draw(Vid.sgSpriteVoid(3));}else{
					  
			wind.draw(Vid.sgSpriteFull(1));
			wind.draw(Vid.sgSpriteVoid(2));
			wind.draw(Vid.sgSpriteVoid(3));
				  }}
	
			SpriteActual++ ;if(SpriteActual>=LimitSprPAnim){SpriteActual=1;}; /// Uso este "SpriteActual" para ver que sprite usar y usar uno por frame
			switch(TeclaPresionada){
			case 1:
				wind.draw(Spr.getSprW(SpriteActual,Flip));
				break;
			case 2:
				wind.draw(Spr.getSprJ(SpriteActual,Flip));
				break;
			case 3:
				wind.draw(Spr.getSprI(SpriteActual,Flip));
				break;}}else{
				
				//Vector2i r2 = GO.Perdio().getPosition();
	
				
			
				
				
				
				wind.draw(GO.Perdiste());
				wind.draw(GO.Salir());
				wind.draw(GO.Reiniciar());
				HoverReiniciar= false;
				HoverSalir= false;
				if(GO.Reiniciar().getGlobalBounds().contains(r1.x,r1.y)){
					HoverReiniciar= true;
					if(Mus.isButtonPressed(Mus.Left)){
						Vid.Reinicio();
						Perdio =false;
					}
					//if(HoverSalir){Men.ColS(200,200,200);}else{Men.ColS(255,255,255);}
				}
				if(HoverReiniciar){GO.ColR(150,150,150);}else{GO.ColR(255,255,255);}
				HoverSalir= false;
				if(GO.Salir().getGlobalBounds().contains(r1.x,r1.y)){
					HoverSalir= true;
				}
				if(HoverSalir){GO.ColS(150,150,150);}else{GO.ColS(255,255,255);}
			}}
			
			wind.display();}
			
	
		
		
		

	






}
