void n4_makeroot_with_directory()
{
	TFile *newf = new TFile("n4_makeroot_with_directory.root","RECREATE");
	
	TRandom3 ran;
	Double_t px, py ,pz;

	TDirectory *dir = newf->mkdir("file") ;
	newf->cd("file");
	TTree *tree = new TTree("tree","tree");
	tree->Branch("px",&px,"px/D");
	tree->Branch("py",&py,"py/D");
	tree->Branch("pz",&pz,"pz/D");

	for(Int_t i=0; i<1000; i++)
	{
		ran.Rannor(px,py);
		pz = sqrt(px*px+py*py);

		tree->Fill();

	}
	newf->Write();
	newf->Close();

}
