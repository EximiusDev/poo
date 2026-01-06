#include "Pantalla.h"
#include "Character.h"
#include <SFML/Window/Event.hpp>
#include <windows.h>
#include <iostream>
#include "Background.h"
using namespace sf;
using namespace std;

//int res_x = 1920, res_y = 1080;
int res_x = 1280, res_y = 720;

//Pantalla::Pantalla():wind(VideoMode(1920,1080),"MyGame"){}
Pantalla::Pantalla():wind(VideoMode(res_x,res_y),"MyGame"){}

void Pantalla::Start(){
	
	string P=".png";
	string P1="Walk";
	int i=1;
	int milesima_de_segundo=30,s=1;
	Character Per;
	vector<Background> Backg(6);
	
	//Vector2f a= Backg[1].getSpr().getPosition();

	//Vector2f a1(0,0);
	
	
	vector<Background> Backg2(6);
	vector<bool> back2(6);
	//Vector2f a2= Backg[1].getSpr().getPosition();
	//Vector2f a3(0,0);
	
	int x=0;
	
	for(int i=1;i<6;i++) { 
		Backg[i].createBackg("B"+to_string(i)+P); 
		Backg2[i].createBackg("B"+to_string(i)+P);
		back2[i] = false;
	}
	
	
	wind.setFramerateLimit(30);
	/**Comienza el while**/
	while(wind.isOpen()) {
		
		Event evt;
		while(wind.pollEvent(evt)) {
			
				if(evt.type == Event::Closed)
					wind.close();	
		}
		
		
			
			//Sleep(milesima_de_segundo);
			
					
			
			
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
				i++; if(i==21){i=1;};
				
				string P2=P1+to_string(i)+P;
				Per.createSpr(P2,-0.5,0.5);
				Per.setPos(450,600);
				if(x <= 0){
					x++;
					for(int j=1;j<7;j++) { Backg[j].setPos(x*j,0); };
				}
			}else{if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
				
			i++; if(i==21){i=1;};
			string P2=P1+to_string(i)+P;
			Per.createSpr(P2,0.5,0.5);
			
			
					x--;
					for(int j=1;j<7;j++) { 
						if (x*j <= -320*6.75 + res_x){
							Backg[j].setPos(x*j + 320*6.75,0);
							Backg2[j].setPos(x*j + 320*6.75,0);
							Backg2[j].setSca(-6.75 ,6.75);
							//back2[j] = true;
							/*if (x <= -640){
								x = x + 320;
							}*/
						}
						else {
							Backg[j].setPos(x*j,0);
							//back2[j] = false;
						}
					}
				
			
			}else{
				i++; if(i==21){i=1;};	
				Per.createSpr(to_string(i)+P,0.5,0.5);
				
				
			}}
			
			for(int j=1;j<7;j++) { 
				if (x*j <= -320*6.75 + res_x){
					
					back2[j] = true;
				}
				else back2[j] = false;
			}
			
			
			wind.clear(Color(255,255,255,255));
			for(int i=1;i<6;i++) { 	
				wind.draw(Backg[i].getSpr());
				if (back2 [i]== true) wind.draw(Backg2[i].getSpr()); 
			}
			
			
			
			wind.draw(Per.getSpr());
			wind.display();}
			
	
		
		
		

	






}
