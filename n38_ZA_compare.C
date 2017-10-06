#include <vector>
#include "TH1D.h"
void n9_ZA_compare()
{
	TFile *f1 = new TFile("n7_offi_ZA.root","READ");
	TFile *f2 = new TFile("n8_292200_ZA.root","READ");

	TTree *t1 =(TTree*)f1->Get("Tree");
	TTree *t2 =(TTree*)f2->Get("Tree");
	TCanvas *cv = new TCanvas("cv","cv",600,600);

	TH1D *hpta1 = new TH1D("photon_pt","photon_pt",20,0,100);
	TH1D* hpta2 = new TH1D("hpta2","hpta2",20,0,100);
	TH1D* hptl1 = new TH1D("lepton_pt","lepton_pt",20,0,100);
	TH1D* hptl2 = new TH1D("hptl2","hptl2",20,0,100);
	TH1D* hMET1  = new TH1D("sec_lepton_pt","sec_lepton_pt",20,0,100);
	TH1D* hMET2  = new TH1D("MET2","MET2",20,0,100);
	TH1D* hptj1  = new TH1D("Jet_pt","Jet_pt",20,0,100);
	TH1D* hptj2  = new TH1D("ptj_2","ptj_2",20,0,100);
	TH1D* hWpt_reco1 = new TH1D("Zpt","Zpt",20,0,100);
	TH1D* hWpt_reco2 = new TH1D("Wpt_reco2","Wpt_reco2",20,0,100);

	double pta;
	double ptl;
	double ptnu;
	double ptj1;
	double pt_recon_W;
	
	t1->SetBranchAddress("pta",&pta);
	t2->SetBranchAddress("pta",&pta);
	t1->SetBranchAddress("ptl",&ptl);
	t2->SetBranchAddress("ptl",&ptl);
	t1->SetBranchAddress("ptnu",&ptnu);
        t2->SetBranchAddress("ptnu",&ptnu);
	t1->SetBranchAddress("ptj1",&ptj1);
        t2->SetBranchAddress("ptj1",&ptj1);
	t1->SetBranchAddress("pt_recon_W",&pt_recon_W);
        t2->SetBranchAddress("pt_recon_W",&pt_recon_W);
	
	Long64_t nentries1 = t1->GetEntries();
	Long64_t nentries2 = t2->GetEntries();

	for(size_t i=0; i<nentries1; i++)
	{
		t1->GetEntry(i);
		hpta1->Fill(pta);
		hptl1->Fill(ptl);
		hMET1->Fill(ptnu);
		hptj1->Fill(ptj1);
		hWpt_reco1->Fill(pt_recon_W);
	}
	hpta1->SetLineColor(kRed);	hptl1->SetLineColor(kRed);	hMET1->SetLineColor(kRed); hptj1->SetLineColor(kRed); hWpt_reco1->SetLineColor(kRed);
	hpta1->SetStats(0);	
	hptl1->SetStats(0);	
	hMET1->SetStats(0);	
	hptj1->SetStats(0);	
	hWpt_reco1->SetStats(0);
//	hpta1->Draw();
//	hptl1->SetMaximum(4000);	hptl1->Draw();
//	hMET1->SetMaximum(4000);	hMET1->Draw();
	hptj1->SetMaximum(900);	hptj1->Draw();
//	hWpt_reco1->SetMaximum(900);  hWpt_reco1->Draw();

	for(size_t i=0; i<nentries2; i++)
	{
		t2->GetEntry(i);
		hpta2->Fill(pta);
		hptl2->Fill(ptl);
                hMET2->Fill(ptnu);
                hptj2->Fill(ptj1);
                hWpt_reco2->Fill(pt_recon_W);
	}
	hpta2->SetLineColor(kBlue);	hptl2->SetLineColor(kBlue);      hMET2->SetLineColor(kBlue); hptj2->SetLineColor(kBlue); hWpt_reco2->SetLineColor(kBlue);
//	hpta2->Draw("same");	
//	hptl2->Draw("same");
//	hMET2->Draw("same");
	hptj2->Draw("same");
//	hWpt_reco2->Draw("same");
	
	TPaveLabel *label1 = new TPaveLabel(-3.5,700,-1,800,"Default option");
	label1->SetFillColor(42);
	label1->Draw();

	TLegend* leg = new TLegend(0.54,0.7,0.88,0.88);
	leg->SetMargin(0.4);
	leg->AddEntry(hpta1,"2016MC");
	leg->AddEntry(hpta2,"MG_2_6_X");
	leg->Draw();
	
}
