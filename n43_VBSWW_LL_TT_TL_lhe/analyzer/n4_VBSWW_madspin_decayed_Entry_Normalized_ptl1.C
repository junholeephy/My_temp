#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"

void n4_VBSWW_madspin_decayed_Entry_Normalized_ptl1()
{
    TCanvas *c1 = new TCanvas("c1","c1");
    gStyle->SetOptStat(0);
    TFile *f = new TFile("../madspin_root_generator/output_madspin_VBSWW.root","READ");

    TTree *treell = (TTree*)f->Get("treeLL");
    TTree *treett = (TTree*)f->Get("treeTT");
    TTree *treetl = (TTree*)f->Get("treeTL");
    TTree *treetotal = (TTree*)f->Get("treeTotal");

    Double_t lep1Pt;
    Double_t lep2Pt;
    Double_t lepPt;
    Double_t P1Pt, P2Pt = -10;
    
    treell->SetBranchAddress("lep1Pt",&lep1Pt); treell->SetBranchAddress("lep2Pt",&lep2Pt); treell->SetBranchAddress("P1Pt",&P1Pt); treell->SetBranchAddress("P2Pt",&P2Pt);
    treett->SetBranchAddress("lep1Pt",&lep1Pt); treett->SetBranchAddress("lep2Pt",&lep2Pt); treett->SetBranchAddress("P1Pt",&P1Pt); treett->SetBranchAddress("P2Pt",&P2Pt);
    treetl->SetBranchAddress("lep1Pt",&lep1Pt); treetl->SetBranchAddress("lep2Pt",&lep2Pt); treetl->SetBranchAddress("P1Pt",&P1Pt); treetl->SetBranchAddress("P2Pt",&P2Pt);
    treetotal->SetBranchAddress("lep1Pt",&lep1Pt); treetotal->SetBranchAddress("lep2Pt",&lep2Pt); treetotal->SetBranchAddress("P1Pt",&P1Pt); treetotal->SetBranchAddress("P2Pt",&P2Pt);


    TH1F *hLLTTTL = new TH1F("hLLTTTL","Proportion of VBS WW, Normalized in Xsec",25,0,400);  hLLTTTL->SetLineColor(kBlue);
    TH1F *hLL = new TH1F("hLL","VBS SS WW, Normalized with Entry number ",25,0,400);  hLL->SetLineColor(kRed);
    TH1F *hTT = new TH1F("hTT","hTT",25,0,400);  hTT->SetLineColor(kGreen);
    TH1F *hTL = new TH1F("hTL","hTL",25,0,400);  hTL->SetLineColor(kBlack);
    
    TH1F *htest = new TH1F("htest","htest",25,0,400); htest->SetLineColor(kYellow); htest->SetLineStyle(10);
    
    for(Int_t i=0; i<treetotal->GetEntries(); i++)
    {
        treetotal->GetEntry(i);
        lepPt = lep1Pt; 
        if(lepPt < lep2Pt) lepPt = lep2Pt;
        if(lepPt>20 && P1Pt>30 && P2Pt>30) hLLTTTL->Fill(lepPt);
        else continue;
    }
    for(Int_t i=0; i<treell->GetEntries(); i++)
    {
        treell->GetEntry(i);
        lepPt = lep1Pt; 
        if(lepPt < lep2Pt) lepPt = lep2Pt;
        if(lepPt>20 && P1Pt>30 && P2Pt>30) hLL->Fill(lepPt);
        else continue;
    }
    for(Int_t i=0; i<treett->GetEntries(); i++)
    {
        treett->GetEntry(i);
        lepPt = lep1Pt;
        if(lepPt < lep2Pt) lepPt = lep2Pt;
        if(lepPt>20 && P1Pt>30 && P2Pt>30) hTT->Fill(lepPt);
        else continue;
    }
    for(Int_t i=0; i<treetl->GetEntries(); i++)
    {
        treetl->GetEntry(i);
        lepPt = lep1Pt;
        if(lepPt < lep2Pt) lepPt = lep2Pt;
        if(lepPt>20 && P1Pt>30 && P2Pt>30) hTL->Fill(lepPt);
        else continue;
    }
    
//    Double_t XSec_lltttl,XSec_tt, XSec_tl, XSec_ll = 0;
//    XSec_lltttl = 0.1829;
//    XSec_tt = 0.1092;
//    XSec_tl = 0.06487;
//    XSec_ll = 0.009335;
//    XSec_lltttl = XSec_tt + XSec_tl + XSec_ll;

//    Double_t scale_lltttl = XSec_lltttl * 1/double(treetotal->GetEntries());
//    cout<<treetotal->GetEntries()<<" "<<scale_lltttl<<endl;
    Double_t scale_tt = 1/double(treett->GetEntries());
    Double_t scale_tl = 1/double(treetl->GetEntries());
    Double_t scale_ll = 1/double(treell->GetEntries());

//    hLLTTTL->Scale(scale_lltttl);    hLLTTTL->Draw("hist");
    hLL->Scale(scale_ll);    hLL->Draw("hist");
    hTL->Scale(scale_tl);    hTL->Draw("same hist");
    hTT->Scale(scale_tt);    hTT->Draw("same hist");
//    htest->Add(hLL);
//    htest->Add(hTL);
//    htest->Add(hTT);
//    htest->Draw("same hist");
//    hLLTTTL->Scale(scale_lltttl);    hLLTTTL->Draw("same hist");
//    hs->Add(hTT);
//    hs->Add(hTL);
//    hs->Add(hLL);
//    hs->Draw("nostack");
//    hs->GetStack()->Last()->Draw("same");

    TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9 , "");
    legend->SetFillColor(kWhite);
//    legend->AddEntry(hLLTTTL->GetName(), "Total VBS WW", "l");
    legend->AddEntry(hTT->GetName(), "VBS WW TT", "l");
    legend->AddEntry(hTL->GetName(), "VBS WW TL", "l");
    legend->AddEntry(hLL->GetName(), "VBS WW LL", "l");
 //   legend->AddEntry("hLLTTTL", "VBS WW total", "l");
//    legend->AddEntry("htest", "VBS WW TT + TL + LL", "l");
    legend->Draw();

    c1->Modified();
    c1->Update();
    c1->Print("plot4_lep1Pt_Entry_normalized.pdf");
}
