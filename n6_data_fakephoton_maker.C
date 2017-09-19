void n6_data_fakephoton_maker()
{
	TFile *f1 = new TFile("/Users/junho/Desktop/VBSWGamma/Run2VBSWGamma_plotting/PKUTree/outtree/outSingleMuon_Run2016C.root","READ");
	TFile *f2 = new TFile("fakephoton_data.root","RECREATE");
	cout<<" no error 0"<<endl;

	Double_t weightfake;

	Double_t scalef;
	Int_t nVtx;
	Double_t theWeight;
	Double_t nump;
	Double_t numm;
	Double_t npT;
	Int_t lep;
	Double_t ptVlepJEC;
	Double_t yVlepJEC;
	Double_t phiVlepJEC;
    Double_t massVlepJEC;
    Double_t mtVlepJECnew;
    Double_t Mla;
    Double_t Mva;
    Double_t ptlep1;
    Double_t etalep1;
    Double_t philep1;
    Double_t drla;
    Int_t nlooseeles;
    Int_t nloosemus;
    Double_t photonet;
    Double_t photoneta;
    Double_t photonphi;
    Double_t photone;
    Double_t photonsieie;
    Double_t photonphoiso;
    Double_t photonchiso;
    Double_t photonnhiso;
    Double_t genMET;
    Double_t MET_et;
    Int_t HLT_Ele1;
    Int_t HLT_Ele2;
    Int_t HLT_Mu1;
    Int_t HLT_Mu2;
    Int_t HLT_Mu3;
    Int_t isTrue;
    Int_t isprompt;
    Double_t lumiWeight;
    Double_t pileupWeight;
    Double_t genphoton_pt[6];
    Double_t genphoton_eta[6];
    Double_t genphoton_phi[6];
    Double_t genmuon_pt[6];
    Double_t genmuon_eta[6];
    Double_t genmuon_phi[6];
    Double_t genelectron_pt[6];
    Double_t genelectron_eta[6];
    Double_t genelectron_phi[6];
    Double_t photon_pt[6];
    Double_t photon_eta[6];
    Double_t photon_phi[6];
    Double_t photon_e[6];
/*    Bool_t photon_pev[6];
    Bool_t photon_pevnew[6];
    Bool_t photon_ppsv[6];
    Bool_t photon_iseb[6];
    Bool_t photon_isee[6]; */
    Double_t photon_hoe[6];
    Double_t photon_sieie[6];
    Double_t photon_sieie2[6];
    Double_t photon_chiso[6];
    Double_t photon_nhiso[6];
    Double_t photon_phoiso[6];
    Int_t photon_istrue[6];
    Int_t photon_isprompt[6];
    Double_t photon_drla[6];
    Double_t photon_mla[6];
	Double_t photon_mva[6];
    Double_t ak4jet_pt[6];
    Double_t ak4jet_eta[6];
    Double_t ak4jet_phi[6];
    Double_t ak4jet_e[6];
    Double_t ak4jet_csv[6];
    Double_t ak4jet_icsv[6];
    Double_t jet1pt;
    Double_t jet1eta;
    Double_t jet1phi;
    Double_t jet1e;
	Double_t jet2pt;
    Double_t jet2eta;
    Double_t jet2phi;
    Double_t jet2e;
    Double_t Mjj;
    Double_t deltaeta;
    Double_t zepp;
    Double_t met;
    Double_t metPhi;
	Double_t j1metPhi;
    Double_t j2metPhi;
    Double_t METraw_et;
    Double_t METraw_sumEt;
    Double_t MET_phi;
    Double_t MET_sumEt;
    Double_t MET_corrPx;
    Double_t MET_corrPy;
//    bool passFilter_HBHE;
//    Bool_t passFilter_HBHEIso;
//    Bool_t passFilter_globalTightHalo;
//	Bool_t passFilter_ECALDeadCell;
//    Bool_t passFilter_GoodVtx;
//	Bool_t passFilter_EEBadSc;




	TTree *t1 = (TTree*)f1->Get("demo");
	TTree *demo = new TTree("demo","demo");


	cout<<"no error 0.5"<<endl;

	t1->SetBranchAddress("scalef",&scalef);										demo->Branch("scalef",&scalef,"scalef/D");
	t1->SetBranchAddress("nVtx",&nVtx);											demo->Branch("nVtx",nVtx,"nVtx/I");
	t1->SetBranchAddress("theWeight",&theWeight);								demo->Branch("theWeight",&theWeight,"theWeight/D");
    t1->SetBranchAddress("nump",&nump); 										demo->Branch("nump",&nump,"nump/D");
    t1->SetBranchAddress("numm",&numm); 										demo->Branch("numm",&numm,"numm/D");
    t1->SetBranchAddress("npT",&npT);											demo->Branch("npT",&npT,"npT/D");
    t1->SetBranchAddress("lep",&lep);											demo->Branch("lep",&lep,"lep/I");
    t1->SetBranchAddress("ptVlepJEC",&ptVlepJEC); 								demo->Branch("ptVlepJEC",&ptVlepJEC,"ptVlepJEC/D");
    t1->SetBranchAddress("yVlepJEC",&yVlepJEC);									demo->Branch("yVlepJEC",&yVlepJEC,"yVlepJEC/D");
    t1->SetBranchAddress("phiVlepJEC",&phiVlepJEC);								demo->Branch("phiVlepJEC",&phiVlepJEC,"phiVlepJEC/D");
    t1->SetBranchAddress("massVlepJEC",&massVlepJEC); 							demo->Branch("massVlepJEC",&massVlepJEC,"massVlepJEC/D");
    t1->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);							demo->Branch("mtVlepJECnew",&mtVlepJECnew,"mtVlepJECnew/D");
    t1->SetBranchAddress("Mla",&Mla);											demo->Branch("Mla",&Mla,"Mla/D");
    t1->SetBranchAddress("Mva",&Mva); 											demo->Branch("Mva",&Mva,"Mva/D");
    t1->SetBranchAddress("ptlep1",&ptlep1);										demo->Branch("ptlep1",&ptlep1,"ptlep1/D");
    t1->SetBranchAddress("etalep1",&etalep1);									demo->Branch("etalep1",&etalep1,"etalep1/D");		
    t1->SetBranchAddress("philep1",&philep1); 									demo->Branch("philep1",&philep1,"philep1/D");
    t1->SetBranchAddress("drla",&drla);											demo->Branch("drla",&drla,"drla/D");
    t1->SetBranchAddress("nlooseeles",&nlooseeles);								demo->Branch("nlooseeles",&nlooseeles,"nlooseeles/I");
    t1->SetBranchAddress("nloosemus",&nloosemus); 								demo->Branch("nloosemus",&nloosemus,"nloosemus/I");
    t1->SetBranchAddress("photonet",&photonet);									demo->Branch("photonet",&photonet,"photonet/D");
    t1->SetBranchAddress("photoneta",&photoneta);								demo->Branch("photoneta",&photoneta,"photoneta/D");
    t1->SetBranchAddress("photonphi",&photonphi); 								demo->Branch("photonphi",&photonphi,"photonphi/D");
    t1->SetBranchAddress("photone",&photone);									demo->Branch("photone",&photone,"photone/D");
    t1->SetBranchAddress("photonphi",&photonphi);								demo->Branch("photonphi",&photonphi,"photonphi/D");
    t1->SetBranchAddress("photonphoiso",&photonphoiso); 						demo->Branch("photonphoiso",&photonphoiso,"photonphoiso/D");
    t1->SetBranchAddress("photonchiso",&photonchiso);							demo->Branch("photonchiso",&photonchiso,"photonchiso/D");
    t1->SetBranchAddress("photonnhiso",&photonnhiso);							demo->Branch("photonnhiso",&photonnhiso,"photonnhiso/D");
    t1->SetBranchAddress("genMET",&genMET); 									demo->Branch("genMET",&genMET,"genMET/D");
    t1->SetBranchAddress("MET_et",&MET_et);										demo->Branch("MET_et",&MET_et,"MET_et/D");
    t1->SetBranchAddress("HLT_Ele1",&HLT_Ele1);									demo->Branch("HLT_Ele1",&HLT_Ele1,"HLT_Ele1/I");
    t1->SetBranchAddress("HLT_Ele2",&HLT_Ele2); 								demo->Branch("HLT_Ele2",&HLT_Ele2,"HLT_Ele2/I");
    t1->SetBranchAddress("HLT_Mu1",&HLT_Mu1);									demo->Branch("HLT_Mu1",&HLT_Mu1,"HLT_Mu1/I");
    t1->SetBranchAddress("HLT_Mu2",&HLT_Mu2);									demo->Branch("HLT_Mu2",&HLT_Mu2,"HLT_Mu2/I");	
    t1->SetBranchAddress("HLT_Mu3",&HLT_Mu3); 									demo->Branch("HLT_Mu3",&HLT_Mu3,"HLT_Mu3/I");
    t1->SetBranchAddress("isTrue",&isTrue);										demo->Branch("isTrue",&isTrue,"isTrue/I");
    t1->SetBranchAddress("isprompt",&isprompt);									demo->Branch("isprompt",&isprompt,"isprompt/I");
    t1->SetBranchAddress("lumiWeight",&lumiWeight); 							demo->Branch("lumiWeight",&lumiWeight,"lumiWeight/D");
    t1->SetBranchAddress("pileupWeight",&pileupWeight);							demo->Branch("pileupWeight",&pileupWeight,"pileupWeight/D");
    t1->SetBranchAddress("genphoton_pt",genphoton_pt);							demo->Branch("genphoton_pt",genphoton_pt,"genphoton_pt/D");
    t1->SetBranchAddress("genphoton_eta",genphoton_eta); 						demo->Branch("genphoton_eta",genphoton_eta,"genphoton_eta/D");
    t1->SetBranchAddress("genphoton_phi",genphoton_phi);						demo->Branch("genphoton_phi",genphoton_phi,"genphoton_phi/D");
    t1->SetBranchAddress("genmuon_pt",genmuon_pt);								demo->Branch("genmuon_pt",genmuon_pt,"genmuon_pt/D");
    t1->SetBranchAddress("genmuon_eta",genmuon_eta); 							demo->Branch("genmuon_eta",genmuon_eta,"genmuon_eta/D");
    t1->SetBranchAddress("genmuon_phi",genmuon_phi);							demo->Branch("genmuon_phi",genmuon_phi,"genmuon_phi/D");
    t1->SetBranchAddress("genelectron_pt",genelectron_pt);						demo->Branch("genelectron_pt",genelectron_pt,"genelectron_pt/D");
    t1->SetBranchAddress("genelectron_eta",genelectron_eta); 					demo->Branch("genelectron_eta",genelectron_eta,"genelectron_eta/D");
    t1->SetBranchAddress("genelectron_phi",genelectron_phi);					demo->Branch("genelectron_phi",genelectron_phi,"genelectron_phi/D");
    t1->SetBranchAddress("photon_pt",photon_pt);								demo->Branch("photon_pt",photon_pt,"photon_pt/D");
    t1->SetBranchAddress("photon_eta",photon_eta); 								demo->Branch("photon_eta",photon_eta,"photon_eta/D");
    t1->SetBranchAddress("photon_phi",photon_phi);								demo->Branch("photon_phi",photon_phi,"photon_phi/D");
    t1->SetBranchAddress("photon_e",photon_e);									demo->Branch("photon_e",photon_e,"photon_e/D");
