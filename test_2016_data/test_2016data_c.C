void test_2016data_c()
{
	TFile *f1 = new TFile("/Users/junho/Desktop/VBSWGamma/Run2VBSWGamma_plotting/PKUTree/tree/SingleMuon_Run2016C.root");
	TFile *f2 = new TFile("data_c.root","RECREATE");
	
	TDirectory *d1 = (TDirectory*)f1->Get("treeDumper");
	TTree *t1 = (TTree*)d1->Get("PKUCandidates");

	Int_t lep;
//	Int_t n = t2->GetEntries();
	int nentries = (int)t1->GetEntries();
	cout<<"number of entries = "<<nentries<<endl;

	t1->SetBranchAddress("lep",&lep);

	int ep, em, mp,  mm, tp, tml
	ep=0;	em=0;
	mp=0;	mm=0;
	tp=0;	tm=0;


	for(int i = 0; i < (nentries); i++)
	{
		t1->GetEntry(i);
		if(i%1000000==0) cout<<"dfsd"<<endl;
//		if(lep+ 

	}


	f2->Close();
	f1->Close();
}
