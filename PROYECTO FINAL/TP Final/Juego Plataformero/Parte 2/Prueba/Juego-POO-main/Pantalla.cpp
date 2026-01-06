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

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Texto.h"

using namespace sf;
using namespace std;
Pantalla::Pantalla():wind(VideoMode(1280,720),"GoodWizard"){}

void Pantalla::Start(){
	int k;
	int Cont=3;
	int n;
	int x=0;
	int y=300;
	int limSalto=300;
	int Piso=-1;
	
	int distancia_recorrida = 0;
	
		/**CREACION PERSONAJE**/
	CrearSprite Spr;
		
		/**CREACION DEL MUNDO**/
	int cantBloques =100;
	CrearMundo Mundo(cantBloques);
	vector<int> Spawn_Enemigo = Mundo.Ver_Spawn_Enem();
	
	/** CREACION DEL TEXTO **/
	Texto Texto1;
	
	
		/**CREACION DEL FONDO**/
	CrearFondo Fondo;
	
	Colision Col;
	
	Vida Vid;
	
	GameOver GO;
	
	Menu Men;
	
	Mouse Mus;
	bool Cayendo=false;
	bool Flip =false;
	bool Left =false;
	bool Right =false;
	bool AirMov =false;
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
	
	
	
	
	
	
	
	
	
	
	
	//Rect<int>HitBoxPer(175,120+yper,340-175,400-120);

	//if(HitBox.contains(HitBoxPer.top,HitBoxPer.left)){chocaPiso=true;}
	
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
			
			
			
			if(HitBox.contains(Spr.getxR()+130,Spr.gety()+200)){
				if(!Vid.pierdeVida()){
					x=0;
					y=300;
					Fondo.setMov(x);Mundo.setMov(x);
				}else{
					
					Perdio=true;
				}
			}
			
			
			
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
			
			
			for(int i=1;i<6;i++) { 	wind.draw(Fondo.getSpr(i)); }
			for(int i=0;i<cantBloques;i++) {
				wind.draw(Mundo.getSpr2(i));
				if(Spawn_Enemigo[i] != -1) wind.draw(Mundo.getSpr_En(i));
			}
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
			
			
			/// //////////////////////////////////////////////////////
			//Texto1.Dibujar_Pant(RenderWindow & wind);
			//Texto1->Dibujar_Pant(wind);
			
			///if (-x > distancia_recorrida) distancia_recorrida = -x;
			///if (x < distancia_recorrida) distancia_recorrida = x;
			//string Dist_rec = "aaaaa";
			//string Dist_rec = to_string(  distancia_recorrida );
			string Dist_rec = to_string(  -x );
			Texto1.Set_oracion( Dist_rec );
			Texto1.Dibujar_Pant(wind);
			//wind.draw( Texto1.Get_Texto() );
			//m_esc->dibujar(m_win);
			
			}else{
				
				//Vector2i r2 = GO.Perdio().getPosition();
	
				
			
				
				
				
				wind.draw(GO.Perdiste());
				wind.draw(GO.Salir());
				wind.draw(GO.Reiniciar());
				HoverReiniciar= false;
				if(GO.Reiniciar().getGlobalBounds().contains(r1.x,r1.y)){
					HoverReiniciar= true;
					if(Mus.isButtonPressed(Mus.Left)){
						Vid.Reinicio();
						Perdio =false;
					}
					//if(HoverSalir){Men.ColS(200,200,200);}else{Men.ColS(255,255,255);}
				}
				if(HoverReiniciar){GO.ColR(150,150,150);}else{GO.ColR(255,255,255);}
			}}
			
			wind.display();}
			
	
		
		
		

	






}
