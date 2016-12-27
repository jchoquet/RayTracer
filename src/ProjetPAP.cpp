/**
 * \file ProjetPAP.cpp
 * \brief Fichier principal.
 * \author Alexandre DE BOE, Julie CHOQUET
 *
 * \details Créé la scène et l'image de rendu puis la sauvegarde.
 *
*/

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

	// Déclaration des différents paramètres
	int nb_shape = 7;
	int height = 2800;
	int width = 2800;
	int x_image = 800;
	int y_topleft_image = 1400;
	int z_topleft_image = -1400;

	// Initialisation des différents élèments composant la scène
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


	// Initialisation de la scène
	Scene scene(cam, tab_S, nb_shape, source);

	// Calcul de l'image et sauvegarde
	scene.render(height,width,"hello.png", x_image, y_topleft_image, z_topleft_image);

	return 0;
}
