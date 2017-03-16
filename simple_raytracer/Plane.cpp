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
double Plane::findIntersection(Ray ray) {
	Vect ray_direction = ray.getRayDirection();

	double a = ray_direction.dotProduct(_normal);

	if (a == 0) {
		/// ray is parallel to the plane
		return -1.0;
	}

	double b = _normal.dotProduct(ray.getRayOrigin().vectAdd(_normal.vectMul(_distance).negation()));
	return -1 * b / a;
}
