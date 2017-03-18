#pragma once
#ifndef __LIGHT_H__
#define __LIGHT_H__

// Project File Headers
#include "LightSource.h"

class Light : public LightSource {
	Vect _position;
	Color _color;
public:
	/// Default constructor
	Light();
	/// General Construtor
	Light(Vect, Color);
	/// Destructor
	~Light();

	// Method Functions
	/// GETTERS
	Vect getLightPosition() { return _position; }
	Color getLightColor() { return _color; }
};


#endif // !1