/*    t1->SetBranchAddress("photon_pev",photon_pev); 
    t1->SetBranchAddress("photon_pevnew",photon_pevnew);
    t1->SetBranchAddress("photon_ppsv",photon_ppsv);
    t1->SetBranchAddress("photon_iseb",photon_iseb); 
    t1->SetBranchAddress("photon_isee",photon_isee); */
    t1->SetBranchAddress("photon_hoe",photon_hoe);								demo->Branch("photon_hoe",photon_hoe,"photon_hoe/D");
    t1->SetBranchAddress("photon_sieie",photon_sieie); 							demo->Branch("photon_sieie",photon_sieie,"photon_sieie/D");
    t1->SetBranchAddress("photon_sieie2",photon_sieie2);						demo->Branch("photon_sieie2",photon_sieie2,"photon_sieie2/D");
    t1->SetBranchAddress("photon_chiso",photon_chiso);							demo->Branch("photon_chiso",photon_chiso,"photon_chiso/D");
    t1->SetBranchAddress("photon_nhiso",photon_nhiso); 							demo->Branch("photon_nhiso",photon_nhiso,"photon_nhiso/D");
    t1->SetBranchAddress("photon_phoiso",photon_phoiso);						demo->Branch("photon_phoiso",photon_phoiso,"photon_phoiso/D");
    t1->SetBranchAddress("photon_istrue",photon_istrue);						demo->Branch("photon_istrue",photon_istrue,"photon_istrue/I");
    t1->SetBranchAddress("photon_isprompt",photon_isprompt); 					demo->Branch("photon_isprompt",photon_isprompt,"photon_isprompt/I");
    t1->SetBranchAddress("photon_drla",photon_drla);							demo->Branch("photon_drla",photon_drla,"photon_drla/D");
    t1->SetBranchAddress("photon_mla",photon_mla);								demo->Branch("photon_mla",photon_mla,"photon_mla/D");
    t1->SetBranchAddress("ak4jet_pt",ak4jet_pt); 								demo->Branch("ak4jet_pt",ak4jet_pt,"ak4jet_pt/D");
    t1->SetBranchAddress("ak4jet_eta",ak4jet_eta);								demo->Branch("ak4jet_eta",ak4jet_eta,"ak4jet_eta/D");
    t1->SetBranchAddress("ak4jet_phi",ak4jet_phi);								demo->Branch("ak4jet_phi",ak4jet_phi,"ak4jet_phi/D");
    t1->SetBranchAddress("ak4jet_e",ak4jet_e); 									demo->Branch("ak4jet_e",ak4jet_e,"ak4jet_e/D");
    t1->SetBranchAddress("ak4jet_csv",ak4jet_csv);								demo->Branch("ak4jet_csv",ak4jet_csv,"ak4jet_csv/D");
    t1->SetBranchAddress("ak4jet_icsv",ak4jet_icsv);							demo->Branch("ak4jet_icsv",ak4jet_icsv,"ak4jet_icsv/D");
    t1->SetBranchAddress("jet1pt",&jet1pt); 									demo->Branch("jet1pt",&jet1pt,"jet1pt/D");
    t1->SetBranchAddress("jet1eta",&jet1eta);									demo->Branch("jet1eta",&jet1eta,"jet1eta/D");
    t1->SetBranchAddress("jet1phi",&jet1phi);									demo->Branch("jet1phi",&jet1phi,"jet1phi/D");
    t1->SetBranchAddress("jet1e",&jet1e); 										demo->Branch("jet1e",&jet1e,"jet1e/D");
    t1->SetBranchAddress("jet2pt",&jet2pt);										demo->Branch("jet2pt",&jet2pt,"jet2pt/D");
    t1->SetBranchAddress("jet2eta",&jet2eta);									demo->Branch("jet2eta",&jet2eta,"jet2eta/D");
    t1->SetBranchAddress("jet2phi",&jet2phi); 									demo->Branch("jet2phi",&jet2phi,"jet2phi/D");
    t1->SetBranchAddress("jet2e",&jet2e);										demo->Branch("jet2e",&jet2e,"jet2e/D");
    t1->SetBranchAddress("Mjj",&Mjj);											demo->Branch("Mjj",&Mjj,"Mjj/D");
    t1->SetBranchAddress("deltaeta",&deltaeta); 								demo->Branch("deltaeta",&deltaeta,"deltaeta/D");
    t1->SetBranchAddress("zepp",&zepp);											demo->Branch("zepp",&zepp,"zepp/D");
    t1->SetBranchAddress("met",&met);											demo->Branch("met",&met,"met/D");
    t1->SetBranchAddress("metPhi",&metPhi); 									demo->Branch("metPhi",&metPhi,"metPhi/D");
    t1->SetBranchAddress("j1metPhi",&j1metPhi);									demo->Branch("j1metPhi",&j1metPhi,"j1metPhi/D");
    t1->SetBranchAddress("j2metPhi",&j2metPhi);									demo->Branch("j2metPhi",&j2metPhi,"j2metPhi/D");
    t1->SetBranchAddress("METraw_et",&METraw_et); 								demo->Branch("METraw_et",&METraw_et,"METraw_et/D");
    t1->SetBranchAddress("METraw_sumEt",&METraw_sumEt);							demo->Branch("METraw_sumEt",&METraw_sumEt,"METraw_sumEt/D");
    t1->SetBranchAddress("MET_phi",&MET_phi);									demo->Branch("MET_phi",&MET_phi,"MET_phi/D");
    t1->SetBranchAddress("MET_sumEt",&MET_sumEt); 								demo->Branch("MET_sumEt",&MET_sumEt,"MET_sumEt/D");
    t1->SetBranchAddress("MET_corrPx",&MET_corrPx);								demo->Branch("MET_corrPx",&MET_corrPx,"MET_corrPx/D");
    t1->SetBranchAddress("MET_corrPy",&MET_corrPy);								demo->Branch("MET_corrPy",&MET_corrPy,"MET_corrPy/D");
