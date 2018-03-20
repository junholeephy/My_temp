#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"

void n1_VBSWW_LL_TT_TL_dphiP1P1_XSec_normalized()
{
    TCanvas *c1 = new TCanvas("c1","c1");
    gStyle->SetOptStat(0);
    TFile *fLLTTTL = new TFile("../root_generator/output_lhe_VBSWW_LL_TT_TL.root","READ");
    TFile *fLL = new TFile("../root_generator/output_lhe_VBSWW_LL.root","READ");
    TFile *fTT = new TFile("../root_generator/output_lhe_VBSWW_TT.root","READ");
    TFile *fTL = new TFile("../root_generator/output_lhe_VBSWW_TL.root","READ");

    TTree *tLLTTTL = (TTree*)fLLTTTL->Get("treeE");
    TTree *tLL = (TTree*)fLL->Get("treeE");
    TTree *tTT = (TTree*)fTT->Get("treeE");
    TTree *tTL = (TTree*)fTL->Get("treeE");

    Double_t P1P2dphi=-10;
    
    tLLTTTL->SetBranchAddress("P1P2dphi",&P1P2dphi);
    tLL->SetBranchAddress("P1P2dphi",&P1P2dphi);
    tTT->SetBranchAddress("P1P2dphi",&P1P2dphi);
    tTL->SetBranchAddress("P1P2dphi",&P1P2dphi);

    THStack *hs = new THStack("hs","Stacked 1D histogram");
    TH1F *hLLTTTL = new TH1F("hLLTTTL","Proportion of VBS WW, Normalized in Xsec",10,0.,3.1415926);  hLLTTTL->SetLineColor(kBlue);
    TH1F *hLL = new TH1F("hLL","hLL",10,0.,3.1415926);  hLL->SetLineColor(kRed);
    TH1F *hTT = new TH1F("hTT","hTT",10,0.,3.1415926);  hTT->SetLineColor(kGreen);
    TH1F *hTL = new TH1F("hTL","hTL",10,0.,3.1415926);  hTL->SetLineColor(kBlack);
    
    TH1F *htest = new TH1F("htest","htest",10,0.,3.1415926); htest->SetLineColor(kYellow); htest->SetLineStyle(10);
    
    for(Int_t i=0; i<tLLTTTL->GetEntries(); i++)
    {
        tLLTTTL->GetEntry(i);
        hLLTTTL->Fill(P1P2dphi);
    }
    for(Int_t i=0; i<tLL->GetEntries(); i++)
    {
        tLL->GetEntry(i);
        hLL->Fill(P1P2dphi);
    }
    for(Int_t i=0; i<tTT->GetEntries(); i++)
    {
        tTT->GetEntry(i);
        hTT->Fill(P1P2dphi);
    }
    for(Int_t i=0; i<tTL->GetEntries(); i++)
    {
        tTL->GetEntry(i);
        hTL->Fill(P1P2dphi);
    }
    
    Double_t XSec_lltttl,XSec_tt, XSec_tl, XSec_ll = 0;
    XSec_lltttl = 0.1829;
    XSec_tt = 0.1092;
    XSec_tl = 0.06487;
    XSec_ll = 0.009335;
//    XSec_lltttl = XSec_tt + XSec_tl + XSec_ll;

    Double_t scale_lltttl = XSec_lltttl * 1/double(tLLTTTL->GetEntries());
    cout<<tLLTTTL->GetEntries()<<" "<<scale_lltttl<<endl;
    Double_t scale_tt = XSec_tt * 1/double(tTT->GetEntries());
    Double_t scale_tl = XSec_tl * 1/double(tTL->GetEntries());
    Double_t scale_ll = XSec_ll * 1/double(tLL->GetEntries());

    hLLTTTL->Scale(scale_lltttl);    hLLTTTL->Draw("hist");
    hLL->Scale(scale_ll);    hLL->Draw("same hist");
    hTL->Scale(scale_tl);    hTL->Draw("same hist");
    hTT->Scale(scale_tt);    hTT->Draw("same hist");
    htest->Add(hLL);
    htest->Add(hTL);
    htest->Add(hTT);
    htest->Draw("same hist");
//    hLLTTTL->Scale(scale_lltttl);    hLLTTTL->Draw("same hist");
//    hs->Add(hTT);
//    hs->Add(hTL);
//    hs->Add(hLL);
//    hs->Draw("nostack");
//    hs->GetStack()->Last()->Draw("same");

    TLegend* legend = new TLegend(0.2, 0.2, 0.4, 0.4 , "");
    legend->SetFillColor(kWhite);
//    legend->AddEntry(hLLTTTL->GetName(), "Total VBS WW", "l");
    legend->AddEntry(hTT->GetName(), "VBS WW TT", "l");
    legend->AddEntry(hTL->GetName(), "VBS WW TL", "l");
    legend->AddEntry(hLL->GetName(), "VBS WW LL", "l");
    legend->AddEntry("hLLTTTL", "VBS WW total", "l");
    legend->AddEntry("htest", "VBS WW TT + TL + LL", "l");
    legend->Draw();

    c1->Modified();
    c1->Update();
    c1->Print("plot1_dphiP1P2_XSec_normalized.png");
}
