/*
 * Quad.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include "Quad.h"
#include "Vector3f.h"

Quad::Quad() : Shape(), origin_(Vector3f()), width_(Vector3f()), height_(Vector3f())
{

}

Quad::Quad(Vector3f origin, Vector3f width, Vector3f height)
{
	Shape();
	origin_ = origin;
	width_ = width;
	height_ = height;
}

Quad::~Quad()
{

}

