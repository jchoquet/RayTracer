/*
 * Ray3f.h
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#ifndef RAY3F_H_
#define RAY3F_H_

#include "Vector3f.h"

class Ray3f {
public:
	Ray3f();
	Ray3f(Vector3f, Vector3f);
	~Ray3f();

	const Vector3f& getDirection() const {
		return direction_;
	}

	void setDirection(const Vector3f& direction) {
		direction_ = direction;
	}

	const Vector3f& getOrigin() const {
		return origin_;
	}

	void setOrigin(const Vector3f& origin) {
		origin_ = origin;
	}

private:
	Vector3f origin_;
	Vector3f direction_;
};

#endif /* RAY3F_H_ */
