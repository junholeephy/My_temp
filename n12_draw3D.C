void n12_draw3D()
{
	TFile *inputf = new TFile("/Volumes/ExHard/event_cut_optimizer/make_small_root/outtree/outSingleMuon_Run2016C_s.root","READ");
	TTree *inputt =(TTree*)inputf->Get("demo");

	double zepp;
	double jet1eta;
	double jet2eta;
	double jet1phi;
	double jet2phi;
	double detajj=-10;
	double dphijj=-10;

	inputt->SetBranchAddress("zepp",&zepp);
	inputt->SetBranchAddress("jet1eta",&jet1eta);
	inputt->SetBranchAddress("jet2eta",&jet2eta);
	inputt->SetBranchAddress("jet1phi",&jet1phi);
	inputt->SetBranchAddress("jet2phi",&jet2phi);

	int bin_x = 10;
	int ini_bin_x = 0;
	int fin_bin_x = 4;
	int bin_y = 10;
	int ini_bin_y = 0;
	int fin_bin_y = 4;
	int bin_z = 10;
	int ini_bin_z = 0;
	int fin_bin_z = 1;

	TH3F *histo1= new TH3F("histo1","histo1",bin_x,ini_bin_x,fin_bin_x,bin_y,ini_bin_y,fin_bin_y,bin_z,ini_bin_z,fin_bin_z);
	histo1->GetXaxis()->SetTitle("detajj");
	histo1->GetYaxis()->SetTitle("dphijj");
	histo1->GetZaxis()->SetTitle("zepp");
	histo1->SetStats(0);

	Long64_t nentries = inputt->GetEntries();
	
	for(Long64_t i=0; i<nentries; i++)
	{
		inputt->GetEntry(i);
		if(i%1000==0) std::cout << "Entry num " << i << std::endl;
		detajj = fabs(jet1eta - jet2eta);
		dphijj = fabs(jet1phi - jet2phi);
		histo1->Fill(detajj, dphijj, zepp, 1);
	}
	histo1->Draw("COLZ");
//	inputf->Close();
}
