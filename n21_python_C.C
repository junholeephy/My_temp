// g++ -o libn21.so -shared -fPIC n21_python_C_good.C

#include "iostream"
using namespace std;

int test()
{
	int a = 10, b = 5;
	return a+b;
}


int n21_python_C()
{
	cout<<"------begin------"<<endl;
	int num = test();
	cout<<"num="<<num<<endl;
	cout<<"------ end ------"<<endl;
	return num;
}
