#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
class Vector
{
public:
	double x;
	double y;
	double z;
	Vector(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {};
	void setx(double k);
	void sety(double k);
	void setz(double k);
	double get_length();
	Vector operator+(Vector & b);
	Vector operator-(Vector & b);
	Vector operator*(double k);
	Vector operator/(double k);
	double getx();
	double gety();
	double getz();
	void operator=(Vector b)
	{
		x = b.x;
		y = b.y;
		z = b.z;
	}
	friend Vector operator*(double k, Vector & b);
};

#endif