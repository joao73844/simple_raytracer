#pragma once
#ifndef __RAY_H__
#define __RAY_H__

// Project File Headers
#include "Vect.h"

class Ray
{
	Vect _orig;
	Vect _dir;
public:
	/// Default constructor
	Ray();
	/// General Construtor
	Ray(Vect o, Vect d);
	/// Destructor
	~Ray();

	// Method Functions
	/// GETTERS
	Vect getRayOrigin() { return _orig; }
	Vect getRayDirection() { return _dir; }
};


#endif // !1
