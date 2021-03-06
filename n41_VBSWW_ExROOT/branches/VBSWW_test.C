// "root -l run.C"    to execute

#include "TChain.h"
//#include "externel/ExRootAnalysis/ExRootTreeReader.h"
#include "TLorentzVector.h"
#include "TSystem.h"
#include "TROOT.h"     // Need this get "gSystem" work!!!!
#include "TClonesArray.h"
#include <vector>
#include "TH1.h"
//#include "H_VBSWW_test.h"


class Vectors
{
    Double_t w1pt,w1eta,w1phi,w1spin;
    Double_t w2pt,w2eta,w2phi,w2spin;
    Double_t p1pt,p1eta,p1phi,p1spin;
    Double_t p2pt,p2eta,p2phi,p2spin;

    public:
        Vectors(): w1pt(0),w1eta(0), w1phi(0), w1spin(0),w2pt(0),w2eta(0), w2phi(0), w2spin(0),p1pt(0),p1eta(0), p1phi(0), p1spin(0),p2pt(0),p2eta(0), p2phi(0), p2spin(0) {}
//        Vectors(): w1pt(0),w1eta(0), w1phi(0), w1spin(0) {}


        Double_t x1() {return w1pt;}
        Double_t x2() {return w1eta;}
        Double_t x3() {return w1phi;}
        Double_t x4() {return w1spin;}
        Double_t x5() {return w2pt;}
        Double_t x6() {return w2eta;}
        Double_t x7() {return w2phi;}
        Double_t x8() {return w2spin;}
        Double_t x9() {return p1pt;}
        Double_t x10() {return p1eta;}
        Double_t x11() {return p1phi;}
        Double_t x12() {return p1spin;}
        Double_t x13() {return p2pt;}
        Double_t x14() {return p2eta;}
        Double_t x15() {return p2phi;}
        Double_t x16() {return p2spin;}

    void SetVecs(Double_t x1, Double_t x2, Double_t x3, Double_t x4, Double_t x5, Double_t x6, Double_t x7, Double_t x8, Double_t x9, Double_t x10, Double_t x11, Double_t x12, Double_t x13, Double_t x14, Double_t x15, Double_t x16)
    { 

//    void SetVecs(Double_t x1, Double_t x2, Double_t x3, Double_t x4)
//    {
        w1pt = x1;
        w1eta = x2;
        w1phi = x3;
        w1spin = x4;
        w2pt = x5;
        w2eta = x6;
        w2phi = x7;
        w2spin = x8;
        p1pt = x9;
        p1eta = x10;
        p1phi = x11;
        p1spin = x12;
        p2pt = x13;
        p2eta = x14;
        p2phi = x15;
        p2spin = x16;

    }
};

