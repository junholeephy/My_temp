void drawing() 
{
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
	dir.ReplaceAll("drawing.C","");
	dir.ReplaceAll("/./","/");

	ifstream vInput;
//	vInput.open(Form("%s2016-10-27_14-06-10_LeakageTest-FoilID_111_Short.dat",dir.Data()));
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
/*
	for(Int_t jj=0; jj<vNData; jj++)
	{

cout<<x[jj]<<endl;
    cout<<y1[jj]<<endl;
	    cout<<jj<<endl;
	}*/
	vInput.close();

	vC1 = new TCanvas("vC1","Smooth Regression",20,10,1000,700);
	TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.98,0.48,21);
    TPad *pad2 = new TPad("pad2","This is pad2",0.02,0.52,0.98,0.98,21);
	//TPad *pad3 = new TPad("pad3","This is pad3",0.02,0.02,0.98,0.32,21);
	pad1->Draw();
	pad2->Draw();
//	pad3->Draw();

	pad1->cd();
	pad1->SetFillColor(0);
	pad1->SetGrid();
	TGraphErrors *gr1 = new TGraphErrors(vNData, x, y1, 0, y1e);
	gr1->SetLineColor(kBlue);
	gr1->SetTitle("Voltage vs time");
	gr1->GetXaxis()->SetTitle("Time [Sec]");
	gr1->GetXaxis()->SetTitleOffset(0.7);
	gr1->GetXaxis()->SetTitleSize(0.07);
	gr1->GetXaxis()->SetLabelSize(0.05);
	gr1->GetYaxis()->SetTitle("HV [Volt]");
	gr1->GetYaxis()->SetTitleSize(0.07);
	gr1->GetYaxis()->SetTitleOffset(0.5);
	gr1->GetYaxis()->SetLabelSize(0.05);
	gr1->Draw();

	pad2->cd();
	pad2->SetFillColor(0);
//	pad2->SetGrid();
	TGraphErrors *gr2 = new TGraphErrors(vNData, x, y2, 0, y2e);
	gr2->SetMaximum(0.0050);
	gr2->SetMinimum(-0.0001);
	gr2->SetLineColor(kGreen);
	gr2->SetMarkerStyle(25);
	gr2->SetMarkerSize(0.3);
	gr2->SetMarkerColor(kBlack);
	gr2->SetTitle("current vs time");
    gr2->GetXaxis()->SetTitle("Time [Sec]");
    gr2->GetXaxis()->SetTitleOffset(0.7);
    gr2->GetXaxis()->SetTitleSize(0.07);
    gr2->GetXaxis()->SetLabelSize(0.05);
    gr2->GetYaxis()->SetTitle("Curr [microA]");
    gr2->GetYaxis()->SetTitleSize(0.07);
    gr2->GetYaxis()->SetTitleOffset(0.5);
    gr2->GetYaxis()->SetLabelSize(0.05);	
//	gr2->Fit("pol5","","",1300,3000);
	gr2->Draw();
	gr2->Fit("expo","","",1550,2750);
	/*	
	pad3->cd();
	pad3->SetFillColor(0);
	pad3->SetGrid();

	TH1F *hr = pad3->DrawFrame(-0.4,0,1.2,12);
	hr->SetXTitle("X title");
	hr->SetYTitle("Y title");
	pad3->GetFrame()->SetFillColor(21);	
	pad3->GetFrame()->SetBorderSize(12);
	
	gr1->Draw("LP");
*/




//	gr1->Draw();
//	float rightmax = 1.1*gr2->GetMaximum();
//	float scale = gPad->GetUymax()/rightmax;
//	gr2->Draw();	
//	gr2->Scale(scale);
	//TGaxis *axis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),gPad->GetUxmax(), gPad->GetUymax(),0,rightmax,510,"+L");
   	//axis->SetLineColor(kRed);
    //axis->SetTextColor(kRed);
	//axis->Draw();
//	TGaxis *axis = new TGaxis(0.90,0.02,0.90,0.90,-0.0001, 0.0050, 510, "+L");
//	TGaxis *axis = new TGaxis(0.50,0.02,0.50,0.90,-0.0001, 0.0050, 510, "+L");
//	TGaxis *axis = new TGaxis(8,-0.8,8,0.8,-0.0001,0.005,50510,"+L");
//	TGaxis *axis = new TGaxis(8,-0.8,8,0.8,0,9000,50510,"+L");
//	axis->SetLineColor(kRed);
//	axis->SetTextColor(kRed);
//	axis->Draw();
//	axis->Draw("same");
//	gr2->Draw("same");
//	gr2->Draw("same");

}
