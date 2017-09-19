void n15_dot2histo()
{
	TFile *f1 = new TFile("histos_allMCs_b.root","READ");
//	TH1D *h1 = (TH1D*)f1->Get("photon_sieie_mu");
//	h1->SetLineColor(kBlack);
//	h1->Draw();	

	TH1D *h2 = (TH1D*)f1->Get("photon_sieie_mu");
	h2->SetLineColor(kBlue);
	h2->SetMarkerStyle(0);
	h2->Draw("same HIST");

}
