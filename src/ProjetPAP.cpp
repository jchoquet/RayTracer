//============================================================================
// Name        : ProjetPAP.cpp
// Author      : Alexandre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "Scene.h"
#include "Vector3f.h"
#include "Camera.h"
#include "Shape.h"
#include "Sphere.h"
#include "Quad.h"
#include "libpng.h"
#include "Image.h"

using namespace std;


int main() {
	cout << "!!!Hello World!!!" << endl;


	// parameters
	int nb_shape = 7;
	int height = 2800;
	int width = 2800;
	int x_image = 800;
	int y_topleft_image = 1400;
	int z_topleft_image = -1400;

	// initialization of elements of the scene
	Camera cam(Vector3f(0,0,0),Vector3f(0,0,0));
	Vector3f source(2800,0,-3598);
	vector<Shape*> tab_S;
	tab_S.reserve(nb_shape);
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(2000,-3600,-3600), Vector3f(4000,1,7200))); // panneau de droite
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(2000, 3600,-3600), Vector3f(4000,1,7200))); // panneau de gauche
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(2000, -3600,3600), Vector3f(4000,7200,1))); // panneau du bas
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(2000, -3600,-3600), Vector3f(4000,7200,1))); // panneau du haut
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(6000, -3600,-3600), Vector3f(1,7200,7200))); // panneau du fond
	tab_S.push_back(new Sphere(Material(155,127,220,0), Vector3f(5200,1200,0), (float) 300)); // sphere
	tab_S.push_back(new Sphere(Material(255,127,0,0), Vector3f(4800,0,0), (float) 800)); // sphere


	// initialization of the scene
	Scene scene(cam, tab_S, nb_shape, source);

	// computing the image
	scene.render(height,width,"hello.png", x_image, y_topleft_image, z_topleft_image);

	return 0;
}
