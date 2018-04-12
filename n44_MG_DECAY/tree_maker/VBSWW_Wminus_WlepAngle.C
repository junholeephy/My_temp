// "root -l 1_run.C"    to execute

#include "TChain.h"
#include "TLorentzVector.h"
#include "TSystem.h"
#include "TROOT.h"     // Need this get "gSystem" work!!!!
#include "TClonesArray.h"
#include <vector>
#include "TH1.h"

void VBSWW_Wminus_WlepAngle()
{
    TTree *treeLL = new TTree("treeLL","treeLL");
    TTree *treeTpTp = new TTree("treeTpTp","treeTpTp");
    TTree *treeTmTm = new TTree("treeTmTm","treeTmTm");
    TTree *treeTpTm = new TTree("treeTpTm","treeTpTm");
    TTree *treeTpL = new TTree("treeTpL","treeTpL");
    TTree *treeTmL = new TTree("treeTmL","treeTmL");

    TChain chain("LHEF");
    chain.Add("/Users/leejunho/Desktop/MadGraph5_v1_5_14/bin/VBSwmwm/Events/run_02_4/VBSwmwm_DECAY.root");

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
    Double_t cos_TpTp_Angle_1, cos_TpTp_Angle_2 = 0;
    Double_t cos_TmTm_Angle_1, cos_TmTm_Angle_2 = 0;
    Double_t cos_TpTm_Angle_1, cos_TpTm_Angle_2 = 0;
    Double_t cos_TpL_Angle_1, cos_TpL_Angle_2 = 0;
    Double_t cos_TmL_Angle_1, cos_TmL_Angle_2 = 0;
    Double_t cthetae1, cthetae2 = 0;
    Double_t weightLL_b=0; Double_t weightTpL_b=0; Double_t weightTmL_b=0; Double_t weightTpTp_b=0; Double_t weightTmTm_b=0; Double_t weightTpTm_b=0;

    treeLL->Branch("cos_LL_Angle_1",&cos_LL_Angle_1,"cos_LL_Angle_1/D");  treeLL->Branch("cos_LL_Angle_2",&cos_LL_Angle_2,"cos_LL_Angle_2/D");  treeLL->Branch("weightLL_b",&weightLL_b, "weightLL_b/D");
    treeTpTp->Branch("cos_TpTp_Angle_1",&cos_TpTp_Angle_1,"cos_TpTp_Angle_1/D");  treeTpTp->Branch("cos_TpTp_Angle_2",&cos_TpTp_Angle_2,"cos_TpTp_Angle_2/D");  treeTpTp->Branch("weightTpTp_b",&weightTpTp_b, "weightTpTp_b/D");
    treeTmTm->Branch("cos_TmTm_Angle_1",&cos_TmTm_Angle_1,"cos_TmTm_Angle_1/D");  treeTmTm->Branch("cos_TmTm_Angle_2",&cos_TmTm_Angle_2,"cos_TmTm_Angle_2/D");  treeTmTm->Branch("weightTmTm_b",&weightTmTm_b, "weightTmTm_b/D");
    treeTpTm->Branch("cos_TpTm_Angle_1",&cos_TpTm_Angle_1,"cos_TpTm_Angle_1/D");  treeTpTm->Branch("cos_TpTm_Angle_2",&cos_TpTm_Angle_2,"cos_TpTm_Angle_2/D");  treeTpTm->Branch("weightTpTm_b",&weightTpTm_b, "weightTpTm_b/D");
    treeTpL->Branch("cos_TpL_Angle_1",&cos_TpL_Angle_1,"cos_TpL_Angle_1/D");  treeTpL->Branch("cos_TpL_Angle_2",&cos_TpL_Angle_2,"cos_TpL_Angle_2/D"); treeTpL->Branch("weightTpL_b",&weightTpL_b, "weightTpL_B/D");
    treeTmL->Branch("cos_TmL_Angle_1",&cos_TmL_Angle_1,"cos_TmL_Angle_1/D");  treeTmL->Branch("cos_TmL_Angle_2",&cos_TmL_Angle_2,"cos_TmL_Angle_2/D");  treeTmL->Branch("weightTmL_b",&weightTmL_b, "weightTmL_b/D");


    TLorentzVector vW1, vW2;
    TLorentzVector vlep1, vlep2;
    TLorentzVector vA1, vA2;
    Double_t weight=0; Double_t weightLL=0; Double_t weightTpL=0; Double_t weightTmL=0; Double_t weightTpTp=0; Double_t weightTmTm=0; Double_t weightTpTm=0;
    Double_t WEIGHT=0;

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
        TRootLHEFEvent *Event = (TRootLHEFEvent*) branchEvent->At(0);
        WEIGHT = Event->Weight;
        weight = weight + WEIGHT;

        W1Pt = particleW1->PT;  W1Eta = particleW1->Eta;  W1Phi = particleW1->Phi;  W1Spin = particleW1->Spin; W1E = particleW1->E;
        W2Pt = particleW2->PT;  W2Eta = particleW2->Eta;  W2Phi = particleW2->Phi;  W2Spin = particleW2->Spin; W2E = particleW2->E;
        lep1Pt = particlelep1->PT; lep1Eta = particlelep1->Eta; lep1Phi = particlelep1->Phi; lep1Spin = particlelep1->Spin; lep1E = particlelep1->E;
        Nu1Pt = particleNu1->PT; Nu1Eta = particleNu1->Eta; Nu1Phi = particleNu1->Phi; Nu1Spin = particleNu1->Spin;
        lep2Pt = particlelep2->PT; lep2Eta = particlelep2->Eta; lep2Phi = particlelep2->Phi; lep2Spin = particlelep2->Spin; lep2E = particlelep2->E;
        Nu2Pt = particleNu2->PT; Nu2Eta = particleNu2->Eta; Nu2Phi = particleNu2->Phi; Nu2Spin = particleNu2->Spin;
        P1Pt = particleP1->PT;  P1Eta = particleP1->Eta;  P1Phi = particleP1->Phi;  P1Spin = particleP1->Spin;
        P2Pt = particleP2->PT;  P2Eta = particleP2->Eta;  P2Phi = particleP2->Phi;  P2Spin = particleP2->Spin;       
 
        vW1.SetPtEtaPhiE(W1Pt,W1Eta,W1Phi,W1E); vlep1.SetPtEtaPhiE(lep1Pt,lep1Eta,lep1Phi,lep1E);
        TVector3 v1 = vW1.Vect();
        TLorentzVector lep_in_w1(vlep1);
        TVector3 wboost1 = -(vW1.BoostVector());
        lep_in_w1.Boost(wboost1);
        TVector3 v12 = lep_in_w1.Vect();
        cthetae1 = cos(v1.Angle(v12));

        vW2.SetPtEtaPhiE(W2Pt,W2Eta,W2Phi,W2E); vlep2.SetPtEtaPhiE(lep2Pt,lep2Eta,lep2Phi,lep2E);
        TVector3 v2 = vW2.Vect();
        TLorentzVector lep_in_w2(vlep2);
        TVector3 wboost2 = -(vW2.BoostVector());
        lep_in_w2.Boost(wboost2);
        TVector3 v22 = lep_in_w2.Vect();
        cthetae2 = cos(v2.Angle(v22));


    
        if(W1Spin ==0 && W2Spin ==0)
        {
            cos_LL_Angle_1 = cthetae1;
            cos_LL_Angle_2 = cthetae2;
            weightLL_b = WEIGHT;
            weightLL = weightLL + WEIGHT;
//            cos_LL_Angle_1 = cos(sqrt((W1Eta-lep1Eta)*(W1Eta-lep1Eta) + (W1Phi-lep1Phi)*(W1Phi-lep1Phi)));
//            cos_LL_Angle_2 = cos(sqrt((W2Eta-lep2Eta)*(W2Eta-lep2Eta) + (W2Phi-lep2Phi)*(W2Phi-lep2Phi)));
            treeLL->Fill();
        }
        else if((W1Spin==0 && W2Spin==1) || (W1Spin==1 && W2Spin==0))
        {
            cos_TpL_Angle_1 = cthetae1;
            cos_TpL_Angle_2 = cthetae2;
            weightTpL_b = WEIGHT;
            weightTpL = weightTpL + WEIGHT;
//            cos_TpL_Angle_1 = cos(sqrt((W1Eta-lep1Eta)*(W1Eta-lep1Eta) + (W1Phi-lep1Phi)*(W1Phi-lep1Phi)));
//            cos_TpL_Angle_2 = cos(sqrt((W2Eta-lep2Eta)*(W2Eta-lep2Eta) + (W2Phi-lep2Phi)*(W2Phi-lep2Phi)));
            treeTpL->Fill();
        }
        else if((W1Spin==0 && W2Spin==-1) || (W1Spin==-1 && W2Spin==0))
        {
            cos_TmL_Angle_1 = cthetae1;
            cos_TmL_Angle_2 = cthetae2;
            weightTmL_b = WEIGHT;
            weightTmL = weightTmL + WEIGHT;
//            cos_TpL_Angle_1 = cos(sqrt((W1Eta-lep1Eta)*(W1Eta-lep1Eta) + (W1Phi-lep1Phi)*(W1Phi-lep1Phi)));
//            cos_TpL_Angle_2 = cos(sqrt((W2Eta-lep2Eta)*(W2Eta-lep2Eta) + (W2Phi-lep2Phi)*(W2Phi-lep2Phi)));
            treeTmL->Fill();
        }
        



//        else if(fabs(W1Spin)==1 && fabs(W2Spin)==1)
        else if((W1Spin==1 && W2Spin==1))
        {
            cos_TpTp_Angle_1 = cthetae1;
            cos_TpTp_Angle_2 = cthetae2;
            weightTpTp_b = WEIGHT;
            weightTpTp = weightTpTp + WEIGHT;
//            cos_TT_Angle_1 = cos(sqrt((W1Eta-lep1Eta)*(W1Eta-lep1Eta) + (W1Phi-lep1Phi)*(W1Phi-lep1Phi)));
//            cos_TT_Angle_2 = cos(sqrt((W2Eta-lep2Eta)*(W2Eta-lep2Eta) + (W2Phi-lep2Phi)*(W2Phi-lep2Phi)));
            treeTpTp->Fill();
        }
        else if((W1Spin==-1 && W2Spin==-1))
        {
            cos_TmTm_Angle_1 = cthetae1;
            cos_TmTm_Angle_2 = cthetae2;
            weightTmTm_b = WEIGHT;
            weightTmTm = weightTmTm + WEIGHT;
//            cos_TT_Angle_1 = cos(sqrt((W1Eta-lep1Eta)*(W1Eta-lep1Eta) + (W1Phi-lep1Phi)*(W1Phi-lep1Phi)));
//            cos_TT_Angle_2 = cos(sqrt((W2Eta-lep2Eta)*(W2Eta-lep2Eta) + (W2Phi-lep2Phi)*(W2Phi-lep2Phi)));
            treeTmTm->Fill();
        }
        else if((W1Spin==1 && W2Spin==-1) || (W1Spin==-1 && W2Spin==1))
        {
            cos_TpTm_Angle_1 = cthetae1;
            cos_TpTm_Angle_2 = cthetae2;
            weightTpTm_b = WEIGHT;
            weightTpTm = weightTpTm + WEIGHT;
//            cos_TT_Angle_1 = cos(sqrt((W1Eta-lep1Eta)*(W1Eta-lep1Eta) + (W1Phi-lep1Phi)*(W1Phi-lep1Phi)));
//            cos_TT_Angle_2 = cos(sqrt((W2Eta-lep2Eta)*(W2Eta-lep2Eta) + (W2Phi-lep2Phi)*(W2Phi-lep2Phi)));
            treeTpTm->Fill();
        }

    }

    cout<<"Total Weight :"<<weight<<endl;
    cout<<"LL Weight all:"<<weightLL<<endl;
    cout<<"TpL Weight all:"<<weightTpL<<endl;
    cout<<"TmL Weight all:"<<weightTmL<<endl;
    cout<<"TpTp Weight all:"<<weightTpTp<<endl;
    cout<<"TmTm Weight all:"<<weightTmTm<<endl;
    cout<<"TpTm Weight all:"<<weightTpTm<<endl;
    cout<<"LL ENTRY :"<<treeLL->GetEntries()<<endl;
    cout<<"TpL ENTRY :"<<treeTpL->GetEntries()<<endl;
    cout<<"TmL ENTRY :"<<treeTmL->GetEntries()<<endl;
    cout<<"TpTp ENTRY :"<<treeTpTp->GetEntries()<<endl;
    cout<<"TmTm ENTRY :"<<treeTmTm->GetEntries()<<endl;
    cout<<"TpTm ENTRY :"<<treeTpTm->GetEntries()<<endl;
   
    TFile *fout = new TFile("output_VBSWW_Wminus_WlepAngle.root","RECREATE"); 
    treeLL->Write();
    treeTpTp->Write();
    treeTmTm->Write();
    treeTpTm->Write();
    treeTpL->Write();
    treeTmL->Write();
    delete fout;
}


