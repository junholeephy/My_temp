#include "TFile.h"
//#include "TH1D.h"
#include <iostream>
#include "TTree.h"
#include <vector>

class n36_infile
{
public:
	//functions
	n36_infile(TFile* file);
//	TH1D* gethisto();
//	TH1D* gethisto_f();
	vector<Int_t> inte();
	vector<TH1D*> gethisto();
	vector<TH1D*> gethistoDATA();
	vector<TH1D*> gethistoMC_T();
	Int_t getentrynum(TTree* t)
	{
		return t->GetEntries();
	}
	void Clear();
	void ClearMC();
	void ClearDATA();
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
//	TH1D* h = new TH1D("tight_pho_etaa","tight_pho_etaa",100,0.0,0.02);
//	TH1D* h1 = new TH1D("tight_pho_with_pta_etaa","tight_pho_with_pta_etaa",100,0.0,0.02);
//	TH1D* h2 = new TH1D("tight_pho_with_pta_etaa_jet","tight_pho_with_pta_etaa_jet",100,0.0,0.02);
//	TH1D* h3 = new TH1D("PLJ_etaa","PLJ_etaa",100,0.0,0.02);
//	TH1D *h4 = new TH1D("PTJ_pta_etaa","PTJ_pta_etaa",100,0.0,0.02);
//	TH1D *h5 = new TH1D("PTJ_pta_etaa_jet","PTJ_pta_etaa_jet",100,0.0,0.02);
	
	TH1D *hMC1 = new TH1D("hMC1","pta [22,30]",50,0.0,0.025);
	TH1D *hMC2 = new TH1D("hMC2","pta [30,40]",50,0.0,0.025);
	TH1D *hMC3 = new TH1D("hMC3","pta [40,50]",50,0.0,0.025);
	TH1D *hMC4 = new TH1D("hMC4","pta [50,75]",50,0.0,0.025);
	TH1D *hMC5 = new TH1D("hMC5","pta [75,400]",50,0.0,0.025);
//	TH1D *hMC6 = new TH1D("hMC6","pta [120,400]",50,0.0,0.025);

	TH1D *hDATA_T1 = new TH1D("hDATA_T1","pta [22,30]",50,0.0,0.025);
	TH1D *hDATA_T2 = new TH1D("hDATA_T2","pta [30,40]",50,0.0,0.025);
	TH1D *hDATA_T3 = new TH1D("hDATA_T3","pta [40,50]",50,0.0,0.025);
	TH1D *hDATA_T4 = new TH1D("hDATA_T4","pta [50,75]",50,0.0,0.025);
	TH1D *hDATA_T5 = new TH1D("hDATA_T5","pta [75,400]",50,0.0,0.025);
//	TH1D *hDATA_T6 = new TH1D("hDATA_T6","pta [120,400]",50,0.0,0.025);

	TH1D *hDATA_F1 = new TH1D("hDATA_F1","pta [22,30]",50,0.0,0.025);
	TH1D *hDATA_F2 = new TH1D("hDATA_F2","pta [30,40]",50,0.0,0.025);
	TH1D *hDATA_F3 = new TH1D("hDATA_F3","pta [40,50]",50,0.0,0.025);
	TH1D *hDATA_F4 = new TH1D("hDATA_F4","pta [50,75]",50,0.0,0.025);
	TH1D *hDATA_F5 = new TH1D("hDATA_F5","pta [75,400]",50,0.0,0.025);
//	TH1D *hDATA_F6 = new TH1D("hDATA_F6","pta [120,400]",50,0.0,0.025);

	vector<Int_t> integral;
};

n36_infile::n36_infile(TFile *file)
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

void n36_infile::setdummy()
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

