#ifndef INPUTBOX_H
#define INPUTBOX_H

#include <SFML/Graphics.hpp>
#include <string>

/**
* Esta clase sirve para facilitar la entrada de strings en una ventana de sfml-2.x.
* Hereda de sf::Text, as� que se usa como un sf::Text. 
* 	- Se lo crea pasandole una fuente, un tama�o y un color (los dos �ltimos opcionales).
* 	- Se le puede cambiar el formato al texto con los mismos m�todos que sf::Text. 
* 	- Se lo dibuja con el m�todo draw de la ventana igual que con los sprites.
* 	- Lo importante es pasarle los eventos del bucle de eventos mediante el m�todo 
* 	  processEvent, que retorna true si era un evento de su interes, o false en caso 
* 		contrario.
* 	- Y adem�s antes de dibujarlo hay que llamar a su m�todo update, en caso contrario 
* 	  no se ver� nada.
* 	
* 	Ejemplode uso:
*				...
*				// crear una instancia
* 			InputText text_entrada(font,30,sf::Color::Black);
* 			text_entrada.setPosition(120,50);
*				...
* 			// bucle principal
* 			while(w.isOpen()) { // w seria la ventana
* 				// procesar eventos
* 				Event e;
* 				while(w.pollEvent(e)) {
* 					if (text_entrada.processEvent(e)) {} // si retorna true, es porque proces� el evento
* 					else if (e.type == ....
* 					...
* 				}
* 				// dibujar
* 				text_entrada.update(); // para que el texto se dibuje correctamente (hay que llamar a update ante de pasarselo a draw)
* 				w.draw(text_entrada);
* 				...
* 				w.display();
* 			}
*
**/

// Version: 2024-01-03

class InputText : public sf::Text {
	
public:
	InputText() = default;
	InputText(const sf::Font &font, int size=30, sf::Color color=sf::Color::Black) {
		// for(int i=0;i<sf::Keyboard::KeyCount;i++) is_down[i]=true;
		setFont(font);
		setCharacterSize(size);
		setFillColor(color);
	}
	
	bool processEvent(const sf::Event &event) {
		if (!m_editable) return false;
		if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode=='\b') {
				if (m_value.size()) m_value.erase(m_value.size()-1,1);
			} else if (event.text.unicode>=32 && event.text.unicode<128) {
				if (m_max_chars==0 || m_value.size()<m_max_chars ) //if (!m_max_chars || m_value.size()<m_max_chars) 
					if (!m_single_word || event.text.unicode!=' ')
						m_value += static_cast<char>(event.text.unicode);
			}
			return true;
		}
		return false;
	}
	void setMaxChars(unsigned int max_len) { m_max_chars = max_len; }
	void update() {
		if (m_editable && int(m_clock.getElapsedTime().asSeconds()*3)%2)
			setString(m_value+"|");
		else 
			setString(m_value);
	}
	void setEditable(bool m_value) { m_editable=m_value; }
	void setSingleWord(bool m_value) { m_single_word=m_value; }
	std::string getValue() { return m_value; }
	void reset() { m_value.clear(); }
	
private:
	sf::Clock m_clock;
	std::string m_value;
	unsigned int m_max_chars = 0;
	bool m_editable = true;
	bool m_single_word = false;
	/*
	bol is_down[sf::Keyboard::KeyCount];
		void TestKey(sf::Keyboard::Key k, char c) {
		bool was_down=is_down[int(k)];
		is_down[int(k)]=sf::Keyboard::isKeyPressed(k);
		if (is_down[int(k)] && !was_down) value+=c;
	}
	*/
};




#endif
