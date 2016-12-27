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
#include "Vector3f.h"

class Scene {
public:
	Scene();
	Scene(Camera&, std::vector<Shape*>, int, Vector3f&);
	~Scene();

	const Camera& getCamera() const {
		return camera_;
	}

	void setCamera(const Camera& camera) {
		camera_ = camera;
	}

	void render(int, int, char*, int, int, int);

	int getNbShape() const {
		return nb_shape_;
	}

	void setNbShape(int nbShape) {
		nb_shape_ = nbShape;
	}

	const std::vector<Shape*>& getShapes() const {
		return shapes_;
	}

	const Vector3f& getSource() const {
		return source_;
	}

	void setSource(const Vector3f& source) {
		source_ = source;
	}

private:
	Camera camera_;
	std::vector<Shape*> shapes_;
	Vector3f source_;
	int nb_shape_;
};

#endif /* SCENE_H_ */
