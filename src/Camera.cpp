/*
 * Camera.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include "Camera.h"

Camera::Camera() : position_(Vector3f()), direction_(Vector3f())
{

}

Camera::Camera(Vector3f position, Vector3f direction)
{
	position_ = position;
	direction_ = direction;
}

Camera::~Camera()
{

}

