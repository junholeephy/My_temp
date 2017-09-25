#include "TH1D.h"
#include <iostream>
#include <vector>
#include "n30_infile.h"
#include "n30_fit.h"
void n30_gaus_fit()
{
	TFile *inputf = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170922_lep_loose/outWJets_s.root","READ");
	TH1D* h=NULL;	
	TCanvas *cv = new TCanvas("cv","cv",700,700);
	n30_infile *infile = new n30_infile(inputf);
	h = infile->gethisto();
	n30_fit *fit=new n30_fit(h);

	cout<<"working fine"<<endl;	
}
