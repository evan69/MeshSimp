#ifndef POINTLIST_H
#define POINTLIST_H
#include <string>
#include "Point.h"
#include "Edge.h"
#include "myVec4d.h"
#include "Mat4.h"
#include "EdgeList.h"
using namespace std;

class PointList
{
	static const int MAXSIZE = 1000000; 
	vector<Point> point;
	int maxID;
	int face;
	EdgeList edge;
public:
	PointList();
	void addPoint(Point&);
	void readin(string filename);
	myVec4d calP(int,int,int);//计算p
	Mat4 calQ(int);//计算误差矩阵
	Point calVer(Edge&);//计算最优收缩点
	void calPri(Edge&);//计算优先级，即收缩代价
	void shrink();//收缩
	void output(string);
	void run(double alpha);
};
#endif