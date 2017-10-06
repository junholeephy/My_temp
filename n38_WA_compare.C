#include <vector>
#include "TH1D.h"
#include "TCanvas.h"
void n38_WA_compare()
{
	TFile *f1 = new TFile("n38_offi_WA.root","READ");
	TFile *f2 = new TFile("n38_292200_WA.root","READ");

	TTree *t1 =(TTree*)f1->Get("Tree");
	TTree *t2 =(TTree*)f2->Get("Tree");
	TCanvas *cv = new TCanvas("cv","cv",600,600);

	TH1D *hpta1 = new TH1D("photon_pt","photon_pt",20,0,100);			const int hpta1_bin= hpta1->GetNbinsX();		double ghpta1[hpta1_bin], ehpta1[hpta1_bin], xhpta1[hpta1_bin], halfwidth_hpta1[hpta1_bin];
	TH1D* hpta2 = new TH1D("hpta2","hpta2",20,0,100);					const int hpta2_bin= hpta2->GetNbinsX();		double ghpta2[hpta2_bin], ehpta2[hpta2_bin], xhpta2[hpta2_bin], halfwidth_hpta2[hpta2_bin];
	TH1D* hptl1 = new TH1D("lepton_pt","lepton_pt",20,0,100);			const int hptl1_bin= hptl1->GetNbinsX();		double ghptl1[hptl1_bin], ehptl1[hptl1_bin], xhptl1[hptl1_bin], halfwidth_hptl1[hptl1_bin];
	TH1D* hptl2 = new TH1D("hptl2","hptl2",20,0,100);					const int hptl2_bin= hptl2->GetNbinsX();		double ghptl2[hptl2_bin], ehptl2[hptl2_bin], xhptl2[hptl2_bin], halfwidth_hptl2[hptl2_bin];
	TH1D* hMET1  = new TH1D("MET","MET",20,0,100);						const int hMET1_bin= hMET1->GetNbinsX();		double ghMET1[hMET1_bin], ehMET1[hMET1_bin], xhMET1[hMET1_bin], halfwidth_hMET1[hMET1_bin];
	TH1D* hMET2  = new TH1D("MET2","MET2",20,0,100);					const int hMET2_bin= hMET2->GetNbinsX();		double ghMET2[hMET2_bin], ehMET2[hMET2_bin], xhMET2[hMET2_bin], halfwidth_hMET2[hMET2_bin];
	TH1D* hptj1  = new TH1D("Jet_pt","Jet_pt",20,0,100);				const int hptj1_bin= hptj1->GetNbinsX();		double ghptj1[hptj1_bin] ,ehptj1[hptj1_bin], xhptj1[hptj1_bin], halfwidth_hptj1[hptj1_bin];
	TH1D* hptj2  = new TH1D("ptj_2","ptj_2",20,0,100);					const int hptj2_bin= hptj2->GetNbinsX();		double ghptj2[hptj2_bin] ,ehptj2[hptj2_bin], xhptj2[hptj2_bin], halfwidth_hptj2[hptj2_bin];
	TH1D* hWpt_reco1 = new TH1D("Wpt","Wpt",20,0,100);					const int hWpt_reco1_bin= hWpt_reco1->GetNbinsX();	double ghWpt_reco1[hWpt_reco1_bin], ehWpt_reco1[hWpt_reco1_bin], xhWpt_reco1[hWpt_reco1_bin], halfwidth_hWpt_reco1[hWpt_reco1_bin];
	TH1D* hWpt_reco2 = new TH1D("Wpt_reco2","Wpt_reco2",20,0,100);		const int hWpt_reco2_bin= hWpt_reco2->GetNbinsX();	double ghWpt_reco2[hWpt_reco2_bin], ehWpt_reco2[hWpt_reco2_bin], xhWpt_reco2[hWpt_reco2_bin], halfwidth_hWpt_reco2[hWpt_reco2_bin];
	TH1D* hetaa1 = new TH1D("photon eta","photon eta",20,-3,3);			const int hetaa1_bin= hetaa1->GetNbinsX();			double ghetaa1[hetaa1_bin], ehetaa1[hetaa1_bin], xhetaa1[hetaa1_bin], halfwidth_hetaa1[hetaa1_bin];
	TH1D* hetaa2 = new TH1D("etaa2","etaa2",20,-3,3);					const int hetaa2_bin= hetaa2->GetNbinsX();			double ghetaa2[hetaa2_bin], ehetaa2[hetaa2_bin], xhetaa2[hetaa2_bin], halfwidth_hetaa2[hetaa2_bin];

	double pta;
	double ptl;
	double ptnu;
	double ptj1;
	double pt_recon_W;
	double etaa;
	double wgt;

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
	t1->SetBranchAddress("etaa",&etaa);
	t2->SetBranchAddress("etaa",&etaa);
	t1->SetBranchAddress("wgt",&wgt);
	t2->SetBranchAddress("wgt",&wgt);

	TH1D *wgt1 = new TH1D("wgt1","wgt1",30,-2000,2000);

	Long64_t nentries1 = t1->GetEntries();
	Long64_t nentries2 = t2->GetEntries();
	
	Long64_t npp1=0, npp2=0;
	Long64_t nmm1=0, nmm2=0;
	
	for(size_t i=0; i<nentries1; i++)
	{	t1->GetEntry(i);if(wgt>0.0) npp1++; else nmm1++;	}
	
	for(size_t i=0; i<nentries2; i++)
	{	t2->GetEntry(i); if(wgt>0) npp2++;	else nmm2++;	}

	cout<<npp1<<"   "<<nmm1<<endl;
	cout<<npp2<<"   "<<nmm2<<endl;
	double scalef;
	for(size_t i=0; i<nentries1; i++)
	{
		scalef = 1;
		t1->GetEntry(i);
	   	scalef = 821.7/float(npp1-nmm1)*fabs(wgt)/wgt;	
		hpta1->Fill(pta,scalef);
		hptl1->Fill(ptl,scalef);
		hMET1->Fill(ptnu,scalef);
		hptj1->Fill(ptj1,scalef);
		hWpt_reco1->Fill(pt_recon_W,scalef);
		hetaa1->Fill(etaa,scalef);	
	}


	hpta1->SetLineColor(kRed);	hptl1->SetLineColor(kRed);	hMET1->SetLineColor(kRed); hptj1->SetLineColor(kRed); hWpt_reco1->SetLineColor(kRed); hetaa1->SetLineColor(kRed);
	hpta1->SetStats(0);	hptl1->SetStats(0);	hMET1->SetStats(0);	hptj1->SetStats(0); hWpt_reco1->SetStats(0);	hetaa1->SetStats(0);
//	hpta1->Draw("H");
//	hptl1->Draw("H");
//	hMET1->Draw("H");
//	hptj1->Draw("H");
//	hWpt_reco1->Draw("H");
	hetaa1->SetMaximum(90);	hetaa1->Draw("H");



	double scalef_2;
	for(size_t i=0; i<nentries2; i++)
	{
		scalef_2 = 1;
		t2->GetEntry(i);
		scalef_2 = 836.1/float(npp2-nmm2)*fabs(wgt)/wgt;
		hpta2->Fill(pta,scalef_2);
		hptl2->Fill(ptl,scalef_2);
                hMET2->Fill(ptnu,scalef_2);
                hptj2->Fill(ptj1,scalef_2);
                hWpt_reco2->Fill(pt_recon_W,scalef_2);
		hetaa2->Fill(etaa,scalef_2);
	}
	
	
	hpta2->SetLineColor(kBlue);	hptl2->SetLineColor(kBlue);      hMET2->SetLineColor(kBlue); hptj2->SetLineColor(kBlue); hWpt_reco2->SetLineColor(kBlue); hetaa2->SetLineColor(kBlue);

//	hpta2->SetMarkerColor(kBlue);   hpta2->SetMarkerStyle(20);	hpta2->Draw("SAME EP");	
//	hptl2->SetMarkerColor(kBlue);   hptl2->SetMarkerStyle(20);	hptl2->Draw("SAME EP");
//	hMET2->SetMarkerColor(kBlue);   hMET2->SetMarkerStyle(20);	hMET2->Draw("SAME EP");
//	hptj2->SetMarkerColor(kBlue);	hptj2->SetMarkerStyle(20);	hptj2->Draw("SAME EP");
//	hWpt_reco2->SetMarkerColor(kBlue);   hWpt_reco2->SetMarkerStyle(20);	hWpt_reco2->Draw("SAME EP");
	hetaa2->SetMarkerColor(kBlue);   hetaa2->SetMarkerStyle(20);	hetaa2->Draw("SAME EP");



	for(int ibin=0; ibin != hpta1_bin; ibin++)
	{	xhpta1[ibin] = hpta1->GetBinCenter(ibin+1);	halfwidth_hpta1[ibin] = hpta1->GetBinWidth(ibin+1)/2;	ghpta1[ibin] = hpta1->GetBinContent(ibin+1);	ehpta1[ibin] = hpta1->GetBinError(ibin+1); 	
		xhpta2[ibin] = hpta2->GetBinCenter(ibin+1); halfwidth_hpta2[ibin] = hpta2->GetBinWidth(ibin+1)/2;	ghpta2[ibin] = hpta2->GetBinContent(ibin+1);	ehpta2[ibin] = hpta2->GetBinError(ibin+1);	}
	for(int ibin=0; ibin != hptl1_bin; ibin++)
	{	xhptl1[ibin] = hptl1->GetBinCenter(ibin+1);	halfwidth_hptl1[ibin] = hptl1->GetBinWidth(ibin+1)/2;	ghptl1[ibin] = hptl1->GetBinContent(ibin+1);	ehptl1[ibin] = hptl1->GetBinError(ibin+1);  
		xhptl2[ibin] = hptl2->GetBinCenter(ibin+1); halfwidth_hptl2[ibin] = hptl2->GetBinWidth(ibin+1)/2;	ghptl2[ibin] = hptl2->GetBinContent(ibin+1);	ehptl2[ibin] = hptl2->GetBinError(ibin+1);	}
	for(int ibin=0; ibin != hMET1_bin; ibin++)
	{	xhMET1[ibin] = hMET1->GetBinCenter(ibin+1);	halfwidth_hMET1[ibin] = hMET1->GetBinWidth(ibin+1)/2;	ghMET1[ibin] = hMET1->GetBinContent(ibin+1);	ehMET1[ibin] = hMET1->GetBinError(ibin+1); 
		xhMET2[ibin] = hMET2->GetBinCenter(ibin+1); halfwidth_hMET2[ibin] = hMET2->GetBinWidth(ibin+1)/2;	ghMET2[ibin] = hMET2->GetBinContent(ibin+1);	ehMET2[ibin] = hMET2->GetBinError(ibin+1);	}
	for(int ibin=0; ibin != hptj1_bin; ibin++)
	{	xhptj1[ibin] = hptj1->GetBinCenter(ibin+1);	halfwidth_hptj1[ibin] = hptj1->GetBinWidth(ibin+1)/2;	ghptj1[ibin] = hptj1->GetBinContent(ibin+1);	ehptj1[ibin] = hptj1->GetBinError(ibin+1); 
		xhptj2[ibin] = hptj2->GetBinCenter(ibin+1); halfwidth_hptj2[ibin] = hptj2->GetBinWidth(ibin+1)/2;	ghptj2[ibin] = hptj2->GetBinContent(ibin+1);	ehptj2[ibin] = hptj2->GetBinError(ibin+1);	}
	for(int ibin=0; ibin != hWpt_reco1_bin; ibin++)
	{	xhWpt_reco1[ibin] = hWpt_reco1->GetBinCenter(ibin+1);	halfwidth_hWpt_reco1[ibin] = hWpt_reco1->GetBinWidth(ibin+1)/2;	ghWpt_reco1[ibin] = hWpt_reco1->GetBinContent(ibin+1);	ehWpt_reco1[ibin] = hWpt_reco1->GetBinError(ibin+1); 
		xhWpt_reco2[ibin] = hWpt_reco2->GetBinCenter(ibin+1);   halfwidth_hWpt_reco2[ibin] = hWpt_reco2->GetBinWidth(ibin+1)/2;	ghWpt_reco2[ibin] = hWpt_reco2->GetBinContent(ibin+1);	ehWpt_reco2[ibin] = hWpt_reco2->GetBinError(ibin+1);	}
	for(int ibin=0; ibin != hetaa1_bin; ibin++)
	{	xhetaa1[ibin] = hetaa1->GetBinCenter(ibin+1);	halfwidth_hetaa1[ibin] = hetaa1->GetBinWidth(ibin+1)/2;	ghetaa1[ibin] = hetaa1->GetBinContent(ibin+1);	ehetaa1[ibin] = hetaa1->GetBinError(ibin+1);		
		xhetaa2[ibin] = hetaa2->GetBinCenter(ibin+1);   halfwidth_hetaa2[ibin] = hetaa2->GetBinWidth(ibin+1)/2;	ghetaa2[ibin] = hetaa2->GetBinContent(ibin+1);	ehetaa2[ibin] = hetaa2->GetBinError(ibin+1);	}
	
	
	TGraphAsymmErrors *gr_pta1  = new TGraphAsymmErrors(hpta1_bin, xhpta1, ghpta1, halfwidth_hpta1, halfwidth_hpta1, ehpta1, ehpta1);
	TGraphAsymmErrors *gr_pta2  = new TGraphAsymmErrors(hpta2_bin, xhpta2, ghpta2, halfwidth_hpta2, halfwidth_hpta2, ehpta2, ehpta2);
	TGraphAsymmErrors *gr_ptl1  = new TGraphAsymmErrors(hptl1_bin, xhptl1, ghptl1, halfwidth_hptl1, halfwidth_hptl1, ehptl1, ehptl1);
	TGraphAsymmErrors *gr_ptl2  = new TGraphAsymmErrors(hptl2_bin, xhptl2, ghptl2, halfwidth_hptl2, halfwidth_hptl2, ehptl2, ehptl2);
	TGraphAsymmErrors *gr_MET1  = new TGraphAsymmErrors(hMET1_bin, xhMET1, ghMET1, halfwidth_hMET1, halfwidth_hMET1, ehMET1, ehMET1);
	TGraphAsymmErrors *gr_MET2  = new TGraphAsymmErrors(hMET2_bin, xhMET2, ghMET2, halfwidth_hMET2, halfwidth_hMET2, ehMET2, ehMET2);
	TGraphAsymmErrors *gr_ptj1  = new TGraphAsymmErrors(hptj1_bin, xhptj1, ghptj1, halfwidth_hptj1, halfwidth_hptj1, ehptj1, ehptj1);
	TGraphAsymmErrors *gr_ptj2  = new TGraphAsymmErrors(hptj2_bin, xhptj2, ghptj2, halfwidth_hptj2, halfwidth_hptj2, ehptj2, ehptj2);
	TGraphAsymmErrors *gr_Wpt_reco1 = new TGraphAsymmErrors(hWpt_reco1_bin, xhWpt_reco1, ghWpt_reco1, halfwidth_hWpt_reco1, halfwidth_hWpt_reco1, ehWpt_reco1, ehWpt_reco1);
	TGraphAsymmErrors *gr_Wpt_reco2 = new TGraphAsymmErrors(hWpt_reco2_bin, xhWpt_reco2, ghWpt_reco2, halfwidth_hWpt_reco2, halfwidth_hWpt_reco2, ehWpt_reco2, ehWpt_reco2);
	TGraphAsymmErrors *gr_etaa1 = new TGraphAsymmErrors(hetaa1_bin, xhetaa1, ghetaa1, halfwidth_hetaa1, halfwidth_hetaa1, ehetaa1, ehetaa1); 
	TGraphAsymmErrors *gr_etaa2 = new TGraphAsymmErrors(hetaa2_bin, xhetaa2, ghetaa2, halfwidth_hetaa2, halfwidth_hetaa2, ehetaa2, ehetaa2);

	gr_pta1->SetFillStyle(3004);		gr_pta1->SetFillColor(kRed);
//	gr_pta2->SetFillStyle(3004);		gr_pta2->SetFillColor(kBlue);
	gr_ptl1->SetFillStyle(3004);		gr_ptl1->SetFillColor(kRed);
//	gr_ptl2->SetFillStyle(3004);		gr_ptl2->SetFillColor(kBlue);
	gr_MET1->SetFillStyle(3004);		gr_MET1->SetFillColor(kRed);
//	gr_MET2->SetFillStyle(3004);		gr_MET2->SetFillColor(kBlue);
	gr_ptj1->SetFillStyle(3004);		gr_ptj1->SetFillColor(kRed);
//	gr_ptj2->SetFillStyle(0);		gr_ptj2->SetFillColor(kBlue);
	gr_Wpt_reco1->SetFillStyle(3004);	gr_Wpt_reco1->SetFillColor(kRed);
//	gr_Wpt_reco2->SetFillStyle(3004);	gr_Wpt_reco2->SetFillColor(kBlue);
	gr_etaa1->SetFillStyle(3004);		gr_etaa1->SetFillColor(kRed);
//	gr_etaa2->SetFillStyle(3004);		gr_etaa2->SetFillColor(kBlue);		gr_etaa1->SetLineColor(kBlue);


//	gr_pta1->Draw("2same");
//	gr_ptl1->Draw("2same");
//	gr_MET1->Draw("2same");
//	gr_ptj1->Draw("2same");
//	gr_Wpt_reco1->Draw("2same");
	gr_etaa1->Draw("2same");


	TPaveLabel *label1 = new TPaveLabel(-3.5,700,-1,800,"Default option");
	label1->SetFillColor(42);
//	label1->Draw();

	TLegend* leg = new TLegend(0.54,0.7,0.88,0.88);
	leg->SetMargin(0.4);
	leg->AddEntry(hetaa1,"2016MC");
	leg->AddEntry(hetaa2,"MG_2_6_X","ep");
	leg->Draw();
//	cv->SaveAs("WA.pdf");
}
