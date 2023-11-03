#include "Point.h"


double Point::Dist(Point p) // 포인트 객체p를 받아 거리를 계산하는 함수
{
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}

Point& Point::SetP(Point p)
{
	x = p.x;
	y = p.y;
	return *this; 
}
Point& Point::SetP(int x, int y)
{
	this->x = x;
	this->y = y;
	return *this;
}//멤버이름이 같기 때문에 컴파일러의 혼동을 방지하기 위해 this사용
//앞에 x는 멤버 x, 뒤의 x는 변수 x
void Point::viewP(const char *s)
{
	printf("%s(%d,%d)\n", s, x, y);

}
Point& Point::MoveP(Point p) //내가 짠 이동 함수
{
	x = x + p.x;
	y = y - p.y;
	return *this;
}
Point& Point::MoveP(int dx, int dy) //교수님. 변수 이름은 동일하지 않아도 괜찮다.
{
	this->x += dx;
	this->y += dy;
	return *this;
}