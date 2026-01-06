#include "Utilities.h"

float Lerp(float goal, float current, float dt)
{
	
	float diference = goal - current;
	
	if (diference > dt){
		return current + dt;
	}
	if(diference < -dt)
		return current - dt;
	
	return goal;
}

	Vector2f Normalize(const Vector2f& source)
	{
		float length = sqrt((source.x * source.x) + (source.y * source.y));
		if (length != 0)
			return Vector2f(source.x / length, source.y / length);
		else
			return source;
	}

	
	float Clamp(float value, float min, float max)
	{
		if(value > max)
			return max;
		if (value < min)
			return min;
		return value;
	}
