#pragma once
#ifndef __INTERSECTIONPOINT_H__
#define __INTERSECTIONPOINT_H__

// IMPORTANT NOTE
/// This Class does NOT BELONG to the tutorial
/// it was made so the intersection algorithmns
/// used in the "3D Programming" Course lectures
/// work, with this ray tracer
/// If you want to use this implementation
/// change the __CLASS_ALGORITHMN__ constant to TRUE
/// (Its defined in the "Source.h" File)
// DESCRIPTION
/// This class implements a Intersection Point
/// between the Rays (from the Ray Tracer) and
/// the Scene Objects
/// It is called inside the "findIntersection"
/// method in each of the Objects and returns 
// ATTRIBUTES
/// This class has 2 attributes, the intersection
/// point and the normal of the intersection point
/// with the center of the sphere

// Project File Headers
#include "Vect.h"

class IntersectionPoint
{
	Vect _intersectionPoint;
	Vect _normal;
public:
	IntersectionPoint(Vect, Vect);
	~IntersectionPoint();
	// Class Methods
	/// GETTERS
	Vect getPoint() { return _intersectionPoint; }
	Vect getNormal() { return _normal; }
};


#endif // !1