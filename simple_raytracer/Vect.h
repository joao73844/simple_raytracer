#pragma once
#ifndef __VECT_H__
#define __VECT_H__

// C general headers
#include "math.h"

class Vect
{
	double _x;
	double _y;
	double _z;
public:
	/// Default constructor
	Vect();
	/// General Construtor
	Vect(double x, double y, double z);
	/// Destructor
	~Vect();

	// Method Functions
	/// GETTERS
	double getX() { return _x; }
	double getY() { return _y; }
	double getZ() { return _z; }

	// Transformations
	/// Scalar Multiplication
	/// Multiply each coordinate by a constant
	Vect vectMul(double k);
	/// Negation of the vector
	/// Returns the vector in the opposite direction
	Vect negation();
	/// Magnitude (Vector Length)
	double magnitude();
	/// Normalization
	/// Returns the same vector but with magnitude = 1
	Vect normalize();
	/// Dot Product
	/// Returns a scalar (...)
	double dotProduct(Vect v);
	/// Cross Product
	/// Returns a vector (...)
	Vect crossProduct(Vect v);
	/// Vector Addition
	/// Returns the vector resulting of adding this
	/// vector with the given vector
	Vect vectAdd(Vect v);
};


#endif // !1