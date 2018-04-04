// "root -l 1_run.C"    to execute

#include "TChain.h"
#include "TLorentzVector.h"
#include "TSystem.h"
#include "TROOT.h"     // Need this get "gSystem" work!!!!
#include "TClonesArray.h"
#include <vector>
#include "TH1.h"

void VBSWW_Wplus()
{
    TFile *fout = new TFile("output_VBSWW_Wplus.root","RECREATE");
    TTree *treeLL = new TTree("treeLL","treeLL");
    TTree *treeTT = new TTree("treeTT","treeTT");
    TTree *treeTL = new TTree("treeTL","treeTL");

    TChain chain("LHEF");
    chain.Add("/Users/leejunho/Desktop/MadGraph5_v1_5_14/bin/VBSwpwp/Events/run_01/VBSwpwp_DECAY.root");

    ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
    Long64_t numberOfEntries = treeReader->GetEntries();
    cout<<"Total Number of Entry Events : "<<numberOfEntries<<endl;

    TClonesArray *branchEvent = treeReader->UseBranch("Event");
    TClonesArray *branchParticle = treeReader->UseBranch("Particle");
   
    Double_t W1Pt, W1Eta, W1Phi, W1Spin = 0;
    Double_t W2Pt, W2Eta, W2Phi, W2Spin = 0;
    Double_t lep1Pt, lep1Eta, lep1Phi, lep1Spin = 0;
    Double_t Nu1Pt, Nu1Eta, Nu1Phi, Nu1Spin = 0;
    Double_t lep2Pt, lep2Eta, lep2Phi, lep2Spin = 0;
    Double_t Nu2Pt, Nu2Eta, Nu2Phi, Nu2Spin = 0;
    Double_t P1Pt, P1Eta, P1Phi, P1Spin = 0;
    Double_t P2Pt, P2Eta, P2Phi, P2Spin = 0;



    treeLL->Branch("W1Pt",&W1Pt,"W1Pt/D");  treeLL->Branch("W1Eta",&W1Eta,"W1Eta/D");  treeLL->Branch("W1Phi",&W1Phi,"W1Phi/D");  treeLL->Branch("W1Spin",&W1Spin,"W1Spin/D");  
    treeLL->Branch("W2Pt",&W2Pt,"W2Pt/D");  treeLL->Branch("W2Eta",&W2Eta,"W2Eta/D");  treeLL->Branch("W2Phi",&W2Phi,"W2Phi/D");  treeLL->Branch("W2Spin",&W2Spin,"W2Spin/D");  
    treeLL->Branch("lep1Pt",&lep1Pt,"lep1Pt/D");  treeLL->Branch("lep1Eta",&lep1Eta,"lep1Eta/D");  treeLL->Branch("lep1Phi",&lep1Phi,"lep1Phi/D");  treeLL->Branch("lep1Spin",&lep1Spin,"lep1Spin/D");  
    treeLL->Branch("Nu1Pt",&Nu1Pt,"Nu1Pt/D");  treeLL->Branch("Nu1Eta",&Nu1Eta,"Nu1Eta/D");  treeLL->Branch("Nu1Phi",&Nu1Phi,"Nu1Phi/D");  treeLL->Branch("Nu1Spin",&Nu1Spin,"Nu1Spin/D");
    treeLL->Branch("lep2Pt",&lep2Pt,"lep2Pt/D");  treeLL->Branch("lep2Eta",&lep2Eta,"lep2Eta/D");  treeLL->Branch("lep2Phi",&lep2Phi,"lep2Phi/D");  treeLL->Branch("lep2Spin",&lep2Spin,"lep2Spin/D");  
    treeLL->Branch("Nu2Pt",&Nu1Pt,"Nu2Pt/D");  treeLL->Branch("Nu2Eta",&Nu2Eta,"Nu2Eta/D");  treeLL->Branch("Nu2Phi",&Nu2Phi,"Nu2Phi/D");  treeLL->Branch("Nu2Spin",&Nu2Spin,"Nu2Spin/D");
    treeLL->Branch("P1Pt",&P1Pt,"P1Pt/D");  treeLL->Branch("P1Eta",&P1Eta,"P1Eta/D");  treeLL->Branch("P1Phi",&P1Phi,"P1Phi/D");  treeLL->Branch("P1Spin",&P1Spin,"P1Spin/D");  
    treeLL->Branch("P2Pt",&P2Pt,"P2Pt/D");  treeLL->Branch("P2Eta",&P2Eta,"P2Eta/D");  treeLL->Branch("P2Phi",&P2Phi,"P2Phi/D");  treeLL->Branch("P2Spin",&P2Spin,"P2Spin/D");

    treeTT->Branch("W1Pt",&W1Pt,"W1Pt/D");  treeTT->Branch("W1Eta",&W1Eta,"W1Eta/D");  treeTT->Branch("W1Phi",&W1Phi,"W1Phi/D");  treeTT->Branch("W1Spin",&W1Spin,"W1Spin/D");
    treeTT->Branch("W2Pt",&W2Pt,"W2Pt/D");  treeTT->Branch("W2Eta",&W2Eta,"W2Eta/D");  treeTT->Branch("W2Phi",&W2Phi,"W2Phi/D");  treeTT->Branch("W2Spin",&W2Spin,"W2Spin/D");
    treeTT->Branch("lep1Pt",&lep1Pt,"lep1Pt/D");  treeTT->Branch("lep1Eta",&lep1Eta,"lep1Eta/D");  treeTT->Branch("lep1Phi",&lep1Phi,"lep1Phi/D");  treeTT->Branch("lep1Spin",&lep1Spin,"lep1Spin/D");
    treeTT->Branch("Nu1Pt",&Nu1Pt,"Nu1Pt/D");  treeTT->Branch("Nu1Eta",&Nu1Eta,"Nu1Eta/D");  treeTT->Branch("Nu1Phi",&Nu1Phi,"Nu1Phi/D");  treeTT->Branch("Nu1Spin",&Nu1Spin,"Nu1Spin/D");
    treeTT->Branch("lep2Pt",&lep2Pt,"lep2Pt/D");  treeTT->Branch("lep2Eta",&lep2Eta,"lep2Eta/D");  treeTT->Branch("lep2Phi",&lep2Phi,"lep2Phi/D");  treeTT->Branch("lep2Spin",&lep2Spin,"lep2Spin/D");
    treeTT->Branch("Nu2Pt",&Nu1Pt,"Nu2Pt/D");  treeTT->Branch("Nu2Eta",&Nu2Eta,"Nu2Eta/D");  treeTT->Branch("Nu2Phi",&Nu2Phi,"Nu2Phi/D");  treeTT->Branch("Nu2Spin",&Nu2Spin,"Nu2Spin/D");
    treeTT->Branch("P1Pt",&P1Pt,"P1Pt/D");  treeTT->Branch("P1Eta",&P1Eta,"P1Eta/D");  treeTT->Branch("P1Phi",&P1Phi,"P1Phi/D");  treeTT->Branch("P1Spin",&P1Spin,"P1Spin/D");
    treeTT->Branch("P2Pt",&P2Pt,"P2Pt/D");  treeTT->Branch("P2Eta",&P2Eta,"P2Eta/D");  treeTT->Branch("P2Phi",&P2Phi,"P2Phi/D");  treeTT->Branch("P2Spin",&P2Spin,"P2Spin/D");

    treeTL->Branch("W1Pt",&W1Pt,"W1Pt/D");  treeTL->Branch("W1Eta",&W1Eta,"W1Eta/D");  treeTL->Branch("W1Phi",&W1Phi,"W1Phi/D");  treeTL->Branch("W1Spin",&W1Spin,"W1Spin/D");
    treeTL->Branch("W2Pt",&W2Pt,"W2Pt/D");  treeTL->Branch("W2Eta",&W2Eta,"W2Eta/D");  treeTL->Branch("W2Phi",&W2Phi,"W2Phi/D");  treeTL->Branch("W2Spin",&W2Spin,"W2Spin/D");
    treeTL->Branch("lep1Pt",&lep1Pt,"lep1Pt/D");  treeTL->Branch("lep1Eta",&lep1Eta,"lep1Eta/D");  treeTL->Branch("lep1Phi",&lep1Phi,"lep1Phi/D");  treeTL->Branch("lep1Spin",&lep1Spin,"lep1Spin/D");
    treeTL->Branch("Nu1Pt",&Nu1Pt,"Nu1Pt/D");  treeTL->Branch("Nu1Eta",&Nu1Eta,"Nu1Eta/D");  treeTL->Branch("Nu1Phi",&Nu1Phi,"Nu1Phi/D");  treeTL->Branch("Nu1Spin",&Nu1Spin,"Nu1Spin/D");
    treeTL->Branch("lep2Pt",&lep2Pt,"lep2Pt/D");  treeTL->Branch("lep2Eta",&lep2Eta,"lep2Eta/D");  treeTL->Branch("lep2Phi",&lep2Phi,"lep2Phi/D");  treeTL->Branch("lep2Spin",&lep2Spin,"lep2Spin/D");
    treeTL->Branch("Nu2Pt",&Nu1Pt,"Nu2Pt/D");  treeTL->Branch("Nu2Eta",&Nu2Eta,"Nu2Eta/D");  treeTL->Branch("Nu2Phi",&Nu2Phi,"Nu2Phi/D");  treeTL->Branch("Nu2Spin",&Nu2Spin,"Nu2Spin/D");
    treeTL->Branch("P1Pt",&P1Pt,"P1Pt/D");  treeTL->Branch("P1Eta",&P1Eta,"P1Eta/D");  treeTL->Branch("P1Phi",&P1Phi,"P1Phi/D");  treeTL->Branch("P1Spin",&P1Spin,"P1Spin/D");
    treeTL->Branch("P2Pt",&P2Pt,"P2Pt/D");  treeTL->Branch("P2Eta",&P2Eta,"P2Eta/D");  treeTL->Branch("P2Phi",&P2Phi,"P2Phi/D");  treeTL->Branch("P2Spin",&P2Spin,"P2Spin/D");

    int ii=0;
    for(int j=0; j<=numberOfEntries-1; j++)
    {
        if(j%50000==0) {cout<<"now looping "<<j<<"th event"<<endl;}
        treeReader->ReadEntry(j);
        TRootLHEFParticle *particleW1=(TRootLHEFParticle*) branchParticle->At(2);
        TRootLHEFParticle *particleW2=(TRootLHEFParticle*) branchParticle->At(3);
        TRootLHEFParticle *particlelep1=(TRootLHEFParticle*) branchParticle->At(6);
        TRootLHEFParticle *particleNu1=(TRootLHEFParticle*) branchParticle->At(7);
        TRootLHEFParticle *particlelep2=(TRootLHEFParticle*) branchParticle->At(8);
        TRootLHEFParticle *particleNu2=(TRootLHEFParticle*) branchParticle->At(9);
        TRootLHEFParticle *particleP1=(TRootLHEFParticle*) branchParticle->At(4);
        TRootLHEFParticle *particleP2=(TRootLHEFParticle*) branchParticle->At(5);
        W1Pt = particleW1->PT;  W1Eta = particleW1->Eta;  W1Phi = particleW1->Phi;  W1Spin = particleW1->Spin;
        W2Pt = particleW2->PT;  W2Eta = particleW2->Eta;  W2Phi = particleW2->Phi;  W2Spin = particleW2->Spin;
        lep1Pt = particlelep1->PT; lep1Eta = particlelep1->Eta; lep1Phi = particlelep1->Phi; lep1Spin = particlelep1->Spin;
        Nu1Pt = particleNu1->PT; Nu1Eta = particleNu1->Eta; Nu1Phi = particleNu1->Phi; Nu1Spin = particleNu1->Spin;
        lep2Pt = particlelep2->PT; lep2Eta = particlelep2->Eta; lep2Phi = particlelep2->Phi; lep2Spin = particlelep2->Spin;
        Nu2Pt = particleNu2->PT; Nu2Eta = particleNu2->Eta; Nu2Phi = particleNu2->Phi; Nu2Spin = particleNu2->Spin;
        P1Pt = particleP1->PT;  P1Eta = particleP1->Eta;  P1Phi = particleP1->Phi;  P1Spin = particleP1->Spin;
        P2Pt = particleP2->PT;  P2Eta = particleP2->Eta;  P2Phi = particleP2->Phi;  P2Spin = particleP2->Spin;

        if(W1Spin ==0 && W2Spin ==0)
        {
            treeLL->Fill(); //ii++;
        }
        else if((W1Spin==0 && fabs(W2Spin)==1) || (fabs(W1Spin)==1 && W2Spin==0))
        {
            treeTL->Fill(); //ii++;
        }
        else if(fabs(W1Spin)==1 && fabs(W2Spin)==1)
        {
            treeTT->Fill(); //ii++;
        }
        else continue;
    }

    cout<<"LL ENTRY :"<<treeLL->GetEntries()<<endl;
    cout<<"TL ENTRY :"<<treeTL->GetEntries()<<endl;
    cout<<"TT ENTRY :"<<treeTT->GetEntries()<<endl;

//    cout<<ii<<endl;
    
    treeLL->Write();
    treeTT->Write();
    treeTL->Write();
    delete fout;
}


