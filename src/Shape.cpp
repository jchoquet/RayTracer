/*
 * Shape.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include "Shape.h"

Shape::Shape() : matter_(Material())
{

}

Shape::Shape(const Material& matter) {
	matter_ = matter;
}

Shape::~Shape() {

}

bool Shape::isHit(Ray3f ray){
	// TODO isHit method to code
}

const Ray3f& Shape::reflect(const Ray3f& ray) {
	// TODO reflect method to code
}
