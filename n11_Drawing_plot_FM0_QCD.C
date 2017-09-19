/////  Because both of the first reweight point and second reweight point corresponds with SM points, there might be some uncorrection with h1 to h2 ... 


#include "TAxis.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TNtupleD.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector.h>

void n11_Drawing_plot_FM0_QCD()
{
	TFile *file1 = new TFile("out_FM0_EWK_QCD_aQGC_all.root","R");
//	TFile *file1 = new TFile("FM0_FM0_aQGC.root","R");

	file1->cd("");
	Double_t SM_inte=0;
	Double_t p1_inte=0;
	Double_t p2_inte=0;
	Double_t p3_inte=0;
	Double_t p4_inte=0;
	Double_t p5_inte=0;
	Double_t p6_inte=0;
	Double_t p7_inte=0;
	Double_t p8_inte=0;
	Double_t QCD_inte=0;

	TCanvas *c1 = new TCanvas("c01","c01",1500,500);
        TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.48,0.98,21);
        TPad *pad2 = new TPad("pad2","This is pad2",0.52,0.02,0.98,0.98,21);
        pad1->Draw();
        pad2->Draw();

        pad1->cd();
        pad1->SetLogy();
        pad1->SetFillColor(0);




TH1D* h0= (TH1D*) SM_WG_QCD->Clone();
TH1D* h1= (TH1D*) FM0_WpT1_QCD->Clone();
TH1D* h2= (TH1D*) FM0_WpT2_QCD->Clone();
TH1D* h3= (TH1D*) FM0_WpT3_QCD->Clone();
TH1D* h4= (TH1D*) FM0_WpT4_QCD->Clone();
TH1D* h5= (TH1D*) FM0_WpT5_QCD->Clone();
TH1D* h6= (TH1D*) FM0_WpT6_QCD->Clone();
TH1D* h7= (TH1D*) FM0_WpT7_QCD->Clone();
TH1D* h8= (TH1D*) FM0_WpT8_QCD->Clone();
TH1D* h9= (TH1D*) FM0_WpT9_QCD->Clone();
TH1D* h10= (TH1D*) FM0_WpT10_QCD->Clone();
TH1D* h11= (TH1D*) FM0_WpT11_QCD->Clone();
TH1D* h12= (TH1D*) FM0_WpT12_QCD->Clone();
TH1D* h13= (TH1D*) FM0_WpT13_QCD->Clone();
//TH1D* h14= (TH1D*) FM0_p14->Clone();
//TH1D* h15= (TH1D*) FM0_p15->Clone();
//TH1D* h16= (TH1D*) FM0_p16->Clone();i


//	TFile *file2 = new TFile("out_smonlyQCD_WG_bkg_pt150.root","R");
//	TH1D* hqcd = (TH1D*) SM_WG_QCD->Clone();


h0->SetLineColor(1);    h0->SetTitle("QCD_WG_FM0_Reweighted");
h1->SetLineColor(2);
h2->SetLineColor(3);
h3->SetLineColor(4);
h4->SetLineColor(14);
h5->SetLineColor(6);
h6->SetLineColor(7);
h7->SetLineColor(2);
h8->SetLineColor(9);
h9->SetLineColor(10);
h10->SetLineColor(11);
h11->SetLineColor(12);
h12->SetLineColor(13);
h13->SetLineColor(14);
//h14->SetLineColor(15);
//h15->SetLineColor(16);
//h16->SetLineColor(17);
//hqcd->SetLineColor(2);



h0->SetLineWidth(2);
h1->SetLineWidth(1);
h2->SetLineWidth(1);
h3->SetLineWidth(1);
h4->SetLineWidth(1);
h5->SetLineWidth(1);
h6->SetLineWidth(1);
h7->SetLineWidth(1);
h8->SetLineWidth(1);
h9->SetLineWidth(1);
h10->SetLineWidth(1);
h11->SetLineWidth(1);
h12->SetLineWidth(1);
h13->SetLineWidth(2);
//h14->SetLineWidth(2);
//h15->SetLineWidth(2);
//h16->SetLineWidth(2);
//hqcd->SetLineWidth(2);

//c1->SetLogy();
h2->Draw();  h2->SetStats(0);
h0->Draw("same");
h1->Draw("same");     //uncomment of Y-log plot
h3->Draw("same");
h4->Draw("same");
h5->Draw("same");
h6->Draw("same");
h7->Draw("same");
h8->Draw("same");
//h9->Draw("same");
//h10->Draw("same");
//h11->Draw("same");
//h12->Draw("same");
//h13->Draw("same");
//h14->Draw("same");
//h15->Draw("same");
//h16->Draw("same");
//hqcd->Draw("same");

TLegend *l1 = new TLegend(0.72,0.6,0.88,0.88);
l1->SetBorderSize(1);
l1->AddEntry(h0,"FM0_SM","FM0_SM");
l1->AddEntry(h1,"FM0_p1","FM0_p1");
l1->AddEntry(h2,"FM0_p2","FM0_p2");
l1->AddEntry(h3,"FM0_p3","FM0_p3");
l1->AddEntry(h4,"FM0_p4","FM0_p4");
l1->AddEntry(h5,"FM0_p5","FM0_p5");
l1->AddEntry(h6,"FM0_p6","FM0_p6");
l1->AddEntry(h7,"FM0_p7","FM0_p7");
l1->AddEntry(h8,"FM0_p8","FM0_p8");
//l1->AddEntry(h9,"-0.5e-10","-0.5e-10");
//l1->AddEntry(h10,"-0.75e-10","-0.75e-10");
//l1->AddEntry(h11,"-1e-10","-1e-10");
//l1->AddEntry(h12,"-1.5e-10","-1.5e-10");
//l1->AddEntry(h13,"-2e-10","-2e-10");
//l1->AddEntry(h14,"-2.5e-10","-2.5e-10");
//l1->AddEntry(h15,"-3e-10","-3e-10");
//l1->AddEntry(h16,"-4e-10","-4e-10");

