#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include "TCanvas.h"
#include "n35_infile.h"

void n35_sieie_PTBin()
{
	char buffer[256];
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
		sprintf(buffer, "can_%s.root", vh.at(i)->GetName());
		vh.at(i)->SaveAs(buffer);
	}
	cv->Update();
	cv->SaveAs("n35_MC_true_pho.pdf");
	cv->Update();
	infile1->ClearMC();
	infile1->ClearDATA();
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
		sprintf(buffer, "can_%s.root", vh.at(i)->GetName());
		vh.at(i)->SaveAs(buffer);
	}  //sprintf(buffer, "%s/root/can_%s.root", nameOutDir_.c_str(), histoName.c_str());
	cv->Update();
	cv->SaveAs("n35_DATA_true_pho.pdf");
	cv->Update();
	for(size_t i=0; i<5; i++)
	{
		cout<<(vh.at(i+5))->GetName()<<" : integral number : "<<num.at(i+5)<<endl;
	}
	for(size_t i=0; i<5; i++)
	{
		cv->cd(i+1);
		vh.at(i+5)->Draw();
		sprintf(buffer, "can_%s.root", vh.at(i+5)->GetName());
		vh.at(i+5)->SaveAs(buffer);
	}
	cv->Update();
	cv->SaveAs("n35_DATA_fake_pho.pdf");
	infile2->ClearDATA();
	vh.clear();
	num.clear();
	infile2->ClearMC();
	infile2->ClearDATA();
}
