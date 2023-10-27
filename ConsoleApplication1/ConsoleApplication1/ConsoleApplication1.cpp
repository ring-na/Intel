#include <iostream>

#define ABS(x)  ((x<0) ? (-x) : (x))
int main()
{
	
   printf("abs 매크로 함수입니다.\n\n");
   
   int x = -9;
   printf("입력값: %d ABS: %d",x,ABS(x));


}
