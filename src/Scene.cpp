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

Scene::Scene() : camera_(Camera()), source_(Vector3f()), nb_shape_(1)
{
	shapes_.push_back(new Sphere(Material(255,127,0,0), Vector3f(500,0,0), (float) 50));
}

Scene::Scene(Camera& camera, std::vector<Shape*> shapes, int nb_shape, Vector3f& source)
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

	double r,g,b;

	bool toChange,isHit;
	double distance, lightDistance, shadowDistance;
	double* pdistance = &distance, *pLightDistance = &lightDistance;

	double x,y,z, lx,ly,lz;
	double *px = &x,*py = &y,*pz = &z, *plx = &lx, *ply = &ly, *plz = &lz;



	// creation of the image with associated width and height
	Image* image = new Image(width, height);

	for (i=0;i<height;i++) {
		for(j=0;j<width;j++) {
			Ray3f line (camera_.getPosition(), Vector3f(x_image, (y_topleft_image - i), (z_topleft_image + j)));

			distance = -1;
			image->setOnePixel(i,j, Pixel(000,127,255));

			//cout << y_topleft_image - i << " -- " << z_topleft_image + j << endl;

			for(int k=0; k<shapes_.size(); k++) {
				//if (line.getDirection().getY() == 0 && line.getDirection().getZ() == 0) {cout << distance << " @ " << x << "/" << y << "/" << z << endl;}
				toChange = shapes_[k]->isHit(line,pdistance,px,py,pz);
				//if (line.getDirection().getY() == 0 && line.getDirection().getZ() == 0) {cout << distance << " @ " << x << "/" << y << "/" << z << "//" << endl;}
				//cout << " [" << toChange << "] ";
				if (toChange) {

					//cout << x << " " << y << " " << z << endl;
					Ray3f lightRay (source_, Vector3f(x,y,z));


					shadowDistance = sqrt((x-source_.getX())*(x-source_.getX()) + (y-source_.getY())*(y-source_.getY()) + (z-source_.getZ())*(z-source_.getZ()));

					Pixel newPix (shapes_[k]->getMatter().getR(), shapes_[k]->getMatter().getG(), shapes_[k]->getMatter().getB());

					// the computation of the light is separate in two functions to avoid to much light around the light source
					if (shadowDistance < 750) {
						newPix.luminosity(0.2*shadowDistance-55);
					} else {
						newPix.luminosity(0.02*shadowDistance+80);
					}

					//if (line.getDirection().getY() == 0 && line.getDirection().getZ() == 0) {cout << (int) newPix.getR() << "[" << (int) newPix.getG() << "]" << (int) newPix.getB() << endl;}

					image->setOnePixel(i,j, newPix);

					lightDistance = -1;

					for(int l=5; l<shapes_.size(); l++) {
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
				}
			}
		}
	}

	// we save the image to an png file
	save_png_to_file(image, (char *) name);

}


