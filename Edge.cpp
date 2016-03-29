#include "edge.h"
#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;
Edge::Edge(int _u,int _v):u(_u),v(_v)
{
}

void Edge::operator=(const Edge& other)
{
	u = other.u;
	v = other.v;
	pri = other.pri;
}

void Edge::setID(int _id)
{
	id = _id;
}

int Edge::getID()
{
	return id;
}

void Edge::setPri(double _pri)
{
	pri = _pri;
}

double Edge::getPri() const
{
	return pri;
}

bool operator<(const Edge& a,const Edge& b)
{
	return (bool)(a.getPri() > b.getPri());
}
