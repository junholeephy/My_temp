#include <string>
#include <vector>
#include <iostream>
#include "TTree.h"
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

class n28_HS_tree
{
public:
	n28_HS_tree(vector<TFile*> files);
	vector<TH1D*> ReturnHistos();	
	vector<TTree*> tree;
	vector<Long64_t> nentries;
	vector<TFile*> files_;
	double mtVlepJECnew;
};

n28_HS_tree::n28_HS_tree(vector<TFile*> files)
{
	files_ = files;
	for(size_t i=0; i!= files.size(); i++)
	{	
		tree.push_back((TTree*)files.at(i)->Get("demo"));
	}
	

	for(size_t i=0; i!=tree.size(); i++)
	{
		(tree.at(i))->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);
		nentries.push_back(tree.at(i)->GetEntries());
		cout<<(files_.at(i)->GetName())<<" , nentries number : " <<nentries.at(i)<<endl;
	}
}



vector<TH1D*> n28_HS_tree::ReturnHistos()
{
	vector<TH1D*> hist;
	TH1D *h1 = new TH1D("h1","h1",20,0,100);
	TH1D *h2 = new TH1D("h2","h2",20,0,100);
	TH1D *h3 = new TH1D("h3","h3",20,0,100);
	hist.push_back(h1); hist.push_back(h2);	hist.push_back(h3);
	
	for(size_t j=0; j<files_.size(); j++)
	{
//		TH1D* h[j] = new TH1D("h","h",20,0,100);
//		hist.push_back(h[j]);
		for(Int_t i=0; i<nentries.at(j); i++)
		{
			tree.at(j)->GetEntry(i);
			hist.at(j)->Fill(mtVlepJECnew);
			if(i==0) cout<<"start looping "<<(files_.at(j)->GetName())<<endl;
			if(i%1000000==0) cout<<"Entry num " << i << std::endl;
		}
	}	
	
	return hist;
}













