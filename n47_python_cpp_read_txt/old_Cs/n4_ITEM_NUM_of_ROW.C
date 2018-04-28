//root -l -q n4_ITEM_NUM_of_ROW.C\('"/Users/leejunho/Desktop/git/python3Env/group_study/project_pre/data_txt/BEIJING_Aqi/Aqi_Beijing_Holi.txt"'\)
#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>
#include "n3_ROW_VECTOR.h"
using namespace std;

void n4_ITEM_NUM_of_ROW(string file)
{

    vector<string> STR; 
    n3_ROW_VECTOR* row_vector = new n3_ROW_VECTOR(&file);
//    cout<<file.data()<<endl;
//    cout<<file.c_str()<<endl;
    STR = row_vector->MAKE_ROW_VECTOR(&file);


    string TEST_STR = STR.at(1);
    int num=0;
    for (int i=0;i<TEST_STR.length();i++)
    {
        if (TEST_STR[i]==32) num++;
    }
    int NUM = num+1;
    return NUM;

//    return 0;
}
