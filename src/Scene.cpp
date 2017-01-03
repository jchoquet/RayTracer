/**
 * \file Scene.cpp
 * \brief Implémentation de la classe Scene.
 * \author Alexandre DE BOE, Julie CHOQUET
*/

#include <iostream>
#include <cmath>

#include "Scene.h"
#include "Material.h"
#include "Image.h"
#include "libpng.h"
#include "Vector3f.h"
#include "Ray3f.h"
#include "Sphere.h"
#include "Shape.h"

using namespace std;

Scene::Scene() : camera_(Camera()), source_(Vector3f()), nb_shape_(1) {
	shapes_.push_back(new Sphere(Material(255,127,0,0), Vector3f(500,0,0), (float) 50));
}

Scene::Scene(Camera& camera, std::vector<Shape*> shapes, int nb_shape, Vector3f& source){
	camera_ = camera;
	shapes_ = shapes;
	source_ = source;
	nb_shape_ = nb_shape;
}

Scene::~Scene(){
	for (int unsigned i=0;i<shapes_.size();i++) {
		delete shapes_[i];
	}
	shapes_.shrink_to_fit();
}

void Scene::render(int width, int height, char* name, int x_image, int y_topleft_image, int z_topleft_image)
{
	// Variables relatives au point d'intersection


	double r,g,b;
	bool toChange; // Intersection entre le rayon camera-pixel et un objet
	double distance, x, y, z; // Position et distance d'un point d'intersection
	double * pdistance = &distance, *px = &x,*py = &y, *pz = &z; // Pointeurs associés
    double shadowDistance; // Distance entre un point d'intersection et la source de lumière

    // Variables permettant de déterminer la luminosité d'un pixel
    bool isHit;
	double lightDistance;
	double *pLightDistance = &lightDistance;
	double lx, ly, lz;
	double *plx = &lx, *ply = &ly, *plz = &lz;

	// Création de l'image
	Image* image = new Image(width, height);

	// On parcourt l'image pixel par pixel de gauche à droite et de haut en bas
	for (int i=0; i<height; i++)
    {
		for(int j=0; j<width; j++)
		{
		    // On initialise la variable distance à -1
		    distance = -1;

		    // On calcule la rayon passant par la camera et le pixel correspondant
			Ray3f line (camera_.getPosition(), Vector3f(x_image, (y_topleft_image - i), (z_topleft_image + j)));

            // On initialise la couleur du pixel (bleu clair)
			image->setOnePixel(i, j, Pixel(000,127,255));

			//cout << y_topleft_image - i << " -- " << z_topleft_image + j << endl;

			// On parcourt le tableau d'objets présents sur la scène
			for(int unsigned k=0; k<shapes_.size(); k++)
            {
                // Pour chaque objet, on regarde s'il y a intersection entre celui-ci et le rayon reliant la caméra et le pixel
				toChange = shapes_[k]->isHit(line, pdistance, px, py, pz);

				//cout << " [" << toChange << "] ";

				// S'il y a une intersection sauvegardée, on cherche l'intensité de la lumière en ce point
				if (toChange) {

					//cout << x << " " << y << " " << z << endl;

					// Création du rayon allant de la source de lumière dans la direction du point d'intersection
					Ray3f lightRay (source_, Vector3f(x, y, z));

					// Calcul de la distance entre la source de lumière et le point d'intersection
					shadowDistance = sqrt((x-source_.getX())*(x-source_.getX()) + (y-source_.getY())*(y-source_.getY()) + (z-source_.getZ())*(z-source_.getZ()));

					// Création d'un pixel de la même couleur que le matériel composant l'objet
					Pixel newPix (shapes_[k]->getMatter().getR(), shapes_[k]->getMatter().getG(), shapes_[k]->getMatter().getB());

					// On calcule l'impact de la luminosité en tenant compte de la distance avec la source de lumière
					// Cela permet d'éviter une luminosité trop importante près de la source
					if (shadowDistance < 750) {
						newPix.luminosity(0.2*shadowDistance-55);
					} else {
						newPix.luminosity(0.02*shadowDistance+80);
					}

					//if (line.getDirection().getY() == 0 && line.getDirection().getZ() == 0) {cout << (int) newPix.getR() << "[" << (int) newPix.getG() << "]" << (int) newPix.getB() << endl;}
					image->setOnePixel(i,j, newPix);

					// On vérifie que le rayon lightRay ne rencontre pas d'autre objet avant le point d'intersection
					// Si oui, le pixel devient de couleur noire
					lightDistance = -1;
					for(int unsigned l=5; l<shapes_.size(); l++) {
						//cout << lightRay.getDirection().getX() << " - " << lightRay.getDirection().getY() << " - " << lightRay.getDirection().getZ() << endl;
						isHit = shapes_[l]->isHit(lightRay,pLightDistance,plx,ply,plz);
						//if (line.getDirection().getY() == 0 && line.getDirection().getZ() == 0) {cout << "[" << isHit << "]" << endl;}


						if (isHit) {
							//if (line.getDirection().getY() == 0 && line.getDirection().getZ() == 0) {cout << "[" << isHit << "]" << endl;}
							r = .5*image->getOnePixel(i,j).getR();
							g = .5*image->getOnePixel(i,j).getG();
							b = .5*image->getOnePixel(i,j).getB();

							if (r<0) {
								r = 0;
							} else if (g<0) {
								g = 0;
							} else if (g<0) {
								b = 0;
							}

							image->setOnePixel(i,j, Pixel(r,g,b));
						}
					}

				} // Fin de la boucle suite à une intersection avec un objet
			} // Fin de la boucle de parcours du tableau d'objets
		} // Fin de la boucle sur la largeur de l'image
	} // Fin de la boucle sur la hauteur de l'image

	// Sauvegarde de l'image dans un fichier pngg
	save_png_to_file(image, (char *) name);
}
