#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include "TCanvas.h"
#include "n35_infile.h"

void n35_sieie_PTBin()
{
	TFile *fMC = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170926_lep_loose/outWG_s.root","READ");
	TFile *fDATA = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170926_lep_loose/outSingleMuon_Run2016_all_s.root","READ");

	vector<TH1D*> vh;
	vector<Int_t> num;
	
	TCanvas *cv = new TCanvas("cv","cv",1200,900);
	cv->Divide(3,2);
	


	n35_infile *infile1 = new n35_infile(fMC);
	vh = infile1->gethistoMC_T();
	num = infile1->inte();
	for(size_t i=0; i<vh.size();i++)
	{
		cout<<(vh.at(i))->GetName()<<" : integral number : "<<num.at(i)<<endl;
	}
	for(size_t i=0; i<vh.size(); i++)
	{
		cv->cd(i+1);
		vh.at(i)->Draw();
	}
	cv->Update();
	cv->SaveAs("n35_MC_true_pho.png");
	cv->Update();
	infile1->ClearMC();
	vh.clear();
	num.clear();

	n35_infile *infile2 = new n35_infile(fDATA);
	vh = infile2->gethistoDATA();
	num = infile2->inte();	
	for(size_t i=0; i<5 ;i++)
	{
		cout<<(vh.at(i))->GetName()<<" : integral number : "<<num.at(i)<<endl;
	}
	for(size_t i=0; i<5; i++)
	{
		cv->cd(i+1);
		vh.at(i)->Draw();
	}
	cv->Update();
	cv->SaveAs("n35_DATA_true_pho.png");
	cv->Update();
	for(size_t i=5; i<vh.size(); i++)
	{
		cout<<(vh.at(i))->GetName()<<" : integral number : "<<num.at(i)<<endl;
	}
	for(size_t i=0; i<5; i++)
	{
		cv->cd(i+1);
		vh.at(i+5)->Draw();
	}
	cv->Update();
	cv->SaveAs("n35_DATA_fake_pho.png");
	infile2->ClearDATA();
	vh.clear();
	num.clear();
}
