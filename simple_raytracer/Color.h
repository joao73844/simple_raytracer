#pragma once
#ifndef __COLOR_H__
#define __COLOR_H__

// C general headers
#include "math.h"

class Color
{
	double _red;
	double _green;
	double _blue;
	double _special;

public:
	/// Default constructor
	Color();
	/// General Construtor
	Color(double r, double g, double b, double s);
	/// Destructor
	~Color();

	// Method Functions
	/// GETTERS
	double getRed() { return _red; }
	double getGreen() { return _green; }
	double getBlue() { return _blue; }
	double getSpecial() { return _special; }

	// Set-up Functions
	double setColorRed(double colorValue) { _red = colorValue; }
	double setColorGreen(double colorValue) { _green = colorValue; }
	double setColorBlue(double colorValue) { _blue = colorValue; }
	double setColorSpecial(double colorValue) { _blue = colorValue; }
	
};


#endif // !1