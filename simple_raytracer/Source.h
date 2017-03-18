#pragma once
/// To disable warnings related with fopen or fwrite
#define _CRT_SECURE_NO_WARNINGS

// C++ Headers
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
// C Headers
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// Project Files Headers
#include "Vect.h"
#include "Ray.h"
#include "Camera.h"
#include "Object3D.h"
#include "Sphere.h"
#include "Plane.h"
#include "Color.h"
#include "Light.h"
#include "LightSource.h"
/// DO NOT USE THIS
#include "IntersectionPoint.h"


/// If __CLASS_ALGORITHMN__ is set to TRUE it will use the algorithm from Classes
#define __CLASS_ALGORITHMN__ false
/// This constant is just to skip the ray tracer algorithmn so in case of working
/// on other classes the compilation is faster
#define __SKIP__ false
// Constants
#define _WIDTH_ 640 /// Divide by 16 to make it faster but with lower resolution
#define _HEIGHT_ 480 /// Divide by 16 to make it faster but with lower resolution
#define _DPI_ 72 /// Dots per inch

// Declarations
/// STRUCTURE for color
struct RGBType;
/// function to save an image to BMP
void savebmp(const char * filename, int w, int h, int dpi, RGBType *data);
/// @var serves as indexing value thats gonna change
/// as the pixels in the ray tracer algorithmn are computed
/// and its gonna be a value we can use to determine what
/// the coordinates (x and y) of an individual pixel are
int thisone;

// Definitions
struct RGBType {
	double r; /// RED
	double g; /// GREEN
	double b; /// BLUE
};

/**
*** @function saveBMP
*** function to save an image to a BMP file
**/
void savebmp(const char * filename, int w, int h, int dpi, RGBType *data) {
	FILE * f;
	int k = w*h;
	int s = 4 * k;
	int filesize = 54 + s;

	double factor = 39.375;
	int m = static_cast<int>(factor);

	int ppm = dpi*m;

	unsigned char bmpfileheader[14] = { 'B', 'M', 0,0,0,0, 0,0,0,0, 54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0 };

	bmpfileheader[ 2] = (unsigned char)(filesize);
	bmpfileheader[ 3] = (unsigned char)(filesize>>8);
	bmpfileheader[ 4] = (unsigned char)(filesize>>16);
	bmpfileheader[ 5] = (unsigned char)(filesize>>24);

	bmpinfoheader[ 4] = (unsigned char)(w);
	bmpinfoheader[ 5] = (unsigned char)(w>>8);
	bmpinfoheader[ 6] = (unsigned char)(w>>16);
	bmpinfoheader[ 7] = (unsigned char)(w>>24);

	bmpinfoheader[ 8] = (unsigned char)(h);
	bmpinfoheader[ 9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);

	bmpinfoheader[21] = (unsigned char)(s);
	bmpinfoheader[22] = (unsigned char)(s >> 8);
	bmpinfoheader[23] = (unsigned char)(s >> 16);
	bmpinfoheader[24] = (unsigned char)(s >> 24);

	bmpinfoheader[25] = (unsigned char)(ppm);
	bmpinfoheader[26] = (unsigned char)(ppm >> 8);
	bmpinfoheader[27] = (unsigned char)(ppm >> 16);
	bmpinfoheader[28] = (unsigned char)(ppm >> 24);

	bmpinfoheader[29] = (unsigned char)(ppm);
	bmpinfoheader[30] = (unsigned char)(ppm >> 8);
	bmpinfoheader[31] = (unsigned char)(ppm >> 16);
	bmpinfoheader[32] = (unsigned char)(ppm >> 24);

	f = fopen(filename, "wb");

	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);

	for (int i = 0; i < k; i++) {
		RGBType rgb = data[i];

		double red = (data[i].r) * 255;
		double green = (data[i].g) * 255;
		double blue = (data[i].b) * 255;

		unsigned char color[3] = { (int)floor(blue),(int)floor(green),(int)floor(red) };

		fwrite(color, 1, 3, f);
	}

	fclose(f);
}


