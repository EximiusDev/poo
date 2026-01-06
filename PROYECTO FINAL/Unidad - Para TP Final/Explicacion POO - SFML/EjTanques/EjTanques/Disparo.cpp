#include "Disparo.h"

Disparo::Disparo(Vector2f pos, Vector2f dir) {
	m_circ.setPosition(pos);
	m_circ.setRadius(2);
	m_circ.setOrigin(2,2);
	m_circ.setFillColor({0,0,0});
	m_vel = dir*3.f;
}

void Disparo::actualizar ( ) {
	m_circ.move(m_vel);
}

void Disparo::dibujar(RenderWindow &w) {
	w.draw(m_circ);
}

Vector2f Disparo::verPosicion ( ) {
	return m_circ.getPosition();
}

