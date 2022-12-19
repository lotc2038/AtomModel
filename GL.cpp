#include "GL.h"
#include "Model.h"
#include <vector>


float rotation = 0.0;
float rotationSpeed = 0.0;
int electornsCount = 0;
int orbitalsCount = 0; 

std::vector <int> orbitalCfg;

const double PI = acos(-1.0);


void drawOrbitals(int orbitalsCount) {
	double innerRadius = 0.01;
	double outerRadius = -1;
	for (int i = 0; i < orbitalsCount; i++) {
		glPushMatrix();
		glColor3f(255.0, 255.0, 255.0);
		glutSolidTorus(0.01 + innerRadius, 3 - outerRadius, 50, 50);
		innerRadius+=0.02;
		outerRadius -= 2;
		glPopMatrix();
	}

}



void drawElectrons(double x, double y, double z, int i) {	
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glRotatef(rotation * i, 0, 0, 1.0);
	glTranslatef(x, y, z);
	glutSolidSphere(0.5, 20.0, 20.0);
	glPopMatrix();
}




void drawCore() {
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0, 0, 0);
	glutSolidSphere(1.0, 20.0, 20.0);
	glPopMatrix();
}

void changeSize(int w, int h) {
	// предотвращение деления на ноль
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);
	// обнуляем матрицу
	glLoadIdentity();
	// установить параметры вьюпорта
	glViewport(0, 0, w, h);
	// установить корректную перспективу
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	// вернуться к матрице проекции
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {
	// очистка буфера цвета и глубины
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	// обнуление трансформации
	glLoadIdentity();
	// установка камеры
	gluLookAt(0.0f, 15.0f, 50.0f,  //0.0f, 15.0f, 15.0f, 50
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);


	drawCore();
	drawOrbitals(orbitalsCount);
	

	double xx = 4, yy = 4, zz = 0;
	double x = 4, y = 0, z = 0;
	double al = PI / 2;
	int spd = orbitalsCount;

	for (int i = 0; i < orbitalsCount; i++) {
		for (int j = 0; j < orbitalCfg[i]; j++) {
			
			double deA = 2 * PI / double(orbitalCfg[i]);
			x =  xx * sin(al);
			y =  yy * cos(al);
			al += deA;

			
			drawElectrons(x, y, z, spd);
			
		}
		
		spd--;
		xx += 2;
		yy += 2;
		
		
	}

	
	
	
	rotation = rotation + 1 + rotationSpeed;
	
		
		if (rotation >= 360) {
				rotation -= 360;
		}
	
	
		glDisable(GL_DEPTH_TEST);
		glutSwapBuffers();
	}



void pressSpecKey(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
			rotationSpeed += 0.3f;
			break;
	case GLUT_KEY_RIGHT:
			rotationSpeed -= 0.3f;
			break;
	}
}

void pressKey(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27:
		glutDestroyWindow(glutGetWindow());
		break;
	}
}


void drawInit(int electrons, int orbitals, std::vector <int> cfg) {

	// Инициализация GLUT и создание окна
	char* myargv[1];
	int myargc = 1;
	myargv[0] = strdup("Myappname");

	glutInit(&myargc, myargv);

	electornsCount = electrons;
	orbitalsCount = orbitals;
	orbitalCfg = cfg;
	

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Atom");

	// регистрация
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(pressSpecKey);
	glutKeyboardFunc(pressKey);
	glutIgnoreKeyRepeat(0);

	// основной цикл
	glutMainLoop();


} 
