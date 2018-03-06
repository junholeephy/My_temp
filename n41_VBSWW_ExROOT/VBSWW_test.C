#include "TChain.h"
//#include "externel/ExRootAnalysis/ExRootTreeReader.h"
#include "TLorentzVector.h"
#include "TSystem.h"
#include "TROOT.h"     // Need this get "gSystem" work!!!!
#include "TClonesArray.h"
#include <vector>
#include "TH1.h"
//#include "VBSWW_test.h"
void VBSWW_test()
{
    TFile *fout = new TFile("VBSWW_GEN_output.root","RECREATE");
    TTree *treeW1 = new TTree("treeW1","treeW1");
    TTree *treeW2 = new TTree("treeW2","treeW2");
    TTree *treeP1 = new TTree("treeP1","treeP1");
    TTree *treeP2 = new TTree("treeP2","treeP2");

    TChain chain("LHEF");
    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_01/10M.root");
    
    ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
    Long64_t numberOfEntries = treeReader->GetEntries();
    cout<<"Total Number of Entry Events : "<<numberOfEntries<<endl;

    TClonesArray *branchEvent = treeReader->UseBranch("Event");
    TClonesArray *branchParticle = treeReader->UseBranch("Particle");
    
//    std::vector<GenParton*> vSelectedGenParton;
    std::vector<TClonesArray*> vSelectedEvent;
    std::vector<TRootLHEFParticle*> vSelectedGenW;
    std::vector<TRootLHEFParticle*> vSelectedGenJet;

    Double_t temp=0;
    Int_t Enum = 0;
    for(int i=0; i<=numberOfEntries-1; i++)
    {
        treeReader->ReadEntry(i);
        TRootLHEFParticle *particleW1=(TRootLHEFParticle*) branchParticle->At(2);
        TRootLHEFParticle *particleW2=(TRootLHEFParticle*) branchParticle->At(3);
        TRootLHEFParticle *particleP1=(TRootLHEFParticle*) branchParticle->At(4);
        TRootLHEFParticle *particleP2=(TRootLHEFParticle*) branchParticle->At(5);
        if(particleW1->PT>=10 && particleW2->PT>=10 && fabs(particleW2->PID)==24 && fabs(particleW2->PID)==24 && particleP1->PT>=30 && fabs(particleP1->Eta)<4.7 && particleP2->PT>=30 && fabs(particleP2->Eta)<4.7 ) {vSelectedEvent.push_back(branchParticle); Enum++;}
    }
    cout<<"total passed event number : "<<Enum<<endl;
    cout<<"stored event number : "<<vSelectedEvent.size()<<endl;
  
    TH1F *hW1pt= new TH1F("hW1pt","hW1pt",50,0.,200.);
    TH1F *hW1Eta = new TH1F("hW1Eta","hW1Eta",20,-5,5);
    TH1F *hW1Phi = new TH1F("hW1Phi","hW1Phi",20,-5,5);
    TH1F *hW2pt= new TH1F("hW2pt","hW2pt",50,0.,200.); 
    TH1F *hW2Eta = new TH1F("hW2Eta","hW2Eta",20,-5,5);
    TH1F *hW2Phi = new TH1F("hW2Phi","hW2Phi",20,-5,5);
    TH1F *hP1pt= new TH1F("hP1pt","hP1pt",50,0.,200.);
    TH1F *hP1Eta = new TH1F("hP1Eta","hP1Eta",20,-5,5);
    TH1F *hP1Phi = new TH1F("hP1Phi","hP1Phi",20,-5,5);
    TH1F *hP2pt= new TH1F("hP2pt","hP2pt",50,0.,200.);
    TH1F *hP2Eta = new TH1F("hP2Eta","hP2Eta",20,-5,5);
    TH1F *hP2Phi = new TH1F("hP2Phi","hP2Phi",20,-5,5);
    
    Double_t W1Pt, W1Eta, W1Phi=0;
    Double_t W2Pt, W2Eta, W2Phi=0;
    Double_t P1Pt, P1Eta, P1Phi=0;
    Double_t P2Pt, P2Eta, P2Phi=0;
    treeW1->Branch("W1Pt",&W1Pt,"W1Pt/D");  treeW1->Branch("W1Eta",&W1Eta,"W1Eta/D");  treeW1->Branch("W1Phi",&W1Phi,"W1Phi/D");
    treeW2->Branch("W2Pt",&W2Pt,"W2Pt/D");  treeW2->Branch("W2Eta",&W2Eta,"W2Eta/D");  treeW2->Branch("W2Phi",&W2Phi,"W2Phi/D");
    treeP1->Branch("P1Pt",&P1Pt,"P1Pt/D");  treeP1->Branch("P1Eta",&P1Eta,"P1Eta/D");  treeP1->Branch("P1Phi",&P1Phi,"P1Phi/D");
    treeP2->Branch("P2Pt",&P2Pt,"P2Pt/D");  treeP2->Branch("P2Eta",&P2Eta,"P2Eta/D");  treeP2->Branch("P2Phi",&P2Phi,"P2Phi/D");

    for(int j=0; j<=vSelectedEvent.size()-1; j++)
    { 
        treeReader->ReadEntry(j);
        TRootLHEFParticle *particleW1=(TRootLHEFParticle*) (vSelectedEvent.at(j))->At(2);
        TRootLHEFParticle *particleW2=(TRootLHEFParticle*) (vSelectedEvent.at(j))->At(3);
        TRootLHEFParticle *particleP1=(TRootLHEFParticle*) (vSelectedEvent.at(j))->At(4);
        TRootLHEFParticle *particleP2=(TRootLHEFParticle*) (vSelectedEvent.at(j))->At(5);

        W1Pt = particleW1->PT;  W1Eta = particleW1->Eta;  W1Phi = particleW1->Phi;
        W2Pt = particleW2->PT;  W2Eta = particleW2->Eta;  W2Phi = particleW2->Phi;
        P1Pt = particleP1->PT;  P1Eta = particleP1->Eta;  P1Eta = particleP1->Phi;
        P2Pt = particleP2->PT;  P2Eta = particleP2->Eta;  P2Eta = particleP2->Phi;

        hW1pt->Fill(particleW1->PT);
        hW1Eta->Fill(particleW1->Eta);
        hW1Phi->Fill(particleW1->Phi);
        hW2pt->Fill(particleW2->PT);
        hW2Eta->Fill(particleW2->Eta);
        hW2Phi->Fill(particleW2->Phi);
        hP1pt->Fill(particleP1->PT);
        hP1Eta->Fill(particleP1->Eta);
        hP1Phi->Fill(particleP1->Phi);
        hP2pt->Fill(particleP2->PT);
        hP2Eta->Fill(particleP2->Eta);
        hP2Phi->Fill(particleP2->Phi);
        treeW1->Fill();
        treeW2->Fill();
        treeP1->Fill();
        treeP2->Fill();
    }
//    hWpt->Draw();
    hW1pt->Write();
    hW1Eta->Write();
    hW1Phi->Write();
    hW2pt->Write();
    hW2Eta->Write();
    hW2Phi->Write();
    hP1pt->Write();
    hP1Eta->Write();
    hP1Phi->Write();
    hP2pt->Write();
    hP2Eta->Write();
    hP2Phi->Write();
    treeW1->Write();
    treeW2->Write();
    treeP1->Write();
    treeP2->Write();
    fout->Close();


}


