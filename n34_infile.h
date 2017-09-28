#include "TFile.h"
//#include "TH1D.h"
#include <iostream>
#include "TTree.h"
#include <vector>

class n34_infile
{
public:
	//functions
	n34_infile(TFile* file);
//	TH1D* gethisto();
//	TH1D* gethisto_f();
	vector<Int_t> inte();
	vector<TH1D*> gethisto();
	Int_t getentrynum(TTree* t)
	{
		return t->GetEntries();
	}
	void Clear();
	void setdummy();

	//variables
	TFile* file_;
	TTree *t = NULL;
	double photonsieie;
	double photonsieie_f;
	int lep ;
	int nlooseeles;
	int nloosemus;
	int HLT_Mu3;
	double ptlep1;
	double etalep1;
	double philep1;
	double MET_et;
	double mtVlepJECnew;
	double photonet;
	double photonet_f;
	double photoneta;
	double photoneta_f;
	double jet1pt;
	double jet1pt_f;
	double jet2pt;
	double jet2pt_f;
	double jet1eta;
	double jet1eta_f;
	double jet2eta;
	double jet2eta_f;

	double photon_hoe[6];
	double photon_sieie[6];
	double photon_chiso[6];
	double photon_phoiso[6];
	double photon_nhiso[6];
	double photon_pt[6];
	double photon_eta[6];
	double photon_phi[6];
	int iphoton;
	int iphoton_f;
	bool photon_ppsv[6];
	bool photon_iseb[6];	

	int nentries;
	vector<TH1D*> vh;
	TH1D* h = new TH1D("tight_pho","tight_pho",100,0.0,0.035);
	TH1D* h1 = new TH1D("tight_pho_with_pta_etaa","tight_pho_with_pta_etaa",100,0.0,0.08);
	TH1D* h2 = new TH1D("PLJ_pta22","PLJ_pta22",100,0.0,0.08);
	TH1D *h3 = new TH1D("PTJ_pta22_jet","PTJ_pta22_jet",100,0.0,0.08);
	vector<Int_t> integral;
};

n34_infile::n34_infile(TFile *file)
{
	file_ =file;
	t = (TTree*)file_->Get("demo");
	t->SetBranchAddress("photonsieie",&photonsieie);
	t->SetBranchAddress("photonsieie_f",&photonsieie_f);
	t->SetBranchAddress("lep",&lep);
	t->SetBranchAddress("nlooseeles",&nlooseeles);
	t->SetBranchAddress("nloosemus",&nloosemus);
	t->SetBranchAddress("HLT_Mu3",&HLT_Mu3);
	t->SetBranchAddress("ptlep1",&ptlep1);
	t->SetBranchAddress("etalep1",&etalep1);
	t->SetBranchAddress("philep1",&philep1);
	t->SetBranchAddress("MET_et",&MET_et);
	t->SetBranchAddress("mtVlepJECnew",&mtVlepJECnew);
	t->SetBranchAddress("photonet",&photonet);
	t->SetBranchAddress("photonet_f",&photonet_f);
	t->SetBranchAddress("photoneta",&photoneta);
	t->SetBranchAddress("photoneta_f",&photoneta_f);
	t->SetBranchAddress("jet1pt",&jet1pt);
	t->SetBranchAddress("jet1pt_f",&jet1pt_f);
	t->SetBranchAddress("jet2pt",&jet2pt);
	t->SetBranchAddress("jet2pt_f",&jet2pt_f);
	t->SetBranchAddress("jet1eta",&jet1eta);
	t->SetBranchAddress("jet1eta_f",&jet1eta_f);
	t->SetBranchAddress("jet2eta",&jet2eta);
	t->SetBranchAddress("jet2eta_f",&jet2eta_f);
	t->SetBranchAddress("photon_sieie",&photon_sieie);
    t->SetBranchAddress("photon_pt",&photon_pt);
    t->SetBranchAddress("photon_hoe",&photon_hoe);
    t->SetBranchAddress("photon_chiso",&photon_chiso);
    t->SetBranchAddress("photon_nhiso",&photon_nhiso);
    t->SetBranchAddress("photon_phoiso",&photon_phoiso);
	t->SetBranchAddress("photon_eta",&photon_eta);
	t->SetBranchAddress("photon_phi",&photon_phi);
    t->SetBranchAddress("photon_ppsv",&photon_ppsv);
    t->SetBranchAddress("photon_iseb",&photon_iseb);	
	nentries = getentrynum(t);	
	cout<<"total entry = "<<nentries<<endl;

}

