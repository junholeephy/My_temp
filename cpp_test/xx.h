#ifndef xx_h
#define xx_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>


class xx {
public :
   TTree          *fChain;   
   Int_t           fCurrent; 

   Int_t           event;
   Int_t           nVtx;
   Double_t        theWeight;
   Int_t           HLT_Ele1;
   Int_t           HLT_Mu1;

   TBranch        *b_event; 
   TBranch        *b_nVtx;  
   TBranch        *b_theWeight; 
   TBranch        *b_HLT_Ele1;  
   TBranch        *b_HLT_Mu1;   

   TString m_dataset;
   xx(TTree *tree=0, TString dataset="");

   virtual ~xx();
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     endJob(); 
   virtual void     Printing();
   private:
   TTree *ExTree;
   TFile *fout; 
   double scalef;

};

#endif


#ifdef xx_cxx
xx::xx(TTree *tree, TString dataset) : fChain(0) 
{
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("treePKU_11.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("treePKU_11.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("treePKU_11.root:/treeDumper");
      dir->GetObject("PKUCandidates",tree);

   }
   m_dataset=dataset;
   Init(tree);
}

xx::~xx()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}


Long64_t xx::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}


void xx::Init(TTree *tree)
{
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fout = new TFile(m_dataset, "RECREATE");
   ExTree = new TTree("demo","demo");
   ExTree->Branch("scalef",&scalef,"scalef/D");
   ExTree->Branch("nVtx", &nVtx, "nVtx/I");
   ExTree->Branch("theWeight", &theWeight, "theWeight/D");
   ExTree->Branch("HLT_Ele1",&HLT_Ele1,"HLT_Ele1/I");
   ExTree->Branch("HLT_Mu1",&HLT_Mu1,"HLT_Mu1/I");


   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("theWeight", &theWeight, &b_theWeight);
   fChain->SetBranchAddress("HLT_Ele1", &HLT_Ele1, &b_HLT_Ele1);
   fChain->SetBranchAddress("HLT_Mu1", &HLT_Mu1, &b_HLT_Mu1);

   Notify();
}

Bool_t xx::Notify()
{
   return kTRUE;
}

void xx::Show(Long64_t entry)
{
   if (!fChain) return;
   fChain->Show(entry);
}

void xx::endJob() {
   fout->cd();
   ExTree->Write();
   fout->Write();
   fout->Close();
   delete fout;
}

void xx::Printing() 
{
	cout<<"this is priting func"<<endl;
}
	

#endif 
