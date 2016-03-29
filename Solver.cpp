#include "Solver.h"
#include <cmath>
using std::fabs;

Solver::Solver(const Mat4& m,const myVec4d& v)
{
	this->mat = m;
	this->vec = v;
}

myVec4d Solver::solve(double eps)
{
	for (int i = 0; i < 4; i++) {
		int j = 0;
		while (j < 4 && fabs(mat.mat[i][j]) < eps)
			j++;
		if (j == 4)
			continue;
		for (int k = 0; k < 4; k++) {
			if (k != i) {
				double rate = mat.mat[k][j] / mat.mat[i][j];
				for (int l = 0; l < 4; l++)
					mat.mat[k][l] -= mat.mat[i][l] * rate;
				vec.data[k] -= vec.data[i] * rate;
			}
		}
	}
	myVec4d X;
	for (int i = 0; i < 4; i++) {
		int j = 0;
		while (j < 4 && fabs(mat.mat[i][j]) < eps)
			j++;
		if (j == 4)
			return myVec4d(0, 0, 0, -1);
		X.data[i] = vec.data[i] / mat.mat[i][j];
	}
	X.data[4] = 1;
	return X;
}