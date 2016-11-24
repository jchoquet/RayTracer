/*
 * Pixel.h
 *
 *  Created on: 12 oct. 2016
 *      Author: Latha
 */

#ifndef SRC_PIXEL_H_
#define SRC_PIXEL_H_

class Pixel {
public:
	Pixel();
	Pixel(int, int, int);
	Pixel(const Pixel & pixel);

	~Pixel();

	int getB() const {
		return b_;
	}

	void setB(int b) {
		b_ = b;
	}

	int getG() const {
		return g_;
	}

	void setG(int g) {
		g_ = g;
	}

	int getR() const {
		return r_;
	}

	void setR(int r) {
		r_ = r;
	}

	Pixel & operator=(const Pixel & pixel);

	friend std::ostream & operator << (std::ostream & st, const Pixel & pixel);

private:
	int r_;
	int g_;
	int b_;
};

#endif /* SRC_PIXEL_H_ */