vector<TH1D*> n36_infile::gethistoDATA()
{
	double perc=0;
	int is_medi;
	int i, ipp;
	double pet;
	for(Long64_t d_ii=0; d_ii<nentries; d_ii++)
	{
//		if(d_ii==30000001) break;   ////////////////FIXME
		is_medi = 0;	i = 0;	ipp = -1;	pet = -1e1;
		if(d_ii%300000==0)
		{perc=double(d_ii*100/nentries);    cout<<"now looping "<<d_ii<<" th event"<<"  total event num "<<nentries;  cout<<"  finished "<<perc<<"%"<<endl;}
		t->GetEntry(d_ii);
		for(size_t ip =0; ip<6; ip++)
		{
			if(photon_ppsv[ip] && photon_iseb[ip] && photon_hoe[ip]<0.0396 && photon_chiso[ip]<0.441 && photon_nhiso[ip]<(2.725+(0.0148*photon_pt[ip]+0.000017*photon_pt[ip]*photon_pt[ip])) && photon_phoiso[ip]<(2.571+0.0047*photon_pt[ip])) {is_medi = 0; i++;}
			else continue;
			if(i==1) { pet = photon_pt[ip]; ipp = ip;}
			else ;
			if(is_medi && i!=1 && sqrt((photon_eta[ipp]-etalep1)*(photon_eta[ipp]-etalep1)+(photon_phi[ipp]-philep1)*(photon_phi[ipp]-philep1) ) > 0.7 && photon_eta[ipp]<1.4442 )
			{
				if(photon_pt[ip]>pet) ipp = ip;
			}
		}
		if(ipp>=0 )
		{
			if(photon_pt[ipp] >22 && photon_eta[ipp]<1.4442)
			{
					if(photon_pt[ipp]>=22 && photon_pt[ipp]<30) hDATA_T1->Fill(photon_sieie[ipp]);
					else if(photon_pt[ipp]>=30 && photon_pt[ipp]<40) hDATA_T2->Fill(photon_sieie[ipp]);
					else if(photon_pt[ipp]>=40 && photon_pt[ipp]<50) hDATA_T3->Fill(photon_sieie[ipp]);
					else if(photon_pt[ipp]>=50 && photon_pt[ipp]<75) hDATA_T4->Fill(photon_sieie[ipp]);
					else if(photon_pt[ipp]>=75 && photon_pt[ipp]<400) hDATA_T5->Fill(photon_sieie[ipp]);
//					else if(photon_pt[ipp]>=120 && photon_pt[ipp]<400) hDATA_T6->Fill(photon_sieie[ipp]);
					else;
			}
		}
	
		if(photonsieie_f != -10 && lep ==13 && nlooseeles==0 && nloosemus<2 && HLT_Mu3 ==1 && ptlep1>25 && fabs(etalep1)<2.1 && MET_et>20 && mtVlepJECnew>30 && fabs(photoneta_f)<1.4442 && photonet_f>22 ) 
		{
			if(photonet_f>=22 && photonet_f<30 )  hDATA_F1->Fill(photonsieie_f);
			else if(photonet_f>=30 && photonet_f<40 )  hDATA_F2->Fill(photonsieie_f);
			else if(photonet_f>=40 && photonet_f<50 )  hDATA_F3->Fill(photonsieie_f);
			else if(photonet_f>=50 && photonet_f<75 )  hDATA_F4->Fill(photonsieie_f);
			else if(photonet_f>=75 && photonet_f<400 )  hDATA_F5->Fill(photonsieie_f);
	//		else if(photonet_f>=120 && photonet_f<400 )  hDATA_F6->Fill(photonsieie_f);
			else ;
		}	
	}
    hDATA_T1->SetXTitle("#sigmai#etai#eta");
    hDATA_T2->SetXTitle("#sigmai#etai#eta");
    hDATA_T3->SetXTitle("#sigmai#etai#eta");
    hDATA_T4->SetXTitle("#sigmai#etai#eta");
    hDATA_T5->SetXTitle("#sigmai#etai#eta");
//    hDATA_T6->SetXTitle("#sigmai#etai#eta");
    hDATA_F1->SetXTitle("#sigmai#etai#eta");
    hDATA_F2->SetXTitle("#sigmai#etai#eta");
    hDATA_F3->SetXTitle("#sigmai#etai#eta");
    hDATA_F4->SetXTitle("#sigmai#etai#eta");
    hDATA_F5->SetXTitle("#sigmai#etai#eta");
//    hDATA_F6->SetXTitle("#sigmai#etai#eta");

	vh.push_back(hDATA_T1);
    vh.push_back(hDATA_T2);
    vh.push_back(hDATA_T3);
    vh.push_back(hDATA_T4);
    vh.push_back(hDATA_T5);
   // vh.push_back(hDATA_T6);
    vh.push_back(hDATA_F1);
    vh.push_back(hDATA_F2);
    vh.push_back(hDATA_F3);
    vh.push_back(hDATA_F4);
    vh.push_back(hDATA_F5);
 //   vh.push_back(hDATA_F6);
    return vh;	

}


