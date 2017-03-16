#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__	

// Project File Headers
#include "Vect.h"

class Camera
{
	/// View Reference Point (VRP)
	/// Camera Position in the WCS (World Coordinates System)
	Vect _campos;
	/// View Plane Normal (VPN)
	/// Camera Direction in the WCS
	Vect _camdir;
	/// @attribute camright
	/// @attribute camdown
	/// Used to define the general coordinate system of the scene
	/// and are used within the method functions of the Vector (Vect)
	/// in order to compute our prespectives
	Vect _camright, _camdown;

public:
	/// Default constructor
	Camera();
	/// General Construtor
	Camera(Vect cp, Vect cdir, Vect cr, Vect cdown);
	/// Destructor
	~Camera();

	// Method Functions
	/// GETTERS
	Vect getCameraPosition() { return _campos; }
	Vect getCameraDirection() { return _camdir; }
	Vect getCameraRight() { return _camright; }
	Vect getCameraDown() { return _camdown; }
};


#endif // !1