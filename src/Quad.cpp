/*
 * Quad.cpp
 *
 *  Created on: 10 oct. 2016
 *      Author: Latha
 */

#include <algorithm>
#include <iostream>
#include <cmath>

#include "Quad.h"
#include "Vector3f.h"

using namespace std;

Quad::Quad() : Shape(), origin_(Vector3f()), size_(Vector3f())
{

}

Quad::Quad(const Material& mater, Vector3f origin, Vector3f size) : Shape (mater)
{
	origin_ = origin;
	size_ = size;
}

Quad::~Quad()
{

}

// With Smit's algorithm
bool Quad::isHit(Ray3f ray3f, double* distance)
{
	bool res;

	double d,x,y,z;
	double newDistance;

	double x0 = origin_.getX();
	double y0 = origin_.getY();
	double z0 = origin_.getZ();

	double x1 = x0 + size_.getX();
	double y1 = y0 + size_.getY();
	double z1 = z0 + size_.getZ();

	double xc = ray3f.getDirection().getX();
	double yc = ray3f.getDirection().getY();
	double zc = ray3f.getDirection().getZ();

	double xi = ray3f.getOrigin().getX();
	double yi = ray3f.getOrigin().getY();
	double zi = ray3f.getOrigin().getZ();

	//cout << xc << "/" << x0 << "/" << xi << endl;

	double tmin, tmax, tymin, tymax, tzmin, tzmax, divx, divy, divz;

	if (xc==0) {
		divx= 1000000;
	} else {
		divx = 1/xc;
		//cout << divx << endl;
	}
	if (divx >= 0) {
		tmin = (x0-xi)*divx;
		//cout << tmin << endl;
		tmax = (x1-xi)*divx;
	} else {
		tmin = (x1-xi)*divx;
		tmax = (x0-xi)*divx;
	}

	//cout << tmin << endl;

	if (yc==0) {
		divy= 1000000;
	} else {
		divy = 1/yc;
	}
	if (divy >= 0) {
		tymin = (y0-yi)*divy;
		tymax = (y1-yi)*divy;
	} else {
		tymin = (y1-yi)*divy;
		tymax = (y0-yi)*divy;
	}

	if (zc==0) {
		divz= 1000000;
	} else {
		divz = 1/zc;
	}
	if (divz >= 0) {
		tzmin = (z0-zi)*divz;
		tzmax = (z1-zi)*divz;
	} else {
		tzmin = (z1-zi)*divz;
		tzmax = (z0-zi)*divz;
	}

	//cout << tmin << " " << tymin << " " << tzmin << " - " << tmax << " " << tymax << " " << tzmax << endl;

	if (x0==x1) {
		//cout << "test" << endl;
		res = (max(tymin,tzmin)<=min(tymax,tzmax));
	} else if (y0==y1){
		res = (max(tmin,tzmin)<=min(tmax,tzmax));
	} else if (z0==z1){
		res = (max(tmin,tymin)<=min(tmax,tymax));
	} else {
		//cout << "test" << endl;
		res = (max(tmin,max(tymin,tzmin))<=min(tmax,min(tymax,tzmax)));
	}

	if (res) {

		if ((x1-x0)<2) {
			d = tmin;
		} else if ((y1-y0)<2) {
			d = tymin;
		} else if ((z1-z0)<2) {
			d = tzmin;
		} else {
			d = max(tmin,max(tymin,tzmin));
		}

		x = xi + d*xc;
		y = yi + d*yc;
		z = zi + d*zc;

		newDistance = sqrt(x*x + y*y + z*z);

		if (*distance < 0 || newDistance < *distance) {
			*distance = newDistance;
			//cout << "test" << endl;
			return true;
		} else {
			//cout << "bouh" << endl;
			return false;
		}
	}
}
