/*
 * Sphere.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include "Sphere.h"

Sphere::Sphere() : Shape(), origin_(Vector3f()), radius_(0)
{

}

Sphere::Sphere(const Material& mater,const Vector3f& origin, float radius) : Shape(mater) {

	origin_ = origin;
	radius_ = radius;
}

Sphere::~Sphere() {

}
