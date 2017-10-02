#include <vector>
#include "TH1D.h"
#include <iostream>
#include "TCanvas.h"
#include "TFractionFitter.h"
class n37_fitter
{
	public:
		n37_fitter(vector<TH1D*> vh1, vector<TH1D*> vh2);
		
};


n37_fitter::n37_fitter(vector<TH1D*> vh1, vector<TH1D*> vh2)
{
	Int_t i=0;
//	TCanvas *cv = new TCanvas("cv","cv",600,600);

//	TObjArray *mc = new TObjArray(2);
	for(size_t j=0; j!=vh1.size(); j++)
	{
//		i++;
		TCanvas *cv = new TCanvas("cv","cv",600,600);
		TObjArray *mc = new TObjArray(2);
		mc->Add(vh1.at(j));		//true template from MC
		mc->Add(vh2.at(j));   //fake template from data
		cout<<"error2"<<endl;
		TFractionFitter *fit = new TFractionFitter(vh2.at(j+5), mc);  //Data template
		cout<<"error3"<<endl;
		fit->Constrain(1,0.0,1.0); 
//		fit->SetRangeX(1,15);      //// use only the first 15 bins in the fit
		Int_t status = fit->Fit(); 
		std::cout << "fit status: " << status << std::endl;
		if (status == 0) 
		{
			TH1D* result = (TH1D*) fit->GetPlot();
			vh2.at(j+5)->Draw("Ep");
			result->SetLineColor(kRed);
			result->Draw("same");
		}
		cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!upper, number "<<j+1<<"th plot!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
		cout<<endl<<endl<<endl<<endl;
		if(j==0)  {cv->SaveAs("n37_pta[22,30].pdf"); cv->Clear(); cv->Delete();  cout<<"first"<<endl;}
		else if(j==1)  {cv->SaveAs("n37_pta[30,40].pdf"); cv->Clear(); cv->Delete(); cout<<"sec"<<endl; }
		else if(j==2)  {cv->SaveAs("n37_pta[40,50].pdf"); cv->Clear(); cv->Delete();cout<<"thrid"<<endl;}
		else if(j==3)  {cv->SaveAs("n37_pta[50,75].pdf"); cv->Clear(); cv->Delete();cout<<"forth"<<endl;}
		else if(j==4)  {cv->SaveAs("n37_pta[75,400].pdf"); cv->Clear(); cv->Delete();cout<<"fifth"<<endl;}
		else ;
		mc->Clear();
		fit->Clear();
	}	
}

