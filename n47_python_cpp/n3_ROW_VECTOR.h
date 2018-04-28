//root -l -q n3_ROW_VECTOR.C\('"/Users/leejunho/Desktop/git/python3Env/group_study/project_pre/data_txt/BEIJING_Aqi/Aqi_Beijing_Holi.txt"'\)
#ifndef _N3_ROW_VECTOR_H_ 
#define _N3_ROW_VECTOR_H_

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>

class n3_ROW_VECTOR
{
    public:
        n3_ROW_VECTOR();
        vector<string> MAKE_ROW_VECTOR(string *file);
};

n3_ROW_VECTOR::n3_ROW_VECTOR()
{
//    cout<<file->data()<<endl;
}

vector<string> n3_ROW_VECTOR::MAKE_ROW_VECTOR(string *file)
{
    ifstream infile;
//    cout<<file<<endl; 
    infile.open(file->data());   
    assert(infile.is_open());   

    vector<string> v_str; 
    string ss;
    while(getline(infile,ss))
    {
//        cout<<s<<endl;
        v_str.push_back(ss);
//        string str1,str2,str3,str4,str5,str6,str7,str8,str9,str10;
//        istringstream is(ss);
//        is>>str1>>str2>>str3>>str4>>str5>>str6>>str7>>str8>>str9>>str10;
//        cout<<str1<<","<<str2<<","<<str3<<","<<str4<<","<<str5<<","<<str6<<","<<str7<<","<<str8<<","<<str9<<","<<str10<<endl;
    }
//    string STR = v_str.at(1);
//    cout<<STR<<endl;
//    for(int i=0; i<v_str.size(); i++)
//    {
//        cout<<v_str.at(i)<<endl;
//    }
    infile.close();              

    return v_str;

}

#endif

