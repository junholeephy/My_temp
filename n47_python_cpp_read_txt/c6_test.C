//root -l -q c6_test.C\('"/Users/leejunho/Desktop/git/python3Env/group_study/project_pre/data_txt/BEIJING_Aqi/Aqi_Beijing_Holi.txt"'\)

#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>
#include "n3_ROW_VECTOR.h"
#include "n4_ITEM_NUM_of_ROW.h"
#include "n5_Column_Vector.h"
#include "n5_Column_list_Vector.h"

using namespace std;

void c6_test(string file)
{
    vector<string> R_STR;
    vector<vector<string>> C_STR;
    vector<string *> C_list_STR;
    n3_ROW_VECTOR* row_vector = new n3_ROW_VECTOR();
    R_STR = row_vector->MAKE_ROW_VECTOR(&file);
    n4_ITEM_NUM_of_ROW* row_num = new n4_ITEM_NUM_of_ROW();
    int RNUM = row_num->ITEMS_OF_ROW(file);
    n5_Column_Vector* col_vector = new n5_Column_Vector();
    C_STR = col_vector->MAKE_Column_Vector(file);
    n5_Column_list_Vector* col_list_vector = new n5_Column_list_Vector();
    C_list_STR = col_list_vector->MAKE_Column_list_Vector(file);
//    cout<<C_list_STR.size()<<endl;

}


