void n8_drawing_tgrapherro_with_dat()
{
	TString dir = gSystem->UnixPathName(gInterpreter->GetCurrentMacroName());
	dir.ReplaceAll("drawing.C","");
	dir.ReplaceAll("/./","/");

	ifstream vInput;
	vInput.open(Form("%s2016-10-27_14-06-10_LeakageTest-FoilID_111_Short.dat",dir.Data()));

	double *x = new double[1480];
	double *y1 = new double[1480];
	double *y1e = new double[1480];
	double *y2 = new double[1480];
	double *y2e = new double[1480];

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
	vInput.close();

	vC1 = new TCanvas("vC1","Smooth Regression",20,10,1000,700);
	TPad *pad1 = new TPad("pad1","This is pad1",0.02,0.64,0.98,0.96,21);
    TPad *pad2 = new TPad("pad2","This is pad2",0.02,0.32,0.98,0.64,21);
	TPad *pad3 = new TPad("pad3","This is pad3",0.02,0.02,0.98,0.32,21);
	pad1->Draw();
	pad2->Draw();
	pad3->Draw();

	pad1->cd();
	pad1->SetFillColor(0);
	pad1->SetGrid();
	TGraphErrors *gr1 = new TGraphErrors(vNData, x, y1, 0, y1e);
	gr1->SetLineColor(kBlue);
	gr1->SetTitle("Voltage vs time");
	gr1->GetXaxis()->SetTitle("time [second]");
	gr1->GetXaxis()->SetTitleOffset(0.7);
	gr1->GetXaxis()->SetTitleSize(0.07);
	gr1->GetXaxis()->SetLabelSize(0.05);
	gr1->GetYaxis()->SetTitle("Voltage [V]");
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
	gr2->SetLineColor(kRed);
	gr2->SetMarkerStyle(25);
	gr2->SetMarkerSize(0.3);
	gr2->SetMarkerColor(kBlack);
	gr2->SetTitle("current vs time");
    gr2->GetXaxis()->SetTitle("time [second]");
    gr2->GetXaxis()->SetTitleOffset(0.7);
    gr2->GetXaxis()->SetTitleSize(0.07);
    gr2->GetXaxis()->SetLabelSize(0.05);
    gr2->GetYaxis()->SetTitle("Current [#muA]");
    gr2->GetYaxis()->SetTitleSize(0.07);
    gr2->GetYaxis()->SetTitleOffset(0.5);
    gr2->GetYaxis()->SetLabelSize(0.05);	
	gr2->Draw();
	
	pad3->cd();
	pad3->SetFillColor(0);
	pad3->SetGrid();
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
	TGaxis *axis = new TGaxis(0.50,0.02,0.50,0.90,-0.0001, 0.0050, 510, "+L");
//	TGaxis *axis = new TGaxis(8,-0.8,8,0.8,-0.0001,0.005,50510,"+L");
//	TGaxis *axis = new TGaxis(8,-0.8,8,0.8,0,9000,50510,"+L");
	axis->SetLineColor(kRed);
	axis->SetTextColor(kRed);
	axis->Draw();
//	axis->Draw("same");
//	gr2->Draw("same");
	gr2->Draw("same");

}
