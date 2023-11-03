#pragma once

//extern double sqrt(double); //sqrt  함수가 외부 어딘가 있다는 것을 알려주는것. 나머지는 link과정에서 찾아서 해결
#include <iostream> //iostream을 여기에 포함시키지 않았을때 extern 사용하는 것
#include <corecrt_math.h> // sqrt가 들어가 있는 헤더파일

class Point
{
private:
	int x;
protected:
	int y;
public:
	//int x, y;

	Point(int x1=0, int y1=0) : x(x1), y(y1) //생성자
	{

	}

	//void SetP(Point p);
	Point& SetP(Point p); //self-reference
	//void SetP(int x, int y);
	Point& SetP(int x, int y);

	double Dist(Point p); // 포인트 객체p를 받아 거리를 계산하는 함수
	void viewP(const char *s = NULL); //view current point
	
	//이동거리 만큼 옮기는 것
	Point& MoveP(Point p); //move point position
	Point& MoveP(int offx, int offy); //professor move point func

	//public이 아니라 private에 int x,y가 있을때
	int& X() { return x; }; //각각의 변수에 접근할 수 있게 함수를 만들어줌
	int& Y() { return y; };

};

class Point3D : protected Point
{
private:
	int z;
public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y), z(z) //상위클래스 생성자 호출
	{	}
	double Dist3D(Point3D p) //Distance 3D
	{
		int w = X() - p.X();
		int h = y - p.y; // Y() - p.Y();
		int d = z - p.z;
		return sqrt(w*w + h*h + d*d);
	}

};