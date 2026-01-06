#include <SFML/Graphics.hpp>
#include "InputText.hpp"

/**
* La clase InputBox sirve para facilitar la entrada de texto en una ventana de sfml-2.x.
* Hereda de sf::Text, así que se usa como un sf::Text. 
* 	- Se lo crea, pasandole opcionalmente una fuente, un tamaño y un color, o
*     definiendolos luego con los métodos de sf::Text como setFont, setFillColor,
*     setPosition, setCharacterSize, etc.
* 	- Se lo dibuja con el método draw de la ventana igual que los demás textos y
*     sprites.
* 	- Las diferencias con un sf::Text son:
*       - hay que pasarle los eventos del bucle de eventos mediante el método 
* 	      processEvent.
* 	    - Además, antes de dibujarlo hay que llamar a su método update, en caso
* 	      contrario no se verá nada.
* 	
* 	Ejemplode uso:
*				...
*			// crear una instancia
* 			InputText text_entrada(font, 30, sf::Color::Black);
* 			text_entrada.setPosition(120, 50);
*				...
* 			// bucle principal
* 			while (w.isOpen()) { // w seria la ventana
* 				// procesar eventos
* 				Event e;
* 				while (w.pollEvent(e)) {
* 					if (text_entrada.processEvent(e)) { } // si retorna true, es porque procesó el evento
* 					else if (e.type == ....
* 					...
* 				}
* 				// actualizar
* 				text_entrada.update(); // para que el texto se actualice correctamente 
* 				...
* 				// dibujar
*               w.clear(sf::Color(255,255,255,255));
* 				w.draw(text_entrada);
* 				...
* 				w.display();
* 			}
**/

int main(int argc, char *argv[]){
	
	// crea una ventana
	sf::RenderWindow w(sf::VideoMode(640,480),"Ejemplo de SFML");
	
	// cargar una fuente para los textos
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	// crear un texto comun
	sf::Text text_comun("Ingrese una palabra (hasta 10 letras):",font);
	text_comun.setCharacterSize(25);
	text_comun.setFillColor(sf::Color::Blue);
	text_comun.setPosition(100,20);
	
	// crear otro texto comun
	std::string palabras="Palabras ingresadas:";
	sf::Text text_palabras(palabras,font);
	text_palabras.setCharacterSize(25);
	text_palabras.setFillColor(sf::Color::Red);
	text_palabras.setPosition(100,100);
	
	// texto que ingresa el usuario
	InputText text_entrada(font,30,sf::Color::Black);
	text_entrada.setPosition(120,50);
	text_entrada.setMaxChars(10); // no mas de 10 caracteres
	text_entrada.setSingleWord(true); // no permitir ingresar espacios, para que sea solo una palabra
		
	// bucle principal
	while(w.isOpen()) {
		
		// procesar eventos
		sf::Event e;
		while(w.pollEvent(e)) {
				if(e.type == sf::Event::Closed) {
					w.close();	
				} else if (e.type==sf::Event::KeyPressed && e.key.code==sf::Keyboard::Return) { // si apretó enter, se toma la palabra y se la agrega a la lista
					std::string string_ingresado = text_entrada.getValue(); // obtener la palabra que se ingresó
					palabras += "\n\t"; palabras += string_ingresado;
					text_palabras.setString(palabras);
					text_entrada.reset(); // reiniciar la entrada para tomar otra palabra
				} else text_entrada.processEvent(e); // para que el texto procese las demás teclas que pulsamos
		}
		
		// actulizar
		text_entrada.update(); // para que el texto se dibuje correctamente (hay que hacer esta llamada despues de processEvent y antes del draw)
		
		// dibujar
		w.clear(sf::Color(255,255,255,255));
		w.draw(text_comun);
		w.draw(text_entrada);
		w.draw(text_palabras);
		w.display();
	}
	return 0;
}

