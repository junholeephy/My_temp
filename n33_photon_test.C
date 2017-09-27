#include "TTree.h"
#include "TFile.h"
void n33_photon_test()
{
//	TFile *f = new TFile("/Volumes/ExHard/Run2VBSWGamma_plotting/PKUTree/tree_170926/VBS_WGamma_signal.root","READ");
	TFile *f = new TFile("/Volumes/ExHard/Run2VBSWGamma_plotting/PKUTree/tree_170926/SingleMuon_Run2016C.root","READ");
	TDirectory *dir = (TDirectory*)f->Get("treeDumper");
	TTree *t =(TTree*)dir->Get("PKUCandidates");

	double photon_pt[6];
	double photonpt = -1e1;
	Int_t iphoton = -1;
	for(int i=0; i<6; i++) { photon_pt[i] = -2e1;}
	Int_t ip = -1;

	t->SetBranchAddress("photon_pt",&photon_pt);
	t->SetBranchAddress("iphoton",&iphoton);
	Int_t i1=0, i2=0, i3=0;
	Int_t j1=0, j2=0, j3=0;

	Long64_t nentries = t->GetEntries();
	for(Long64_t it=0; it<nentries; it++)
	{	
		if(it%100000==0)	cout<<"now looping "<<it<<" th event"<<"  total event num "<<nentries<<endl;
		if(it==1000000) break;
		t->GetEntry(it);
	/*	
		for(size_t i=0; i<6; i++)
		{
			if(photon_pt[i]>photonpt)   {photonpt = photon_pt[i]; ip = i;}
		}
		if(ip>0)
		{
			j1++;
			if(iphoton == ip ) j2++;
			else j3++;	
		}
		ip=0;
*/
		if(iphoton==-1) continue;
		for(size_t i=0; i<6; i++)
		{
			if(photon_pt[i]>photonpt)	{photonpt = photon_pt[i]; ip = i;}
		}
		if(ip>=0)
		{	
			if(it%100000==0) {cout<<"iphoton = "<<iphoton<<endl;}
			i1++;
			if(iphoton == ip ) i2++;
			else i3++;
		}
	}
	cout<<endl;
    cout<<"valid tight photons num : "<<i1<<endl;
    cout<<"under tight photon selection, num of iphoton is leading photon : "<<i2<<endl;
    cout<<"under tight photon selection, num of iphoton is not leading photon : "<<i3<<endl;	
	cout<<endl;
//	cout<<"no tight photon requirement, valid photon events : "<<j1<<endl;
//	cout<<"no tight photon requirement, num of iphoton is leading photon : "<<j2<<endl;
//	cout<<"no tight photon requirement, num of iphoton is not leading photon : "<<j3<<endl;
}
