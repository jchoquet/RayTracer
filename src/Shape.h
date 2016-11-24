/*
 * Shape.h
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "Material.h"
#include "Ray3f.h"

class Shape {
public:
	Shape();
	Shape(const Material&);
	~Shape();

	const Material& getMatter() const {
		return matter_;
	}

	void setMatter(const Material& matter) {
		matter_ = matter;
	}

	bool isHit(Ray3f);

	const Ray3f& reflect(const Ray3f&);

protected:
	Material matter_;
};

#endif /* SHAPE_H_ */
