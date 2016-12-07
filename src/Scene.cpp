/*
 * Scene.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include <iostream>

#include "Material.h"
#include "Image.h"
#include "libpng.h"

Scene::Scene() : camera_(Camera()), source_(Ray3f())
{
	shapes_ = new Shape[1];
}

Scene::Scene(Camera camera, Shape shapes[], Ray3f source)
{
	camera_ = camera;
	shapes_ = shapes;
	source_ = source;
}

Scene::~Scene()
{
	delete[] shapes_;
}

void Scene::render(int width, int height, std::string name )
{
	Image* image = new Image(width, height);
	std::cout << *image << std::endl;
	save_png_to_file(image, (char *) name);
}


