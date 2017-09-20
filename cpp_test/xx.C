#define xx_cxx
#include "xx.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void xx::Loop()
{
	if(fChain ==0) return;
	Long64_t nentries = fChain->GetEntriesFast();

	Long64_t npp = fChain->GetEntries("theWeight>0.");
	Long64_t nmm = fChain->GetEntries("theWeight<0.");

	std::cout<<"number of np : "<<npp<<"  number of nm : "<<nmm<<std::endl;


	TFile *input1 = new TFile("puweight.root");
	TH1* h = NULL;
	input1->GetObject("h2",h);

	Long64_t nbytes = 0, nb =0;

	for(Long64_t jentry=0; jentry<nentries; jentry++)
	{
		Long64_t ientry = LoadTree(jentry);
		if(ientry < 0) break;
		nb = fChain->GetEntry(jentry);
		nbytes += nb;


		if(jentry%100000==0) {cout<<" "<<HLT_Ele1<<" "<<HLT_Mu1<<" "<<fabs(theWeight)/theWeight<<" "<<m_dataset<<" "<<jentry<<" "<<nentries<<endl; /*  Show(jentry); */ }

		
		if(m_dataset == "outVBS_WGamma_signal.root") {scalef=1000*0.776/float(npp-nmm)*fabs(theWeight)/theWeight;}

	ExTree->Fill();
	}

	input1->Close();
}








