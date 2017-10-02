#include "n37_fitter.h"
#include "TFile.h"
#include "TH1D.h"
#include <vector>
#include <iostream>
void n37_fakepho()
{
	vector<TH1D*> vhMC;
	vector<TH1D*> vhDATA;

	TFile *fmc1 = new TFile("can_hMC1.root","READ");
	TFile *fmc2 = new TFile("can_hMC2.root","READ");
	TFile *fmc3 = new TFile("can_hMC3.root","READ");
	TFile *fmc4 = new TFile("can_hMC4.root","READ");
	TFile *fmc5 = new TFile("can_hMC5.root","READ");
	TH1D* hmc1 =(TH1D*)fmc1->Get("hMC1");
	TH1D* hmc2 =(TH1D*)fmc2->Get("hMC2");
	TH1D* hmc3 =(TH1D*)fmc3->Get("hMC3");
	TH1D* hmc4 =(TH1D*)fmc4->Get("hMC4");
	TH1D* hmc5 =(TH1D*)fmc5->Get("hMC5");
	vhMC.push_back(hmc1);
	vhMC.push_back(hmc2);
	vhMC.push_back(hmc3);
	vhMC.push_back(hmc4);
	vhMC.push_back(hmc5);

	TFile *fdata1 = new TFile("can_hDATA_F1.root","READ");
	TFile *fdata2 = new TFile("can_hDATA_F2.root","READ");
	TFile *fdata3 = new TFile("can_hDATA_F3.root","READ");
	TFile *fdata4 = new TFile("can_hDATA_F4.root","READ");
	TFile *fdata5 = new TFile("can_hDATA_F5.root","READ");
	TFile *fdata6 = new TFile("can_hDATA_T1.root","READ");
	TFile *fdata7 = new TFile("can_hDATA_T2.root","READ");
	TFile *fdata8 = new TFile("can_hDATA_T3.root","READ");
	TFile *fdata9 = new TFile("can_hDATA_T4.root","READ");
	TFile *fdata10= new TFile("can_hDATA_T5.root","READ");
	TH1D* hdata1 =(TH1D*)fdata1->Get("hDATA_F1");
	TH1D* hdata2 =(TH1D*)fdata2->Get("hDATA_F2");
	TH1D* hdata3 =(TH1D*)fdata3->Get("hDATA_F3");
	TH1D* hdata4 =(TH1D*)fdata4->Get("hDATA_F4");
	TH1D* hdata5 =(TH1D*)fdata5->Get("hDATA_F5");
	TH1D* hdata6 =(TH1D*)fdata6->Get("hDATA_T1");
	TH1D* hdata7 =(TH1D*)fdata7->Get("hDATA_T2");
	TH1D* hdata8 =(TH1D*)fdata8->Get("hDATA_T3");
	TH1D* hdata9 =(TH1D*)fdata9->Get("hDATA_T4");
	TH1D* hdata10=(TH1D*)fdata10->Get("hDATA_T5");
	vhDATA.push_back(hdata1);
	vhDATA.push_back(hdata2);
	vhDATA.push_back(hdata3);
	vhDATA.push_back(hdata4);
	vhDATA.push_back(hdata5);
	vhDATA.push_back(hdata6);
	vhDATA.push_back(hdata7);
	vhDATA.push_back(hdata8);
	vhDATA.push_back(hdata9);
	vhDATA.push_back(hdata10);

	cout<<"totolly having "<<vhMC.size()<<" histograms for Inclusive WGamma NLO." <<endl<<"And "<<vhDATA.size()<<" histograms for DATA sample including DATA and Fake template."<<endl;

//	TH1D* temp1 = vhMC.at(1);
//	temp1->Draw();

	n37_fitter *Fit = new n37_fitter(vhMC, vhDATA);

}
