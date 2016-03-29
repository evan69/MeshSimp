#include "myVec4d.h"

myVec4d::myVec4d()
{
	for(int i = 0;i < 4;++i) 
		data[i] = 0;
}

myVec4d::myVec4d(double _x,double _y,double _z,double _w)
{
	data[0] = _x;
	data[1] = _y;
	data[2] = _z;
	data[3] = _w;
}

myVec4d::~myVec4d()
{

}

myVec4d operator+(const myVec4d& a,const myVec4d& b)
{
	myVec4d ret;
	for(int i = 0;i < 4;++i) 
		ret.data[i] = a.data[i] * b.data[i];
	return ret;
}

Mat4 operator*(const myVec4d& a,const myVec4d& b)
{
	Mat4 ret;
	for(int i = 0;i < 4;++i)
		for(int j = 0;j < 4;++j)
			ret.mat[i][j] = a.data[i] * b.data[j];
	return ret;
}

double cal( const myVec4d& a, const myVec4d& b)
{
	double ret = 0.0;
	for(int i = 0;i < 4;i++)
	{
		ret += a.data[i] * b.data[i];
	}
	return ret;
}

void myVec4d::operator=(const myVec4d& v)
{
	for(int i = 0;i < 4;i++)
		this->data[i] = v.data[i];
}