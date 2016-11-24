/*
 * Camera.h
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector3f.h"

class Camera {
public:
	Camera();
	Camera(Vector3f, Vector3f);
	~Camera();

	const Vector3f& getDirection() const {
		return direction_;
	}

	void setDirection(const Vector3f& direction) {
		direction_ = direction;
	}

	const Vector3f& getPosition() const {
		return position_;
	}

	void setPosition(const Vector3f& position) {
		position_ = position;
	}

private:
	Vector3f position_;
	Vector3f direction_;
};

#endif /* CAMERA_H_ */
