#pragma once
#include "Model.h"
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>
#include <vector>

void drawInit(int electrons, int orbitals, std::vector <int> or);
void drawCore();
void drawElectrons(double x, double y, double z);
void drawOrbitals(int orbitalsCount);
void renderScene(void);
void changeSize(int w, int h);

