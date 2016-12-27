/**
 * \file Scene.cpp
 * \brief Implémentation de la classe Scene.
 * \author Alexandre DE BOE, Julie CHOQUET
*/

#include <iostream>

#include "Scene.h"
#include "Material.h"
#include "Image.h"
#include "libpng.h"
#include "Vector3f.h"
#include "Ray3f.h"
#include "Sphere.h"
#include "Shape.h"

using namespace std;

Scene::Scene() : camera_(Camera()), source_(Ray3f()), nb_shape_(1)
{
	shapes_.push_back(new Sphere(Material(255,127,0,0), Vector3f(500,0,0), (float) 50));
}

Scene::Scene(Camera& camera, std::vector<Shape*> shapes, int nb_shape, Ray3f& source)
{
	camera_ = camera;
	shapes_ = shapes;
	source_ = source;
	nb_shape_ = nb_shape;
}

Scene::~Scene()
{
	for (int i=0;i<shapes_.size();i++) {
		delete shapes_[i];
	}
	shapes_.shrink_to_fit();
}

void Scene::render(int width, int height, char* name, int x_image, int y_topleft_image, int z_topleft_image )
{
	// initialization of the variable
	int i,j;
	bool toChange;;
	double distance = -1;
	double* pdistance;

	pdistance = &distance;

	// creation of the image with associated width and height
	Image* image = new Image(width, height);

	for (i=0;i<height;i++) {
		for(j=0;j<width;j++) {
			Ray3f line (camera_.getPosition(), Vector3f(x_image, (y_topleft_image - i), (z_topleft_image + j)));

			distance = -1;
			image->setOnePixel(i,j, Pixel(000,127,255));

			//cout << y_topleft_image - i << " -- " << z_topleft_image + j << endl;

			for(int k=0; k<shapes_.size(); k++) {
				toChange = shapes_[k]->isHit(line,pdistance);
				//cout << " [" << res << "] ";
				if (toChange) {
					Pixel newPix (shapes_[k]->getMatter().getR(), shapes_[k]->getMatter().getG(), shapes_[k]->getMatter().getB());
					image->setOnePixel(i,j, newPix);
				}
			}
		}
	}

	cout << endl;

	// we save the image to an png file
	save_png_to_file(image, (char *) name);

}


