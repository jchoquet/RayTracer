/*
 * Vector3f.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include "Vector3f.h"

Vector3f::Vector3f(): x_(0),y_(0), z_(0)
{

}

Vector3f::Vector3f(float x, float y, float z)
{
	x_ = x;
	y_ = y;
	z_ = z;
}

Vector3f::~Vector3f()
{
}