//    t1->SetBranchAddress("passFilter_HBHE",&passFilter_HBHE); 
//    t1->SetBranchAddress("passFilter_HBHEIso",&passFilter_HBHEIso);
//    t1->SetBranchAddress("passFilter_globalTightHalo",&passFilter_globalTightHalo);
//    t1->SetBranchAddress("passFilter_ECALDeadCell",&passFilter_ECALDeadCell); 
//    t1->SetBranchAddress("passFilter_GoodVtx",&passFilter_GoodVtx);
//    t1->SetBranchAddress("passFilter_EEBadSc",&passFilter_EEBadSc);





	cout<<"no error 1"<<endl;

//	demo->Branch("scalef",&scalef,"scalef/D");
//	demo->Branch("photon_e",&photon_e,"photon_e/D");
	demo->Branch("weightfake",&weightfake,"weightfake/D");
	//	demo->Branch("photon_e",&photon_e);
	cout<<"no error 2"<<endl;


	Long64_t n = t1->GetEntries();
    cout<<"entry number is = "<<n<< endl;

	for(Int_t i=0; i<n ; i++)
	{
		if(i%1000000==0) cout<<"now looping "<<i<<"th event"<<endl;
		t1->GetEntry(i);
		weightfake=-10;
//		if(photonet < 20) continue;
		if(photonet == 20 || (photonet>20 && photonet<30 ))
		{
			weightfake = 0.29754;
		}
		else if( photonet==30 ||(photonet >30 && photonet < 40))
		{
			weightfake = 0.16676;
		}
		else if( photonet==40 || (photonet>40 && photonet<50))
		{
			weightfake = 0.134771;
		}
		else if( photonet==50 || (photonet>50 && photonet<60))
		{
			weightfake = 0.116279;
		}

		else if ( photonet==60 || (photonet>60 && photonet<70))
		{
			weightfake = 0.115982;
		}

		else if ( photonet==70  || (photonet>70 && photonet<80))
		{
			weightfake = 0.101083;
		}

		else if ( photonet==80  || photonet>80)
		{
			weightfake = 0.0599114;
		}

		else 
		{
			weightfake =  -10;
		}

		demo->Fill(); // cout<<"filled"<<endl;
	//	if(i>300000) break;
	}


	demo->Write();

	f2->Write();
	f2->Close();
	f1->Close();
}