void VBSWW_test()
{
    TFile *fout = new TFile("VBSWW_GEN_output.root","RECREATE");
    TTree *treeE  = new TTree("treeE","treeE");
//    vector<double> branchE;
//    treeE->Branch("Ebranch",&branchE,32000,1);

    Vectors *v = new Vectors();
    treeE->Branch("Vs",&v,32000,1);

    TChain chain("LHEF");
    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_01/10M.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_0/run020.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_1/run021.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_2/run022.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_3/run023.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_4/run024.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_5/run025.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_6/run026.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_7/run027.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_8/run028.root");
//    chain.Add("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/bin/VBSww/Events/run_02_9/run029.root");
    
    ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
    Long64_t numberOfEntries = treeReader->GetEntries();
    cout<<"Total Number of Entry Events : "<<numberOfEntries<<endl;

    TClonesArray *branchEvent = treeReader->UseBranch("Event");
    TClonesArray *branchParticle = treeReader->UseBranch("Particle");
    std::vector<TClonesArray*> vSelectedEvent;

/*
    Double_t temp=0;
    Int_t Enum = 0;
    for(int i=0; i<=numberOfEntries-1; i++)
    {
        treeReader->ReadEntry(i);
        TRootLHEFParticle *particleW1=(TRootLHEFParticle*) branchParticle->At(2);
        TRootLHEFParticle *particleW2=(TRootLHEFParticle*) branchParticle->At(3);
        TRootLHEFParticle *particleP1=(TRootLHEFParticle*) branchParticle->At(4);
        TRootLHEFParticle *particleP2=(TRootLHEFParticle*) branchParticle->At(5);
        if(particleW1->PT>=10 && particleW2->PT>=10 && fabs(particleW2->PID)==24 && fabs(particleW2->PID)==24 && particleP1->PT>=30 && fabs(particleP1->Eta)<4.7 && particleP2->PT>=30 && fabs(particleP2->Eta)<4.7 ) 
        {
            vSelectedEvent.push_back(branchParticle); 
            Enum++;
        }
    }
    cout<<"total passed event number : "<<Enum<<endl;
    cout<<"stored event number : "<<vSelectedEvent.size()<<endl;
 */

 
    TH1F *hW1pt= new TH1F("hW1pt","hW1pt",50,0.,200.);
    TH1F *hW1Eta = new TH1F("hW1Eta","hW1Eta",20,-5,5);
    TH1F *hW1Phi = new TH1F("hW1Phi","hW1Phi",20,-5,5);
    TH1F *hW1Spin = new TH1F("hW1Spin","hW1Spin",10,-3,3);
    TH1F *hW2pt= new TH1F("hW2pt","hW2pt",50,0.,200.); 
    TH1F *hW2Eta = new TH1F("hW2Eta","hW2Eta",20,-5,5);
    TH1F *hW2Phi = new TH1F("hW2Phi","hW2Phi",20,-5,5);
    TH1F *hW2Spin = new TH1F("hW2Spin","hW2Spin",10,-3,3);
    TH1F *hP1pt= new TH1F("hP1pt","hP1pt",50,0.,200.);
    TH1F *hP1Eta = new TH1F("hP1Eta","hP1Eta",20,-5,5);
    TH1F *hP1Phi = new TH1F("hP1Phi","hP1Phi",20,-5,5);
    TH1F *hP1Spin = new TH1F("hP1Spin","hP1Spin",10,-3,3);
    TH1F *hP2pt= new TH1F("hP2pt","hP2pt",50,0.,200.);
    TH1F *hP2Eta = new TH1F("hP2Eta","hP2Eta",20,-5,5);
    TH1F *hP2Phi = new TH1F("hP2Phi","hP2Phi",20,-5,5);
    TH1F *hP2Spin = new TH1F("hP2Spin","hP2Spin",10,-3,3);    

    Double_t W1Pt, W1Eta, W1Phi, W1Spin = 0;
    Double_t W2Pt, W2Eta, W2Phi, W2Spin = 0;
    Double_t P1Pt, P1Eta, P1Phi, P1Spin = 0;
    Double_t P2Pt, P2Eta, P2Phi, P2Spin = 0;

//    treeE->Branch("W1Pt",&W1Pt,"W1Pt/D");  treeE->Branch("W1Eta",&W1Eta,"W1Eta/D");  treeE->Branch("W1Phi",&W1Phi,"W1Phi/D");  treeE->Branch("W1Spin",&W1Spin,"W1Spin/D");  treeE->Branch("W2Pt",&W2Pt,"W2Pt/D");  treeE->Branch("W2Eta",&W2Eta,"W2Eta/D");  treeE->Branch("W2Phi",&W2Phi,"W2Phi/D");  treeE->Branch("W2Spin",&W2Spin,"W2Spin/D");  treeE->Branch("P1Pt",&P1Pt,"P1Pt/D");  treeE->Branch("P1Eta",&P1Eta,"P1Eta/D");  treeE->Branch("P1Phi",&P1Phi,"P1Phi/D");  treeE->Branch("P1Spin",&P1Spin,"P1Spin/D");  treeE->Branch("P2Pt",&P2Pt,"P2Pt/D");  treeE->Branch("P2Eta",&P2Eta,"P2Eta/D");  treeE->Branch("P2Phi",&P2Phi,"P2Phi/D");  treeE->Branch("P2Spin",&P2Spin,"P2Spin/D");

    for(int j=0; j<=numberOfEntries-1; j++)
    { 
        if(j%500==0) cout<<"now looping "<<j<<"th event"<<endl;
        treeReader->ReadEntry(j);
        TRootLHEFParticle *particleW1=(TRootLHEFParticle*) branchParticle->At(2);
        TRootLHEFParticle *particleW2=(TRootLHEFParticle*) branchParticle->At(3);
        TRootLHEFParticle *particleP1=(TRootLHEFParticle*) branchParticle->At(4);
        TRootLHEFParticle *particleP2=(TRootLHEFParticle*) branchParticle->At(5);

        W1Pt = particleW1->PT;  W1Eta = particleW1->Eta;  W1Phi = particleW1->Phi;  W1Spin = particleW1->Spin;
        W2Pt = particleW2->PT;  W2Eta = particleW2->Eta;  W2Phi = particleW2->Phi;  W2Spin = particleW2->Spin;
        P1Pt = particleP1->PT;  P1Eta = particleP1->Eta;  P1Phi = particleP1->Phi;  P1Spin = particleP1->Spin;
        P2Pt = particleP2->PT;  P2Eta = particleP2->Eta;  P2Phi = particleP2->Phi;  P2Spin = particleP2->Spin;
//        branchE.push_back(W1Pt);
//        branchE.push_back(W1Eta);
        v->SetVecs(W1Pt,W1Eta,W1Phi,W1Spin,W2Pt,W2Eta,W2Phi,W2Spin,P1Pt,P1Eta,P1Phi,P1Spin,P2Pt,P2Eta,P2Phi,P2Spin);
//        v->SetVecs(W1Pt,W1Eta,W1Phi,W1Spin);

        hW1pt->Fill(particleW1->PT);
        hW1Eta->Fill(particleW1->Eta);
        hW1Phi->Fill(particleW1->Phi);
        hW1Spin->Fill(W1Spin);
        hW2pt->Fill(particleW2->PT);
        hW2Eta->Fill(particleW2->Eta);
        hW2Phi->Fill(particleW2->Phi);
        hW2Spin->Fill(W2Spin);
        hP1pt->Fill(particleP1->PT);
        hP1Eta->Fill(particleP1->Eta);
        hP1Phi->Fill(particleP1->Phi);
        hP1Spin->Fill(P1Spin);
        hP2pt->Fill(particleP2->PT);
        hP2Eta->Fill(particleP2->Eta);
        hP2Phi->Fill(particleP2->Phi);
        hP2Spin->Fill(P2Spin);
        treeE->Fill();
//        branchE.clear();
    }
//    treeE->Fill();
    hW1pt->Write();
    hW1Eta->Write();
    hW1Phi->Write();
    hW1Spin->Write();
    hW2pt->Write();
    hW2Eta->Write();
    hW2Phi->Write();
    hW2Spin->Write();
    hP1pt->Write();
    hP1Eta->Write();
    hP1Phi->Write();
    hP1Spin->Write();
    hP2pt->Write();
    hP2Eta->Write();
    hP2Phi->Write();
    hP2Spin->Write();
    treeE->Write();
    fout->Close();
}


