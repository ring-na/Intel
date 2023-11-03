#include <iostream>
#include "Point.h"

int main()
{
	Point p1(5,10), p2(30,40), p3;
	p1.viewP("P1"); //""에서 문자열은 자동으로 앞에 const가 붙는다.
	//그렇기에 const를 안하고 그냥 p1만 적었다면 오류가 뜬다
	p2.viewP();
	p3.viewP();

	Point p4 = p3, p5(p2); //p4를 p3으로 초기화, p5를 p2로 초기화

	
	p2.SetP(Point(20,30)).viewP("P2");
	p3.SetP(40, 70).viewP("P3");
	//p2.viewP("P2");
	//p3.viewP("P3");

	p1.MoveP(Point(15, 1)).viewP("newP");//내 이동함수 test
	printf("Point Move Test......\n");//교수님꺼 이동함수 test
	p1.MoveP(1, 1).viewP("P1_1");
	p1.MoveP(1, 1).viewP("P1_1");
	p1.MoveP(1, 1).viewP("P1_1");
	p1.MoveP(1, 1).viewP("P1_1");

	//private에 접근 하기 위한 출력 테스트
	printf("Point print Test...P1(%d,%d).\n",p1.X(), p1.Y());
	p1.X() = 10; p1.Y() = 10; //디폴트 복사 생성자
	printf("Point Ref. Access Test...P1.");
	p1.viewP("P1");

	Point3D pp0, pp1(10, 20, 30);
	double d3 = pp0.Dist3D(pp1);
	double d2 = pp0.Dist3D(Point3D(10,20)); //상위클래스 변수들
	printf("pp0(0,0,0) 과 pp1(10,20,30)의 거리는 %f\n", d3);
	printf("pp0(0,0,0) 과 pp1(10,20)의 거리는 %f\n", d2);
}

