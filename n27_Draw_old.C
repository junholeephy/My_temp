#include "n27_HS.h"
#include "n27_HS_tree.h"
#include "TTree.h"
#include "TFile.h"
void n27_Draw()
{
	vector<TH1D*> histoss;
	vector<TFile*> files;
	TFile *f1 = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170918_lep_loose/outZG_s.root","READ");
	TFile *f2 = new TFile("/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170918_lep_loose/outVV_s.root","READ");
	files.push_back(f1);
	files.push_back(f2);

///////////////
	n27_HS_tree *hstree = new n27_HS_tree(files);
	
	histoss = hstree->ReturnHistos();
//	cout<<"error 4"<<endl;

///////////////
/*
	TTree *t1 =(TTree*)f1->Get("demo");
	TTree *t2 =(TTree*)f2->Get("demo");

	double mtVlepJECnew;
	t1->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);
	t2->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);	
	
	Long64_t nentries1 = t1->GetEntries();
	Long64_t nentries2 = t2->GetEntries();
	cout<<endl;
//	cout<<"ZG entries : " <<nentries1<<std::endl;
//	std::cout<<"VV entries : "<<nentries2<<std::endl;
//	cout<<endl;

	TH1D *h1 = new TH1D("h1","h1",20,0,100);
	TH1D *h2 = new TH1D("h2","h2",20,0,100);

	for(Int_t i=0; i<nentries1; i++)
	{
		t1->GetEntry(i);
		h1->Fill(mtVlepJECnew);	
		if(i==0) cout<<"Start Looping ZG "<<endl;
		if(i%1000000==0) cout<<"Entry num " << i << std::endl;
	}
	cout<<endl;
	for(Int_t i=0; i<nentries2; i++)
	{
		t2->GetEntry(i);
		h2->Fill(mtVlepJECnew);
		if(i==0) cout<<"Start Looping VV "<<endl;
		if(i%1000000==0) cout<<"Entry num " << i << std::endl;
	}





	histos.push_back(h1);
	histos.push_back(h2);
//	TH1D *h1 = NULL;
//	TH1D *h2 = (TH1D*)t1->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);

*/

	n27_HS *hstack = new n27_HS(histoss);	
//	cout<<"error 5"<<endl;
	hstack->Draw();


///// return test from *.h file	////////
/*
	vector<string> STRING;
	STRING = hstack->Name();
	cout<<STRING.at(1)<<endl;
	STRING = hstack->Name2(histoss);

	for(size_t i =0; i!=STRING.size(); i++)
	{	
		cout<<STRING.at(i)<<endl;
	}

	vector<TH1D*> tht;
	tht = hstack->TH_return(histoss);
//	tht.at(0)->Draw();
///////////////////////
*/
}

