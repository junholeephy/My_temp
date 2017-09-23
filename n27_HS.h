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

};


n27_HS::n27_HS(std::vector<TH1D*> histos)
{
	for(size_t i=0; i!=histos.size(); i++)
	{
		histos.at(i)->SetFillColor(i+1);
		hs->Add(histos.at(i));
		Draw();
	}	
}

void n27_HS::Draw()
{
	hs->Draw();
}













