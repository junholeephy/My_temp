#ifndef _TwoD_FIT_MAKE_FRACTION_H_ 
#define _TwoD_FIT_MAKE_FRACTION_H_

#include <iostream>
#include <string>
#include <vector>

///// calculating event number on 1 ab Lumi
class TwoD_Fit_Make_Fraction
{
    public:
        TwoD_Fit_Make_Fraction();
        vector<double> VNums;
        vector<double> V_Events_num_LL(string *STR, double low, double high);
        vector<double> V_Events_num_TL(string *STR, double low, double high);
        vector<double> V_Events_num_TT(string *STR, double low, double high);
        void Reset();

};

TwoD_Fit_Make_Fraction::TwoD_Fit_Make_Fraction()
{
}



vector<double> TwoD_Fit_Make_Fraction::V_Events_num_LL(string *STR, double low, double high)
{
    vector<double> LLNums;
    TFile *f = new TFile(STR->data(),"READ");
    TTree *tLL = (TTree*)f->Get("treeLL"); 
    Double_t cos_LL_Angle_1, cos_LL_Angle_2 = -10;
    Double_t weightLL_b = -10;
    tLL->SetBranchAddress("cos_LL_Angle_1",&cos_LL_Angle_1);  tLL->SetBranchAddress("cos_LL_Angle_2",&cos_LL_Angle_2); tLL->SetBranchAddress("weightLL_b",&weightLL_b);
    Double_t LLEn = tLL->GetEntries();
    Double_t W1, W2, W3, W4, W5=0;
    for(int i=0; i<LLEn-1; i++)
    {
        tLL->GetEntry(i);
        if(cos_LL_Angle_2<high && cos_LL_Angle_2>=low)
        {
            if(cos_LL_Angle_1<-0.6) {W1 = weightLL_b+W1;}
            else if(cos_LL_Angle_1>=-0.6 && cos_LL_Angle_1<-0.2 ) {W2 = weightLL_b+W2;}
            else if(cos_LL_Angle_1>=-0.2 && cos_LL_Angle_1<0.2 ) {W3 = weightLL_b+W3;}
            else if(cos_LL_Angle_1>=0.2 && cos_LL_Angle_1<0.6 ) {W4 = weightLL_b+W4;}
            else if(cos_LL_Angle_1>=0.6 && cos_LL_Angle_1<1.0 ) {W5 = weightLL_b+W5;}
        }
    }
    W1 = 1000000*W1; LLNums.push_back(W1);
    W2 = 1000000*W2; LLNums.push_back(W2);
    W3 = 1000000*W3; LLNums.push_back(W3);
    W4 = 1000000*W4; LLNums.push_back(W4);
    W5 = 1000000*W5; LLNums.push_back(W5);
    f->Close();
    return LLNums;
}



