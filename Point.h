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

	int getId();//获取id
	void setId(int);//设置id

	bool isAdjoin(int);//判断另一个点是否在该点邻域内
	void addAdjoin(int p);//添加到邻域
	void noCheckAddAdjoin(int p);
	void removeAdjoin(int);//从邻域中去掉

	friend bool operator==(const Point& a,const Point& b);//判等
};

#endif