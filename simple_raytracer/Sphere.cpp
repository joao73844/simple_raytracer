#include "Sphere.h"


// Default Constructor
/// Creates a Grey Sphere in the origin with radius 1
Sphere::Sphere() {
	_center = Vect(0, 0, 0);
	_radius = 1.0;
	_color = Color(0.5, 0.5, 0.5, 0);
}
// General Constructor
Sphere::Sphere(Vect center, double radius, Color color) {
	_center = center;
	_radius = radius;
	_color = color;
}


Sphere::~Sphere()
{
}
