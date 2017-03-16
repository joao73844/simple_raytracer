#include "Light.h"


// Default Constructor
/// Creates a white light in the origin
Light::Light() {
	_position = Vect(0, 0, 0);
	_color = Color(1, 1, 1, 0);
}
// General Constructor
Light::Light(Vect p, Color c) {
	_position = p;
	_color = c;
}


Light::~Light()
{
}
