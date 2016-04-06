#ifndef POINT_H
#define POINT_H
#include <vector>
#include "myVec3d.h"
using namespace std;
class Point
{
	int id;//��Point��id��Ҳ����pointList���������
public:
	myVec3d vec;
	vector<int> adjoin;//�ڽӵĵ��id

	Point();
	Point(myVec3d);
	Point(double,double,double);
	~Point();

	int getId();//��ȡid
	void setId(int);//����id

	bool isAdjoin(int);//�ж���һ�����Ƿ��ڸõ�������
	void addAdjoin(int p);//��ӵ�����
	void noCheckAddAdjoin(int p);
	void removeAdjoin(int);//��������ȥ��

	friend bool operator==(const Point& a,const Point& b);//�е�
};

#endif