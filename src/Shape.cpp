/**
 * \file Shape.cpp
 * \brief Implémentation de la classe Shape.
 * \author Alexandre DE BOE, Julie CHOQUET
*/

#include "Shape.h"

Shape::Shape() : matter_(Material()) {
}

Shape::Shape(const Material& matter) {
	matter_ = matter;
}

Shape::~Shape() {
}

const Ray3f& Shape::reflect(const Ray3f& ray) {
	// TODO reflect method to code
}
