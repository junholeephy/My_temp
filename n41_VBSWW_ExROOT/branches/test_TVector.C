#include "TVectorD.h"

void test_TVector()
{
    TVectorD v1(8);
    v1[0]=3;
    v1[1]=1;
    v1[4]=1;
    v1[2]=1;
    v1[3]=1;

//    v1.Draw();
//    v1[2]=2;
//    cout<<v1<<endl;
    v1.Print();
    double N1 = v1[0];  cout<<N1<<endl;
    int i=0;
    while(true)
    {
        if(i>=8) break;
        if(!v1[i]){ i++;continue;}
        else i++;
        cout<<v1[i]<<endl;
    }cout<<"size of TVector : "<<i<<endl;

}
