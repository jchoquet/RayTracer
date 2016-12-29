/**
 * \file Sphere.cpp
 * \brief Implémentation de la classe Shape.
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
	double xB = ray.getDirection().getX();
	double yB = ray.getDirection().getY();
	double zB = ray.getDirection().getZ();

	// On récupère le rayon de la sphère ainsi que les coordonnées de son centre
	double xC = origin_.getX();
	double yC = origin_.getY();
	double zC = origin_.getZ();
	double r = radius_;

	/* Calcul de l'intersection entre le rayon et la sphère */

	// L'intersection entre le rayon et la sphère amène l'équation du 2nd degré : a*d² + b*d + c = 0
	// On calcule les coefficients de cette équation
	a = (xB-xA)*(xB-xA) + (yB-yA)*(yB-yA) + (zB-zA)*(zB-zA);
	b = 2*((xB-xA)*(xA-xC)+(yB-yA)*(yA-yC)+(zB-zA)*(zA-zC));
	c = (xA-xC)*(xA-xC) + (yA-yC)*(yA-yC) + (zA-zC)*(zA-zC) - r*r;

	// Calcul du discriminant
	delta = b*b - 4*a*c;

	/*if (yB == 0 && zB == 0) {
		cout << a << " * " << b << " * " << c << endl;
		cout << delta;
	}*/

    // Calcul de la solution (paramètre d)
	if (a == 0) {
		d = -c/b;
	} else if (delta < 0) { /* Pas de solution */
		return false;
	} else if (delta == 0) { /* Unique solution */
		d = b/(2*a);
	} else { /* Deux solutions */
		d = min((b-sqrt(delta))/(2*a),(b+sqrt(delta))/(2*a));
	}

	// Injection du paramètre d dans l'équation du rayon
	x = xA + d*xB;
	y = yA + d*yB;
	z = zA + d*zB;

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
