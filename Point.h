#ifndef POINT_H
#define POINT_H
#include <vector>
#include "myVec3d.h"
using namespace std;
class Point
{
	int id;//本Point的id，也即在pointList里面的索引
public:
	myVec3d vec;
	vector<int> adjoin;//邻接的点的id

	Point();
	Point(myVec3d);
	Point(double,double,double);
	~Point();

	int getId();
	void setId(int);

	bool isAdjoin(int);
	void addAdjoin(int p);
	void noCheckAddAdjoin(int p);
	void removeAdjoin(int);

	friend bool operator==(const Point& a,const Point& b);
};

#endif