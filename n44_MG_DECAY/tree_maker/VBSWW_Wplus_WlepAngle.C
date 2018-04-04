// "root -l 1_run.C"    to execute

#include "TChain.h"
#include "TLorentzVector.h"
#include "TSystem.h"
#include "TROOT.h"     // Need this get "gSystem" work!!!!
#include "TClonesArray.h"
#include <vector>
#include "TH1.h"

void VBSWW_Wplus_WlepAngle()
{
    TFile *fout = new TFile("output_VBSWW_Wplus_WlepAngle.root","RECREATE");
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

    Double_t W1Pt, W1Eta, W1Phi, W1Spin, W1E = 0;
    Double_t W2Pt, W2Eta, W2Phi, W2Spin, W2E = 0;
    Double_t lep1Pt, lep1Eta, lep1Phi, lep1Spin, lep1E = 0;
    Double_t Nu1Pt, Nu1Eta, Nu1Phi, Nu1Spin = 0;
    Double_t lep2Pt, lep2Eta, lep2Phi, lep2Spin, lep2E = 0;
    Double_t Nu2Pt, Nu2Eta, Nu2Phi, Nu2Spin = 0;
    Double_t P1Pt, P1Eta, P1Phi, P1Spin = 0;
    Double_t P2Pt, P2Eta, P2Phi, P2Spin = 0;

    Double_t cos_LL_Angle_1, cos_LL_Angle_2 = 0;
    Double_t cos_TT_Angle_1, cos_TT_Angle_2 = 0;
    Double_t cos_TL_Angle_1, cos_TL_Angle_2 = 0;
    Double_t cthetae1, cthetae2 = 0;

    treeLL->Branch("cos_LL_Angle_1",&cos_LL_Angle_1,"cos_LL_Angle_1/D");  treeLL->Branch("cos_LL_Angle_2",&cos_LL_Angle_2,"cos_LL_Angle_2/D");
    treeTT->Branch("cos_TT_Angle_1",&cos_TT_Angle_1,"cos_TT_Angle_1/D");  treeTT->Branch("cos_TT_Angle_2",&cos_TT_Angle_2,"cos_TT_Angle_2/D");
    treeTL->Branch("cos_TL_Angle_1",&cos_TL_Angle_1,"cos_TL_Angle_1/D");  treeTL->Branch("cos_TL_Angle_2",&cos_TL_Angle_2,"cos_TL_Angle_2/D");

    TLorentzVector vW1, vW2;
    TLorentzVector vlep1, vlep2;
    TLorentzVector vA1, vA2;

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

        W1Pt = particleW1->PT;  W1Eta = particleW1->Eta;  W1Phi = particleW1->Phi;  W1Spin = particleW1->Spin; W1E = particleW1->E;
        W2Pt = particleW2->PT;  W2Eta = particleW2->Eta;  W2Phi = particleW2->Phi;  W2Spin = particleW2->Spin; W2E = particleW2->E;
        lep1Pt = particlelep1->PT; lep1Eta = particlelep1->Eta; lep1Phi = particlelep1->Phi; lep1Spin = particlelep1->Spin; lep1E = particlelep1->E;
        Nu1Pt = particleNu1->PT; Nu1Eta = particleNu1->Eta; Nu1Phi = particleNu1->Phi; Nu1Spin = particleNu1->Spin;
        lep2Pt = particlelep2->PT; lep2Eta = particlelep2->Eta; lep2Phi = particlelep2->Phi; lep2Spin = particlelep2->Spin; lep2E = particlelep2->E;
        Nu2Pt = particleNu2->PT; Nu2Eta = particleNu2->Eta; Nu2Phi = particleNu2->Phi; Nu2Spin = particleNu2->Spin;
        P1Pt = particleP1->PT;  P1Eta = particleP1->Eta;  P1Phi = particleP1->Phi;  P1Spin = particleP1->Spin;
        P2Pt = particleP2->PT;  P2Eta = particleP2->Eta;  P2Phi = particleP2->Phi;  P2Spin = particleP2->Spin;       
 
        vW1.SetPtEtaPhiE(W1Pt,W1Eta,W1Phi,W1E);  vW2.SetPtEtaPhiE(W2Pt,W2Eta,W2Phi,W2E);
        vlep1.SetPtEtaPhiE(lep1Pt,lep1Eta,lep1Phi,lep1E);    vlep2.SetPtEtaPhiE(lep2Pt,lep2Eta,lep2Phi,lep2E);
        TVector3 v1 = vW1.Vect(); TVector3 v2 = vW2.Vect();
        TLorentzVector lep_in_w1(vlep1);
        TLorentzVector lep_in_w2(vlep2);
        TVector3 wboost1 = -(vW1.BoostVector()); TVector3 wboost2 = -(vW2.BoostVector());
        lep_in_w1.Boost(wboost1); lep_in_w2.Boost(wboost2);
        TVector3 vv1 = lep_in_w1.Vect(); TVector3 vv2 = lep_in_w2.Vect();
        cthetae1 = cos(v1.Angle(vv1));
        cthetae2 = cos(v2.Angle(vv2));

        vA1 = vW1 - vlep1;
        vA2 = vW2 - vlep2;
    
        if(W1Spin ==0 && W2Spin ==0)
        {
            cos_LL_Angle_1 = cthetae1;
            cos_LL_Angle_2 = cthetae2;
//            cos_LL_Angle_1 = cos(sqrt((W1Eta-lep1Eta)*(W1Eta-lep1Eta) + (W1Phi-lep1Phi)*(W1Phi-lep1Phi)));
//            cos_LL_Angle_2 = cos(sqrt((W2Eta-lep2Eta)*(W2Eta-lep2Eta) + (W2Phi-lep2Phi)*(W2Phi-lep2Phi)));
            treeLL->Fill();
        }
        else if((W1Spin==0 && fabs(W2Spin)==1) || (fabs(W1Spin)==1 && W2Spin==0))
        {
            cos_TL_Angle_1 = cthetae1;
            cos_TL_Angle_2 = cthetae2;
//            cos_TL_Angle_1 = cos(sqrt((W1Eta-lep1Eta)*(W1Eta-lep1Eta) + (W1Phi-lep1Phi)*(W1Phi-lep1Phi)));
//            cos_TL_Angle_2 = cos(sqrt((W2Eta-lep2Eta)*(W2Eta-lep2Eta) + (W2Phi-lep2Phi)*(W2Phi-lep2Phi)));
            treeTL->Fill();
        }
        else if(fabs(W1Spin)==1 && fabs(W2Spin)==1)
        {
            cos_TT_Angle_1 = cthetae1;
            cos_TT_Angle_2 = cthetae2;
//            cos_TT_Angle_1 = cos(sqrt((W1Eta-lep1Eta)*(W1Eta-lep1Eta) + (W1Phi-lep1Phi)*(W1Phi-lep1Phi)));
//            cos_TT_Angle_2 = cos(sqrt((W2Eta-lep2Eta)*(W2Eta-lep2Eta) + (W2Phi-lep2Phi)*(W2Phi-lep2Phi)));
            treeTT->Fill();
        }
    }
    cout<<"LL ENTRY :"<<treeLL->GetEntries()<<endl;
    cout<<"TL ENTRY :"<<treeTL->GetEntries()<<endl;
    cout<<"TT ENTRY :"<<treeTT->GetEntries()<<endl;
    
    treeLL->Write();
    treeTT->Write();
    treeTL->Write();
    delete fout;
}


