#include "n28_HS.h"
#include "n28_HS_tree.h"
#include "TTree.h"
#include "TFile.h"
void n28_Draw()
{
	vector<TH1D*> histos;
	vector<TFile*> files;

	std::string pathToTrees="/Volumes/ExHard/Run2VBSWGamma_quick_plotting/making_root_small/outtree_170918_lep_loose/";
	const int nMC = 3;	
	std::string mcLabels[nMC]={"ZG_s","VV_s","WG_s"};	
	std::vector<std::string> fMC;
	for(size_t i=0; i<nMC; i++)
	{
		fMC.push_back(pathToTrees+"out"+mcLabels[i]+".root");
	}

	for(size_t i=0; i<nMC; i++)
	{
		TFile *filesMC = TFile::Open(fMC.at(i).c_str());
		files.push_back(filesMC);
	}



///////////////////////
	n28_HS_tree *hstree = new n28_HS_tree(files);
	histos = hstree->ReturnHistos();

	n28_HS *hstack = new n28_HS(histos);	
	hstack->Draw();


}

