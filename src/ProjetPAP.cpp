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
#include <cmath>

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

	/*
	 * Initialisation des différents paramètres de l'image
	 */

	// Taille de l'image
	int height = 2800;
	int width = 2800;

	// Position de l'image
	int x_image = 800;
	int y_topleft_image = 1400;
	int z_topleft_image = -1400;

	/*
	 * Initialisation des différents paramètres de la scène
	 */

	// Nombre d'objets présents sur la scène
	int nb_shape = 12;

	// Création de la caméra
	Camera cam(Vector3f(0,0,0),Vector3f(0,0,0));

	// Création de la source de lumière
	Vector3f source(5800,0,-3598);

	// Création du tableau d'objets contenant nb_shape objets
	vector<Shape*> tab_S;
	tab_S.reserve(nb_shape);

	/*
	 * Ajout des objets
	 */
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(2000,-3600,-3600), Vector3f(4000,1,7200))); // panneau de droite
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(2000, 3600,-3600), Vector3f(4000,1,7200))); // panneau de gauche
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(2000, -3600,3600), Vector3f(4000,7200,1))); // panneau du bas
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(2000, -3600,-3600), Vector3f(4000,7200,1))); // panneau du haut
	tab_S.push_back(new Quad(Material(147,207,220,0), Vector3f(6000, -3600,-3600), Vector3f(1,7200,7200))); // panneau du fond

	tab_S.push_back(new Sphere(Material(255,127,0,0.72), Vector3f(4200,1800,2600), (float) 800)); // sphere

	tab_S.push_back(new Quad(Material(192,120,220,0), Vector3f(4000,-2500,-1200), Vector3f(500,1,1800))); // panneau de droite du cube
	tab_S.push_back(new Quad(Material(192,120,220,0), Vector3f(4000, -700,-1200), Vector3f(500,1,1800))); // panneau de gauche du cube
	tab_S.push_back(new Quad(Material(192,120,220,0), Vector3f(4000, -2500,600), Vector3f(500,1800,1))); // panneau du bas du cube
	tab_S.push_back(new Quad(Material(192,120,220,0), Vector3f(4000, -2500,-1200), Vector3f(500,1800,1))); // panneau du haut du cube
	tab_S.push_back(new Quad(Material(192,120,220,0), Vector3f(4000, -2500,-1200), Vector3f(1,1800,1800))); // panneau du fond du cube
	tab_S.push_back(new Quad(Material(192,120,220,0), Vector3f(4000, -2500, -1200), Vector3f(1,1800,1800))); // panneau du devant du cube

	// Initialisation de la scène
	Scene scene(cam, tab_S, nb_shape, source);

	// Calcul de l'image et sauvegarde
	scene.render(height, width, "rendu.png", x_image, y_topleft_image, z_topleft_image);

	return 0;
}
