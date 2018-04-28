#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void test2()
{
    string str1 = "qwe bbb 333";
    string str2,str3,str4;
    istringstream is(str1);
    is>>str2>>str3>>str4;
    cout<<str2<<","<<str3<<","<<str4<<endl;
}

