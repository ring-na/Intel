#pragma once
#include <iostream>

#define MIN(x,y) (((x)>(y))?(y):(x))
#define MAX(x,y) (((x)<(y))?(y):(x))

class Point
{
private: //접근지시자(외부참조불가)

public: //접근지시자(외부참조가능)


    int x, y, z;//멤버변수 선언, 객체(나 자신)의 좌표
    Point(int x1 = 0, int y1 = 0)//생성자 정의, 멤버변수를 초기화해준다 :x(x1),y(y1) ->이렇게도 가능한데 이것을 이니셜라이저라고 함
    {                      //함수적 특성(default,overload)이 있음
        x = x1;
        y = y1;
        z = 0;
    }

    void SetP(int x1 = 0, int y1 = 0)
    {
        x = x1;
        y = y1;
    }


    double Dist(Point p) //멤버함수: 두 점간의 거리 계산 하는 함수
    {
        int w = x - p.x;
        int h = y - p.y;
        double d = sqrt(w * w + h * h); //루트 함수
        return d; //혹은 return sqrt(w*w + h*h); ..sqrt 함수 자체가 double형
    }
    double Dist(Point p1, Point p2) //멤버함수, 두 점(자신 제외)간의 거리 계산 함수
    {
        int w = p1.x - p2.x;
        int h = p1.y - p2.y;
        double d = sqrt(w * w + h * h);
        return d;
    }



};

class Rect
{

public: //접근지시자(외부참조가능)

    Point p11, p22; //클래스 멤버변수 선언
    Point LL, LR, UL, UR; //외부참조 가능

    Rect(Point p1, Point p2)
    { /*
        int xl = MIN(p1.x, p2.x); //로컬변수. 외부참조 불가
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