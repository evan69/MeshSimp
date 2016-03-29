#include "mat4.h"

Mat4::Mat4()
{
	for(int i = 0;i < 4;++i)
		for(int j = 0;j < 4;++j)
			mat[i][j] = 0.0;
}

Mat4 operator+(const Mat4& a,const Mat4& b)
{
	Mat4 ret;
	for(int i = 0;i < 4;++i)
		for(int j = 0;j < 4;++j)
			ret.mat[i][j] = a.mat[i][j] + b.mat[i][j];
	return ret;
}

void Mat4::operator=(const Mat4& m)
{
	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 4;j++)
			this->mat[i][j] = m.mat[i][j];
}

myVec4d Mat4::leftMulti(const myVec4d& a)
{
	myVec4d ret;
	for(int i = 0;i < 4;i++)
	{
		for(int j = 0;j < 4;j++)
		{
			ret.data[i] += this->mat[i][j] * a.data[j];
		}
	}
	return ret;
}