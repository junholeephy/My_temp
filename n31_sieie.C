#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include "TCanvas.h"
#include "n31_infile.h"
//#include ""


void n31_sieie()
{
	TFile *inputf1 = new TFile("/Volumes/ExHard/Run2VBSWGamma_plotting/PKUTree/outtree_170926/outWJets-2.root","READ");
	TFile *inputf2 = new TFile("/Volumes/ExHard/Run2VBSWGamma_plotting/PKUTree/outtree_170926/outSingleMuon_Run2016C.root","READ");
	vector<TH1D*> vh;
	vector<Int_t> num;
	char buffer[256];	

	TCanvas *cv = new TCanvas("cv","cv", 900,900);
	cv->Divide(2,2);

	n31_infile *infile1 = new n31_infile(inputf1);
	vh = infile1->gethisto();
	num = infile1->inte();
	for(size_t i=0; i<num.size(); i++)
	{
		cout<<(vh.at(i))->GetName()<<" : integral number : "<<num.at(i)<<endl;
	}
	for(size_t i=0; i<vh.size(); i++)
	{
		cv->cd(i+1);
		vh.at(i)->Draw();
	}
	cv->SaveAs("n31_WJets_photonsieie.png");
	cv->Update();
	infile1->Clear();
	vh.clear();
	num.clear();



	n31_infile *infile2 = new n31_infile(inputf2);
	vh = infile2->gethisto();
	num = infile2->inte();
	for(size_t i=0; i<num.size(); i++)
	{
		cout<<(vh.at(i))->GetName()<<" : integral number : "<<num.at(i)<<endl;
	}
	for(size_t i=0; i<vh.size(); i++)
	{
		cv->cd(i+1);
		vh.at(i)->Draw();
	}
	cv->SaveAs("n31_dataC_photonsieie.png");
	cv->Update();
	infile2->Clear();
	vh.clear();
	num.clear();


	cout << "working fine "<<endl;	

}
