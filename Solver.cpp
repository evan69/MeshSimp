#include "Solver.h"
#include <cmath>
using std::fabs;

Solver::Solver(const Mat4& m,const myVec4d& v)
{
	this->mat = m;
	this->vec = v;
}

myVec4d Solver::solve(double eps)//使用类里的矩阵，解非齐次线性方程组
{
	myVec4d ret;
	for (int i = 0; i < 4; i++)
	{
		int j = 0;
		while (j < 4 && fabs(mat.mat[i][j]) < eps)
		{
			j++;
		}
		if (j == 4) continue;
		for (int k = 0; k < 4; k++)
		{
			if (k != i)
			{
				double rate = mat.mat[k][j] / mat.mat[i][j];
				for (int l = 0; l < 4; l++)
					mat.mat[k][l] -= mat.mat[i][l] * rate;
				vec.data[k] -= vec.data[i] * rate;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int j = 0;
		while (j < 4 && fabs(mat.mat[i][j]) < eps)
		{
			j++;
		}
		if (j == 4)
		{
			return myVec4d(0.0, 0.0, 0.0, -1.0);
		}
		ret.data[i] = vec.data[i] / mat.mat[i][j];
	}
	ret.data[4] = 1.0;
	return ret;
}