/** @function closestObject
*** function that receives a vector containning
*** all the distances from a Ray to all the intersected
*** and returns the index of the object closest to
*** the ray
**/
int closestObject(std::vector<double> object_intersections) {
	/// Returns the index of the Closest Object to The Ray

	// prevent unnessary calculations
	/// if there are no intersections
	if (object_intersections.size() == 0) return -1;
	/// if the ray only intersected 1 object
	if (object_intersections.size() == 1) {
		/// if that intersection is greater that zero than its our index of minimum value
		if (object_intersections.at(0) > 0) return 0;
		/// otherwise the only intersection is negative
		else return -1;
	}

	/// if it reach here it means that the ray intesected more than 1 object
	// 1st - Find Maximum Value
	/// ... which corresponds to the greatest distance from ray to intersection point
	int index_of_minimum_value = 0;
	double max = 0;
	for (unsigned int i = 0; i < object_intersections.size(); i++) {
		if (max < object_intersections.at(i)) {
			max = object_intersections.at(i);
		}
	}
	/// Then starting from the maximum value, find the minimum positive value
	if (max > 0) {
		/// we only want positive intersections
		for (unsigned int i = 0; i < object_intersections.size(); i++) {
			if (object_intersections.at(i) > 0 && object_intersections.at(i) <= max) {
				max = object_intersections.at(i);
				index_of_minimum_value = i;
			}
		}
		return index_of_minimum_value;
	}

	/// otherwise, all the intersections were negatives
	/// so, they didn't actually intersect anything...
	return -1;
}

/** @function getColorAt
*** returns the color of a intersection point
**/
Color getColorAt(
	Vect intersection_position,
	Vect interection_ray_direction,
	std::vector<Object3D*> scene_objects,
	int index_of_closest_object,
	std::vector<LightSource*> light_sources,
	double accuracy,
	double ambientlight)
{
	Color closest_object_color = scene_objects.at(index_of_closest_object)->getColor();
	Vect closest_object_normal = scene_objects.at(index_of_closest_object)->getNormalAt(intersection_position);
	Color final_color = closest_object_color.colorScalar(ambientlight);

	// 1st - Loop Through the Light Sources
	for (unsigned int light_index = 0; light_index < light_sources.size(); light_index++) {
		/// The vector representing the Light Direction, is nothing more than
		/// Ld = Lp - Ip , where:
		/// Ld (Light Direction), Lp (Light Position), Ip (IntersectionPoint Position)
		Vect light_position = light_sources.at(light_index)->getLightPosition();
		Vect light_direction = light_position.vectSub(intersection_position).normalize();

		double cosine_angle = closest_object_normal.dotProduct(light_direction);

		if (cosine_angle > 0) {
			// Test for shadows
			/// <variable> to check if the current pixel is in shadow or not
			bool shadowed = false;

			Vect distance_to_light = light_position.vectSub(intersection_position).normalize();
			double distance_to_light_magnitude = distance_to_light.magnitude();

			// Create a Shadow Ray
			/// A shadow ray is a ray going from an intersection point (with an object)
			/// to a light source, basically to check if there is an object in the way, or not
			/// if it is, it means the object is in shadow
			Vect shadow_ray_origin = intersection_position;
			Vect shadow_ray_direction = light_position.vectSub(intersection_position).normalize();
			Ray shadow_ray(shadow_ray_origin,shadow_ray_direction);

			// Check if the Shadow Ray intersects with a scene object
			/// <vector> containning all the intersection values
			/// between the shadow ray and the scene objects
			std::vector<double> shadow_ray_intersections;
			double intersection = 0.0;
			/// loop to run compute intersections with all the scene objects
			/// if it finds any object in the way the loop stops
			for (unsigned int object_index = 0;
				object_index < scene_objects.size() && shadowed == false;
				object_index++)
			{
				intersection = scene_objects.at(object_index)->findIntersection(shadow_ray);
				shadow_ray_intersections.push_back(intersection);
			}
			/// 
			for (unsigned int i = 0; i < shadow_ray_intersections.size(); i++) {
				if (shadow_ray_intersections.at(i) > accuracy) {
					if (shadow_ray_intersections.at(i) <= distance_to_light_magnitude) {
						shadowed = true;
					}
					break;
				}
			}
			///
			if (shadowed == false) {
				Color light_source_color = light_sources.at(light_index)->getColor();
				final_color = final_color.colorAdd(closest_object_color.colorMultiply(light_source_color).colorScalar(cosine_angle));
				// Applying shininess
				double closest_object_shininess = closest_object_color.getSpecial();
				if (closest_object_shininess > 0.0 &&
					closest_object_shininess <= 1.0) {
					double dot1 = closest_object_normal.dotProduct(interection_ray_direction.negation());
					Vect scalar1 = closest_object_normal.vectMul(dot1);
					Vect add1 = scalar1.vectAdd(interection_ray_direction);
					Vect scalar2 = add1.vectMul(2);
					Vect add2 = interection_ray_direction.negation().vectAdd(scalar2);
					Vect reflection_direction = add2.normalize();

					double specular = reflection_direction.dotProduct(light_direction);
					if (specular > 0.0) {
						specular = pow(specular, 10);
						final_color = final_color.colorAdd(light_source_color.colorScalar(specular*closest_object_color.getSpecial()));
					}
				}
			}

		} /// END of IF-statement (cosine_angle > 0)
	} /// END of FOR-Loop running through all the light sources

	return final_color;
}