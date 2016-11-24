/*
 * Material.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include "Material.h"

Material::Material() : r_(0), g_(0), b_(0), shininess_(0)
{

}

Material::Material(float r, float g, float b, float shininess)
{
	r_ = r;
	g_ = g;
	b_ = b;
	shininess_ = shininess;
}

Material::~Material()
{

}

