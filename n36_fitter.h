#include <vector>
#include "TH1D.h"
#include <iostream>
#include "TCanvas.h"
#include "TFractionFitter.h"
class n36_fitter
{
	public:
		n36_fitter(vector<TH1D*> vh1, vector<TH1D*> vh2);
		

		vector<TObjArray*> vTObjA;

};


n36_fitter::n36_fitter(vector<TH1D*> vh1, vector<TH1D*> vh2)
{
	Int_t i=0;
//	TCanvas *cv = new TCanvas("cv","cv",600,600);

//	TObjArray *mc = new TObjArray(2);
	for(size_t j=0; j!=vh1.size(); j++)
	{
		TCanvas *cv = new TCanvas("cv","cv",600,600);
		i++;
		TObjArray *mc = new TObjArray(2);
		mc->Add(vh1.at(j));		//true template from MC
		mc->Add(vh2.at(j+5));   //fake template from data
		TFractionFitter *fit = new TFractionFitter(vh2.at(j), mc);  //Data template
		fit->Constrain(1,0.0,1.0); 
//		fit->SetRangeX(1,15);      //// use only the first 15 bins in the fit
		Int_t status = fit->Fit(); 
		std::cout << "fit status: " << status << std::endl;
		if (status == 0) 
		{
			TH1D* result = (TH1D*) fit->GetPlot();
			vh2.at(j)->Draw("Ep");
			result->SetLineColor(kRed);
			result->Draw("same");
		}
		cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!upper, number "<<i<<"th plot!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
		cout<<endl<<endl<<endl<<endl;
		if(i==1)  {cv->SaveAs("n36_pta[22,30].pdf"); cv->Clear(); cv->Delete();}
		if(i==2)  {cv->SaveAs("n36_pta[30,40].pdf"); cv->Clear(); cv->Delete();}
		if(i==3)  {cv->SaveAs("n36_pta[40,50].pdf"); cv->Clear(); cv->Delete();}
		if(i==4)  {cv->SaveAs("n36_pta[50,75].pdf"); cv->Clear(); cv->Delete();}
		if(i==5)  {cv->SaveAs("n36_pta[75,400].pdf"); cv->Clear(); cv->Delete();}
		mc->Clear();
	}	
}

