#ifndef UTILITIES_H
#define UTILITIES_H

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;
using namespace sf;

float Lerp(float goal, float current, float dt);

Vector2f Normalize(const Vector2f& source);

float Clamp(float value, float min, float max);
#endif
