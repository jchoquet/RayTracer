/*
 * Material.h
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

class Material {
public:
	Material();
	Material(float, float, float, float);
	~Material();

	float getB() const {
		return b_;
	}

	void setB(float b) {
		b_ = b;
	}

	float getG() const {
		return g_;
	}

	void setG(float g) {
		g_ = g;
	}

	float getR() const {
		return r_;
	}

	void setR(float r) {
		r_ = r;
	}

	float getShininess() const {
		return shininess_;
	}

	void setShininess(float shininess) {
		shininess_ = shininess;
	}

private:
	float r_;
	float g_;
	float b_;
	float shininess_;
};

#endif /* MATERIAL_H_ */
