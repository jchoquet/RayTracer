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
	virtual ~Shape();

	const Material& getMatter() const {
		return matter_;
	}

	void setMatter(const Material& matter) {
		matter_ = matter;
	}

	const Ray3f& reflect(const Ray3f&);

	virtual bool isHit(Ray3f,double*,double*,double*,double*) = 0;

protected:
	Material matter_;
};

#endif /* SHAPE_H_ */
