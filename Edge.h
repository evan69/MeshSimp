#ifndef EDGE_H
#define EDGE_H
#include "point.h"
class Edge
{
	double pri;
public:
	int u,v;//point id

	Edge(int,int);

	void operator=(const Edge& other);
	double getPri() const;//获取边优先级
	void setPri(double);//设置边优先级
	friend bool operator<(const Edge&,const Edge&);

};

#endif