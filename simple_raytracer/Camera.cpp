#include "Camera.h"



Camera::Camera() {
	/// By default it will create a camera with center
	/// in the origin and pointing in the -z axis
	/// (-z because the camera will be pointing in
	/// the opposite direction)
	_campos = Vect();
	_camdir = Vect(0, 0, 1);
	_camright = Vect();
	_camdown = Vect();
}


Camera::Camera(Vect cp, Vect cdir, Vect cr, Vect cdown) {
	_campos = cp;
	_camdir = cdir;
	_camright = cr;
	_camdown = cdown;
}

Camera::~Camera() {
}
