#include <string>
#include <vector>
#include <iostream>
#include "TFile.h"
#include "TH1D.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLine.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
//#include "CMSLabels.h"
#include "TVectorD.h"
#include "TGraph.h"
#include "TMath.h"
#include "TLatex.h"
#include "TGraphAsymmErrors.h"
#include "TGraphErrors.h"


class n29_HS
{
	public:
		THStack *hs = new THStack("hs","");
		n29_HS();
//		virtual void ~HS();
		void Draw();	
		void DrawD();
		THStack* SetMC(std::vector<TH1D*> histos);
		THStack* SetDATA(std::vector<TH1D*> histos);
		vector<TH1D*> histos_;
//		vector<std::string> Name();
//		vector<std::string> Name2(std::vector<TH1D*> histos);
//		THStack stack(std::vector<TH1D*> histos);

//		vector<TH1D*> TH_return(std::vector<TH1D*> histos);
};

n29_HS::n29_HS()
{
		
}

THStack* n29_HS::SetMC(std::vector<TH1D*> histos)
{
	THStack * hs1 = new THStack("hs1","hs1");
	cout<<"num of histos : "<<histos.size()<<endl;
	for(size_t i=0; i!=histos.size(); i++)
	{	
		histos.at(i)->SetFillColor(i+2);
		histos.at(i)->SetLineColor(i+2);
		hs1->Add(histos.at(i));
	}
	return hs1;
}
THStack *n29_HS::SetDATA(std::vector<TH1D*> histos)
{
	THStack *hs2 = new THStack("h2","h2");
	cout<<"num of histos : "<<histos.size()<<endl;
	for(size_t i=0; i!=histos.size(); i++)
	{
		histos.at(i)->SetMarkerColor(1);
		histos.at(i)->SetMarkerStyle(20);
		hs2->Add(histos.at(i));
	}
	return hs2;
}

void n29_HS::Draw()
{
	hs->Draw("SAME");
}



void n29_HS::DrawD()
{
	TCanvas *cv = new TCanvas("stack","stack",700,600);
	hs->Draw("EP");
}
/*
THStack n29_HS::stack(std::vector<TH1D*> histos)
{
	THStack hs1 =THStack("hs1","");
    cout<<"num of histos : "<<histos.size()<<endl;
    for(size_t i=0; i!=histos.size(); i++)
    {   
        histos.at(i)->SetFillColor(i+1);
        histos.at(i)->SetLineColor(i+1);
        hs1.Add(histos.at(i));
	}
	return hs1;
}
*/
/*

/////////////////////////////////////////
vector<TH1D*> n29_HS::TH_return(std::vector<TH1D*> histos)
{
	vector<TH1D*> hhh;
	for(size_t i=0; i!=histos.size(); i++)
	{
		hhh.push_back(histos.at(i));
	}
	return hhh;

}




vector<string> n29_HS::Name2(std::vector<TH1D*> histos)
{
	vector<string> ss;
	for(size_t i=0; i!=histos.size(); i++)
    {
		ss.push_back((histos.at(i))->GetName());
	}
	return ss;			

}


vector<string> n29_HS::Name()
{
	vector<string> ss;
	string s1 = "ttt";
	string s2 = "sss";
	ss.push_back(s1);
	ss.push_back(s2);	
	return ss;

}

*/
