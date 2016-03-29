objects = myVec3d.o myVec4d.o Mat4.o Point.o PointList.o Edge.o EdgeList.o Solver.o

all: main.exe

main.exe: main.cpp $(objects)
	g++ main.cpp $(objects) -o main.exe -O2

myVec3d.o: myVec3d.h myVec3d.cpp
	g++ -c myVec3d.cpp -o myVec3d.o -O2
	
myVec4d.o: myVec4d.h myVec4d.cpp
	g++ -c myVec4d.cpp -o myVec4d.o -O2

Mat4.o: Mat4.h Mat4.cpp
	g++ -c Mat4.cpp -o Mat4.o -O2
	
Point.o: Point.h Point.cpp
	g++ -c Point.cpp -o Point.o -O2
	
PointList.o: PointList.h PointList.cpp
	g++ -c PointList.cpp -o PointList.o -O2

Edge.o: Edge.h Edge.cpp
	g++ -c Edge.cpp -o Edge.o -O2

EdgeList.o: EdgeList.h EdgeList.cpp
	g++ -c EdgeList.cpp -o EdgeList.o -O2
	
Solver.o: Solver.h Solver.cpp
	g++ -c Solver.cpp -o Solver.o -O2

clean:
	rm *.o *.exe