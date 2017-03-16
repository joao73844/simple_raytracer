#pragma once
#ifndef __PLANE_H__
#define __PLANE_H__

// C File Headers
#include "math.h"
// Project File Headers
#include "Object3D.h"
#include "Vect.h"
#include "Color.h"

class Plane : public Object3D {
	Vect _normal;
	double _distance;
	Color _color;
public:
	/// Default constructor
	Plane();
	/// General Construtor
	Plane(Vect, double, Color);
	/// Destructor
	~Plane();

	// Method Functions
	/// GETTERS
	Vect getPlaneNormal() { return _normal; }
	double getPlaneDistance() { return _distance; }
	Color getPlaneColor() { return _color; }
	
	/// GEOMETRY METHODS
	Vect Plane::getNormalAt(Vect intersectionPoint) {
		return _normal;
	}
	double findIntersection(Ray ray);
	// WARNING
	/// DO NOT USE THIS METHOD
	IntersectionPoint findIntersection_2(Ray ray) { return IntersectionPoint(Vect(), Vect()); }
};


#endif // !1