vector<double> TwoD_Fit_Make_Fraction::V_Events_num_TL(string *STR, double low, double high)
{   
    vector<double> TLNums;
    TFile *f = new TFile(STR->data(),"READ");
    TTree *tTpL = (TTree*)f->Get("treeTpL");  
    TTree *tTmL = (TTree*)f->Get("treeTmL");  
    Double_t cos_TpL_Angle_1, cos_TpL_Angle_2 = -10;
    Double_t cos_TmL_Angle_1, cos_TmL_Angle_2 = -10;    
    Double_t weightTpL_b, weightTmL_b = -10;
    tTpL->SetBranchAddress("cos_TpL_Angle_1",&cos_TpL_Angle_1);  tTpL->SetBranchAddress("cos_TpL_Angle_2",&cos_TpL_Angle_2); tTpL->SetBranchAddress("weightTpL_b",&weightTpL_b);
    tTmL->SetBranchAddress("cos_TmL_Angle_1",&cos_TmL_Angle_1);  tTmL->SetBranchAddress("cos_TmL_Angle_2",&cos_TmL_Angle_2); tTmL->SetBranchAddress("weightTmL_b",&weightTmL_b);
    Double_t TpLEn = tTpL->GetEntries();
    Double_t TmLEn = tTmL->GetEntries();
    Double_t W1, W2, W3, W4, W5=0;
    for(int i=0; i<TpLEn-1; i++)
    {   
        tTpL->GetEntry(i);
        if(cos_TpL_Angle_2<high && cos_TpL_Angle_2>=low)
        {   
            if(cos_TpL_Angle_1<-0.6) {W1 = weightTpL_b+W1;}
            else if(cos_TpL_Angle_1>=-0.6 && cos_TpL_Angle_1<-0.2 ) {W2 = weightTpL_b+W2;}
            else if(cos_TpL_Angle_1>=-0.2 && cos_TpL_Angle_1<0.2 ) {W3 = weightTpL_b+W3;}
            else if(cos_TpL_Angle_1>=0.2 && cos_TpL_Angle_1<0.6 ) {W4 = weightTpL_b+W4;}
            else if(cos_TpL_Angle_1>=0.6 && cos_TpL_Angle_1<1.0 ) {W5 = weightTpL_b+W5;}
        }
    }
    for(int i=0; i<TmLEn-1; i++)
    {
        tTmL->GetEntry(i);
        if(cos_TmL_Angle_2<high && cos_TmL_Angle_2>=low)
        {
            if(cos_TmL_Angle_1<-0.6) {W1 = weightTmL_b+W1;}
            else if(cos_TmL_Angle_1>=-0.6 && cos_TmL_Angle_1<-0.2 ) {W2 = weightTmL_b+W2;}
            else if(cos_TmL_Angle_1>=-0.2 && cos_TmL_Angle_1<0.2 ) {W3 = weightTmL_b+W3;}
            else if(cos_TmL_Angle_1>=0.2 && cos_TmL_Angle_1<0.6 ) {W4 = weightTmL_b+W4;}
            else if(cos_TmL_Angle_1>=0.6 && cos_TmL_Angle_1<1.0 ) {W5 = weightTmL_b+W5;}
        }
    }


    W1 = 1000000*W1; TLNums.push_back(W1);
    W2 = 1000000*W2; TLNums.push_back(W2);
    W3 = 1000000*W3; TLNums.push_back(W3);
    W4 = 1000000*W4; TLNums.push_back(W4);
    W5 = 1000000*W5; TLNums.push_back(W5);

    f->Close();
    return TLNums;
}


