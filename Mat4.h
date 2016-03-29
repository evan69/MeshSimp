#ifndef MAT4_H
#define MAT4_H
#include "myVec4d.h"
class myVec4d;
class Mat4
{
public:
	double mat[5][5];
	Mat4();
	friend Mat4 operator+(const Mat4&,const Mat4&);
	void operator=(const Mat4&);
	myVec4d leftMulti(const myVec4d&);
};

#endif