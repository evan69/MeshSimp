#include "myVec3d.h"
#include <cmath>
using std::sqrt;

myVec3d::myVec3d()
{
	x = y = z = 0;
}

myVec3d::myVec3d(double _x,double _y,double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

myVec3d::~myVec3d()
{

}

myVec3d operator + ( const myVec3d& A , const myVec3d& B ) {
	return myVec3d( A.x + B.x , A.y + B.y , A.z + B.z );
}

myVec3d operator - ( const myVec3d& A , const myVec3d& B ) {
	return myVec3d( A.x - B.x , A.y - B.y , A.z - B.z );
}

myVec3d operator * ( const myVec3d& A , const double& k ) {
	return myVec3d( A.x * k , A.y * k , A.z * k );
}

myVec3d operator / ( const myVec3d& A , const double& k ) {
	return myVec3d( A.x / k , A.y / k , A.z / k );
}

myVec3d operator * ( const myVec3d& A , const myVec3d& B ) {
	return myVec3d( A.x * B.x , A.y * B.y , A.z * B.z );
}

myVec3d& operator += ( myVec3d& A , const myVec3d& B ) {
	A = A + B;
	return A;
}

myVec3d& operator -= ( myVec3d& A, const myVec3d& B) {
	A = A - B;
	return A;
}

myVec3d& operator *= ( myVec3d& A , const double& k) {
	A = A * k;
	return A;
}

myVec3d& operator /= (myVec3d& A,const double& k) {
	A = A / k;
	return A;
}

myVec3d& operator *= (myVec3d& A,const myVec3d& B) {
	A = A * B;
	return A;
}

myVec3d operator - ( const myVec3d& A ) {
	return myVec3d( -A.x , -A.y , -A.z );
}

double myVec3d::Module2() {
	return x * x + y * y + z * z;
}

double myVec3d::Module() {
	return sqrt( x * x + y * y + z * z );
}

myVec3d myVec3d::Cross(const myVec3d& a) {
	return myVec3d(y * a.z - z * a.y , z * a.x - x * a.z , x * a.y - y * a.x );
}