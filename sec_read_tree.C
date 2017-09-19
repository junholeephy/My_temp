void sec_read_tree()
{
	TFile *f = new TFile("first_histo_n_tree_n_ntuple.root","READ");
	TFile *f2 = new TFile("sec_read_tree.root","RECREATE");

	TTree *t2 = (TTree*)f->Get("t1");
	
	Float_t pzf;
	Double_t pxd, pyd;

	t2->SetBranchAddress("pzf",&pzf);
	t2->SetBranchAddress("pxd",&pxd);
	t2->SetBranchAddress("pyd",&pyd);

	Long64_t n = t2->GetEntries(); 
	cout<<"entry number is = "<<n<< endl;

	TH1F *z = new TH1F("z","z",10,0,5);
	TH1F *x = new TH1F("x","x",10,0,10);
	TH1D *y = new TH1D("y","y",10,0,10);


	for(Int_t i=0; i<n; i++)
	{
		t2->GetEntry(i);
//		cout<<"pxd = "<<pxd<<endl;
//		cout<<"pyd = "<<pyd<<endl;
//		cout<<"pzf = "<<pzf<<endl;
	
		z->Fill(pzf);
		x->Fill(pxd);
		y->Fill(pyd);

	}

	f2->Write();
	f2->Close();
}
