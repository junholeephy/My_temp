void n23_histo_counting()
{
	TFile *f = new TFile("n23_treePKU.root","READ");
	TDirectory * dir1 = (TDirectory*)f->Get("treeDumper");
	TTree *t = (TTree*) dir1->Get("PKUCandidates");
	
	Long64_t nentries = t->GetEntries();
	cout<<"total entries : "<<nentries<<endl;

	double muisolation;
	TH1D *h = new TH1D("h","h",100,-1,1);
	t->SetBranchAddress("muisolation",&muisolation);

	for(Int_t i=0; i<nentries; i++)
	{
		t->GetEntry(i);
		if(i%1==0) cout<<muisolation<<endl; else ; 
		if(muisolation<-5) continue;
		else h->Fill(muisolation);		
	}

	h->Draw();
	Int_t inte;
	inte = h->Integral();
	cout<<"Integrated num : "<<inte<<endl;
}
