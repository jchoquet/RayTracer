//============================================================================
// Name        : ProjetPAP.cpp
// Author      : Alexandre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Scene.h"
#include "Vector3f.h"
#include "Camera.h"
#include "Shape.h"
#include "Sphere.h"

using namespace std;


int main() {
	cout << "!!!Hello World!!!" << endl;

	// parameters
	int nb_shape = 1;
	int height = 100;
	int width = 100;
	int x_image = 200;
	int y_topleft_image = 50;
	int z_topleft_image = -50;

	// initialization of elements of the scene
	Camera cam(Vector3f(0,0,0),Vector3f(0,0,0));
	Ray3f source(Vector3f(500,200,0), Vector3f(0,0,0));
	Shape* tab_S = new Shape[nb_shape];
	//tab_S[0] = Sphere(Material(255,127,0,0), Vector3f(500,0,0), (float) 50);

	// initialization of the scene
	Scene scene(cam, tab_S, nb_shape, source);

	// computing the image
	scene.render(height,width,"hello.png", x_image, y_topleft_image, z_topleft_image);

	return 0;
}
