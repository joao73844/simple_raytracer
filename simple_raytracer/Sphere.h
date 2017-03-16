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
};


#endif // !1