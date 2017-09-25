#include "TFile.h"
//#include "TH1D.h"
#include <iostream>
#include "TTree.h"
#include <vector>

class n30_infile
{
public:
	//functions
	n30_infile(TFile* file);
	TH1D* gethisto();
	Int_t getentrynum(TTree* t)
	{
		return t->GetEntries();
	}


	//variables
	TFile* file_;
	TTree *t = NULL;
	double mtVlepJECnew=0;
	int nentries;
	TH1D* h = new TH1D("h","h",100,0,200);
};

n30_infile::n30_infile(TFile *file)
{
	file_ =file;
	t = (TTree*)file_->Get("demo");
	t->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);
	nentries = getentrynum(t);	
	cout<<"total entry = "<<nentries<<endl;

}

TH1D* n30_infile::gethisto()
{
	double perc=0;
	for(Long64_t d_ii=0; d_ii<nentries; d_ii++)
	{
		if(d_ii%300000==0) 
		{	perc=double(d_ii*100/nentries);    cout<<"now looping "<<d_ii<<" th event"<<"  total event num "<<nentries;  cout<<"  finished "<<perc<<"%"<<endl;
		}
		t->GetEntry(d_ii);
		if(mtVlepJECnew>=0) h->Fill(mtVlepJECnew);
	}	
	return h;
}


