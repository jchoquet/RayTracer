/**
 * \file Quad.cpp
 * \brief Implémentation de la classe Quad.
 * \author Alexandre DE BOE, Julie CHOQUET
*/

#include <algorithm>
#include <iostream>
#include <cmath>

#include "Quad.h"
#include "Vector3f.h"

using namespace std;

Quad::Quad() : Shape(), origin_(Vector3f()), size_(Vector3f()){
}

Quad::Quad(const Material& matter, Vector3f origin, Vector3f nsize) : Shape(matter) {
	origin_ = origin;
	size_ = nsize;
}

Quad::~Quad(){
}

bool Quad::isHit(Ray3f ray3f, double* distance, double* px, double* py, double* pz) {

  /* Initialisation des variables */

	bool res; // Variable résultat

	double newDistance; // Contiendra la distance entre l'origine du rayon et l'intersection
	double d, x, y, z; // Calcul des coordonnées de l'intersection

	// On récupère les coordonnées du centre du cube
	double x0 = origin_.getX();
	double y0 = origin_.getY();
	double z0 = origin_.getZ();

	// On calcule les coordonnées de l'extrémité du cube grâce au vecteur size_
	double x1 = x0 + size_.getX();
	double y1 = y0 + size_.getY();
	double z1 = z0 + size_.getZ();

	// On récupère les coordonnées de l'origin du rayon considéré
	double xi = ray3f.getOrigin().getX();
	double yi = ray3f.getOrigin().getY();
	double zi = ray3f.getOrigin().getZ();

	// Variables nécessaires à l'application de la méthode de la dalle
	double tmin, tmax, tymin, tymax, tzmin, tzmax;
	double divx = (ray3f.getInvDirection().getX() != 0) ? ray3f.getInvDirection().getX() : 1000000;
	double divy = (ray3f.getInvDirection().getY() != 0) ? ray3f.getInvDirection().getY() : 1000000;
	double divz = (ray3f.getInvDirection().getZ() != 0) ? ray3f.getInvDirection().getZ() : 1000000;

	// On récupère les coordonnées de la direction du rayon considéré
	double xc = ray3f.getDirection().getX()-xi;
	double yc = ray3f.getDirection().getY()-yi;
	double zc = ray3f.getDirection().getZ()-zi;

	//cout << xc << "/" << x0 << "/" << xi << endl;

	/* Calcul de l'intersection entre le rayon et le cube avec la méthode de la dalle */

	// Pour chaque coordonnée, on détermine la borne inférieure et la borne supérieure

	if (divx >= 0) {
		tmin = (x0-xi)*divx;
		tmax = (x1-xi)*divx;
	} else {
		tmin = (x1-xi)*divx;
		tmax = (x0-xi)*divx;
	}

	if (divy >= 0) {
		tymin = (y0-yi)*divy;
		tymax = (y1-yi)*divy;
	} else {
		tymin = (y1-yi)*divy;
		tymax = (y0-yi)*divy;
	}

	if (divz >= 0) {
		tzmin = (z0-zi)*divz;
		tzmax = (z1-zi)*divz;
	} else {
		tzmin = (z1-zi)*divz;
		tzmax = (z0-zi)*divz;
	}

	//cout << tmin << " " << tymin << " " << tzmin << " - " << tmax << " " << tymax << " " << tzmax << endl;

	// On détermine s'il existe une intersection avec la méthode de la dalle

	if (x0 == x1) {
		res = (max(tymin,tzmin) <= min(tymax,tzmax));
	} else if (y0 == y1){
		res = (max(tmin,tzmin) <= min(tmax,tzmax));
	} else if (z0 == z1){
		res = (max(tmin,tymin) <= min(tmax,tymax));
	} else {
		res = (max(tmin,max(tymin,tzmin)) <= min(tmax,min(tymax,tzmax)));
	}

	// S'il existe une intersection, on calcule le point d'intersection
	if (res) {

		if ((x1-x0) < 2) {
			d = tmin;
		} else if ((y1-y0) < 2) {
			d = tymin;
		} else if ((z1-z0) < 2) {
			d = tzmin;
		} else {
			d = max(tmin,max(tymin,tzmin));
		}

		// Injection du paramètre d dans l'équation du rayon
		x = xi + d*xc;
		y = yi + d*yc;
		z = zi + d*zc;

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
}
