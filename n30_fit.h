#include "TH1D.h"
#include <iostream>
#include "TROOT.h"
#include "TSystem.h"

class n30_fit
{
	public:
		//functions
		n30_fit(TH1D* h);


		//variables
		TH1D *hh = new TH1D("hh","hh",100,0,150);
};

n30_fit::n30_fit(TH1D *h)
{
	h->Fit("gaus");
	h->Draw();	

}
