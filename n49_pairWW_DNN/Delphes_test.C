#include <vector>
#include <iostream>
#include "TSystem.h"
#include "TChain.h"
#include "TH1.h"
#include "TClonesArray.h"
#include "TCanvas.h"
#include "TLorentzVector.h"

//gSystem->Load("libDelphes");
#include "classes/DelphesClasses.h"
//#include "/Users/leejunho/Desktop/MG5_aMC_v2_6_1/Delphes/classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
//#include "/Users/leejunho/Desktop/MG5_aMC_v2_6_1/Delphes/external/ExRootAnalysis/ExRootTreeReader.h"

using namespace std;

void Delphes_test()
{
    cout<<"test"<<endl;
    TChain chain("Delphes");
    chain.Add("small_PairWW_delphes.root");

    ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
    Long64_t N_Entries = treeReader->GetEntries();
    cout<<"Entry number : "<<N_Entries<<endl;

    TClonesArray *branchEvent = treeReader->UseBranch("Event");
    TClonesArray *branchJet = treeReader->UseBranch("Jet");
    TClonesArray *branchElectron = treeReader->UseBranch("Electron");
    TClonesArray *branchMuon = treeReader->UseBranch("Muon");
    TClonesArray* branchMissingET = treeReader->UseBranch("MissingET");
    TClonesArray* branchGenParticle = treeReader->UseBranch("Particle");
    TClonesArray* branchGenMissingET = treeReader->UseBranch("GenMissingET");

//    std::vector<Jet*> vSelectedJets;
//    std::vector<Lepton*> vSelectedLeptons_1;
//    vector<Lepton*> vSelectedLeptons_2;
    vector<Electron*> vSelectedElectrons;
    vector<Muon*> vSelectedMuons;
    vector<MissingET*> vSelectedMET;
//    vector<
//    vector<GenParticle*> vSelectedPartons;
    vector<GenParticle*> vSelectedNeutrinos_1;
    vector<GenParticle*> vSelectedNeutrinos_2;
    vector<GenParticle*> vSelectedGenLeptons_1;
    vector<GenParticle*> vSelectedGenLeptons_2;
    vector<GenParticle*> vSelectedW_1;
    vector<GenParticle*> vSelectedW_2;

//    vector<std::pair<Jet*, GenParticle*>> MatchedJets;

    vSelectedElectrons.clear();
    vSelectedMuons.clear();
    vSelectedNeutrinos_1.clear();
    vSelectedNeutrinos_2.clear();
    vSelectedGenLeptons_1.clear();
    vSelectedGenLeptons_2.clear();
    vSelectedW_1.clear();
    vSelectedW_2.clear();


    TFile *Of = new TFile("Outfile_delphes.root","RECREATE");
    for(Long64_t entry=0; entry<N_Entries; entry++)
    {
        treeReader->ReadEntry(entry);
        if(entry%5000 == 0) cout<<"Now Looping "<<entry<<"th Event."<<endl;

        GenParticle *genparticle;
        if(branchGenParticle->GetEntries() >0)
        {
            int GEN_W_Boson =0;
            int GENW_flag = 0;
            GenParticle *genmother_temp;
            for(Int_t ig=0; ig<branchGenParticle->GetEntries(); ig++)
            {
                genparticle = (GenParticle*)branchGenParticle->At(ig);
                if(abs(genparticle->PID)==12 || abs(genparticle->PID)==14 || abs(genparticle->PID)==16 & GENW_flag==0)
                {
                    //cout << "TEST GenParticle "<<ig<<" PID="<<genparticle->PID<<" status="<<genparticle->Status << endl;
                    Int_t m = genparticle->M1;
                    GenParticle *genmother = (GenParticle*)branchGenParticle->At(m);
                    if(abs(genmother->PID)==24)
                    {
                        //cout<<"W GEN-level boson! "<<entry<<" : "<<ig<<endl;
                        if(GEN_W_Boson==1) {vSelectedW_1.push_back(genmother_temp); vSelectedW_2.push_back(genmother); GENW_flag=1;}  //cout<<"Two W bosons picked"<<", Entry Num : "<<entry<<endl;}
                        if(GEN_W_Boson==0) {genmother_temp=genmother; GEN_W_Boson++;}
 
                    }
                }

            }
            if(GENW_flag==1)
            {
                Electron* elec;
                Muon*     muon;
                MissingET* MET;
                if(branchElectron->GetEntries() >0)
                {
//                    cout<<"electron number of this events:"<<branchElectron->GetEntries()<<endl;
                    int Elec_flag = -1;
                    for(Int_t ie=0; ie<branchElectron->GetEntries(); ie++)
                    {
                        elec = (Electron*)branchElectron->At(ie);
                        if(elec->PT> 15 && fabs(elec->Eta)<2.4 && Elec_flag == -1)
                        {
                            Elec_flag = ie;
                        }
                        else if (Elec_flag != -1 && fabs(elec->Eta)<2.4 && elec->PT> ((Electron*)branchElectron->At(Elec_flag))->PT)
                        {
                            Elec_flag = ie;
                        }
                    }
                    if(Elec_flag!=-1) vSelectedElectrons.push_back((Electron*)branchElectron->At(Elec_flag)); //storing leading electron
                }
                else continue;
//                else cout<<"no electron"<<endl;
                if(branchMuon->GetEntries()>0)
                {
                    int Muon_flag = -1;
                    for(Int_t im=0; im<branchMuon->GetEntries(); im++)
                    {
                        muon = (Muon*)branchMuon->At(im);
                        if(muon->PT>15 && fabs(muon->Eta)<2.4 && Muon_flag == -1)
                        {
                            Muon_flag = im;
                        }
                        else if(Muon_flag!=-1 && fabs(muon->Eta)<2.4 && muon->PT> ((Muon*)branchMuon->At(Muon_flag))->PT)
                        {
                            Muon_flag = im;
                        }
                    }
                    if(Muon_flag != -1) vSelectedMuons.push_back((Muon*)branchMuon->At(Muon_flag));
                }
                else continue;
                if(branchMissingET->GetEntries()>0)
                {
                    int MET_flag = -1;  //FIXME
                    for(Int_t imet=0; imet<branchMissingET->GetEntries(); imet++)
                    {
                        MET = (MissingET*)branchMissingET->At(imet);
                        if(MET->MET>0 && MET_flag==-1) {MET_flag=imet;}
                        else if(MET_flag!=-1 && MET->MET > ((MissingET*)branchMissingET->At(MET_flag))->MET)
                        { MET_flag = imet;}
                    }
                    if(MET_flag != -1) vSelectedMET.push_back((MissingET*)branchMissingET->At(MET_flag));
                }
                else continue;
            }
            else continue;
        }
    }

    Of->Close();
}






