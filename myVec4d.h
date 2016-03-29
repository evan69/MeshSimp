#ifndef MYVEC4D_H
#define MYVEC4D_H
#include "mat4.h"
class Mat4;
class myVec4d
{
public:
	double data[5];
	myVec4d();
	myVec4d(double,double,double,double);
	~myVec4d();

	friend myVec4d operator+(const myVec4d& a,const myVec4d& b);//�������
	friend Mat4 operator*(const myVec4d& a,const myVec4d& b);//�����������������
	friend double cal( const myVec4d& , const myVec4d& );//���

	void operator=(const myVec4d&);//����
};

#endif