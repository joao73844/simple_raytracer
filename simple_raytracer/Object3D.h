#pragma once
#ifndef __OBJECT3D_H__
#define __OBJECT3D_H__

// C File Headers
// Project File Headers
#include "Vect.h"
#include "Ray.h"
#include "Color.h"

class Object3D {
public:
	/// Default constructor
	Object3D();
	/// Destructor
	~Object3D();

	// Method Functions
	/// GETTERS
	Color getObjectColor() { return Color(0.0, 0.0, 0.0, 0); }
	/// GEOMETRY OPERATIONS
	double findIntersection(Ray ray) {
		return 0.0;
	}
};


#endif // !1