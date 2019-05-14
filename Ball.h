#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Vector.h"

class  Ball
{
public:
	double r;
	Vector pos;
	Vector vel;
	double c1;
	double c2;
	double c3;
	Ball()
	{
		c1 = ((double)(rand() % 10)) / 10;
		c2 = ((double)(rand() % 10)) / 10;
		c3 = ((double)(rand() % 10)) / 10;
		r = 5;
		pos = Vector(0, 0, 0);
		vel = Vector(0, 0, 0);
	}
	void init()
	{
		srand(time(NULL));
		r = ((double)(rand() % 100 + 10)) / 100;
		pos = Vector(0, 0, 0);
		vel = Vector(rand() % 2000 - 1000, rand() % 2000 - 1000, rand() % 2000 - 1000);
		std::cout << r << std::endl;
	}
	~Ball() {}
	void move(double time)
	{
		Vector buffer = vel;
		pos = pos + buffer*time;
	}
	void operator=(Ball b)
	{
		this->r = b.r;
		this->pos = b.pos;
		this->vel = b.vel;
	}
};
#endif