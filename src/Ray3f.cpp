/**
 * \file Ray3f.cpp
 * \brief Implémentation de la classe Ray3f.
 * \author Alexandre DE BOE, Julie CHOQUET
*/

#include "Ray3f.h"

Ray3f::Ray3f() : origin_(Vector3f()), direction_(Vector3f()), inv_direction_(Vector3f()) {
}

Ray3f::Ray3f(Vector3f origin, Vector3f direction) : inv_direction_(Vector3f()){
	float x, y, z;

	origin_ = origin;
	direction_ = direction;

	x = direction_.getX(), y = direction_.getY(), z = direction_.getZ();

	if (x != 0){
		inv_direction_.setX(1/(x-origin_.getX()));
	}
	if (y != 0){
		inv_direction_.setY(1/(y-origin_.getY()));
	}
	if (z != 0){
		inv_direction_.setZ(1/(z-origin_.getZ()));
	}
}

Ray3f::~Ray3f() {
}
