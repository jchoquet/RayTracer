/**
 * \file Ray3f.cpp
 * \brief Implémentation de la classe Ray3f.
 * \author Alexandre DE BOE, Julie CHOQUET
*/

#include "Ray3f.h"

Ray3f::Ray3f() : origin_(Vector3f()), direction_(Vector3f()), inv_direction_(Vector3f(1000000,1000000,1000000)) {
}

Ray3f::Ray3f(Vector3f origin, Vector3f direction) : inv_direction_(Vector3f(1000000,1000000,1000000)){
	float x, y, z;

	origin_ = origin;
	direction_ = direction;

    x = direction_.getX(), y = direction_.getY(), z = direction_.getZ();

    if (x != 0){
        inv_direction_.setX(1/x);
    }
    if (y != 0){
        inv_direction_.setY(1/y);
    }
    if (z != 0){
        inv_direction_.setZ(1/z);
    }
}

Ray3f::~Ray3f() {
}
