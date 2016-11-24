/*
 * Sphere.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include "Sphere.h"

Sphere::Sphere() : origin_(Vector3f()), radius_(0)
{

}

Sphere::Sphere(const Vector3f& origin, float radius) {
	origin_ = origin;
	radius_ = radius;
}

Sphere::~Sphere() {

}
