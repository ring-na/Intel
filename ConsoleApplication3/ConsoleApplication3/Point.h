#pragma once
#include <iostream>

#define MIN(x,y) (((x)>(y))?(y):(x))
#define MAX(x,y) (((x)<(y))?(y):(x))

class Point
{
private: //����������(�ܺ������Ұ�)

public: //����������(�ܺ���������)


    int x, y, z;//������� ����, ��ü(�� �ڽ�)�� ��ǥ
    Point(int x1 = 0, int y1 = 0)//������ ����, ��������� �ʱ�ȭ���ش� :x(x1),y(y1) ->�̷��Ե� �����ѵ� �̰��� �̴ϼȶ�������� ��
    {                      //�Լ��� Ư��(default,overload)�� ����
        x = x1;
        y = y1;
        z = 0;
    }

    void SetP(int x1 = 0, int y1 = 0)
    {
        x = x1;
        y = y1;
    }


    double Dist(Point p) //����Լ�: �� ������ �Ÿ� ��� �ϴ� �Լ�
    {
        int w = x - p.x;
        int h = y - p.y;
        double d = sqrt(w * w + h * h); //��Ʈ �Լ�
        return d; //Ȥ�� return sqrt(w*w + h*h); ..sqrt �Լ� ��ü�� double��
    }
    double Dist(Point p1, Point p2) //����Լ�, �� ��(�ڽ� ����)���� �Ÿ� ��� �Լ�
    {
        int w = p1.x - p2.x;
        int h = p1.y - p2.y;
        double d = sqrt(w * w + h * h);
        return d;
    }



};

class Rect
{

public: //����������(�ܺ���������)

    Point p11, p22; //Ŭ���� ������� ����
    Point LL, LR, UL, UR; //�ܺ����� ����

    Rect(Point p1, Point p2)
    { /*
        int xl = MIN(p1.x, p2.x); //���ú���. �ܺ����� �Ұ�
        int xr = MAX(p1.x, p2.x);
        int yl = MIN(p1.y, p2.y);
        int yu = MAX(p1.y, p2.y);
        LL = Point(xl, yl);
        LR = Point(xr, yl);
        UL = Point(xl, yu);
        UR = Point(xr, yu);
        */
        p11 = p1;
        p22 = p2;
    }

    Point GetLL(Point p1, Point p2)
    {
        /*
        int xl = MIN(p1.x, p2.x);
        int yl = MIN(p1.y, p2.y);
        LL = Point(xl, yl);
        return LL;
        */
        Point p = Point(MIN(p11.x, p22.x), MIN(p11.y, p22.y));
        return p;
    }
    Point GetLR(Point p1, Point p2)
    {
        Point p = Point(MAX(p11.x, p22.x), MIN(p11.y, p22.y));
        return p;
    }
    Point GetUL(Point p1, Point p2)
    {
        Point p = Point(MIN(p11.x, p22.x), MAX(p11.y, p22.y));
        return p;
    }
    Point GetUR(Point p1, Point p2)
    {
        Point p = Point(MAX(p11.x, p22.x), MAX(p11.y, p22.y));
        return p;
    }

};