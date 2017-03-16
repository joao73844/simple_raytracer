#include "Source.h"

int main(int argc, char * argv[]) {
	std::cout << "rendering..." << std::endl;

	int n = _WIDTH_ * _HEIGHT_;
	RGBType *pixels = new RGBType[n];
	// Special Vectors/Points
	/// Origin Point
	Vect O (0, 0, 0);
	/// Plane Unity Vectors
	Vect X (1, 0, 0);
	Vect Y (0, 1, 0);
	Vect Z (0, 0, 1);

	// Create Camera
	/// Vectors of the camera
	/// Position of the camera
	Vect campos(3, 1.5, -4);
	Vect look_at(0,0,0);
	/// Difference Between
	/// the coordinates are the difference between the X coordinate of ?? that we
	/// give our cam positions, minus the X coordinate that we gave look at
	Vect diff_btw(campos.getX() - look_at.getX(), campos.getY() - look_at.getY(), campos.getZ() - look_at.getZ());
	/// Direction of camera
	Vect camdir = diff_btw.negation().normalize();
	Vect camright = Y.crossProduct(camdir).normalize();
	Vect camdown = camright.crossProduct(camdir);
	/// the actual camera
	Camera scene_cam(campos, camdir, camright, camdown);

	// Light Creation
	/// Light Colors
	Color white(1.0, 1.0, 1.0, 1.0);
	Color pretty_green(0.5, 1.0, 0.5, 0.3);
	Color gray();
	Color black(0.0, 0.0, 0.0, 0.0);
	/// Light Position
	Vect light_position(-7, 10, -10);
	Light scene_light(light_position, white);


	// Scene Objects
	/// Sphere
	Sphere scene_sphere(O, 1.0, pretty_green);

	// Ray Tracing Algorithm
	for (int x = 0; x < _WIDTH_ ; x++) {
		for (int y = 0; y < _HEIGHT_ ; y++) {
			thisone = y* _WIDTH_ + x;

			if ((x > 200 && x < 440) && (y > 200 && y < 280)) {
				pixels[thisone].r = 23;
				pixels[thisone].g = 222;
				pixels[thisone].b = 10;
			}
			else {
				pixels[thisone].r = 0;
				pixels[thisone].g = 0;
				pixels[thisone].b = 0;
			}
		}
	}

	savebmp("scene.bmp", _WIDTH_, _HEIGHT_, _DPI_, pixels);

	return 0;
}