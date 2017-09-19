void n25_histo_counting()
{
	TFile *f = new TFile("n25_treePKU.root","READ");
	TDirectory * dir1 = (TDirectory*)f->Get("treeDumper");
	TTree *t = (TTree*) dir1->Get("PKUCandidates");
	
	Long64_t nentries = t->GetEntries();
	cout<<"total entries : "<<nentries<<endl;

	double muisolation;
	int lep;

Int_t ii=0;
Int_t iii=0;
Int_t jj=0;
Int_t jjj=0;

	TH1D *h = new TH1D("h","h",100,-1,1);
	t->SetBranchAddress("muisolation",&muisolation);
	t->SetBranchAddress("lep",&lep);
	for(Int_t i=0; i<nentries; i++)
	{
		t->GetEntry(i);
		if(i%100==0) cout<<muisolation<<endl; else ; 
		if(lep==13 || lep==-13) ii++; else ;
//		if(lep==14 || lep==-14) cout<<"muon nu detected"<<endl; else ;
		if(muisolation!=-10) iii++; else ;
		if(muisolation >= 0.25) jjj++; else ;
		if(muisolation<-5 ) continue ;
		else { jj++; h->Fill(muisolation);}
	}
	cout<<"total muon num = "<<ii<<endl;
	cout<<"valid num of muoniso = "<<iii<<endl;

	h->Draw();
	Int_t inte;
//	inte = h->Integral();
	cout<<"plotted num (muisolation<0.15) : "<<jj<<endl;
	cout<<"num of muisolation >= 0.25 (invert of loosemuon iso) : "<<jjj<<endl;
}
