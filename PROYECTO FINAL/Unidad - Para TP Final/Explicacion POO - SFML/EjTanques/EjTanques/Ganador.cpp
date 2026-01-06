#include "Ganador.h"
#include "Partida.h"
#include "Juego.h"

Ganador::Ganador (bool player_one) {
	m_font.loadFromFile("asap.ttf");
	
	m_text.setFont(m_font);
	m_text.setPosition(250,250);
	m_text.setCharacterSize(40);
	if (player_one) {
		m_text.setString("Player One Wins!");
		m_text.setFillColor({255,128,128});
	} else {
		m_text.setString("Player Two Wins!");
		m_text.setFillColor({128,255,128});
	}
}

void Ganador::actualizar (Juego &j) {
	if (Keyboard::isKeyPressed(Keyboard::Return))
		j.cambiarEscena(new Partida);
}

void Ganador::dibujar (RenderWindow & w) {
	w.clear({0,0,0});
	w.draw(m_text);
}

