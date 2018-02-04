void fitting() 
{
	gStyle->SetOptFit();
//    ifstream infile("2016-10-27_14-06-10_LeakageTest-FoilID_111_Short.dat");
  	ifstream infile("2016-10-21_09-13-26_LeakageTest-FoilID_103_Long.txt");
  	int n=0;
    char str[10000];
    while(!infile.eof())
	{
       infile.getline(str, sizeof(str));
       n++;
    }
    cout<<n<<endl;	


	TString dir = gSystem->UnixPathName(gInterpreter->GetCurrentMacroName());
	dir.ReplaceAll("fitting.C","");
	dir.ReplaceAll("/./","/");

	ifstream vInput;
//	vInput.open(Form("%s2016-10-27_14-06-10_LeakageTest-FoilID_111_Short.dat",dir.Data()));
//	vInput.open(Form("%s",dir.Data())+TString());
	vInput.open(Form("%s2016-10-21_09-13-26_LeakageTest-FoilID_103_Long.txt",dir.Data()));

	double *x = new double[n];
	double *y1 = new double[n];
	double *y1e = new double[n];
	double *y2 = new double[n];
	double *y2e = new double[n];

	double vx, vy1, vy1e, vy2, vy2e;
	int vNData = 0;

	while (1){
		vInput >> vx >> vy1 >> vy1e >> vy2 >> vy2e;
		if (!vInput.good()) break;
		x[vNData] = vx;
		y1[vNData] = vy1;
		y1e[vNData] = vy1e;
		y2[vNData] = vy2;
		y2e[vNData]	= vy2e;
		vNData++;
		
	}
	cout<<vNData<<endl;

	int jjj=0;
	int iii=0;
	double xs, xe;
	xs=0; xe=0;
	for(Int_t jj=0; jj<vNData; jj++)
	{
		if(y1[jj]>595 && jjj==0)
		{
			xs = x[jj];
			jjj++;
		}
		if(y1[jj]<550 && jjj==1)
		{
			xe = x[jj];
			jjj--;
			iii++;
		}
		if( (xe-xs) > 1195 && iii==1 )
		{
			iii--;
			break;
		}
		if((xe-xs)< 1195 && iii==1)
		{
			jjj=0;
			xs=0;
			xe=0;
			iii=0;
		}
		else continue;

	}
	cout<<endl;
	if((xe-xs) <1190) cout<<"no 1200s flat voltage found"<<endl<<endl;

	xs = xs + 10;
	xe = xe - 10;

//	cout<<"x starting point = "<<xs<<endl;
//	cout<<"x ending point = "<<xe<<endl;

	vInput.close();

	TCanvas *vC1 = new TCanvas("vC1","Smooth Regression",20,10,1000,700);
	TGraph *gr2 = new TGraph(vNData, x, y2);
	gr2->SetMaximum(0.0050);
	gr2->SetMinimum(-0.0001);
	gr2->SetLineColor(kGreen);
	gr2->SetMarkerStyle(25);
	gr2->SetMarkerSize(0.3);
	gr2->SetMarkerColor(kBlack);
	gr2->SetTitle("current vs time");
    gr2->GetXaxis()->SetTitle("Time [Sec]");
    gr2->GetXaxis()->SetTitleOffset(1.0);
    gr2->GetXaxis()->SetTitleSize(0.03);
    gr2->GetXaxis()->SetLabelSize(0.03);
    gr2->GetYaxis()->SetTitle("Curr [microA]");
    gr2->GetYaxis()->SetTitleSize(0.03);
    gr2->GetYaxis()->SetTitleOffset(1.5);
    gr2->GetYaxis()->SetLabelSize(0.03);	
	gr2->Draw();
//	gr2->Fit("expo ","","",xs,xe);
	gr2->Fit("pol5","","",xs,xe);	

	TPaveStats *stats1 = (TPaveStats*)gr2->GetListOfFunctions()->FindObject("stats");
	stats1->SetTextColor(kRed);
	stats1->SetX1NDC(0.12); stats1->SetX2NDC(0.32); stats1->SetY1NDC(0.75);
//	stats1->Draw("same");
	vC1->Modified();


}
