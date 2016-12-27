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
	Quad(const Material&, Vector3f, Vector3f);
	~Quad();

	const Vector3f& getOrigin() const {
		return origin_;
	}

	void setOrigin(const Vector3f& origin) {
		origin_ = origin;
	}

	bool isHit(Ray3f,double*,double*,double*,double*);

	const Vector3f& getSize() const {
		return size_;
	}

	void setSize(const Vector3f& size) {
		size_ = size;
	}

private:
	Vector3f origin_;
	Vector3f size_;
};

#endif /* QUAD_H_ */
