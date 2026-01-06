#include "Partida.h"
#include <cmath>
#include <iostream>
#include "Juego.h"
#include "Ganador.h"
using namespace std;

Partida::Partida() : m_tanque_p1(true), m_tanque_p2(false) {
	
}

bool colisiona(Disparo &d, Tanque &t) {
	Vector2f pd = d.verPosicion();
	Vector2f pt = t.verPosicion();
	Vector2f v = pd-pt;
	return sqrt(v.x*v.x+v.y*v.y)<25;
}

bool fuera_de_la_pantalla(Disparo &d) {
	Vector2f p = d.verPosicion();
	if (p.x<0 or p.x>800) return true;
	if (p.y<0 or p.y>600) return true;
	return false;
}

void Partida::actualizar (Juego &j) {
	m_tanque_p1.actualizar();
	if (m_tanque_p1.debeDisparar())
		m_disparos.push_back(m_tanque_p1.generarDisparo());
	m_tanque_p2.actualizar();
	if (m_tanque_p2.debeDisparar())
		m_disparos.push_back(m_tanque_p2.generarDisparo());
	for(Disparo &d : m_disparos)
		d.actualizar();
	for(Disparo &d : m_disparos) {
		if (colisiona(d,m_tanque_p1)) {
			j.cambiarEscena(new Ganador(false));
		}
		if (colisiona(d,m_tanque_p2)) {
			j.cambiarEscena(new Ganador(true));
		}
	}
	auto it = remove_if(m_disparos.begin(),m_disparos.end(),fuera_de_la_pantalla);
	m_disparos.erase(it,m_disparos.end());
}

void Partida::dibujar (RenderWindow & w) {
	w.clear(Color(220,220,180,255));
	m_tanque_p1.dibujar(w);
	m_tanque_p2.dibujar(w);
	for(Disparo &d : m_disparos)
		d.dibujar(w);
}

