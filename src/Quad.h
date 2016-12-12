/*
 * Quad.h
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#ifndef QUAD_H_
#define QUAD_H_

#include "Shape.h"
#include "Vector3f.h"

class Quad: public Shape {
public:
	Quad();
	Quad(Vector3f, Vector3f, Vector3f);
	~Quad();

	const Vector3f& getHeight() const {
		return height_;
	}

	void setHeight(const Vector3f& height) {
		height_ = height;
	}

	const Vector3f& getOrigin() const {
		return origin_;
	}

	void setOrigin(const Vector3f& origin) {
		origin_ = origin;
	}

	const Vector3f& getWidth() const {
		return width_;
	}

	void setWidth(const Vector3f& width) {
		width_ = width;
	}

	bool isHit(Ray3f);

private:
	Vector3f origin_;
	Vector3f width_;
	Vector3f height_;
};

#endif /* QUAD_H_ */
