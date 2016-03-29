#ifndef EDGE_H
#define EDGE_H
#include "point.h"
class Edge
{
	int id;
	double pri;
public:
	int u,v;//point id

	Edge(int,int);

	void operator=(const Edge& other);
	void setID(int);
	int getID();
	double getPri() const;
	void setPri(double);
	friend bool operator<(const Edge&,const Edge&);

};

#endif