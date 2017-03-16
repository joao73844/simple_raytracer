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
	Vect getNormalAt(Vect);
	double findIntersection(Ray ray) {
		Vect ray_direction = ray.getRayDirection();

		double a = ray_direction.dotProduct(_normal);

		if (a == 0) {
			/// ray is parallel to the plane
			return -1.0;
		}

		double b = _normal.dotProduct(ray.getRayOrigin().vectAdd(_normal.vectMul(_distance).negation()));
		return -1 * b / a;
	}
};


#endif // !1