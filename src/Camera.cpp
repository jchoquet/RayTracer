/**
 * \file Camera.cpp
 * \brief Implémentation de la classe Camera.
 * \author Alexandre DE BOE, Julie CHOQUET
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

