void thrid_read_ntuple()
{
	TFile *f = new TFile("first_histo_n_tree_n_ntuple.root","READ");
	TFile *f2 = new TFile("thrid_read_ntuple.root","RECREATE");

//	TH2D *pzd = new TH2D("pzd","pzd",10,0,5,10,0,5);
//	TH1D *pxd = new TH1D("pxd","pxd",10,0,10);

//	TNtuple *temp = (TNtuple*)->Get("ntuple");

	TNtuple *temp = new TNtuple("temp1","temp1","pxd:pzd,pyd");
	temp = (TNtuple*) f->Get("ntuple2");

	Long64_t n = temp->GetEntries();	
	cout<<"event number = "<<n<<endl;

//	temp->Draw("pxd","");
//	temp->Draw("pzd","");
	temp->Draw("pxd","pzd");
 



	f2->Write();
	f2->Close();

}