//l1->AddEntry(hqcd,"SM_QCD","SM_QCD");
l1->Draw();


        pad2->cd();
//        pad2->SetLogy();
        pad2->SetFillColor(0);

h6->Draw();  h6->SetStats(0);
h0->Draw("same");
h3->Draw("same");     //uncomment of Y-log plot
h4->Draw("same");
h1->Draw("same");
h5->Draw("same");
h2->Draw("same");
h7->Draw("same");
h8->Draw("same");
//h9->Draw("same");
//h10->Draw("same");
//h11->Draw("same");
//h12->Draw("same");
//h13->Draw("same");
//h14->Draw("same");
//h15->Draw("same");
//h16->Draw("same");
//hqcd->Draw("same");

SM_inte=h0->Integral();	 cout<<"SM QCD integral = "<<SM_inte<<endl;
p1_inte=h1->Integral();  cout<<"p1 integral = "<<p1_inte<<endl;
p2_inte=h2->Integral();  cout<<"p2 integral = "<<p2_inte<<endl;
p3_inte=h3->Integral();  cout<<"p3 integral = "<<p3_inte<<endl;
p4_inte=h4->Integral();  cout<<"p4 integral = "<<p4_inte<<endl;
p5_inte=h5->Integral();  cout<<"p5 integral = "<<p5_inte<<endl;
p6_inte=h6->Integral();  cout<<"p6 integral = "<<p6_inte<<endl;
p7_inte=h7->Integral();	 cout<<"p7 integral = "<<p7_inte<<endl;
p8_inte=h8->Integral();  cout<<"p8 integral = "<<p8_inte<<endl;
//QCD_inte=hqcd->Integral(); cout<<"QCD SM integral = "<<QCD_inte<<endl;

//Double_t Signal = 1.96*sqrt(SM_inte) + SM_inte;  cout<<"Signal would be = "<<Signal<<endl; 	 
//Double_t Signal = 1.96*sqrt(SM_inte + QCD_inte) + (SM_inte + QCD_inte);  cout<<"Signal would be = "<<Signal<<endl; 
//Double_t Signal = 1.96*sqrt(QCD_inte) + (QCD_inte) ; cout<<"Signal would be = "<<Signal<<endl; 
Double_t Signal = 1.96*sqrt(SM_inte) + (SM_inte) ; cout<<"Signal would be = "<<Signal<<endl; 

TLegend *l1 = new TLegend(0.72,0.6,0.88,0.88);
l1->SetBorderSize(1);
//l1->SetFillColor(0);
//l1->AddEntry(h0,"SM","SM");
//l1->AddEntry(h1,"-4e-10","-4e-10");
//l1->AddEntry(h2,"-3e-10","-3e-10");
//l1->AddEntry(h3,"-2.5e-10","-2.5e-10");
//l1->AddEntry(h4,"-2e-10","-2e-10");
//l1->AddEntry(h5,"-1.5e-10","-1.5e-10");
//l1->AddEntry(h6,"-1e-10","-1e-10");
//l1->AddEntry(h7,"-0.75e-10","-0.75e-10");
//l1->AddEntry(h8,"-0.5e-10","-0.5e-10");
//l1->AddEntry(h9,"-0.5e-10","-0.5e-10");
//l1->AddEntry(h10,"-0.75e-10","-0.75e-10");
//l1->AddEntry(h11,"-1e-10","-1e-10");
//l1->AddEntry(h12,"-1.5e-10","-1.5e-10");
//l1->AddEntry(h13,"-2e-10","-2e-10");
//l1->AddEntry(h14,"-2.5e-10","-2.5e-10");
//l1->AddEntry(h15,"-3e-10","-3e-10");
//l1->AddEntry(h16,"-4e-10","-4e-10");
/*
l1->AddEntry(h0,"SM","SM");
//l1->AddEntry(h1,"-80e-12","-80e-12");
l1->AddEntry(h2,"-50e-12","-50e-12");
l1->AddEntry(h3,"-20e-12","-20e-12");
l1->AddEntry(h4,"-10e-12","-10e-12");
l1->AddEntry(h5,"-5e-12","-5e-12");
l1->AddEntry(h6,"-1e-12","-1e-12");
//l1->AddEntry(hqcd,"SM_QCD","SM_QCD");
l1->AddEntry(h7,"-2e-10","-2e-10");
*/
l1->AddEntry(h0,"FM0_SM","FM0_SM");
l1->AddEntry(h1,"FM0_p1","FM0_p1");
l1->AddEntry(h2,"FM0_p2","FM0_p2");
l1->AddEntry(h3,"FM0_p3","FM0_p3");
l1->AddEntry(h4,"FM0_p4","FM0_p4");
l1->AddEntry(h5,"FM0_p5","FM0_p5");
l1->AddEntry(h6,"FM0_p6","FM0_p6");
l1->AddEntry(h7,"FM0_p7","FM0_p7");
l1->AddEntry(h8,"FM0_p8","FM0_p8");
l1->Draw();


c1->SaveAs(TString("Drawing_plot_FM0_QCD.png"));



}
