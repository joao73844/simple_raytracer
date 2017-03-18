#pragma once
#ifndef __OBJECT3D_H__
#define __OBJECT3D_H__

// C File Headers
// Project File Headers
#include "IntersectionPoint.h"
#include "Vect.h"
#include "Ray.h"
#include "Color.h"

// Constants
/// To calculate the accuracy error in the intersections
#define _ACCURACY_ERROR_EPSILON_ 0.000001

class Object3D {
public:
	/// Default constructor
	Object3D();
	/// Destructor
	~Object3D();

	// Method Functions
	/// GETTERS
	virtual Color getColor() = 0;
	/// GEOMETRY OPERATIONS
	virtual double findIntersection(Ray ray) = 0;
	virtual Vect getNormalAt(Vect intersectionPoint) = 0;
	// WARNING
	/// DO NOT USE THIS METHOD
	virtual IntersectionPoint findIntersection_2(Ray ray) { return IntersectionPoint(Vect(), Vect()); }
};


#endif // !1