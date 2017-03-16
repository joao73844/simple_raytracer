#include "Vect.h"



Vect::Vect() {
	_x = 0;
	_y = 0;
	_z = 0;
}

Vect::Vect(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;
}

Vect::~Vect() {
}

Vect Vect::vectMul(double k) {
	return Vect(_x*k, _y*k, _z*k);
}

Vect Vect::negation() {
	return vectMul(-1);
}

double Vect::magnitude() {
	return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
}

Vect Vect::normalize() {
	return Vect(_x / magnitude(), _y / magnitude(), _z / magnitude());
}

double Vect::dotProduct(Vect v)
{
	return _x*v.getX() + _y*v.getY() + _z*v.getZ();
}

Vect Vect::crossProduct(Vect v)
{
	double x = _y*v.getZ() - _z*v.getY();
	double y = _z*v.getX() - _x*v.getZ();
	double z = _x*v.getY() - _y*v.getX();
	return Vect(x, y, z);
}

Vect Vect::vectAdd(Vect v)
{
	return Vect(_x + v.getX(), _y + v.getY(), _z + v.getZ());
}
