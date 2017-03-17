#include "Source.h"

int main(int argc, char * argv[]) {
	std::cout << "rendering..." << std::endl;

	// Window Variables
	int width = _WIDTH_;
	int height = _HEIGHT_;
	int n = width * height;
	double aspectratio = (double)width / (double)height;
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
	Color gray(0.5,0.5,0.5,0);
	Color black(0.0, 0.0, 0.0, 0.0);
	Color maroon(0.5, 0.25, 0.25, 0);
	/// Light Position
	Vect light_position(-7, 10, -10);
	Light scene_light(light_position, white);


	// Scene Objects
	/// Sphere
	Sphere scene_sphere(O, 1.0, pretty_green);
	/// Plane
	Plane scene_plane(Y, -1, maroon);
	/// Vector (Array) with all the scene objects
	std::vector<Object3D*> scene_objects;
	scene_objects.push_back(dynamic_cast<Object3D*>(&scene_sphere));
	scene_objects.push_back(dynamic_cast<Object3D*>(&scene_plane));

	// Auxiliar Variables
	///@xamnt @yamnt values that will be slightly to the left
	/// and slightly to the right, of the direction the camera is pointing
	double xamnt, yamnt;

	// Ray Tracing Algorithm
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			thisone = y* width + x;

			/// Without AntiAliasing
			if (width > height) {
				/// image is wider than it is tall
				xamnt = ((x + 0.5) / width)*aspectratio - (((width - height) / (double)height) / 2);
				yamnt = ((height - y) + 0.5) / height;
			}
			else if (height > width) {
				/// image is taller than it is wide
				xamnt = (x + 0.5) / width;
				yamnt = (((height - y) + 0.5) / height) / aspectratio - (((height - width) / (double)width) / 2);
			}
			else {
				/// the image is square
				xamnt = (x + 0.5) / width;
				yamnt = ((height - y) + 0.5) / height;
			}

			// Rays
			/// Ray coordinates
			/// The Ray will be shoot from the camera, so it
			/// has to come from the same point
			Vect cam_ray_origin = scene_cam.getCameraPosition();
			Vect cam_ray_direction = camdir.vectAdd(camright.vectMul(xamnt - 0.5).vectAdd(camdown.vectMul(yamnt - 0.5))).normalize();
			Ray cam_ray(cam_ray_origin, cam_ray_direction);

			// Check the intersections
			/// vector containing the result of all the intersection operations
			std::vector <double> intersections;
			/// check if the ray intersects any of the objects in the scene
			for (unsigned int index = 0; index < scene_objects.size(); index++) {
				intersections.push_back(scene_objects.at(index)->findIntersection(cam_ray));
			}

			// Determine what object is the closest one
			int index_of_closest_obj = closestObject(intersections);

			// Pixel Color
			/// If its inside the coloring area
			if (index_of_closest_obj == -1) {
				/// Set the backgroung to black
				pixels[thisone].r = 0;
				pixels[thisone].g = 0;
				pixels[thisone].b = 0;
			}
			else {
				/// Its in the margin
				/// index corresponds to an object in the scene

				Color this_color = scene_objects.at(index_of_closest_obj)->getColor();

				pixels[thisone].r = this_color.getRed();
				pixels[thisone].g = this_color.getGreen();
				pixels[thisone].b = this_color.getBlue();
			}
		}
	}

	savebmp("scene.bmp", _WIDTH_, _HEIGHT_, _DPI_, pixels);

	return 0;
}