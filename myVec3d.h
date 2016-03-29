#ifndef MYVEC3D_H
#define MYVEC3D_H

class myVec3d
{
public:
	double x,y,z;
	myVec3d();
	myVec3d(double,double,double);
	~myVec3d();
	//myVec3d(myVec3d&);
	friend myVec3d operator + ( const myVec3d& , const myVec3d& );
	friend myVec3d operator - ( const myVec3d& , const myVec3d& );
	friend myVec3d operator * ( const myVec3d& , const double& );
	friend myVec3d operator / ( const myVec3d& , const double& );
	friend myVec3d operator * ( const myVec3d& , const myVec3d& );
	friend myVec3d& operator += ( myVec3d& , const myVec3d& );
	friend myVec3d& operator -= ( myVec3d& , const myVec3d& );
	friend myVec3d& operator *= ( myVec3d& , const double& );
	friend myVec3d& operator /= ( myVec3d& , const double& );
	friend myVec3d& operator *= ( myVec3d& , const myVec3d& );
	friend myVec3d operator - ( const myVec3d& A );
	double Module2();
	double Module();
	myVec3d Cross(const myVec3d& );
};

#endif