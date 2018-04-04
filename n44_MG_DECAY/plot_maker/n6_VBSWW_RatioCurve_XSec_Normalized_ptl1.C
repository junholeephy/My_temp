
void n6_VBSWW_RatioCurve_XSec_Normalized_ptl1()
{
    TCanvas *c1 = new TCanvas("c1","c1");
    gStyle->SetOptStat(0);
    TFile *f = new TFile("/Users/leejunho/Desktop/git/My_git/My_temp/n44_MG_DECAY/make_tree/output_VBSWW_Wplus.root","READ");

    TTree *treell = (TTree*)f->Get("treeLL");
    TTree *treett = (TTree*)f->Get("treeTT");
    TTree *treetl = (TTree*)f->Get("treeTL");

    Double_t lep1Pt = -10;
    Double_t lep2Pt = -10;
    Double_t lepPt = -10;
    Double_t P1Pt, P2Pt = -10;

    treell->SetBranchAddress("lep1Pt",&lep1Pt); treell->SetBranchAddress("lep2Pt",&lep2Pt); treell->SetBranchAddress("P1Pt",&P1Pt); treell->SetBranchAddress("P2Pt",&P2Pt);
    treett->SetBranchAddress("lep1Pt",&lep1Pt); treett->SetBranchAddress("lep2Pt",&lep2Pt); treett->SetBranchAddress("P1Pt",&P1Pt); treett->SetBranchAddress("P2Pt",&P2Pt);
    treetl->SetBranchAddress("lep1Pt",&lep1Pt); treetl->SetBranchAddress("lep2Pt",&lep2Pt); treetl->SetBranchAddress("P1Pt",&P1Pt); treetl->SetBranchAddress("P2Pt",&P2Pt);


    TH1F *hLL = new TH1F("hLL","hLL",20,0.,400);  hLL->SetLineColor(kRed);
    TH1F *hTT = new TH1F("hTT","hTT",20,0.,400);  hTT->SetLineColor(kGreen);
    TH1F *hTL = new TH1F("hTL","hTL",20,0.,400);  hTL->SetLineColor(kBlack);

    TH1F *htest = new TH1F("htest","htest",20,0.,400); htest->SetLineColor(kMagenta); htest->SetLineStyle(10);

    for(Int_t i=0; i<treell->GetEntries(); i++)
    {
        treell->GetEntry(i);
        lepPt = lep1Pt;
        if(lepPt < lep2Pt) lepPt = lep2Pt;
        if(lepPt>20 && P1Pt>30 && P2Pt>30)  hLL->Fill(lepPt);
        else continue;
    }
    for(Int_t i=0; i<treett->GetEntries(); i++)
    {
        treett->GetEntry(i);
        lepPt = lep1Pt;
        if(lepPt < lep2Pt) lepPt = lep2Pt;
        if(lepPt>20 && P1Pt>30 && P2Pt>30)  hTT->Fill(lepPt);
        else continue;
    }
    for(Int_t i=0; i<treetl->GetEntries(); i++)
    {
        treetl->GetEntry(i);
        lepPt = lep1Pt;
        if(lepPt < lep2Pt) lepPt = lep2Pt;
        if(lepPt>20 && P1Pt>30 && P2Pt>30)  hTL->Fill(lepPt);
        else continue;
    }

    Double_t XSec_lltttl,XSec_tt, XSec_tl, XSec_ll = 0;
    XSec_lltttl = 0.1829;
    XSec_tt = 0.1092;
    XSec_tl = 0.06487;
    XSec_ll = 0.009335;
//    XSec_lltttl = XSec_tt + XSec_tl + XSec_ll;

    Double_t scale_tt = XSec_tt * 1/double(treett->GetEntries());
    Double_t scale_tl = XSec_tl * 1/double(treetl->GetEntries());
    Double_t scale_ll = XSec_ll * 1/double(treell->GetEntries());

    hLL->Scale(scale_ll);    //hLL->Draw("same hist");
    hTL->Scale(scale_tl);    //hTL->Draw("same hist");
    hTT->Scale(scale_tt);    //hTT->Draw("same hist");
    htest->Add(hLL);
    htest->Add(hTL);
    htest->Add(hTT);    //htest->Draw("same hist");

    Double_t Bin_Content=0;
    Double_t PBin_Content=0;
    for(Int_t ijk=0; ijk<htest->GetNbinsX(); ijk++)
    {
        Bin_Content = htest->GetBinContent(ijk+1);
        if(Bin_Content==0) 
        {
            hLL->SetBinContent(ijk+1,0);
            hTT->SetBinContent(ijk+1,0);
            hTL->SetBinContent(ijk+1,0);
            htest->SetBinContent(ijk+1,0);
        }
        else
        {    
            PBin_Content = hLL->GetBinContent(ijk+1) / Bin_Content; hLL->SetBinContent(ijk+1,PBin_Content);
            PBin_Content = hTT->GetBinContent(ijk+1) / Bin_Content; hTT->SetBinContent(ijk+1,PBin_Content);
            PBin_Content = hTL->GetBinContent(ijk+1) / Bin_Content; hTL->SetBinContent(ijk+1,PBin_Content);
            PBin_Content = htest->GetBinContent(ijk+1) / Bin_Content; htest->SetBinContent(ijk+1,PBin_Content);
            htest->SetBinContent(ijk+1,1);
        }
    }
    htest->GetYaxis()->SetRangeUser(0., 1.2);  htest->GetXaxis()->SetTitle("pt_lep1");
    htest->Draw("hist");
    hLL->Draw("same hist");
    hTT->Draw("same hist");
    hTL->Draw("same hist");

    TLegend* legend = new TLegend(0.85, 0.85, 1., 1. , "");
    legend->SetFillColor(kWhite);
//    legend->AddEntry(hLLTTTL->GetName(), "Total VBS WW", "l");
    legend->AddEntry(hTT->GetName(), "VBS WW TT", "l");
    legend->AddEntry(hTL->GetName(), "VBS WW TL", "l");
    legend->AddEntry(hLL->GetName(), "VBS WW LL", "l");
//    legend->AddEntry("hLLTTTL", "VBS WW total", "l");
    legend->AddEntry("htest", "VBS WW TT + TL + LL", "l");
    legend->Draw();

    c1->Modified();
    c1->Update();
    c1->Print("plot6_RatioCurve_ptl1_XSec_normalized.pdf");

} 

