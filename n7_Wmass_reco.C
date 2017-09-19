void n7_Wmass_reco()
{
	gSystem->Load("/Users/junho/Downloads/MG5_aMC_v2_3_3/ExRootAnalysis/libExRootAnalysis.so"); 
	gSystem->Load("/Users/junho/Downloads/root/lib/libPhysics.so");

	TChain chain("LHEF");
	TString IFile = "EWK_LNUJJ.root";
    chain.Add(IFile);
	
	TFile *f = new TFile("n7_Wmass_reco_output.root","RECREATE");
	TH1F *Wmass_h = new TH1F("Wmass_h","Wmass_h",200,40,120);
	TH1F *dijet_M = new TH1F("dijet_M","dijet_M",200,0,2000);

	TLorentzVector lep, nu, Wparticle;
	TLorentzVector jet1, jet2, jet;
	double lep_pt, lep_eta, lep_phi, lep_e;
	double nu_pt, nu_eta, nu_phi, nu_e;
	double jet_pt, jet_eta, jet_phi, jet_e;
	int ii, jj, ll1, ll2;
	int kk=0;
	int kkk;
	int kkkk;
	double Wmass;
	double Mjj;

	ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
	Long64_t numberOfEntries = treeReader->GetEntries();

	TClonesArray *branchEvent = treeReader->UseBranch("Event");
	TClonesArray *branchParticle = treeReader->UseBranch("Particle");
	TClonesArray *branchRwgt = treeReader->UseBranch("Rwgt");
	cout<<numberOfEntries<<endl;

	for(int count=0; count < numberOfEntries; count++)
	{
		treeReader->ReadEntry(count) ;
		TRootLHEFEvent *event=(TRootLHEFEvent*) branchEvent->At(0);
		lep_pt = -100; lep_eta=-100; lep_phi=-100; lep_e=-100;
		nu_pt = -100;  nu_eta=-100;  nu_phi=-100;  nu_e=-100;
		ii=0;
		jj=0;
		Wmass = -10;
		Mjj=-10;
		kkk=0;
		kkkk=0;
		ll1=0, ll2=0;
		jet1.SetPtEtaPhiE(-10,-10,-10,-10);
		jet2.SetPtEtaPhiE(-10,-10,-10,-10);

		if(count%1000==0)  cout<<"looping events = "<<count<<endl;

		for(int i=0;i<event->Nparticles;i++)
		{
			TRootLHEFParticle *ppw=(TRootLHEFParticle*) branchParticle->At(i);
			if(ppw->Status != 1) continue;
			if(((ppw->PID)-11)==0 || ((ppw->PID)+11)==0 || ((ppw->PID)-13)==0 || ((ppw->PID)+13)==0 || ((ppw->PID)-15)==0 || ((ppw->PID)+15)==0 )
			{
				lep_pt=ppw->PT; lep_eta=ppw->Eta; lep_phi=ppw->Phi; lep_e=ppw->E;
				if(lep_pt>0)
				{
					lep.SetPtEtaPhiE(lep_pt,lep_eta,lep_phi,lep_e);
					ii++;
				}
			}

			if(((ppw->PID)-12)==0 || ((ppw->PID)+12)==0 || ((ppw->PID)-14)==0 || ((ppw->PID)+14)==0 || ((ppw->PID)-16)==0 || ((ppw->PID)+16)==0 )
			{
				nu_pt=ppw->PT; nu_eta=ppw->Eta; nu_phi=ppw->Phi; nu_e=ppw->E;
				if(nu_pt>0)
				{
					nu.SetPtEtaPhiE(nu_pt,nu_eta,nu_phi,nu_e);
					jj++;
				}
			}

			 if((i==6)  && ((ppw->PID))==1 || (ppw->PID)==2 || (ppw->PID)==-1 || (ppw->PID)==-2 || (ppw->PID)==3 ||  (ppw->PID)==-3 ||  (ppw->PID)==-4 ||  (ppw->PID)==4 ||  (ppw->PID)==-5 ||  (ppw->PID)==5 ||  (ppw->PID)==-6 ||  (ppw->PID)==6)
			{
			        jet_pt = ppw->PT; jet_eta = ppw->Eta; jet_phi = ppw->Phi; jet_e = ppw->E;
			        if(jet_pt>0)
                    {
	                     jet1.SetPtEtaPhiE(jet_pt, jet_eta, jet_phi, jet_e);
	                     ll1++;
	                 //  cout<<"!!! jet event 1  !!!"<<endl;
	                }
             }

			 if((i==7)  && ((ppw->PID))==1 || (ppw->PID)==2 || (ppw->PID)==-1 || (ppw->PID)==-2 || (ppw->PID)==3 ||  (ppw->PID)==-3 ||  (ppw->PID)==-4 ||  (ppw->PID)==4 ||  (ppw->PID)==-5 ||  (ppw->PID)==5 ||  (ppw->PID)==-6 ||  (ppw->PID)==6)
              {
	                  jet_pt=0;
	                  jet_pt = ppw->PT; jet_eta = ppw->Eta; jet_phi = ppw->Phi; jet_e = ppw->E;
	                  if(jet_pt>0)
	                  {
	                      jet2.SetPtEtaPhiE(jet_pt, jet_eta, jet_phi, jet_e);
	                      ll2++;
		                  //  cout<<"!!! jet event 2   !!!"<<endl;
	                  }
               }

 			if(ll1==1 && ll2==1 && kkkk==0)
			{
					jet = jet1+jet2;
					Mjj=jet.M();
					dijet_M->Fill(Mjj);
					kkkk++;
			}



	
			if(ii==1 && jj==1 && kkk==0)
			{
				Wparticle = lep + nu;
				Wmass = Wparticle.M();
				Wmass_h->Fill(Wmass);
				kk++;
				kkk++;
			}
		}
	}
	cout<<"W particle event entry = "<<kk<<endl;
	Wmass_h->Write();
	dijet_M->Write();
	f->Close();

}
