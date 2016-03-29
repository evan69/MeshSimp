#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "PointList.h"
using std::atof;
using std::cout;
using std::endl;
int main(int argc,char** argv)
{
	if(argc < 4)
	{
		cout << "Wrong input!" << endl;
		cout << "Usage:main [input filename] [output filename] [alpha]" << endl;
		return 0;
	}
	time_t start,end;
	start = clock();
	char* in = argv[1];
	char* out = argv[2];
	double alpha = atof(argv[3]);
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	PointList pp;
	pp.readin(in);
	time_t readin = clock();
	cout << "input time consume:" << (double)(readin-start)/CLOCKS_PER_SEC << "sec" << endl;
	pp.run(alpha);
	time_t run = clock();
	cout << "run time consume:" << (double)(run-readin)/CLOCKS_PER_SEC << "sec" << endl;
	pp.output(out);
	end = clock();
	time_t output = clock();
	cout << "output time consume:" << (double)(output - run)/CLOCKS_PER_SEC << "sec" << endl;
	cout << "total time consume:" << (double)(end-start)/CLOCKS_PER_SEC << "sec" << endl;
	return 0;
}