/*
 * Pixel.h
 *
 *  Created on: 12 oct. 2016
 *      Author: Latha
 */

#include <cstdint>
#include <ostream>

#ifndef SRC_PIXEL_H_
#define SRC_PIXEL_H_

class Pixel {
public:
	Pixel();
	Pixel(uint8_t, uint8_t, uint8_t);
	Pixel(const Pixel & pixel);

	~Pixel();

	uint8_t getB() const {
		return b_;
	}

	void setB(uint8_t b) {
		b_ = b;
	}

	uint8_t getG() const {
		return g_;
	}

	void setG(uint8_t g) {
		g_ = g;
	}

	uint8_t getR() const {
		return r_;
	}

	void setR(uint8_t r) {
		r_ = r;
	}

	Pixel & operator=(const Pixel & pixel);

	friend std::ostream & operator << (std::ostream & st, const Pixel & pixel);

private:
	uint8_t r_;
	uint8_t g_;
	uint8_t b_;
};

#endif /* SRC_PIXEL_H_ */
