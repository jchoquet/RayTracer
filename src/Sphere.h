/*
 * Sphere.h
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Shape.h"

class Sphere: public Shape {
public:
	Sphere();
	Sphere(const Material&, const Vector3f&, float);
	~Sphere();

	const Vector3f& getOrigin() const {
		return origin_;
	}

	void setOrigin(const Vector3f& origin) {
		origin_ = origin;
	}

	float getRadius() const {
		return radius_;
	}

	void setRadius(float radius) {
		radius_ = radius;
	}

private:
	Vector3f origin_;
	float radius_;
};

#endif /* SPHERE_H_ */
