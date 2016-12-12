/*
 * Sphere.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include <iostream>

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

bool Sphere::isHit(Ray3f ray)
{
	// initizialization of all parameters
		float a,b,c;
		float delta;

		int xA = ray.getOrigin().getX();
		int yA = ray.getOrigin().getY();
		int zA = ray.getOrigin().getZ();

		int xB = ray.getDirection().getX();
		int yB = ray.getDirection().getY();
		int zB = ray.getDirection().getZ();

		int xC = origin_.getX();
		int yC = origin_.getY();
		int zC = origin_.getZ();
		float r = radius_;

		// intersection between line and sphere -> a*d²+b*d+c=0
		// computation of a, b and c
		a = (xB-xA)*(xB-xA) + (yB-yA)*(yB-yA) + (zB-zA)*(zB-zA);
		b = 2*((xB-xA)*(xA-xC)+(yB-yA)*(yA-yC)+(zB-zA)*(zA-zC));
		c = (xA-xC)*(xA-xC) + (yA-yC)*(yA-yC) + (zA-zC)*(zA-zC) - r*r;

		cout << a << " * " << b << " * " << c << endl;

		// computation of delta
		delta = b*b - 4*a*c;

		return (delta >= 0);
}
