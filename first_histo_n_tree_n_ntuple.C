#include <TFile.h>
#include <TNtuple.h>
#include <TH2.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TRandom3.h>
#include <TInterpreter.h>
#include <TTree.h>

void first_histo_n_tree_n_ntuple()
{
	TFile *f = new TFile("first_histo_n_tree_n_ntuple.root","RECREATE");

	TRandom3 random;
	Float_t pxf, pyf, pzf;
	Double_t pxd, pyd, pzd;


///////////////////////////////// make just histos   ///////////////////
	TH1F *hpxf = new TH1F("hpxf","hpxf",20,0,10);
	TH1F *hpyf = new TH1F("hpyf","hpyf",20,0,10); 

	TH1D *hpyd = new TH1D("hpyd","hpyd",20,0,10);
	TH1D *hpxd = new TH1D("hpxd","hpxd",20,0,10);

	TH2F *hpxpzf = new TH2F("hpxpyf","hpxpyf",10,0,4,10,0,4);
	TH2D *hpxpzd = new TH2D("hpxpyd","hpxpyd",10,0,4,10,0,4);



/////////////////////////// make tree ////////////////////

    TTree *t1 = new TTree("t1","t1");
//    TTree t2("t2","t22");        					//// not available since the TFile is zhizhen style.

    t1->Branch("pxd",&pxd,"pxd/D");
    t1->Branch("pyd",&pyd,"pyd/D");
    t1->Branch("pzf",&pzf,"pzf/F");
//    t2.Branch("pxf",&pxf,"pxf/F");
//    t2.Branch("pyf",&pyf,"pyf/F");



///////////////////////// make ntuple ////////////////////////


	TNtuple *ntuple1 = new TNtuple("ntuple1","ntuple1","pxd:pyd:pzd");
	
	TNtuple *ntuple2 = new TNtuple("ntuple2","ntuple2","pxd:pyd:pzd:pxf:pyf:pzf");






///////////////////// make those histogram into the root file ////////////
	for(Int_t i=0; i<25000; i++)
	{
		random.Rannor(pxf,pyf);
		random.Rannor(pxd,pyd);
		pzf = pxf*pxf + pyf*pyf;
		pzd = pxd*pxd + pyd*pyd;
		
		hpxf->Fill(pxf);
		hpyf->Fill(pyf);

		hpxd->Fill(pxd);
		hpyd->Fill(pyd);

		hpxpzf->Fill(pxf,pzf);
		hpxpzd->Fill(pxd,pzd);

		t1->Fill();
//		t2.Fill();



		ntuple1->Fill(pxd,pyd);
		
		ntuple2->Fill(pxd,pyd,pzd,pxf,pyf,pzf);

	}
/////////////////////////////////////// end of the process. write and close the newly generated file //////////////


	f->Write();
	f->Close();


}