void n34_infile::setdummy()
{
	photonsieie=-1e1;
    photonsieie_f =-1e1;
    lep =-1e1;
    nlooseeles = -1e1;
    nloosemus = -1e1;
    HLT_Mu3 = -1e1;
    ptlep1 =-1e1;
    etalep1 = -1e1;
	philep1 = -1e1;
    MET_et = -1e1;
    mtVlepJECnew =-1e1;
    photonet=-1e1;
    photonet_f=-1e1;
    photoneta =-1e1;
    photoneta_f=-1e1;
    jet1pt =-1e1;
    jet1pt_f=-1e1;
    jet2pt =-1e1;
    jet2pt_f=-1e1;
    jet1eta = -1e1;
    jet1eta_f=-1e1;
    jet2eta = -1e1;
    jet2eta_f=-1e1;
	iphoton = -1;
    iphoton_f =-1;

	for(size_t i =0; i<6; i++)
	{
		photon_hoe[i]=-1e1;
	    photon_sieie[i]=-1e1;
	    photon_chiso[i]=-1e1;
	    photon_phoiso[i]=-1e1;
	    photon_nhiso[i]=-1e1;
	    photon_eta[i] = -1e1;
		photon_phi[i] = -1e1;
		photon_pt[i]=-1e1;
		photon_ppsv[i]=0;
    	photon_iseb[i]=0;		
	}

}


vector<TH1D*> n34_infile::gethisto()
{
    double perc=0;
    int is_medi;
	int i, ipp;
	double pet;	
	for(Long64_t d_ii=0; d_ii<nentries; d_ii++)
    {	
		is_medi = 0;
        i = 0;
		ipp = -1;
		pet = -1e1;
		if(d_ii%300000==0) 
        {   
			perc=double(d_ii*100/nentries);    cout<<"now looping "<<d_ii<<" th event"<<"  total event num "<<nentries;  cout<<"  finished "<<perc<<"%"<<endl;
        }
//        if(d_ii == 600000) break;
		t->GetEntry(d_ii);
        for(size_t ip =0; ip<6; ip++)
		{
			if(photon_ppsv[ip] && photon_iseb[ip] && photon_hoe[ip]<0.0396 && photon_chiso[ip]<0.441 && photon_nhiso[ip]<(2.725+(0.0148*photon_pt[ip]+0.000017*photon_pt[ip]*photon_pt[ip])) && photon_phoiso[ip]<(2.571+0.0047*photon_pt[ip])) {is_medi = 0; i++;}
			else continue;
			if(i==1) { pet = photon_pt[ip]; ipp = ip;}
			else ;
			
			if(is_medi && i!=1 && sqrt((photon_eta[ipp]-etalep1)*(photon_eta[ipp]-etalep1)+(photon_phi[ipp]-philep1)*(photon_phi[ipp]-philep1) ) > 0.7  )
			{	
				if(photon_pt[ip]>pet) ipp = ip;
			}

		}
		if(ipp>=0 ) 
		{
			h->Fill(photon_sieie[ipp]);
			if(photon_pt[ipp] >22 && photon_eta[ipp]<1.44) h1->Fill(photon_sieie[ipp]);
		}
		//if(photonsieie != -10 && lep ==13 && nlooseeles==0 && nloosemus<2 && HLT_Mu3 ==1 && ptlep1>25 && fabs(etalep1)<2.1 && MET_et>20 && mtVlepJECnew>30 && photonet>22 && fabs(photoneta)<1.44 && jet1pt>20 && jet2pt>20 && fabs(jet1eta)<4.7 && fabs(jet2eta)<4.7 ) h->Fill(photonsieie);



		if(photonsieie_f != -10 && lep ==13 && nlooseeles==0 && nloosemus<2 && HLT_Mu3 ==1 && ptlep1>25 && fabs(etalep1)<2.1 && MET_et>20 && mtVlepJECnew>30 && fabs(photoneta_f)<1.44 && photonet_f>22 ) h2->Fill(photonsieie_f);


		if(photonsieie_f != -10 && lep ==13 && nlooseeles==0 && nloosemus<2 && HLT_Mu3 ==1 && ptlep1>25 && fabs(etalep1)<2.1 && MET_et>20 && mtVlepJECnew>30 && fabs(photoneta_f)<1.44 && photonet_f>22 && jet1pt>40 && jet2pt>30 && fabs(jet1eta)<4.7 && fabs(jet2eta)<4.7 ) h3->Fill(photonsieie_f);	



	}
	h->SetXTitle("#sigmai#etai#eta");
	h1->SetXTitle("#sigmai#etai#eta");
	h2->SetXTitle("#sigmai#etai#eta");
	h3->SetXTitle("#sigmai#etai#eta");
 	vh.push_back(h);
	vh.push_back(h1);	
    vh.push_back(h2);
	vh.push_back(h3);
	return vh;
}

vector<Int_t> n34_infile::inte()
{
	Int_t num;
	for(size_t i = 0; i!= vh.size(); i++)
	{	
		num=(vh.at(i))->Integral();
		integral.push_back(num);		
	}
	return integral;
}

void n34_infile::Clear()
{
	h->Clear();
	h1->Clear();
	h2->Clear();
	h3->Clear();
	vh.clear();	
	integral.clear();

}
