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
	myVec4d calP(int,int,int);//����p
	Mat4 calQ(int);//����������
	Point calVer(Edge&);//��������������
	void calPri(Edge&);//�������ȼ�������������
	void shrink();//����
	void output(string);
	void run(double alpha);
};
#endif