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

Sphere::Sphere() : Shape(), origin_(Vector3f()), radius_(0)
{

}

Sphere::Sphere(const Material& mater,const Vector3f& origin, float radius) : Shape(mater) {

	origin_ = origin;
	radius_ = radius;
}

Sphere::~Sphere() {

}

bool Sphere::isHit(Ray3f ray, double* distance,double* px,double* py, double* pz)
{
	//cout << ray.getDirection().getX() << " " << ray.getDirection().getY() << " " << ray.getDirection().getZ() << "///" << endl;

	// initizialization of all parameters
	double a,b,c;
	double delta;

	double newDistance;
	double d,x,y,z;

	double xA = ray.getOrigin().getX();
	double yA = ray.getOrigin().getY();
	double zA = ray.getOrigin().getZ();

	double xB = ray.getDirection().getX()-xA;
	double yB = ray.getDirection().getY()-yA;
	double zB = ray.getDirection().getZ()-zA;



	double xC = origin_.getX();
	double yC = origin_.getY();
	double zC = origin_.getZ();
	double r = radius_;

	//détecter si le point est sur la sphere

	// intersection between line and sphere -> a*d²+b*d+c=0
	// computation of a, b and c

	//a = (xB-xA)*(xB-xA) + (yB-yA)*(yB-yA) + (zB-zA)*(zB-zA);
	a = xB*xB + yB*yB + zB*zB;
	//b = 2*((xB-xA)*(xA-xC)+(yB-yA)*(yA-yC)+(zB-zA)*(zA-zC));
	b = 2*(xB*(xA-xC)+yB*(yA-yC)+zB*(zA-zC));
	//c = (xA-xC)*(xA-xC) + (yA-yC)*(yA-yC) + (zA-zC)*(zA-zC) - r*r;
	c = (xA-xC)*(xA-xC) + (yA-yC)*(yA-yC) + (zA-zC)*(zA-zC) - r*r;

	// computation of delta
	delta = b*b - 4*a*c;

	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "++" << xA << " / " << yA << " / " << zA << endl;}
	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "==" << xB+xA << " / " << yB+yA << " / " << zB+zA << endl;}
	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "^^" << xC << " / " << yC << " / " << zC << endl;}

	/*if (yB+yA == 0 && zB+zA == 0) {
		cout << a << " * " << b << " * " << c << endl;
		cout << delta << endl;
	}*/

	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "++" << (xB+xA-xC)*(xB+xA-xC)+(yB+yA-yC)*(yB+yA-yC)+(zB+zA-zC)*(zB+zA-zC) << endl;}
	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "--" << sqrt((xB-xA)*(xB-xA)+(yB-yA)*(yB-yA)+(zB-zA)*(zB-zA)) << endl;}

	if (a==0) {
		d = -c/b;
	} else if (delta < 0) {
		return false;
	} else if (delta == 0) {
		d = -b/(2*a);
	} else {
		d = min((-b-sqrt(delta))/(2*a),(-b+sqrt(delta))/(2*a));
	}

	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "~~ " << d << " ~~" << endl;}

	x = xA + d*xB;
	y = yA + d*yB;
	z = zA + d*zB;

	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << "||" << sqrt((x-xA)*(x-xA)+(y-yA)*(y-yA)+(z-zA)*(z-zA)) << endl;}

	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << xB+xA << " / " << yB+yA << " / " << zB+zA << endl;}
	//if (ray.getDirection().getY() == 0 && ray.getDirection().getZ() == 0) {cout << x << " / " << y << " / " << z << endl;}

	//if (d>0.99 && d<1.01) {cout << "##########################" << d << "##########################" << endl;}

	// détection de la face de la sphere pour éclairer seulement la face dirigée vers la lumière
	// si la nouvelle intersection est la meme qu'avant --> l'intersection était celle la plus proche de la lumiere --> face eclairée
	if (d>0.99 && d<1.01) {
		return false;
	}

	*px = x;
	*py = y;
	*pz = z;

	newDistance = sqrt(x*x + y*y + z*z);

	if (*distance < 0 || newDistance < *distance) {
		*distance = newDistance;
		return true;
	} else {
		return false;
	}
}
