#include "n29_HS.h"
#include "n29_HS_tree.h"
#include "TTree.h"
#include "TFile.h"
void n29_Draw()
{
	vector<TH1D*> histos;
	vector<TH1D*> histosD;
	vector<TFile*> files;
	vector<TFile*> filesD;

	std::string pathToTrees="/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170918_lep_loose/";
	const int nMC = 2;	
	const int nDATA = 1;
	std::string mcLabels[nMC]={"ZG_s","VV_s"};	
	std::string dataLabels[nDATA] = {"WG_s"};
	std::vector<std::string> fMC;
	std::vector<std::string> fDATA;
	
	for(size_t i=0; i<nMC; i++)
	{
		fMC.push_back(pathToTrees+"out"+mcLabels[i]+".root");
	}
	for(size_t i=0; i<nMC; i++)
	{
		TFile *filesMC = TFile::Open(fMC.at(i).c_str());
		files.push_back(filesMC);
	}

	for(size_t i=0; i<nDATA; i++)
	{
		fDATA.push_back(pathToTrees+"out"+dataLabels[i]+".root");
	}
	for(size_t i=0; i<nDATA; i++)
	{
		TFile *filesDATA = TFile::Open(fDATA.at(i).c_str());
		filesD.push_back(filesDATA);
	}




	THStack *hhh2 = new THStack("hhh2","hhh2");
	n29_HS_tree *hstree = new n29_HS_tree(files);
	histos = hstree->ReturnHistos();
	n29_HS *hstack = new n29_HS();	
	hhh2 = hstack->SetMC(histos);
	hhh2->Draw();

    THStack* hhh1 = new THStack("hhh1","hhh1");
    n29_HS_tree *hstreeD = new n29_HS_tree(filesD);
    histosD = hstreeD->ReturnHistos();
    n29_HS *hstackD = new n29_HS();
    hhh1 = hstackD->SetDATA(histosD);
    hhh1->Draw("SAME EP");


}

