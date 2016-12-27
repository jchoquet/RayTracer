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
	// initizialization of all parameters
	double a,b,c;
	double delta;

	double newDistance;
	double d,x,y,z;

	double xA = ray.getOrigin().getX();
	double yA = ray.getOrigin().getY();
	double zA = ray.getOrigin().getZ();

	double xB = ray.getDirection().getX();
	double yB = ray.getDirection().getY();
	double zB = ray.getDirection().getZ();

	double xC = origin_.getX();
	double yC = origin_.getY();
	double zC = origin_.getZ();
	double r = radius_;

	// intersection between line and sphere -> a*d²+b*d+c=0
	// computation of a, b and c
	a = (xB-xA)*(xB-xA) + (yB-yA)*(yB-yA) + (zB-zA)*(zB-zA);
	b = 2*((xB-xA)*(xA-xC)+(yB-yA)*(yA-yC)+(zB-zA)*(zA-zC));
	c = (xA-xC)*(xA-xC) + (yA-yC)*(yA-yC) + (zA-zC)*(zA-zC) - r*r;

	// computation of delta
	delta = b*b - 4*a*c;

	/*if (yB == 0 && zB == 0) {
		cout << a << " * " << b << " * " << c << endl;
		cout << delta;
	}*/

	if (a==0) {
		d = -c/b;
	} else if (delta < 0) {
		return false;
	} else if (delta == 0) {
		d = b/(2*a);
	} else {
		d = min((b-sqrt(delta))/(2*a),(b+sqrt(delta))/(2*a));
	}

	x = xA + d*xB;
	y = yA + d*yB;
	z = zA + d*zB;

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
