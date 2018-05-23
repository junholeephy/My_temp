TH1D* GetHistoWeight(TTree* t, string variable, int nbins, double xmin, double xmax, string cut, string weight, string name){
        string sxmin, sxmax, snbins;
        stringstream ss[3];

        ss[0] << xmin;
        ss[0] >> sxmin;
        ss[1] << xmax;
        ss[1] >> sxmax;
        ss[2] << nbins;
        ss[2] >> snbins;

        string variablenew = variable + " >> h(" + snbins + "," + sxmin + "," + sxmax + ")";

        string cutnew = weight + " * (" + cut + ")";

        t->Draw(variablenew.c_str(), cutnew.c_str());
        TH1D *histo = (TH1D*)gDirectory->Get("h");

        if (histo->GetEntries()==0) return histo;

        double underflow = histo->GetBinContent(0);
        double val = 0;
        if (underflow>0) {
                val = histo->GetBinContent(1);
                histo->SetBinContent(1, val+underflow);
                histo->SetBinContent(0, 0);
        }
        double overflow = histo->GetBinContent(nbins+1);
        if (overflow>0) {
                val = histo->GetBinContent(nbins);
                histo->SetBinContent(nbins+1, 0);
                histo->SetBinContent(nbins, val+overflow);
        }

        histo->SetName(name.c_str());
        histo->SetTitle(name.c_str());

        return histo;
}


void Plot(){

  gROOT->ProcessLine(".x setTDRStyle.C");

  TFile* f = new TFile("TMVAReg.root","READ");
  TTree* tTrain = (TTree*) f->Get("TestTree");
  TTree* tTest = (TTree*) f->Get("TrainTree");
  
/*
  string var = "Target_BjetTopHad_E";
  double nbin = 50;
  double xmin = 0;
  double xmax = 1000;
*/

  string var = "cthetam";
  double nbin = 50;
  double xmin = -1;
  double xmax = 1;

  TH1D* HistoOutput_Train = GetHistoWeight(tTrain, "MLP", nbin, xmin, xmax, "1", "weight", "MLPTrain");
  TH1D* HistoOutput_Test = GetHistoWeight(tTest, "MLP", nbin, xmin, xmax, "1", "weight", "MLPTest");

  TH1D* HistoTarget_Train = GetHistoWeight(tTrain, var, nbin, xmin, xmax, "1", "weight", "TargetTrain");
  TH1D* HistoTarget_Test = GetHistoWeight(tTest, var, nbin, xmin, xmax, "1", "weight", "TargetTest");


  TH1F* HistoConvergence_Train = (TH1F*) f->Get("Method_MLP/MLP/estimatorHistTrain");
  TH1F* HistoConvergence_Test = (TH1F*) f->Get("Method_MLP/MLP/estimatorHistTest");


  TCanvas* Canvas1 = new TCanvas("Canvas1","Canvas1");

  HistoOutput_Train->SetXTitle("Bjet Energy from Had. Top");
  HistoOutput_Train->SetLineColor(kRed);
  HistoOutput_Train->Draw("HIST");
  HistoOutput_Test->SetLineColor(kRed);
  HistoOutput_Test->SetMarkerStyle(20);
  HistoOutput_Test->SetMarkerColor(kRed);
  HistoOutput_Test->Draw("EPsame");

  HistoTarget_Train->SetLineColor(kBlack);
  HistoTarget_Train->Draw("HISTsame");
  HistoTarget_Test->SetLineColor(kBlack);
  HistoTarget_Test->SetMarkerStyle(20);
  HistoTarget_Test->SetMarkerColor(kBlack);
  HistoTarget_Test->Draw("EPsame");

  TLegend* legend = new TLegend(0.5, 0.72, 0.8, 0.92, "");
  legend->SetFillColor(kWhite);
  legend->AddEntry(HistoTarget_Train->GetName(), "Target, train", "l");
  legend->AddEntry(HistoTarget_Test->GetName(), "Target, test", "p");
  legend->AddEntry(HistoOutput_Train->GetName(), "Output, train", "l");
  legend->AddEntry(HistoOutput_Test->GetName(), "Output, test", "p");
  legend->Draw();

  Canvas1->Print("NNoutput.gif");


  TCanvas* CanvasConvergence = new TCanvas("CanvasConvergence","CanvasConvergence");

  HistoConvergence_Train->SetXTitle("Estimator");
  HistoConvergence_Train->SetLineColor(8);
  HistoConvergence_Train->Draw("HIST");
  HistoConvergence_Test->SetLineColor(kBlue);
  HistoConvergence_Test->Draw("HISTsame");

  TLegend* legend2 = new TLegend(0.5, 0.5, 0.8, 0.65, "");
  legend2->SetFillColor(kWhite);
  legend2->AddEntry(HistoConvergence_Train->GetName(), "Train", "l");
  legend2->AddEntry(HistoConvergence_Test->GetName(), "Test", "l");
  legend2->Draw();
  
  CanvasConvergence->SetLogy(1);

  CanvasConvergence->Print("Convergence.gif");
}
