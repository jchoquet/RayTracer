/**
 * \file Image.cpp
 * \brief Implémentation de la classe Image.
 * \author Alexandre DE BOE, Julie CHOQUET
*/

#include <stdexcept>
#include <iostream>

#include "Image.h"

Image::Image() : width_(20), height_(15){
    // Création du tableau de pixels
	pixels_ = new Pixel[300];

	// Remplissage du tableau de pixels avec des pixels de couleur blanche
	for (int i=0; i<300; i++)
	{
		pixels_[i] = Pixel(255,255,255);
	}
}

Image::Image(int width, int height){

    // Vérification de la validité des arguments
	if (width<1 || height<1)
	{
		throw std::runtime_error("Incompatible value : value > 0 required");
	}

	// Initialisation des paramètres
	width_ = width;
	height_ = height;
	pixels_ = new Pixel[width*height];
	for (int i=0;i<width*height;i++)
	{
		pixels_[i] = Pixel(255,255,255);
	}
}

Image::Image(const Image& image){
	width_ = image.getWidth();
	height_ = image.getHeight();
	pixels_ = new Pixel[width_*height_];
	for (int i=0; i<width_*height_; i++)
	{
		pixels_[i] = image.getOnePixel(i);
	}
}

Image::~Image(){
	delete[] pixels_;
}

Image& Image::operator =(const Image& image){
	// TODO operator= pour Image
}

std::ostream & operator <<(std::ostream & st,const Image & image){
	for (int i=0; i<image.getHeight()*image.getWidth(); i++)
	{
		st << image.getOnePixel(i) << ", ";
		if (0==(i+1)%image.getWidth() && i!=0)
		{
			st << std::endl;
		}
	}

	return st;
}
