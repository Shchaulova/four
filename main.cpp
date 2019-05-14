#include <iostream>
#include <glut.h>
#include <vector>
#include <random>
#include <ctime>
#include "Ball.h"
#include"Vector.h"
#include <math.h>
#define CONVERT 0.02635872
std::vector<Ball> data;
unsigned int count = 0;
bool flag = true;
unsigned int time1 = 0, time2 = 0;
void display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 1, 0.1, 30);
	glClear(GL_COLOR_BUFFER_BIT);
	if (int ttt = clock() - time1 >= 10)
	{
		for (int i = 0; i < data.size(); i++)
		{
			
				data[i].move(0.00001*ttt);
				glColor3f(data[i].c1, data[i].c2, data[i].c3);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(data[i].pos.getx(), data[i].pos.gety(), -25 + data[i].pos.getz());
				glutSolidSphere(data[i].r, 20, 20);
				time1 = clock();
			
		}
	}
	else
	{
		for (int i = 0; i < data.size(); i++)
		{
			if ((acos(data[i].pos.z *(1 / data[i].pos.get_length())))>70)
			{
				data.erase(data.begin() + i);
			}

			glColor3f(data[i].c1, data[i].c2, data[i].c3);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(data[i].pos.getx(), data[i].pos.gety(), -25 + data[i].pos.getz());
			glutSolidSphere(data[i].r, 20, 20);

		}
	}
	glutSwapBuffers();
		}
	
void  idle()
{
	std::cout << data.size() << std::endl;
	if (clock() - time2 >= 500)
	{
		Ball buff;
		buff.init();
		data.push_back(buff);
		time2 = clock();
	}
	glutPostRedisplay();
}
int main(int argc, char ** argv) {

	data.push_back(Ball());
	data[0].init();
	Vector a(1, 1, 1);
	Vector b(2, 2, 1);
	Vector c(2, 2, 2);
	a = a + b;
	std::cout << a.getx() << " " << a.gety() << " " << a.getz()<<std::endl;
	int i = 0;
	std::cout << data[i].vel.getx() << " " << data[i].vel.gety() << " " << data[i].vel.gety() << " " << data[i].r << std::endl;
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutCreateWindow("MY WINDOW");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}