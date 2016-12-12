/*
 * Pixel.cpp

 *
 *  Created on: 12 oct. 2016
 *      Author: Latha
 */

#include <stdexcept>
#include <iostream>

#include "Pixel.h"

Pixel::Pixel() : r_(255), g_(255), b_(255)
{

}

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b)
{
	if (r<0 || r>255 || g<0 || g>255 || b<0 || b>255)
	{
		throw std::runtime_error("Incompatible value : 8bits int required");
	}

	r_ = r;
	g_ = g;
	b_ = b;
}

Pixel::~Pixel()
{
	// Dtor for Pixel
}

std::ostream & operator << (std::ostream & st, const Pixel & pixel)
{
	st << "[" << pixel.getR() << ", " << pixel.getG() << ", " << pixel.getB() << "]";
	return st;
}

Pixel& Pixel::operator =(const Pixel& pixel)
{
	r_ = pixel.getR();
	g_ = pixel.getG();
	b_ = pixel.getB();

	return *this;
}

Pixel::Pixel(const Pixel& pixel)
{
	r_ = pixel.getR();
	g_ = pixel.getG();
	b_ = pixel.getB();
}
