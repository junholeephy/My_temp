#include "TInterpreter.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TFile.h"
#include "TH2.h"
#include "TNtuple.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TFrame.h"
#include "TSystem.h"
#include "TInterpreter.h"


void n16_histointe()
{
	TFile *fileMC = new TFile("histos_allMCs_b.root","READ"); 
//	TFile *fileWJets = new TFile("histos_WJets_b.root","READ"); 
//	TFile *fileWG = new TFile("histos_WG_b.root","READ");
//	TFile *filedata = new TFile("histos_outSingleMuon_Run2016BCD_b.root","READ");
//	TFile *fileMC = TFile::Open("histos_allMCs_b.root");

	if(!fileMC) return;
	cout<<endl<<endl;
	fileMC->ls();
	cout<<endl<<endl;
	TH1D *histoMC = (TH1D*)fileMC->Get("photon_sieie_mu"); 
	histoMC->SetLineColor(kBlack);
//	TH1D *histoWJets = (TH1D*)fileWJets->Get("photon_sieie_mu");
//	histoWJets->SetLineColor(kRed);
//	TH1D *histoWG = (TH1D*)fileWG->Get("photon_sieie_mu");
//	histoWG->SetLineColor(kBlue);

	TCanvas *c1 = new TCanvas("c1","c1",600,600);
	histoMC->Draw("HIST");
//	histoWJets->Draw("same HIST");
//	histoWG->Draw("same HIST");

	TAxis *axis = histoMC->GetXaxis();
	int bfir = axis->FindBin(0.004);	cout<<bfir<<endl;
	int bmin = axis->FindBin(0.0102);	cout<<bmin<<endl;
	int bmax = axis->FindBin(0.018);	cout<<bmax<<endl;
	double allMC = histoMC->Integral(bfir,bmax);
	double allMCsg = histoMC->Integral(bfir,bmin);
	double allMCsb = histoMC->Integral(bmin,bmax);

	cout<<"pseudodata at sig + sideband integral = "<<allMC<<endl;
	cout<<"pseudodata at sideband integral = "<<allMCsb<<endl;
	cout<<"pseudodata at signal integral = "<<allMCsg<<endl;

}
