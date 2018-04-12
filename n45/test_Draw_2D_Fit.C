#include <iostream>
#include <string>
#include <vector>
#include "TwoD_Fit_Make_fraction.h"

void test_Draw_2D_Fit()
{
    vector<double> LL_NUM, TL_NUM, TT_NUM;
    Double_t LOW, HIGH = -10;
    LOW = -1.0; HIGH = -0.6;
    string INFILE = "../n44_MG_DECAY/tree_maker/output_VBSWW_WW_WlepAngle_original.root";
    
    for(int j=0; j<5; j++)
    {
        TwoD_Fit_Make_Fraction *LL = new TwoD_Fit_Make_Fraction();
        LL_NUM = LL->V_Events_num_LL(&INFILE, LOW, HIGH);  
        for (int i=0; i<LL_NUM.size(); i++)
        {
            cout<<LL_NUM.at(i)<<endl;
        }
        cout<<endl;
        LL_NUM.clear();
        HIGH = 0.4+HIGH;
        LOW = 0.4+LOW;
    }
    LOW = -1.0; HIGH = -0.6;
    
    for(int j=0; j<5; j++)
    {
        TwoD_Fit_Make_Fraction *TL = new TwoD_Fit_Make_Fraction();
        TL_NUM = TL->V_Events_num_TL(&INFILE, LOW, HIGH);
        for (int i=0; i<TL_NUM.size(); i++)
        {
            cout<<TL_NUM.at(i)<<endl;
        }
        cout<<endl;
        TL_NUM.clear();
        HIGH = 0.4+HIGH;
        LOW = 0.4+LOW;
    }

    LOW = -1.0; HIGH = -0.6;

    for(int j=0; j<5; j++)
    {
        TwoD_Fit_Make_Fraction *TT = new TwoD_Fit_Make_Fraction();
        TT_NUM = TT->V_Events_num_TT(&INFILE, LOW, HIGH);
        for (int i=0; i<TT_NUM.size(); i++)
        {
            cout<<TT_NUM.at(i)<<endl;
        }
        cout<<endl;
        TT_NUM.clear();
        HIGH = 0.4+HIGH;
        LOW = 0.4+LOW;
    }


}


