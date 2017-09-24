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


class n27_HS
{
	public:
		THStack *hs = new THStack("hs","");
	
		n27_HS(std::vector<TH1D*> histos);
//		virtual void ~HS();
		void Draw();	
		vector<std::string> Name();
		vector<std::string> Name2(std::vector<TH1D*> histos);

		vector<TH1D*> TH_return(std::vector<TH1D*> histos);
};

n27_HS::n27_HS(std::vector<TH1D*> histos)
{
	cout<<"num of histos : "<<histos.size()<<endl;
	for(size_t i=0; i!=histos.size(); i++)
	{
		histos.at(i)->SetFillColor(i+1);
		hs->Add(histos.at(i));
//		Draw();
	}	
}
void n27_HS::Draw()
{
	hs->Draw();
}

/////////////////////////////////////////
vector<TH1D*> n27_HS::TH_return(std::vector<TH1D*> histos)
{
	vector<TH1D*> hhh;
	for(size_t i=0; i!=histos.size(); i++)
	{
		hhh.push_back(histos.at(i));
	}
	return hhh;

}




vector<string> n27_HS::Name2(std::vector<TH1D*> histos)
{
	vector<string> ss;
	for(size_t i=0; i!=histos.size(); i++)
    {
		ss.push_back((histos.at(i))->GetName());
	}
	return ss;			

}


vector<string> n27_HS::Name()
{
	vector<string> ss;
	string s1 = "ttt";
	string s2 = "sss";
	ss.push_back(s1);
	ss.push_back(s2);	
	return ss;

}










