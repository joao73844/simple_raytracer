#pragma once
#ifndef __SPHERE_H__
#define __SPHERE_H__

// C File Headers
#include "math.h"
// Project File Headers
#include "Object3D.h"
#include "Vect.h"
#include "Color.h"


class Sphere : public Object3D {
	Vect _center;
	double _radius;
	Color _color;
public:
	/// Default constructor
	Sphere();
	/// General Construtor
	Sphere(Vect, double, Color);
	/// Destructor
	~Sphere();

	// Method Functions
	/// GETTERS
	Vect getSphereCenter() { return _center; }
	double getSphereRadius() { return _radius; }
	Color getSphereColor() { return _color; }
	
	// GEOMETRY OPERATIONS
	/// returns the normal vector at a point of intersection
	Vect getNormalAt(Vect point) {
		/// normal always points away from the center of a sphere
		return point.vectAdd(_center.negation()).normalize();
	}
	/// <funtion> checks if the Ray intersects
	/// with the Sphere and returns the distance of the
	/// origin of the ray to the point of intersection
	/// returns -1.0 (a negative number) if it didn't intersect
	double findIntersection(Ray ray);
	// WARNING
	/// DO NOT USE THIS METHOD
	IntersectionPoint findIntersection_2(Ray ray);
};


#endif // !1