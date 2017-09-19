void n5_readingroot_with_directory()
{
	TFile *f1 = new TFile("n4_makeroot_with_directory.root","READ");
	TFile *f2 = new TFile("n5_readingroot_with_directory.root","RECREATE");
	TDirectory *d1 = (TDirectory*)f1->Get("file");
	TTree *t1 = (TTree*)d1->Get("tree");
	Double_t px, py, pz;
	Double_t px1, py1, pz1;
	Int_t nentries = t1->GetEntries();	

	cout<<"nentries = "<<nentries<<endl;

//	t1->Branch("px1",&px1);
//	t1->Branch("py1",&py1);
//	t1->Branch("pz1",&pz1);

	t1->SetBranchAddress("px",&px);
	t1->SetBranchAddress("py",&py);
	t1->SetBranchAddress("pz",&pz);
	
	Double_t pxt;
	TTree *t2 = new TTree("t2","t2");
	t2->Branch("px",&px,"px/D");


	TH1D *pxh=new TH1D("pxh","pxh",10,0,5);	

	for(Int_t i=0; i<nentries; i++)
	{
		t1->GetEntry(i);
		pxh->Fill(px);
		t2->Fill();
	}
//	pxh->Write();
	t2->Write();
	f1->Close();
	f2->Write();
	f2->Close();

}
