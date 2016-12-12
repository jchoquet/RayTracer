/*
 * Scene.h
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include <string>
#include "Camera.h"
#include "Shape.h"
#include "Ray3f.h"

class Scene {
public:
	Scene();
	Scene(Camera&, Shape*, int, Ray3f&);
	~Scene();

	const Camera& getCamera() const {
		return camera_;
	}

	void setCamera(const Camera& camera) {
		camera_ = camera;
	}

	const Ray3f& getSource() const {
		return source_;
	}

	void setSource(const Ray3f& source) {
		source_ = source;
	}

	void render(int, int, char*, int, int, int);

	Shape* getShapes() const {
		return shapes_;
	}

	int getNbShape() const {
		return nb_shape_;
	}

	void setNbShape(int nbShape) {
		nb_shape_ = nbShape;
	}

private:
	Camera camera_;
	Shape* shapes_;
	Ray3f source_;
	int nb_shape_;
};

#endif /* SCENE_H_ */
