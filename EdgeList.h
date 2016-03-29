#ifndef EDGELIST_H
#define EDGELIST_H
#include <queue>
#include "Edge.h"
using namespace std;
class EdgeList
{
public:
	priority_queue<Edge> Q;
	EdgeList(void);
	~EdgeList(void);
};
#endif

