#include <iostream>
#include <cmath>
using namespace std;

class Vec2 {
public:
	Vec2(float x, float y) : m_x(x), m_y(y) { }
	float VerX() { return m_x; }
	float VerY() { return m_y; }
//	Vec2 operator+(Vec2 ov) {
//		Vec2 suma(this->m_x+ov.m_x, this->m_y+ov.m_y);
//		return suma;
//	}
	float VerModulo() { return sqrt(m_x*m_x+m_y*m_y); }
private:
	float m_x, m_y;
};

Vec2 operator+(Vec2 v1, Vec2 v2) {
	Vec2 suma(v1.VerX()+v2.VerX(), v1.VerY()+v2.VerY());
	return suma;
}
Vec2 operator-(Vec2 v1, Vec2 v2) {
	Vec2 suma(v1.VerX()-v2.VerX(), v1.VerY()-v2.VerY());
	return suma;
}


class Proyectil {
public:
//	Proyectil(float x_pos, float y_pos, float x_vel, float y_vel)
//		: m_pos(x_pos,y_pos), m_vel(x_vel,y_vel) { }
	Proyectil(Vec2 pos, Vec2 vel) : m_pos(pos), m_vel(vel) { }
	Vec2 VerPosicion() { return m_pos; }
	Vec2 VerVelocidad() { return m_vel; }
	void Mover() { m_pos = m_pos + m_vel; }
	bool Colisiona(Vec2 pos_otro, float radio) {
		Vec2 vd = pos_otro-m_pos;
		float dist = vd.VerModulo();
		return dist <= radio;
//		if (dist <= radio) return true;
//		else               return false;
	}
private:
	Vec2 m_pos, m_vel;
};



