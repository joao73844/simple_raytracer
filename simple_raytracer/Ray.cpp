#include "Ray.h"



Ray::Ray() {
	/// By default it will create a ray with center
	/// in the origin and pointing in the x axis
	_orig = Vect();
	_dir = Vect(1, 0, 0);
}

Ray::Ray(Vect o, Vect d) {
	_orig = o;
	_dir = d;
}

Ray::~Ray() {
}
