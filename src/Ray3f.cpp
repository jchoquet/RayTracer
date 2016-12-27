/**
 * \file Ray3f.cpp
 * \brief Implémentation de la classe Ray3f.
 * \author Alexandre DE BOE, Julie CHOQUET
*/

#include "Ray3f.h"

Ray3f::Ray3f() : origin_(Vector3f()), direction_(Vector3f()) {
}

Ray3f::Ray3f(Vector3f origin, Vector3f direction) {
	origin_ = origin;
	direction_ = direction;
}

Ray3f::~Ray3f() {
}
