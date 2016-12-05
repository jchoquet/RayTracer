//============================================================================
// Name        : ProjetPAP.cpp
// Author      : Alexandre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Scene.h"
#include "libpng.cpp"

using namespace std;


int main() {
	cout << "!!!Hello World!!!" << endl;
	Scene* scene = new Scene();
	scene->render(4,4,"hello");
	return 0;
}
