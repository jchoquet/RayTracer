/*
 * Image.h
 *
 *  Created on: 12 oct. 2016
 *      Author: Latha
 */

#ifndef SRC_IMAGE_H_
#define SRC_IMAGE_H_

#include <iostream>

#include "Pixel.h"

class Image {
public:
	Image();
	Image(int, int);
	Image(const Image & image);
	~Image();

	int getHeight() const {
		return height_;
	}

	void setHeight(int height) {
		height_ = height;
	}

	void setOnePixel (int x, int y, Pixel pixel)
	{
	    pixels_[width_*y+x] = pixel;
	}

	Pixel getOnePixel (int x, int y)
	{
		return pixels_[width_*y+x];
	}

	Pixel getOnePixel (int i) const
	{
		return pixels_[i];
	}

	int getWidth() const {
		return width_;
	}

	void setWidth(int width) {
		width_ = width;
	}

	Image & operator=(const Image & image);

	friend std::ostream & operator << (std::ostream & st,const Image & image);

	Pixel*& getPixels() {
		return pixels_;
	}

public:
	int width_;
	int height_;
	Pixel* pixels_;
};

#endif /* SRC_IMAGE_H_ */
