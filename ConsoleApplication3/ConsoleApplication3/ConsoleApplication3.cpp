#include <iostream>
#include "Point.h" //파일의 전체경로 

#define MIN(x,y) (((x)>(y))?(y):(x))
#define MAX(x,y) (((x)<(y))?(y):(x))




void PrintP(Point p)
{
    printf("Point(%d,%d)\n", p.x,p.y);
}

void swap_v(int a, int b) // call-by-value
{
    int t(a); //int t = a;
    printf("[swap]초기값 a = %d , b = %d\n", a, b);
    a = b;
    b = t;
    printf("[swap]결과값 a = %d , b = %d\n", a, b);
}

void swap_p(int *a, int *b) // call-by-reference
{//a라는 변수는 포인터. . 선언부 상의 *와 아닌 부분의 *가 뜻하는 것이 다르다
    int t(*a); //*사용시는 해당 포인터의 값을 뜻한다 즉 *a 는 10, a는 주소값
    printf("[swap_p]초기값 a = %d , b = %d\n", *a, *b);
    *a = *b;
    *b = t;
    printf("[swap_p]결과값 a = %d , b = %d\n", *a, *b);
}

void swap_r(int &a, int &b) // call-by-reference (using refer. variables)
{
    int t(a);
    printf("[swap_r]초기값 a = %d , b = %d\n", a, b);
    a = b;
    b = t;
    printf("[swap_r]결과값 a = %d , b = %d\n", a, b);
}

int main()
{
 /*
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

    //reference 변수 테스트 
    int a(10), b(20); //<- 이렇게 해도 대입이 된다. 원래는 a=10,b=20
    printf("초기값 a = %d , b = %d\n",a,b);
    swap_v(a, b);
    swap_p(&a, &b);
    swap_r(a, b);
    printf("결과값 a = %d , b = %d\n", a, b);

    int n = 1234, n1 = 1000;
    int &m = n;
    printf("[레퍼런스 변수 테스트] n = %d, m = %d\n", n,m);
    //&m = n1; 이렇게는 불가. 왜냐하면 한번 지정한 별명을 또 바꾸는 것이 x
    m = 5678;
    printf("[레퍼런스 변수 테스트] n = %d, m = %d\n", n,m);
*/

    Point arr[3];   //Point p1,p2,p3; 와 같은 의미이다
    //객체 배열: 3개의 point 클래스 객체가 디폴트로 초기화 되었다.
    arr[0].SetP(10, 10); PrintP(arr[0]);
    arr[1].SetP(20, 30); PrintP(arr[1]);
    arr[2].SetP(40, 60); PrintP(arr[2]);

    printf("class point 객체 크기: %zd\n", sizeof(arr)); 
    Point* Parr[3]; //point 객체 포인터(*) 배열 : 객체화 되어 있지 않음
    printf("point 객체 포인터 크기: %zd\n", sizeof(Parr));
    Parr[0] = new Point(10, 10); //->SetP(10, 10); 초기화를 무조건 해줘야함. 
    //그런데 객체화 되어 있지 않으니까 -> setp로 하면 오류가 뜬다.
    Parr[1] = new Point(20, 30);
    Parr[2] = new Point(40, 60);
    PrintP(*Parr[0]);
    PrintP(*Parr[1]);
    PrintP(*Parr[2]);

}
