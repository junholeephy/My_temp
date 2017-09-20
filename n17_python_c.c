// the file name has to be **.c not **.C. means c language but not c++
//  gcc -o libn17_python_c.so -shared -fPIC n17_python_c.c  
#include <stdio.h>
#include "stdlib.h"
int adding(int a, int b)
{
	printf("you input %d and %d\n", a, b);
	printf("a = %d \n",a);	
	printf("b = %d \n",b);
	return a+b;
	
}
