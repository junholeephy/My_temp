// need extern "C" helps ...  not good.
// g++ -o libn20.so -shared -fPIC n20_python_C.C
#include <iostream>
using namespace std;

class TestLib
{
	public:
		void display1();
		void display2(int a);
};

void TestLib::display1() 
{
	cout<<"first : just printing " <<endl;
}

void TestLib::display2(int a)
{
	cout<<"second : printint input number "<<a<<endl;
}

extern "C"
{
	TestLib obj;
	void display1()
	{
		obj.display1();
	}
	void display2()
	{
		obj.display2(2);
	}
}

