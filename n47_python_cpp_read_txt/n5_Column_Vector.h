#ifndef _N5_COLUMN_VECTOR_H_
#define _N5_COLUMN_VECTOR_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>
#include "n3_ROW_VECTOR.h"
#include "n4_ITEM_NUM_of_ROW.h"
using namespace std;

class n5_Column_Vector
{
    public:
        n5_Column_Vector();
        void makePoints(string *x, vector<string> STF);
        vector<vector<string>> MAKE_Column_Vector(string file);
};

n5_Column_Vector::n5_Column_Vector()
{
}

void n5_Column_Vector::makePoints(string *x, vector<string> STF)
{
    for(int i=0; i<STF.size(); i++)
    {
        x[i] = STF.at(i);
    }
}

vector<vector<string>> n5_Column_Vector::MAKE_Column_Vector(string file)
{
    vector<string> STR;
    n3_ROW_VECTOR* row_vector = new n3_ROW_VECTOR();
    STR = row_vector->MAKE_ROW_VECTOR(&file);
    n4_ITEM_NUM_of_ROW* row_num = new n4_ITEM_NUM_of_ROW();
    int RNUM = row_num->ITEMS_OF_ROW(file); //cout<<RNUM<<endl;

    vector<vector<string>> VS;
    for(int j=0; j<STR.size(); j++)  // 1582 times
    {
        vector<string> temp_VS;
        istringstream is(STR.at(j));
        string temp_str;
        for(int i=0; i<RNUM; i++)
        {
            is>>temp_str;
            temp_VS.push_back(temp_str);
        }
        VS.push_back(temp_VS);
    }     

//    cout<<VS.size()<<endl;
//    cout<<VS.at(0).size()<<endl;

    vector<vector<string>> COL_VECTOR;
    for(int i=0; i<VS.at(0).size(); i++)
    {
        vector<string> temp_vec;
        for(int j=0; j<VS.size(); j++)
        {
            temp_vec.push_back(VS.at(j).at(i));
        }
        COL_VECTOR.push_back(temp_vec);
    }
//    cout<<COL_VECTOR.size()<<endl;
//    cout<<COL_VECTOR.at(0).size()<<endl;
    VS.clear();
/*
    Int_t n= STR.size();
    vector<string *> point_string;
    for(int ii=0; ii<COL_VECTOR.size(); ii++)
    {
        string *x = new string[n];
        makePoints(x, COL_VECTOR.at(ii));
        point_string.push_back(x);
    }
*/
    return COL_VECTOR;
//    COL_VECTOR.clear();
//    cout<<point_string.at(0)[1]<<endl;
//    return point_string;
}

#endif
