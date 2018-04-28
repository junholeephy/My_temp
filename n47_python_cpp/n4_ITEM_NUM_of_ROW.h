#ifndef _N4_ITEM_NUM_OF_ROW_H_
#define _N4_ITEM_NUM_OF_ROW_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>
#include "n3_ROW_VECTOR.h"

class n4_ITEM_NUM_of_ROW
{
    public:
        n4_ITEM_NUM_of_ROW();
        int ITEMS_OF_ROW(string file);
};

n4_ITEM_NUM_of_ROW::n4_ITEM_NUM_of_ROW()
{
}

int n4_ITEM_NUM_of_ROW::ITEMS_OF_ROW(string file)
{
    vector<string> STR;
    n3_ROW_VECTOR* row_vector = new n3_ROW_VECTOR();
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
}

#endif
