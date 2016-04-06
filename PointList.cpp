#include <fstream>
#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include "pointList.h"
#include "Solver.h"
using namespace std;
PointList::PointList()
{
	point.clear();
	Point a;
	a.setId(0);//id为0表示不是真实的点，或已经删除的点
	point.push_back(a);//占住索引为0的位置
	maxID = 0;
	face = 0;
}

void PointList::addPoint(Point& p)
{
	maxID++;
	p.setId(maxID);
	point.push_back(p);
}

void PointList::readin(string filename)
{
	ifstream fin(filename.c_str());
	char flag;
	int cnt = 0;
	while(!fin.eof())
	{
		fin >> flag;
		if(flag == '#')
		{
			string s;
			getline(fin,s);
			continue;
		}
		if(flag == 'v' || flag == 'V')//verticals
		{
			double tmp[3];
			fin >> tmp[0] >> tmp[1] >> tmp[2];
			Point po(tmp[0],tmp[1],tmp[2]);
			addPoint(po);
		}
		if(flag == 'f' || flag == 'F')//face
		{
			face++;
			int tmp[3];
			fin >> tmp[0] >> tmp[1] >> tmp[2];
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) 
				{
					if(tmp[i] > tmp[j])
					{
						point[tmp[i]].addAdjoin(tmp[j]);
						point[tmp[j]].addAdjoin(tmp[i]);
					}
				}
		}
	}
	for(int it1 = 0;it1 < point.size();++it1)
	{
		if(point[it1].getId() <= 0) continue;
		for(vector<int>::iterator it2 = point[it1].adjoin.begin();it2 != point[it1].adjoin.end();++it2)
		{
			if(*it2 > it1)
			{
				Edge e = Edge(it1,*it2);
				calPri(e);
				edge.Q.push(e);
			}
		}
	}
	
}

myVec4d PointList::calP(int a,int b,int c)//计算三个点对应的面的法向量P
{
	myVec3d r = point[a].vec - point[b].vec;
	myVec3d s = point[a].vec - point[c].vec;
	myVec3d p0 = r.Cross(s);
	p0 = p0 / (p0.Module());
	double d = - (p0.x * point[a].vec.x + p0.y * point[a].vec.y + p0.z * point[a].vec.z);
	myVec4d ret = myVec4d(p0.x,p0.y,p0.z,d);
	return ret;
}

Mat4 PointList::calQ(int index)//计算index点的误差矩阵Q
{
	Mat4 ret = Mat4();
	Point po = point[index];
	for(vector<int>::iterator it1 = po.adjoin.begin();it1 != po.adjoin.end();++it1)
		for(vector<int>::iterator it2 = po.adjoin.begin();it2 != po.adjoin.end();++it2)
		{
			if(*it1 < *it2 && point[*it1].isAdjoin(*it2))
			{
				myVec4d tmp = calP(index,*it1,*it2);
				ret = ret + (tmp * tmp);
			}
		}
	return ret;
}

Point PointList::calVer(Edge& e)
{
	Point ver;
	Mat4 m = calQ(e.u) + calQ(e.v);
	m.mat[3][0] = 0.0;
	m.mat[3][1] = 0.0;
	m.mat[3][2] = 0.0;
	m.mat[3][3] = 1.0;
	myVec4d v = myVec4d(0,0,0,1);
	Solver s = Solver(m,v);
	myVec4d ret = s.solve();
	ver.vec.x = ret.data[0];
	ver.vec.y = ret.data[1];
	ver.vec.z = ret.data[2];
	if(ret.data[3] > 0.001 && (ver.vec - (point[e.u].vec + point[e.v].vec) / 2).Module() < 1)
	{
		return ver;
	}//若是计算出的点偏差不大，则用之
	ver.vec = (point[e.u].vec + point[e.v].vec) / 2;
	return ver;
}

void PointList::calPri(Edge& e)
{
	Point ver = calVer(e);
	myVec4d v = myVec4d(ver.vec.x,ver.vec.y,ver.vec.z,1.0);
	Mat4 theQ = calQ(e.v) + calQ(e.u);
	double pri = cal(v,(theQ.leftMulti(v)));
	e.setPri(pri);
}

void PointList::shrink()
{
	clock_t a[4];
	double totaltime;
	a[0]=clock();
	
	Edge e = edge.Q.top();
	while(point[e.u].getId() <= 0 || point[e.v].getId() <= 0)
	{
		edge.Q.pop();
		e = edge.Q.top();
	}//直到得到一条两端点都未被删除的真实的边为止
	edge.Q.pop();//删除该边
	point[e.u].setId(0);
	point[e.v].setId(0);
	Point toadd = calVer(e);
	addPoint(toadd);//计算，并添加最优收缩点
	for(vector<int>::iterator it = point[e.u].adjoin.begin();it != point[e.u].adjoin.end();it++)
	{
		if(*it == maxID) continue;
		if(point[*it].getId() <= 0) continue;
		point[*it].addAdjoin(maxID);
		if(point[*it].getId() > 0) point[maxID].addAdjoin(*it);
	}
	for(vector<int>::iterator it = point[e.v].adjoin.begin();it != point[e.v].adjoin.end();++it)
	{
		if(*it == maxID) continue;
		if(point[*it].getId() <= 0) continue;
		point[*it].addAdjoin(maxID);
		if(point[*it].getId() > 0) point[maxID].addAdjoin(*it);
	}
	for(vector<int>::iterator it = point[maxID].adjoin.begin();it != point[maxID].adjoin.end();++it)
	{
		if(point[*it].getId() <= 0) continue;
		Edge tmp = Edge(maxID,*it);
		calPri(tmp);
		edge.Q.push(tmp);
	}
}

void PointList::run(double alpha)
{
	int i = face;
	while(i > face * alpha)
	{
		//cout << i << endl;
		shrink();
		i = i - 2;
	}
}

void PointList::output(string filename)
{
	ofstream fout(filename.c_str());
	int index = 1;
	int cnt = 1;
	//以下输出顶点坐标
	while(index <= maxID)
	{
		if(point[index].getId() > 0)
		{
			point[index].setId(cnt);
			cnt++;
			myVec3d tmpVec = point[index].vec;
			fout << "v " << tmpVec.x << " " << tmpVec.y << " " << tmpVec.z << endl;
		}
		index++;
	}
	index = 0;
	//以下开始输出面信息
	while(index < point.size())
	{
		if(point[index].getId() <= 0)
		{
			index++;
			continue;
		}
		for(vector<int>::iterator it1 = point[index].adjoin.begin();it1 != point[index].adjoin.end();++it1)
		{
			if(point[*it1].getId() <= 0) continue;
			for(vector<int>::iterator it2 = point[index].adjoin.begin();it2 != point[index].adjoin.end();++it2)
			{
				if(point[*it2].getId() <= 0) continue;
				if(index < *it1 && *it1 < *it2 && point[*it1].isAdjoin(*it2))
				{
					fout << "f " << point[index].getId() << " " << point[*it1].getId() << " " << point[*it2].getId() << endl;
				}
			}
		}
		index++;
	}
	fout.close();
}