//============================================================================
// Name        : ProjetPAP.cpp
// Author      : Alexandre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Scene.h"

using namespace std;


int main() {
	cout << "!!!Hello World!!!" << endl;
	Scene* scene = new Scene();
	scene->render(100,100,"hello.png");
	return 0;
}
