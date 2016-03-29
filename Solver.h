#ifndef SOLVER_H
#define SOLVER_H
#include "Mat4.h"
#include "myVec4d.h"
#include "myVec3d.h"
class Solver
{
	Mat4 mat;
	myVec4d vec;
public:
	Solver(const Mat4&,const myVec4d&);
	myVec4d solve(double eps = 1e-8);
};

#endif