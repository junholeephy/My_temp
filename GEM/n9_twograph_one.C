// three points need to changed on each specific data.txt file 
// ifstream infile("~~~");
// vInput.open(Form("~~~",dir.Data()));
// c1->SaveAs("~~~.pdf");

void n9_twograph_one()
{
//    ifstream infile("2016-10-27_14-06-10_LeakageTest-FoilID_111_Short.dat");
//	ifstream infile("2016-10-21_09-13-26_LeakageTest-FoilID_103_Long.txt");
//	ifstream infile("2016-10-31_19-57-45_LeakageTest-FoilID_40_Short.txt");
//	ifstream infile("2016-11-01_08-41-41_LeakageTest-FoilID_36_Short.txt");
//	ifstream infile("2016-11-01_09-05-52_LeakageTest-FoilID_36_Short.txt");
//	ifstream infile("2016-11-01_20-28-29_LeakageTest-FoilID_36_Short.txt");
//	ifstream infile("2016-11-02_13-58-56_LeakageTest-FoilID_44_Short.txt");
//	ifstream infile("2016-11-03_14-03-03_LeakageTest-FoilID_103_Short.txt");
//	ifstream infile("2016-11-03_18-37-00_LeakageTest-FoilID_103_Short.txt");
//	ifstream infile("2016-11-05_17-25-09_LeakageTest-FoilID_103_Short.txt");
//	ifstream infile("2016-11-07_08-48-40_LeakageTest-FoilID_105_Short.txt");
	ifstream infile("2016-09-11_20-32-35_LeakageTest-FoilID_85_Short.txt");
//	ifstream infile("2016-10-28_12-07-21_LeakageTest-FoilID_103_Long.txt");

	int n=0;
    char str[10000];
    while(!infile.eof())
	    {
	         infile.getline(str, sizeof(str));
			 n++;
		}
    cout<<n<<endl;	
	

	TString dir = gSystem->UnixPathName(gInterpreter->GetCurrentMacroName());
    dir.ReplaceAll("n9_twograph_one.C","");
    dir.ReplaceAll("/./","/");

    ifstream vInput;
//    vInput.open(Form("%s2016-10-27_14-06-10_LeakageTest-FoilID_111_Short.dat",dir.Data()));
//	vInput.open(Form("2016-10-21_09-13-26_LeakageTest-FoilID_103_Long.txt",dir.Data()));
//	vInput.open(Form("2016-10-31_19-57-45_LeakageTest-FoilID_40_Short.txt",dir.Data()));
//	vInput.open(Form("%s2016-11-01_08-41-41_LeakageTest-FoilID_36_Short.txt",dir.Data()));
//    vInput.open(Form("2016-11-01_09-05-52_LeakageTest-FoilID_36_Short.txt",dir.Data()));
//	vInput.open(Form("2016-11-01_20-28-29_LeakageTest-FoilID_36_Short.txt",dir.Data()));
//	vInput.open(Form("2016-11-02_13-58-56_LeakageTest-FoilID_44_Short.txt",dir.Data()));
//	vInput.open(Form("2016-11-03_14-03-03_LeakageTest-FoilID_103_Short.txt",dir.Data()));
//	vInput.open(Form("2016-11-03_18-37-00_LeakageTest-FoilID_103_Short.txt",dir.Data()));
//	vInput.open(Form("2016-11-05_17-25-09_LeakageTest-FoilID_103_Short.txt",dir.Data()));
//	vInput.open(Form("2016-11-07_08-48-40_LeakageTest-FoilID_105_Short.txt",dir.Data()));
	vInput.open(Form("2016-09-11_20-32-35_LeakageTest-FoilID_85_Short.txt",dir.Data()));
//	vInput.open(Form("2016-10-28_12-07-21_LeakageTest-FoilID_103_Long.txt",dir.Data()));

    double *x = new double[n];
    double *y1 = new double[n];
    double *y1e = new double[n];
    double *y2 = new double[n];
    double *y2e = new double[n];

    double vx, vy1, vy1e, vy2, vy2e;
    int vNData = 0;
	double Current_max =0;

    while (1){
        vInput >> vx >> vy1 >> vy1e >> vy2 >> vy2e;
        if (!vInput.good()) break;
        x[vNData] = vx;
        y1[vNData] = vy1;
        y1e[vNData] = vy1e;
        y2[vNData] = vy2;
        y2e[vNData] = vy2e;
        vNData++;
		if(vy2>Current_max) Current_max=vy2;
	}
	cout<<"current max = "<<Current_max<<endl;
	double endx = x[vNData-1];
	cout<<"end of x = "<<endx<<endl;
/*
    for(Int_t jj=0; jj<vNData; jj++)
	{
		cout<<x[jj]<<endl;
	    cout<<y1[jj]<<endl;
	    cout<<jj<<endl;
    }
*/
    vInput.close();


   c1 = new TCanvas("c1","gerrors2",20,10,1000,700);

   TPad *pad = new TPad("pad","",0,0,1,1);
   pad->SetFillColor(0);
   pad->SetGrid();
   pad->Draw();
   pad->cd();

//   TH1F *hr = pad->DrawFrame(0,0,5000,650);
   TH1F *hr = pad->DrawFrame(0,0,endx+50,650);	
   hr->SetXTitle("Time [Sec]");
   hr->SetYTitle("HV [Volt]");
   pad->GetFrame()->SetFillColor(0);
   pad->GetFrame()->SetBorderSize(12);

   gr1 = new TGraphErrors(vNData, x, y1, 0, y1e);
   gr1->SetTitle("Voltage vs time && Current vs time");
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(24);
   gr1->SetMarkerSize(0.3);
   gr1->GetXaxis()->SetLabelSize(0.05);
   gr1->Draw("LP");


   c1->cd();
   TPad *overlay = new TPad("overlay","",0,0,1,1);
   overlay->SetFillStyle(4000);
   overlay->SetFillColor(0);
   overlay->SetFrameFillStyle(4000);
   overlay->Draw();
   overlay->cd();


   gr2 = new TGraphErrors(vNData, x, y2, 0, y2e);
   gr2->SetMarkerColor(kRed);
   gr2->SetMarkerStyle(25);
   gr2->SetMarkerSize(0.3);
   gr2->SetName("gr2");
   Double_t xmin = pad->GetUxmin();
   Double_t ymin = -0.0001;
//	Double_t ymin = 58;
//   Double_t ymin = -(Current_max/5); 
//	Double_t ymin = 58;
   Double_t xmax = pad->GetUxmax();
	Double_t ymax = 0.06;
//   Double_t ymax = 0.005;
//	Double_t ymax = 61;
//   Double_t ymax = Current_max+0.005;
//	Double_t ymax = 60+5;
   TH1F *hframe = overlay->DrawFrame(xmin,ymin,xmax,ymax);
   hframe->GetXaxis()->SetLabelOffset(99);
   hframe->GetYaxis()->SetLabelOffset(99);
   gr2->Draw("LP");
   
   
   TGaxis *axis = new TGaxis(xmax,ymin,xmax, ymax,ymin,ymax,510,"+L");
   axis->SetLineColor(kRed);
   axis->SetLabelColor(kRed);
   axis->SetTitle("Curr [microA]");
   axis->SetTitleOffset(1.3);
   axis->SetTitleColor(kRed);
   axis->Draw();


//	c1->SaveAs("2016-10-27_14-06-10_LeakageTest-FoilID_111_Short.pdf");
//	c1->SaveAs("2016-10-21_09-13-26_LeakageTest-FoilID_103_Long.pdf");
//	c1->SaveAs("2016-10-31_19-57-45_LeakageTest-FoilID_40_Short.pdf");
//	c1->SaveAs("2016-11-01_08-41-41_LeakageTest-FoilID_36_Short.pdf");
//	c1->SaveAs("2016-11-01_09-05-52_LeakageTest-FoilID_36_Short.pdf");
//	c1->SaveAs("2016-11-01_20-28-29_LeakageTest-FoilID_36_Short.pdf");
//	c1->SaveAs("2016-11-02_13-58-56_LeakageTest-FoilID_44_Short.pdf");
//	c1->SaveAs("2016-11-03_14-03-03_LeakageTest-FoilID_103_Short.pdf");
//	c1->SaveAs("2016-11-03_18-37-00_LeakageTest-FoilID_103_Short.pdf");
//	c1->SaveAs("2016-11-05_17-25-09_LeakageTest-FoilID_103_Short.pdf");
//	c1->SaveAs("2016-11-07_08-48-40_LeakageTest-FoilID_105_Short.pdf");
	c1->SaveAs("2016-09-11_20-32-35_LeakageTest-FoilID_85_Short.pdf");
//	c1->SaveAs("2016-10-28_12-07-21_LeakageTest-FoilID_103_Long.pdf");	

}
