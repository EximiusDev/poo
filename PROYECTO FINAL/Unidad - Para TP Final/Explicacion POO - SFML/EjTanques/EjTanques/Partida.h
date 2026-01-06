#ifndef PARTIDA_H
#define PARTIDA_H
#include "Tanque.h"
#include "Disparo.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
using namespace sf;
using namespace std;

class Partida : public Escena {
public:
	Partida();
	void actualizar(Juego &j) override;
	void dibujar(RenderWindow &w) override;
private:
	Tanque m_tanque_p1;
	Tanque m_tanque_p2;
	vector<Disparo> m_disparos;
};

#endif

