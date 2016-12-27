/**
 * \file Pixel.cpp
 * \brief Implémentation de la classe Pixel.
 * \author Alexandre DE BOE, Julie CHOQUET
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

void Pixel::luminosity(double level)
{
	double tempR,tempG,tempB;

	tempR = r_ - level + 155;
	tempG = g_ - level + 155;
	tempB = b_ - level + 155;

	if (tempR > 255) {
		r_ = 255;
	} else if (tempR < 0) {
		r_ = 0;
	} else {
		r_ = (uint8_t) tempR;
	}

	if (tempG > 255) {
		g_ = 255;
	} else if (tempG < 0) {
		g_ = 0;
	} else {
		g_ = (uint8_t) tempG;
	}

	if (tempB > 255) {
		b_ = 255;
	} else if (tempB < 0) {
		b_ = 0;
	} else {
		b_ = (uint8_t) tempB;
	}
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
