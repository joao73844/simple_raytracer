#pragma once
#ifndef __SOURCE_H__
#define __SOURCE_H__

// Project File Headers
#include "Vect.h"
#include "Color.h"


class LightSource
{
public:
	LightSource();
	~LightSource();

	virtual Vect getLightPosition() { return Vect(0, 0, 0); }
	virtual Color getColor() { return Color(1, 1, 1, 0); }

};


#endif // !__SOURCE_H__