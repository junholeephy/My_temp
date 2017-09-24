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

	n27_HS_tree *hstree = new n27_HS_tree(files);
	histoss = hstree->ReturnHistos();

	n27_HS *hstack = new n27_HS(histoss);	
	hstack->Draw();


}

