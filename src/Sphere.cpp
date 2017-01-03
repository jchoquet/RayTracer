/**
 * \file Sphere.cpp
 * \brief Implémentation de la classe Sphere.
 * \author Alexandre DE BOE, Julie CHOQUET
*/

#include <iostream>
#include <algorithm>
#include <cmath>

#include "Sphere.h"

using namespace std;

Sphere::Sphere() : Shape(), origin_(Vector3f()), radius_(0){
}

Sphere::Sphere(const Material& matter, const Vector3f& origin, float radius) : Shape(matter) {
	origin_ = origin;
	radius_ = radius;
}

Sphere::~Sphere() {
}
bool Sphere::isHit(Ray3f ray, double* distance, double* px, double* py, double* pz) {

    /* Initialisation des variables */

    // Variables pour la résolution de l'équation paramétrique d'intersection
	double a, b, c;
	double delta;

	double newDistance; // Contiendra la distance entre l'origine du rayon et l'intersection
	double d, x, y, z; // Calcul des coordonnées de l'intersection

	// On récupère les coordonnées d'origine du rayon
	double xA = ray.getOrigin().getX();
	double yA = ray.getOrigin().getY();
	double zA = ray.getOrigin().getZ();

	// On récupère les coordonnées de direction du rayon
	double xB = ray.getDirection().getX()-xA;
	double yB = ray.getDirection().getY()-yA;
	double zB = ray.getDirection().getZ()-zA;

	// On récupère le rayon de la sphère ainsi que les coordonnées de son centre
	double xC = origin_.getX();
	double yC = origin_.getY();
	double zC = origin_.getZ();
	double r = radius_;

	/* Calcul de l'intersection entre le rayon et la sphère */

	// L'intersection entre le rayon et la sphère amène l'équation du 2nd degré : a*d² + b*d + c = 0
	// On calcule les coefficients de cette équation
	a = xB*xB + yB*yB + zB*zB;
	b = 2*(xB*(xA-xC)+yB*(yA-yC)+zB*(zA-zC));
	c = (xA-xC)*(xA-xC) + (yA-yC)*(yA-yC) + (zA-zC)*(zA-zC) - r*r;

	// Calcul du discriminant
	delta = b*b - 4*a*c;

	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "++" << xA << " / " << yA << " / " << zA << endl;}
	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "==" << xB+xA << " / " << yB+yA << " / " << zB+zA << endl;}
	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "^^" << xC << " / " << yC << " / " << zC << endl;}

	/*if (yB+yA == 0 && zB+zA == 0) {
		cout << a << " * " << b << " * " << c << endl;
		cout << delta << endl;
	}*/

    // Calcul de la solution (paramètre d)
	if (a == 0) {
		d = -c/b;
	} else if (delta < 0) { /* Pas de solution */
		return false;
	} else if (delta == 0) { /* Unique solution */
		d = b/(2*a);
	} else { /* Deux solutions */
		d = min((-b-sqrt(delta))/(2*a),(-b+sqrt(delta))/(2*a));
	}

	// Injection du paramètre d dans l'équation du rayon
	x = xA + d*xB;
	y = yA + d*yB;
	z = zA + d*zB;

	// détection de la face de la sphere pour éclairer seulement la face dirigée vers la lumière
	// si la nouvelle intersection est la meme qu'avant --> l'intersection était celle la plus proche de la lumiere --> face eclairée
	if (d>0.99 && d<1.01) {
		return false;
	} else if (d<0) { // détection de la direction du rayon pour éviter les ombres doubles
		return false;
	}

	// On fait pointer vers les coordonnées d'intersection
	*px = x;
	*py = y;
	*pz = z;

	// Calcul de la distance entre l'origine du rayon et le point d'intersection
	newDistance = sqrt(x*x + y*y + z*z);

	// On compare la distance trouvée avec celle de la précedente intersection
	if (*distance < 0 || newDistance < *distance) {
		*distance = newDistance;
		return true;
	} else {
		return false;
	}
}
