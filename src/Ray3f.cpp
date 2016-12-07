/*

 * Ray3f.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include "Ray3f.h"

Ray3f::Ray3f() : origin_(Vector3f()), direction_(Vector3f())
{

}

Ray3f::Ray3f(Vector3f origin, Vector3f direction) {
	origin_ = origin;
	direction_ = direction;
}

Ray3f::~Ray3f() {

}