vector<double> TwoD_Fit_Make_Fraction::V_Events_num_TT(string *STR, double low, double high)
{   
    vector<double> TTNums;
    TFile *f = new TFile(STR->data(),"READ");
    TTree *tTpTp = (TTree*)f->Get("treeTpTp");
    TTree *tTmTm = (TTree*)f->Get("treeTmTm");
    TTree *tTpTm = (TTree*)f->Get("treeTpTm");
    TTree *tTmL = (TTree*)f->Get("treeTmL");  
    Double_t cos_TpTp_Angle_1, cos_TpTp_Angle_2 = -10;
    Double_t cos_TmTm_Angle_1, cos_TmTm_Angle_2 = -10;
    Double_t cos_TpTm_Angle_1, cos_TpTm_Angle_2 = -10;
    Double_t weightTpTp_b, weightTmTm_b, weightTpTm_b = -10;
    tTpTp->SetBranchAddress("cos_TpTp_Angle_1",&cos_TpTp_Angle_1);  tTpTp->SetBranchAddress("cos_TpTp_Angle_2",&cos_TpTp_Angle_2); tTpTp->SetBranchAddress("weightTpTp_b",&weightTpTp_b);
    tTmTm->SetBranchAddress("cos_TmTm_Angle_1",&cos_TmTm_Angle_1);  tTmTm->SetBranchAddress("cos_TmTm_Angle_2",&cos_TmTm_Angle_2); tTmTm->SetBranchAddress("weightTmTm_b",&weightTmTm_b);
    tTpTm->SetBranchAddress("cos_TpTm_Angle_1",&cos_TpTm_Angle_1);  tTpTm->SetBranchAddress("cos_TpTm_Angle_2",&cos_TpTm_Angle_2); tTpTm->SetBranchAddress("weightTpTm_b",&weightTpTm_b);
    Double_t TpTpEn= tTpTp->GetEntries();
    Double_t TmTmEn= tTmTm->GetEntries();
    Double_t TpTmEn= tTpTm->GetEntries();
    Double_t W1, W2, W3, W4, W5=0;
    for(int i=0; i<TpTpEn-1; i++)
    {
        tTpTp->GetEntry(i);
        if(cos_TpTp_Angle_2<high && cos_TpTp_Angle_2>=low)
        {
            if(cos_TpTp_Angle_1<-0.6) {W1 = weightTpTp_b+W1;}
            else if(cos_TpTp_Angle_1>=-0.6 && cos_TpTp_Angle_1<-0.2 ) {W2 = weightTpTp_b+W2;}
            else if(cos_TpTp_Angle_1>=-0.2 && cos_TpTp_Angle_1<0.2 ) {W3 = weightTpTp_b+W3;}
            else if(cos_TpTp_Angle_1>=0.2 && cos_TpTp_Angle_1<0.6 ) {W4 = weightTpTp_b+W4;}
            else if(cos_TpTp_Angle_1>=0.6 && cos_TpTp_Angle_1<1.0 ) {W5 = weightTpTp_b+W5;}
        }
    }
    for(int i=0; i<TmTmEn-1; i++)
    {
        tTmTm->GetEntry(i);
        if(cos_TmTm_Angle_2<high && cos_TmTm_Angle_2>=low)
        {
            if(cos_TmTm_Angle_1<-0.6) {W1 = weightTmTm_b+W1;}
            else if(cos_TmTm_Angle_1>=-0.6 && cos_TmTm_Angle_1<-0.2 ) {W2 = weightTmTm_b+W2;}
            else if(cos_TmTm_Angle_1>=-0.2 && cos_TmTm_Angle_1<0.2 ) {W3 = weightTmTm_b+W3;}
            else if(cos_TmTm_Angle_1>=0.2 && cos_TmTm_Angle_1<0.6 ) {W4 = weightTmTm_b+W4;}
            else if(cos_TmTm_Angle_1>=0.6 && cos_TmTm_Angle_1<1.0 ) {W5 = weightTmTm_b+W5;}
        }
    }
    for(int i=0; i<TpTmEn-1; i++)
    {
        tTpTm->GetEntry(i);
        if(cos_TpTm_Angle_2<high && cos_TpTm_Angle_2>=low)
        {
            if(cos_TpTm_Angle_1<-0.6) {W1 = weightTpTm_b+W1;}
            else if(cos_TpTm_Angle_1>=-0.6 && cos_TpTm_Angle_1<-0.2 ) {W2 = weightTpTm_b+W2;}
            else if(cos_TpTm_Angle_1>=-0.2 && cos_TpTm_Angle_1<0.2 ) {W3 = weightTpTm_b+W3;}
            else if(cos_TpTm_Angle_1>=0.2 && cos_TpTm_Angle_1<0.6 ) {W4 = weightTpTm_b+W4;}
            else if(cos_TpTm_Angle_1>=0.6 && cos_TpTm_Angle_1<1.0 ) {W5 = weightTpTm_b+W5;}
        }
    }
    W1 = 1000000*W1; TTNums.push_back(W1);
    W2 = 1000000*W2; TTNums.push_back(W2);
    W3 = 1000000*W3; TTNums.push_back(W3);
    W4 = 1000000*W4; TTNums.push_back(W4);
    W5 = 1000000*W5; TTNums.push_back(W5);
    
    f->Close();
    return TTNums;
}

void TwoD_Fit_Make_Fraction::Reset()
{
    VNums.clear();
}

#endif
