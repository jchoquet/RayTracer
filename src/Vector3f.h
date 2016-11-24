/*
 * Vector3f.h
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#ifndef VECTOR3F_H_
#define VECTOR3F_H_

class Vector3f {
public:
	Vector3f();
	Vector3f(float, float, float);
	~Vector3f();

	float getX() const {
		return x_;
	}

	void setX(float x) {
		x_ = x;
	}

	float getY() const {
		return y_;
	}

	void setY(float y) {
		y_ = y;
	}

	float getZ() const {
		return z_;
	}

	void setZ(float z) {
		z_ = z;
	}

private:
	float x_;
	float y_;
	float z_;
};

#endif /* VECTOR3F_H_ */
