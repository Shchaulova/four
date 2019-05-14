#include <math.h>
#include "Vector.h"
using namespace std;

double Vector::get_length()
{
	return sqrt(x*x + y*y + z*z);
};
Vector Vector::operator+(Vector & b)
{
	return Vector(this->x + b.x, this->y + b.y, this->z + b.z);
};
Vector Vector::operator-(Vector & b)
{
	return Vector(this->x - b.x, this->y - b.y, this->z - b.z);
};
Vector Vector::operator*(double k)
{
	return Vector(this->x * k, this->y * k, this->z * k);
};
Vector operator*(double k, Vector & b)
{
	return (b * k);
};
double Vector::getx()
{
	return x;
};
double Vector::gety()
{
	return y;
};
double Vector::getz()
{
	return z;
};
void Vector::setx(double k)
{
	x = k;
};
void Vector::sety(double k)
{
	y = k;
};
void Vector::setz(double k)
{
	z = k;
};
