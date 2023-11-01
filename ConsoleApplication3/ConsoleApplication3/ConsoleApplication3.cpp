#include <iostream>

#define MIN(x,y) (((x)>(y))?(y):(x))
#define MAX(x,y) (((x)<(y))?(y):(x))

class Point
{
private: //접근지시자(외부참조불가)

public: //접근지시자(외부참조가능)

    
    int x, y;//멤버변수 선언, 객체(나 자신)의 좌표
    Point(int x1 = 0, int y1 = 0)//생성자 정의, 멤버변수를 초기화해준다 :x(x1),y(y1) ->이렇게도 가능한데 이것을 이니셜라이저라고 함
    {                      //함수적 특성(default,overload)이 있음
        x = x1;
        y = y1;
    }
    
    double Dist(Point p) //멤버함수: 두 점간의 거리 계산 하는 함수
    {
        int w = x - p.x;
        int h = y - p.y;
        double d = sqrt(w*w + h*h); //루트 함수
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
        Point p = Point(MIN(p11.x,p22.x),MIN(p11.y,p22.y));
        return p;
    }
    Point GetLR(Point p1, Point p2)
    {
        Point p = Point(MAX(p11.x, p22.x), MIN(p11.y, p22.y));
        return p;
    }
    Point GetUL (Point p1, Point p2)
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


void PrintP(Point p)
{
    printf("Point(%d,%d)\n", p.x,p.y);
}

int main()
{
    
    Point p1, p2(10,10), p3(30,30),p4; //포인트 객체 선언 .. 초기화처럼 값을 주는것

    double d = p1.Dist(p2); //p1에서 p2까지의 거리를 얻고자 할때
    double d1 = p2.Dist(p3); //p2와 p3의 사이의 거리
    double d2 = p1.Dist(p2, p3); //p2와 p3의 사이의 거리
    PrintP(p1);
    PrintP(p2);
    PrintP(p3);
    printf("두 점간의 거리 계산: d = %.2f d1 = %.2f d2 = %.2f\n",d,d1,d2);
    
    //Point p1, p2(10,10),p3(20,30),p4; //포인트 객체 선언
    //p4 = p3;
    PrintP(p1); PrintP(p2); PrintP(p3); PrintP(p4);
    Rect r(p2,p3);
    printf("두 점 \n");
    PrintP(p2);
    PrintP(p3);
    printf("에 의해 정의된 사각형의 꼭지점의 좌표는\n");
    PrintP(r.GetLL(p2,p3));
    PrintP(r.GetLR(p2, p3));
    PrintP(r.GetUL(p2, p3));
    PrintP(r.GetUR(p2, p3));

    //printf("%d\n", p11.GetLL(p2, p3));
}
