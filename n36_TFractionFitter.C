#include <iostream>
#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TFractionFitter.h"
#include "n36_infile.h"
#include "n36_fitter.h"
void n36_TFractionFitter()
{
	cout<<"test"<<endl;	
	
	TFile *fMC = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170926_lep_loose/outWG_s.root","READ");
	TFile *fDATA = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170926_lep_loose/outSingleMuon_Run2016_all_s.root","READ");
	vector<TH1D*> vhMC;
	vector<TH1D*> vhDATA;

	n36_infile *fileMC = new n36_infile(fMC);
	vhMC = fileMC->gethistoMC_T();
	fileMC->ClearMC();
	fileMC->ClearDATA();
	n36_infile *fileDATA = new n36_infile(fDATA);
	vhDATA = fileDATA->gethistoDATA();
	fileDATA->ClearMC();
	fileMC->ClearDATA();
	cout<<"totolly having "<<vhMC.size()<<" histograms for Inclusive WGamma NLO. And "<<vhDATA.size()<<" histograms for DATA sample including DATA and Fake template."<<endl;

	n36_fitter *Fit = new n36_fitter(vhMC, vhDATA);

	cout<<"!!!  working done  !!!"<<endl;
}
