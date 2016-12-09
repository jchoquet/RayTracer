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

	// initialization of elements of the scene
	Camera cam(Vector3f(0,0,0),Vector3f(0,0,0));
	Ray3f source(Vector3f(500,200,0), Vector3f(0,0,0));
	Shape* tab_S = new Shape[10];
	tab_S[0] = Sphere(Material(255,127,0,0), Vector3f(500,0,0), (float) 50);

	// initialization of the scene
	Scene scene(cam, tab_S, source);

	// computing the image
	scene.render(100,100,"hello.png");

	return 0;
}
