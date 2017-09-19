void n14_copy_histo()
{
	TFile *f1 = new TFile("histos_allMCs_b.root","READ");
	if(!f1) return;

	TH1D *h1 = (TH1D*)f1->Get("photon_sieie_mu");
	h1->Draw();



}
