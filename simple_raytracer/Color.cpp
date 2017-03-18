#include "Color.h"


// Default Constructor
/// Initializates with color grey
Color::Color() {
	_red = 0.5;
	_green = 0.5;
	_blue = 0.5;
	_special = 0.0;
}

// General Constructor
Color::Color(double r, double g, double b, double s) {
	_red = r;
	_green = g;
	_blue = b;
	_special = s;
}

Color::~Color() {
}



/// Returns a new color which is the result of multiplying
/// this color by a scalar
Color Color::colorScalar(double scalar)
{
	// Compute the Colors
	/// Compute the <RED> Color
	double red = _red * scalar;
	/// The max value for a color is 1.0
	if (red > 1.0) red = 1.0;
	/// the min value for a color is 0.0
	else if (red < 0.0) red = 0.0;
	/// Compute the <GREEN> Color
	double green = _green * scalar;
	/// The max value for a color is 1.0
	if (green > 1.0) green = 1.0;
	/// the min value for a color is 0.0
	else if (green < 0.0) green = 0.0;
	/// Compute the <BLUE> Color
	double blue = _blue * scalar;
	/// The max value for a color is 1.0
	if (blue > 1.0) blue = 1.0;
	/// the min value for a color is 0.0
	else if (blue < 0.0) blue = 0.0;
	// Return the new color
	return Color(red, green, blue, _special);
}

/// Returns a new color which is the result of
/// adding both colors
Color Color::colorAdd(Color c)
{
	// Compute the Colors
	/// Compute the <RED> Color
	double red = _red + c.getRed();
	/// The max value for a color is 1.0
	if (red > 1.0) red = 1.0;
	/// the min value for a color is 0.0
	else if (red < 0.0) red = 0.0;
	/// Compute the <GREEN> Color
	double green = _green + c.getGreen();
	/// The max value for a color is 1.0
	if (green > 1.0) green = 1.0;
	/// the min value for a color is 0.0
	else if (green < 0.0) green = 0.0;
	/// Compute the <BLUE> Color
	double blue = _blue + c.getBlue();
	/// The max value for a color is 1.0
	if (blue > 1.0) blue = 1.0;
	/// the min value for a color is 0.0
	else if (blue < 0.0) blue = 0.0;
	// Return the new color
	return Color(red, green, blue, _special);
}

/// Returns a new color which is the result of
/// multiplying both colors
Color Color::colorMultiply(Color c)
{
	// Compute the Colors
	/// Compute the <RED> Color
	double red = _red * c.getRed();
	/// The max value for a color is 1.0
	if (red > 1.0) red = 1.0;
	/// the min value for a color is 0.0
	else if (red < 0.0) red = 0.0;
	/// Compute the <GREEN> Color
	double green = _green * c.getGreen();
	/// The max value for a color is 1.0
	if (green > 1.0) green = 1.0;
	/// the min value for a color is 0.0
	else if (green < 0.0) green = 0.0;
	/// Compute the <BLUE> Color
	double blue = _blue * c.getBlue();
	/// The max value for a color is 1.0
	if (blue > 1.0) blue = 1.0;
	/// the min value for a color is 0.0
	else if (blue < 0.0) blue = 0.0;
	// Return the new color
	return Color(red, green, blue, _special);
}

/// Returns a new color which is the average
/// of both colors
Color Color::colorAverage(Color c)
{
	// Compute the Colors
	/// Compute the <RED> Color
	double red = (_red + c.getRed()) / 2;
	/// Compute the <GREEN> Color
	double green = (_green + c.getGreen()) / 2;
	/// Compute the <BLUE> Color
	double blue = (_blue + c.getBlue()) / 2;
	// Return the new color
	return Color(red, green, blue, _special);
}