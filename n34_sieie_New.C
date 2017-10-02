#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include "TCanvas.h"
#include "n34_infile.h"
//#include ""


void n34_sieie_New()
{
///// test PLJ selection
//	TFile *inputf1 = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170926_lep_loose/outWG_s.root","READ");
//	TFile *inputf2 = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170926_lep_loose/outSingleMuon_Run2016_all_s.root","READ");
/////////

///////// Qianming's fake photon
	TFile *inputf1 = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170926_lep_loose/outWG_fakepho_s.root","READ");
	TFile *inputf2 = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170926_lep_loose/outSingleMuon_Run2016B_fakepho_s.root","READ");
//////////

	vector<TH1D*> vh;
	vector<Int_t> num;
	char buffer[256];	

	TCanvas *cv = new TCanvas("cv","cv", 1200,900);
	cv->Divide(3,2);
/*
	n34_infile *infile1 = new n34_infile(inputf1);
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
	cv->Update();
	cv->SaveAs("n34_WG.pdf");
	infile1->Clear();
	vh.clear();
	num.clear();
//	cv->Clear();
*/

	n34_infile *infile2 = new n34_infile(inputf2);
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
	cv->Update();
	cv->SaveAs("n34_DATA.png");
	infile2->Clear();
	vh.clear();
	num.clear();


	cout << "working fine "<<endl;	

}
