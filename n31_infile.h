#include "TFile.h"
//#include "TH1D.h"
#include <iostream>
#include "TTree.h"
#include <vector>

class n31_infile
{
public:
	//functions
	n31_infile(TFile* file);
//	TH1D* gethisto();
//	TH1D* gethisto_f();
	vector<Int_t> inte();
	vector<TH1D*> gethisto();
	Int_t getentrynum(TTree* t)
	{
		return t->GetEntries();
	}
	void Clear();

	//variables
	TFile* file_;
	TTree *t = NULL;
	double photonsieie=0;
	double photonsieie_f =0;
	int lep =0;
	int nlooseeles = 0;
	int nloosemus = 0;
	int HLT_Mu3 = 0;
	double ptlep1 =0;
	double etalep1 = 0;
	double MET_et = 0;
	double mtVlepJECnew =0;
	double photonet=0;
	double photonet_f=0;
	double photoneta =0;
	double photoneta_f=0;
	double jet1pt =0;
	double jet1pt_f=0;
	double jet2pt =0;
	double jet2pt_f=0;
	double jet1eta = 0;
	double jet1eta_f=0;
	double jet2eta = 0;
	double jet2eta_f=0;
	int nentries;
	vector<TH1D*> vh;
	TH1D* h = new TH1D("h","h",100,0.0,0.035);
	TH1D* h1 = new TH1D("h1","h1",100,0.0,0.08);
	TH1D* h2 = new TH1D("h2","h2",100,0.0,0.08);
	TH1D *h3 = new TH1D("h3","h3",100,0.0,0.08);
	vector<Int_t> integral;
};

n31_infile::n31_infile(TFile *file)
{
	file_ =file;
	t = (TTree*)file_->Get("demo");
	t->SetBranchAddress("photonsieie",&photonsieie);
	t->SetBranchAddress("photonsieie_f",&photonsieie_f);
	t->SetBranchAddress("lep",&lep);
	t->SetBranchAddress("nlooseeles",&nlooseeles);
	t->SetBranchAddress("nloosemus",&nloosemus);
	t->SetBranchAddress("HLT_Mu3",&HLT_Mu3);
	t->SetBranchAddress("ptlep1",&ptlep1);
	t->SetBranchAddress("etalep1",&etalep1);
	t->SetBranchAddress("MET_et",&MET_et);
	t->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);
	t->SetBranchAddress("photonet",&photonet);
	t->SetBranchAddress("photonet_f",&photonet_f);
	t->SetBranchAddress("photoneta",&photoneta);
	t->SetBranchAddress("photoneta_f",&photoneta_f);
	t->SetBranchAddress("jet1pt",&jet1pt);
	t->SetBranchAddress("jet1pt_f",&jet1pt_f);
	t->SetBranchAddress("jet2pt",&jet2pt);
	t->SetBranchAddress("jet2pt_f",&jet2pt_f);
	t->SetBranchAddress("jet1eta",&jet1eta);
	t->SetBranchAddress("jet1eta_f",&jet1eta_f);
	t->SetBranchAddress("jet2eta",&jet2eta);
	t->SetBranchAddress("jet2eta_f",&jet2eta_f);
	nentries = getentrynum(t);	
	cout<<"total entry = "<<nentries<<endl;

}

vector<TH1D*> n31_infile::gethisto()
{
    double perc=0;
    for(Long64_t d_ii=0; d_ii<nentries; d_ii++)
    {
        if(d_ii%300000==0) 
        {   
			perc=double(d_ii*100/nentries);    cout<<"now looping "<<d_ii<<" th event"<<"  total event num "<<nentries;  cout<<"  finished "<<perc<<"%"<<endl;
        }
//        if(d_ii == 600000) break;
		t->GetEntry(d_ii);
        if(photonsieie != -10 && lep ==13 && nlooseeles==0 && nloosemus<2 && HLT_Mu3 ==1 && ptlep1>25 && fabs(etalep1)<2.1 && MET_et>20 && mtVlepJECnew>30 && photonet>22 && fabs(photoneta)<1.44 && jet1pt>20 && jet2pt>20 && fabs(jet1eta)<4.7 && fabs(jet2eta)<4.7 ) h->Fill(photonsieie);
    	if(photonsieie_f != -10 && lep ==13 && nlooseeles==0 && nloosemus<2 && HLT_Mu3 ==1 && ptlep1>25 && fabs(etalep1)<2.1 && MET_et>20 && mtVlepJECnew>30) h1->Fill(photonsieie_f);
		if(photonsieie_f != -10 && lep ==13 && nlooseeles==0 && nloosemus<2 && HLT_Mu3 ==1 && ptlep1>25 && fabs(etalep1)<2.1 && MET_et>20 && mtVlepJECnew>30 && fabs(photoneta_f)<1.44) h2->Fill(photonsieie_f);
		if(photonsieie_f != -10 && lep ==13 && nlooseeles==0 && nloosemus<2 && HLT_Mu3 ==1 && ptlep1>25 && fabs(etalep1)<2.1 && MET_et>20 && mtVlepJECnew>30 && photonet_f>22 && fabs(photoneta_f)<1.44 ) h3->Fill(photonsieie_f);		
	}
 	vh.push_back(h);
	vh.push_back(h1);	
    vh.push_back(h2);
	vh.push_back(h3);
	return vh;
}

vector<Int_t> n31_infile::inte()
{
	Int_t num;
	for(size_t i = 0; i!= vh.size(); i++)
	{	
		num=(vh.at(i))->Integral();
		integral.push_back(num);		
	}
	return integral;
}

void n31_infile::Clear()
{
	h->Clear();
	h1->Clear();
	h2->Clear();
	h3->Clear();
	vh.clear();	
	integral.clear();

}
