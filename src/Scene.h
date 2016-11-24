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

class Scene {
public:
	Scene();
	Scene(Camera, Shape[], Ray3f);
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

	void render(int, int, std::string);

	Shape* getShapes() const {
		return shapes_;
	}

private:
	Camera camera_;
	Shape* shapes_;
	Ray3f source_;
};

#endif /* SCENE_H_ */
