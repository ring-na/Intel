#pragma once

//extern double sqrt(double); //sqrt  �Լ��� �ܺ� ��� �ִٴ� ���� �˷��ִ°�. �������� link�������� ã�Ƽ� �ذ�
#include <iostream> //iostream�� ���⿡ ���Խ�Ű�� �ʾ����� extern ����ϴ� ��
#include <corecrt_math.h> // sqrt�� �� �ִ� �������

class Point
{
private:
	int x;
protected:
	int y;
public:
	//int x, y;

	Point(int x1=0, int y1=0) : x(x1), y(y1) //������
	{

	}

	//void SetP(Point p);
	Point& SetP(Point p); //self-reference
	//void SetP(int x, int y);
	Point& SetP(int x, int y);

	double Dist(Point p); // ����Ʈ ��üp�� �޾� �Ÿ��� ����ϴ� �Լ�
	void viewP(const char *s = NULL); //view current point
	
	//�̵��Ÿ� ��ŭ �ű�� ��
	Point& MoveP(Point p); //move point position
	Point& MoveP(int offx, int offy); //professor move point func

	//public�� �ƴ϶� private�� int x,y�� ������
	int& X() { return x; }; //������ ������ ������ �� �ְ� �Լ��� �������
	int& Y() { return y; };

};

class Point3D : protected Point
{
private:
	int z;
public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y), z(z) //����Ŭ���� ������ ȣ��
	{	}
	double Dist3D(Point3D p) //Distance 3D
	{
		int w = X() - p.X();
		int h = y - p.y; // Y() - p.Y();
		int d = z - p.z;
		return sqrt(w*w + h*h + d*d);
	}

};