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

using namespace std;


int main() {
	cout << "!!!Hello World!!!" << endl;

	// parameters
	int nb_shape = 6;
	int height = 700;
	int width = 700;
	int x_image = 200;
	int y_topleft_image = 350;
	int z_topleft_image = -350;

	// initialization of elements of the scene
	Camera cam(Vector3f(0,0,0),Vector3f(0,0,0));
	Ray3f source(Vector3f(500,200,0), Vector3f(0,0,0));
	vector<Shape*> tab_S;
	tab_S.reserve(nb_shape);
	tab_S.push_back(new Sphere(Material(255,127,0,0), Vector3f(500,0,0), (float) 200));
	tab_S.push_back(new Quad(Material(127,147,200,0), Vector3f(500,-900,-900), Vector3f(1000,1,1800))); // panneau de droite
	tab_S.push_back(new Quad(Material(127,187,200,0), Vector3f(500, 900,-900), Vector3f(1000,1,1800))); // panneau de gauche
	tab_S.push_back(new Quad(Material(127,227,100,0), Vector3f(500, -900,900), Vector3f(1000,1800,1))); // panneau du bas
	tab_S.push_back(new Quad(Material(127,267,100,0), Vector3f(500, -900,-900), Vector3f(1000,1800,1))); // panneau du haut
	tab_S.push_back(new Quad(Material(27,267,100,0), Vector3f(1500, -900,-900), Vector3f(1,1800,1800))); // panneau du fond
	//tab_S.push_back(new Sphere(Material(255,127,0,0), Vector3f(500,0,0), (float) 300)); // sphere

	// initialization of the scene
	Scene scene(cam, tab_S, nb_shape, source);

	// computing the image
	scene.render(height,width,"hello.png", x_image, y_topleft_image, z_topleft_image);

	return 0;
}
