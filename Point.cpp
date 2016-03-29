#include "Point.h"
#include <assert.h>
using namespace std;
Point::Point():vec(0,0,0)
{
	id = 0;
	adjoin.clear();
}

Point::Point(myVec3d _vec)
{
	vec = _vec;
	id = 0;
	adjoin.clear();
}

Point::Point(double _x,double _y,double _z):vec(_x,_y,_z)
{
	id = 0;
	adjoin.clear();
}

Point::~Point()
{

}

int Point::getId()
{
	return id;
}

void Point::setId(int _id)
{
	id = _id;
}

bool Point::isAdjoin(int p)
{
	for(vector<int>::iterator it = adjoin.begin();it != adjoin.end();++it)
	{
		if(*it == p) return true;
	}
	return false;
}

void Point::addAdjoin(int p)
{
	assert(p != id);
	if(isAdjoin(p)) 
	{
		return;
	}
	adjoin.push_back(p);
}

void Point::noCheckAddAdjoin(int p)
{
	adjoin.push_back(p);
}

void Point::removeAdjoin(int p)
{
	for (vector<int>::iterator it = adjoin.begin(); it != adjoin.end(); ++it) 
	{
		if ((*it) == p) {
			adjoin.erase(it);
			return;
		}
	}
}

bool operator==(const Point& a,const Point& b)
{
	return (bool)(a.id == b.id);
}