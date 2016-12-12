/*
 * Scene.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
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

Scene::Scene() : camera_(Camera()), source_(Ray3f()), nb_shape_(1)
{
	shapes_ = new Shape[1];
}

Scene::Scene(Camera& camera, Shape* shapes, int nb_shape, Ray3f& source)
{
	camera_ = camera;
	shapes_ = shapes;
	source_ = source;
	nb_shape_ = nb_shape;
}

Scene::~Scene()
{
	delete[] shapes_;
}

void Scene::render(int width, int height, char* name, int x_image, int y_topleft_image, int z_topleft_image )
{
	// initialization of the variable
	int i,j;

	// creation of the image with associated width and height
	Image* image = Image(width, height);

	for (i=0;i<height;i++) {
		for(j=0;j<width;j++) {
			Ray3f line (camera_.getPosition(), Vector3f(x_image, (y_topleft_image + i), (z_topleft_image + j)));
			bool res = shapes_[0].isHit(line);

			if (res) {
				Pixel newPix (shapes_[0].getMatter().getR(), shapes_[0].getMatter().getG(), shapes_[0].getMatter().getB());
				image->setOnePixel(i,j, newPix);
			} else {
				image->setOnePixel(i,j, Pixel(0,0,0));
			}
		}
	}

	// we save the image to an png file
	save_png_to_file(image, (char *) name);

}


