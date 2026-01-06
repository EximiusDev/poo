#include "Pantalla.h"
#include "Character.h"
#include <SFML/Window/Event.hpp>
#include <windows.h>
#include <iostream>
#include "Background.h"
#include "Bloques.h"
using namespace sf;
using namespace std;
Pantalla::Pantalla():wind(VideoMode(1920,1080),"Plataforma2D"){}
//Pantalla::Pantalla():wind(VideoMode(1280,720),"Plataforma2D"){}

void Pantalla::Start(){
	
	string P=".png";
	string P1="Walk";
	int i=1;
	int milesima_de_segundo=30,s=1;
	Character Per;
	int cantBloques =100;
	vector<Background> Backg(6);
	bool chocaPiso;
	int x=0;
	int xpos=300;
	int ypos=600;
	int yper=200;
	int y_auxper=200;
	int x_auxper=300;
	bool Space=false;
	bool Caida=false;
	
	bool tecla_izq = false;
	bool tecla_der = false;
	bool tecla_espacio = false;
	/*bool tecla_arriba = false;
	bool tecla_abajo = false;
	*/
	
	for(int i=1;i<6;i++) { 
		Backg[i].createBackg("B"+to_string(i)+P); 
	}
	vector<Bloques>Tierra(cantBloques);
	vector<Bloques>Tierra1(cantBloques);
	for(int i=1;i<cantBloques;i++) { 
		Tierra[i].Start("Tierra.png");
		Tierra1[i].Start("Tierra2.png");
		Tierra1[i].setPos(i*96,804);
		Tierra[i].setPos(i*96,900);
	}
	
		
	Per.setPos(xpos,ypos);
	wind.setFramerateLimit(30);
	/**Comienza el while**/
	while(wind.isOpen()) {
		
		Event evt;
		while(wind.pollEvent(evt)) {
			
				if(evt.type == Event::Closed)
					wind.close();	
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Key::Left)){tecla_izq = true;}
		else tecla_izq = false;
		if (Keyboard::isKeyPressed(Keyboard::Key::Right)){tecla_der = true;}
		else tecla_der = false;
		if (Keyboard::isKeyPressed(Keyboard::Key::Space)){tecla_espacio = true;}
		else tecla_espacio = false;
		
		
		
			chocaPiso=false;
			//Sleep(milesima_de_segundo);
			for(int i=0;i<cantBloques;i++) { 
				FloatRect r1 = Per.getSpr().getGlobalBounds();
				FloatRect r2 = Tierra1[i].getSpr().getGlobalBounds();
				if(r1.intersects(r2)){
					chocaPiso=true;
				}
			}
			if(!chocaPiso&&!Space){
				yper=yper+30;
				Per.setPos(xpos,yper);
				//yper=yper-30;
				Caida=true;}
			else{Caida=false;}
			

			if (Keyboard::isKeyPressed(Keyboard::Key::Space)&&!Caida) {
				yper=yper-15;
				Per.setPos(xpos,yper);
				Space=true;
				if( y_auxper*2-yper>=200){
					Space=false;
				}
				
			}else{Space=false;}
			
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
				i++; if(i==21){i=1;};
				
				string P2=P1+to_string(i)+P;
				Per.createSpr(P2,-0.5,0.5);
				
				if(Space || Caida){
					xpos = xpos + 280;
					Per.setPos(xpos,yper);
					xpos = xpos - 280;
				}
				else{
					/*
					xpos = xpos + 280;
					Per.setPos(xpos,yper);
					xpos = xpos - 280;
					*/
				}
				
				if(x <= 0){
					x++;
					for(int j=1;j<7;j++) { Backg[j].setPos(x*j,0); };
					for(int i=0;i<cantBloques;i++) { 
						Tierra1[i].setPos(i*96+x*10,804);
						Tierra[i].setPos(i*96+x*10,900);
					}
				}
			}else{if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
				
			i++; if(i==21){i=1;};
			string P2=P1+to_string(i)+P;
			Per.createSpr(P2,0.5,0.5);
			
			Per.setPos(xpos,yper);
				
					x--;
					for(int j=1;j<7;j++) { Backg[j].setPos(x*j,0); }
					for(int i=0;i<cantBloques;i++) { 
						Tierra1[i].setPos(i*96+x*10,804);
						Tierra[i].setPos(i*96+x*10,900);
					}
			
			}else{
				i++; if(i==21){i=1;};	
				Per.createSpr(to_string(i)+P,0.5,0.5);
				
				
			}}
			
			
			
		
			
			wind.clear(Color(255,255,255,255));
			for(int i=1;i<6;i++) { 	wind.draw(Backg[i].getSpr()); }
				
			for(int i=0;i<cantBloques;i++) { 
				wind.draw(Tierra[i].getSpr());
				wind.draw(Tierra1[i].getSpr());
			}
				
			
			wind.draw(Per.getSpr());
			wind.display();}
			
	
		
		
		

	






}
