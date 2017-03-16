#include "Plane.h"


// Default Constructor
/// Creates a Grey Plane in the x-axis
/// placed in the origin
Plane::Plane() {
	_normal = Vect(1.0, 0.0, 0.0);
	_distance = 0.0;
	_color = Color(0.5, 0.5, 0.5, 0);
}
// General Constructor
Plane::Plane(Vect n, double d, Color c) {
	_normal = n;
	_distance = d;
	_color = c;
}


Plane::~Plane()
{
}


// Method Functions
/// GEOMETRY FUNCTIONS
Vect Plane::getNormalAt(Vect intersectionPoint) {
	return _normal;
}
