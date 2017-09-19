void n10_reco_pat_pho_counter()
{
	TFile *f1 = new TFile("/Users/junho/Desktop/VBSWGamma/Run2VBSWGamma_plotting/PKUTree/outtree/outVBS_WGamma_signal.root","READ");
		
    Double_t genphoton_pt[6];
    Double_t genphoton_eta[6];
    Double_t genphoton_phi[6];

	Double_t photonet;

	Double_t photon_pt[6];
	Double_t photon_eta[6];
	Double_t photon_phi[6];

	TTree *t1 = (TTree*)f1->Get("demo");

	t1->SetBranchAddress("genphoton_pt",genphoton_pt);
	t1->SetBranchAddress("genphoton_eta",genphoton_eta);
	t1->SetBranchAddress("genphoton_phi",genphoton_phi);

	t1->SetBranchAddress("photonet",&photonet);

	t1->SetBranchAddress("photon_pt",photon_pt);	
	t1->SetBranchAddress("photon_eta",photon_eta);
	t1->SetBranchAddress("photon_phi",photon_phi);

	Long64_t nentries = t1->GetEntries();
	cout<<"number of entries = "<<nentries<<endl;
	
	Int_t gennum;
	Int_t gennum0,gennum1, gennum2, gennum3, gennum4, gennum5, gennum6, gennum7;

	Int_t phonum=0;

	Int_t reconum;
	Int_t reconum0, reconum1, reconum2, reconum3, reconum4, reconum5, reconum6, reconum7;
	
	Int_t is_same=0;

	Int_t iii, jjj;
	Int_t kkk=0;
	gennum0=0;  gennum1=0; gennum2=0; gennum3=0; gennum4=0; gennum5=0; gennum6=0; gennum7=0;
	for(Int_t i=0; i<nentries ; i++)
	{
		if(i%1000000==0) cout<<"now looping "<<i<<"th event"<<endl;
		gennum=0;
		reconum=0;
		iii=0;
		jjj=0;

		t1->GetEntry(i);
		for(Int_t ii=0; ii<6; ii++)
		{
			if(genphoton_pt[ii]<0) break;
			gennum++;
			iii++;
		}
		if(gennum ==0) gennum0++;
		else if(gennum==1) gennum1++;
		else if(gennum==2)	gennum2++;
		else if(gennum==3)	gennum3++;
	    else if(gennum==4)	gennum4++;
		else if(gennum==5)	gennum5++;
		else if(gennum==6) gennum6++;
		else gennum7++;

		if(photonet>0) phonum++;

		for(Int_t jj=0; jj<6; jj++)
		{
			if(photon_pt[jj]<0) break;
			reconum++;
			jjj++;
		}
		if(reconum==0) reconum0++;
		else if(reconum==1)	reconum1++;
		else if(reconum==2) reconum2++;
		else if(reconum==3) reconum3++;
		else if(reconum==4) reconum4++;
		else if(reconum==5) reconum5++;
		else if(reconum==6) reconum6++;
		else reconum7++;

		if(iii>0 && jjj>0)	kkk++;
		if(iii==jjj && iii!=0) is_same++;
	}
	cout<<endl;
	cout<<"<<<<<<<<<<<gen photon<<<<<<<<<<<<<<"<<endl;	
	cout<<"event number of no genphotons = "<<gennum0<<endl<<endl;
    cout<<"event number of one genphotons = "<<gennum1<<endl;
	cout<<"event number of two genphotons = "<<gennum2<<endl;
	cout<<"event number of three genphotons = "<<gennum3<<endl;
	cout<<"event number of four genphotons = "<<gennum4<<endl;
	cout<<"event number of five genphotons = "<<gennum5<<endl;
	cout<<"event number of six genphotons = "<<gennum6<<endl;
	cout<<"event number of more than six genphotons = "<<gennum7<<endl;

	Int_t totalnum;
	totalnum =  gennum1 + gennum2 + gennum3 + gennum4 + gennum5 + gennum6;
	cout<<"total events number containg gen events = "<<totalnum<<endl;
	cout<<"add up gen0 and gen1 gen2 .. = "<<totalnum+gennum0<<endl;
	cout<<"number of entries = "<<nentries<<endl;
	cout<<endl<<endl;

	cout<<"<<<<<<<<<<<pat photon<<<<<<<<<<<<"<<endl;
	cout<<"event number of no pat photons = "<<reconum0<<endl<<endl;
	cout<<"event number of one pat photons = "<<reconum1<<endl;
	cout<<"event number of two pat photons = "<<reconum2<<endl;
	cout<<"event number of three pat photons = "<<reconum3<<endl;
	cout<<"event number of four pat photons = "<<reconum4<<endl;
	cout<<"event number of five pat photons = "<<reconum5<<endl;
	cout<<"event number of six pat photons = "<<reconum6<<endl;
	cout<<"event number of more than six pat photons = "<<reconum7<<endl;

	Int_t totalnum_reco;
    totalnum_reco =  reconum1 + reconum2 + reconum3 + reconum4 + reconum5 + reconum6;
    cout<<"total events number containg gen events = "<<totalnum_reco<<endl;
    cout<<"add up gen0 and gen1 gen2 .. = "<<totalnum_reco+reconum0<<endl;
    cout<<"number of entries = "<<nentries<<endl;
	cout<<endl<<endl;
	cout<<"!!!!  "<<kkk<<" events having gen and reco photon at same time"<<endl;
	cout<<"!!!!  "<<is_same<<" events has exactly same number of gen_photon and reco_photon"<<endl;
	cout<<endl<<endl;


	cout<<"<<<<<<<<<<<pt highest photon<<<<<<<<<<<<"<<endl;
	cout<<"number of entries = "<<nentries<<endl;
	cout<<"event number of photons = "<<phonum<<endl;
	f1->Close();
}
