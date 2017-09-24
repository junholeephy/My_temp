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

class n27_HS_tree
{
public:
	n27_HS_tree(vector<TFile*> files);
	vector<TH1D*> ReturnHistos();	
	vector<TTree*> tree;
	Long64_t nentries1;
	Long64_t nentries2;
	double mtVlepJECnew;
//	vector<TH1D*> returnhistos;
};

n27_HS_tree::n27_HS_tree(vector<TFile*> files)
{
	for(size_t i=0; i!= files.size(); i++)
	{	
		tree.push_back((TTree*)files.at(i)->Get("demo"));
	}

//	TTree *t1 =(TTree*)files.at(0)->Get("demo");	
//	TTree *t2 =(TTree*)files.at(1)->Get("demo");
	

	for(size_t i=0; i!=tree.size(); i++)
	{
		(tree.at(i))->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);
	}

//	t1->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);
//    t2->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);


	nentries1 = tree.at(0)->GetEntries();
	nentries2 = tree.at(1)->GetEntries();

	cout<<"ZG entries : " <<nentries1<<std::endl;
	std::cout<<"VV entries : "<<nentries2<<std::endl;
	std::cout<<std::endl;
}

vector<TH1D*> n27_HS_tree::ReturnHistos()
{
	vector<TH1D*> returnhistos;
	TH1D *h1 = new TH1D("h1","h1",20,0,100);
	TH1D *h2 = new TH1D("h2","h2",20,0,100);
	for(Int_t i=0; i<nentries1; i++)
	{
		tree.at(0)->GetEntry(i);
		h1->Fill(mtVlepJECnew);
		if(i==0) cout<<"Start Looping ZG "<<endl;
		if(i%1000000==0) cout<<"Entry num " << i << std::endl;
	}
	returnhistos.push_back(h1);

	for(Int_t i=0; i<nentries2; i++)
	{
		tree.at(1)->GetEntry(i);
		h2->Fill(mtVlepJECnew);
		if(i==0) cout<<"Start Looping VV "<<endl;
		if(i%1000000==0) cout<<"Entry num " << i << std::endl;
	}

//	cout<<"error 2!!!"<<endl;
	returnhistos.push_back(h2);
//	cout<<"error 1!!!"<<endl;
	return returnhistos;
}