vector<TH1D*> n36_infile::gethistoMC_T()
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
//		if(d_ii==3000001) break;   //////FIXME
		if(d_ii%1000000==0)
		{
			perc=double(d_ii*100/nentries);    cout<<"now looping "<<d_ii<<" th event"<<"  total event num "<<nentries;  cout<<"  finished "<<perc<<"%"<<endl;
		}
		t->GetEntry(d_ii);
		for(size_t ip =0; ip<6; ip++)
		{
			if(photon_ppsv[ip] && photon_iseb[ip] && photon_hoe[ip]<0.0396 && photon_chiso[ip]<0.441 && photon_nhiso[ip]<(2.725+(0.0148*photon_pt[ip]+0.000017*photon_pt[ip]*photon_pt[ip])) && photon_phoiso[ip]<(2.571+0.0047*photon_pt[ip])) {is_medi = 0; i++;}
			else continue;
			if(i==1) { pet = photon_pt[ip]; ipp = ip;}
			else ;
			if(is_medi && i!=1 && sqrt((photon_eta[ipp]-etalep1)*(photon_eta[ipp]-etalep1)+(photon_phi[ipp]-philep1)*(photon_phi[ipp]-philep1) ) > 0.7 && photon_eta[ipp]<1.4442 )
			{
				if(photon_pt[ip]>pet) ipp = ip;
			}
		}
		if(ipp>=0 )
		{
			if(photon_pt[ipp] >22 && photon_eta[ipp]<1.4442)
			{
				if(photon_pt[ipp]>=22 && photon_pt[ipp]<30)	hMC1->Fill(photon_sieie[ipp]);
				else if(photon_pt[ipp]>=30 && photon_pt[ipp]<40) hMC2->Fill(photon_sieie[ipp]);
				else if(photon_pt[ipp]>=40 && photon_pt[ipp]<50) hMC3->Fill(photon_sieie[ipp]);
				else if(photon_pt[ipp]>=50 && photon_pt[ipp]<75) hMC4->Fill(photon_sieie[ipp]);
				else if(photon_pt[ipp]>=75 && photon_pt[ipp]<400) hMC5->Fill(photon_sieie[ipp]);
//				else if(photon_pt[ipp]>=120 && photon_pt[ipp]<400) hMC6->Fill(photon_sieie[ipp]);
				else ;
			}
		}
	}
    hMC1->SetXTitle("#sigmai#etai#eta");
    hMC2->SetXTitle("#sigmai#etai#eta");
    hMC3->SetXTitle("#sigmai#etai#eta");
    hMC4->SetXTitle("#sigmai#etai#eta");
    hMC5->SetXTitle("#sigmai#etai#eta");
 //   hMC6->SetXTitle("#sigmai#etai#eta");
    vh.push_back(hMC1);
    vh.push_back(hMC2);
    vh.push_back(hMC3);
    vh.push_back(hMC4);
    vh.push_back(hMC5);
 //   vh.push_back(hMC6);
    return vh;
}



vector<Int_t> n36_infile::inte()
{
	Int_t num;
	for(size_t i = 0; i!= vh.size(); i++)
	{	
		num=(vh.at(i))->Integral();
		integral.push_back(num);		
	}
	return integral;
}
/*
void n36_infile::Clear()
{
	h->Clear();
	h1->Clear();
	h2->Clear();
	h3->Clear();
	h4->Clear();
	h5->Clear();
	vh.clear();	
	integral.clear();
}
*/
void n36_infile::ClearMC()
{
	hMC1->Clear();
	hMC2->Clear();
	hMC3->Clear();
	hMC4->Clear();
	hMC5->Clear();
//	hMC6->Clear();
	vh.clear();
	integral.clear();
}

void n36_infile::ClearDATA()
{
	hDATA_T1->Clear();
	hDATA_T2->Clear();
	hDATA_T3->Clear();
	hDATA_T4->Clear();
	hDATA_T5->Clear();
//	hDATA_T6->Clear();
	hDATA_F1->Clear();
	hDATA_F2->Clear();
	hDATA_F3->Clear();
	hDATA_F4->Clear();
	hDATA_F5->Clear();
//	hDATA_F6->Clear();
	vh.clear();
	integral.clear();
}






