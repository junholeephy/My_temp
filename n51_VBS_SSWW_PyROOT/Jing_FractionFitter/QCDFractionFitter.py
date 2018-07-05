from ROOT import TFractionFitter
from ROOT import TH1D
from ROOT import TObjArray
from ROOT import *
from TreePlot import *
import ROOT
import os
import sys
import os.path
from array import array


class QCDFractionFitter:

      def __init__(self, filename, scalefactortxtfilename, treename, lumi, channel, savelabel):
          
          self.tmpplot = TreePlot()

          self.batch_ = False

          self.filedict_ = filename

          self.scalefactortxtfilename_ = scalefactortxtfilename
          
          self.treename_ = treename

          self.histograms_ = {}

          self.multiplicitylabel_ = {}

          self.lumi_ = lumi

          self.channel_ = channel

          self.savelabel_ = savelabel
          
          self.constrains_ = []

          self.fit_ = None
          
          self.qcdfraction_ = 0.0

          self.qcdfractionerror_ = 0.0

      def SetBatch(self):

          self.batch_ = True
      
      def SetVariableCutWeightName(self, variable, cutname, weightname):
          
          self.variable_ = variable
          self.cutname_ = cutname
          self.weightname_ = weightname
      
      def SetXtitleYtitle(self, xtitle, ytitle):
          
          self.xtitle_ = xtitle
          self.ytitle_ = ytitle

      def SetBinMinMax(self, bin, min, max):
          
          self.bin_ = bin
          self.min_ = min
          self.max_ = max

      def SetConstrainPartLabel(self, constrains):
          
          self.constrains_ = constrains

      def SetAnalysisCut(self, metcut):
          
          self.metcut_ = metcut

      def GetQCDFractionResult(self):

          return [self.qcdfraction_, self.qcdfractionerror_]

      def FitAndPlot(self, fitpattern):
          
          #####Prepare the Histogram to the TFractionFitter####################
          print "We are Fitting the variable: " + self.variable_
          print "We are using the cut: " + self.cutname_
          print "We are using the weight: " + self.weightname_
          
          ttbarregionsignal = ""

          for tmpfiletype in self.filedict_.keys():
              
              tmpcutname = self.cutname_
              self.tmpplot.SetBinMinMax(self.bin_,self.min_,self.max_)
              self.tmpplot.SetCutWeightName(tmpcutname,self.weightname_)

              if (tmpfiletype != "data" and tmpfiletype != "QCD" and tmpfiletype != "WJets"):
                 self.tmpplot.DrawTrees(self.filedict_[tmpfiletype],self.treename_,self.variable_,0,self.xtitle_,self.ytitle_,"%s:%s"%(self.scalefactortxtfilename_,tmpfiletype),self.lumi_,tmpfiletype,self.histograms_,self.multiplicitylabel_,ttbarregionsignal)
              elif (tmpfiletype == "WJets"):
                 self.tmpplot.SetCutWeightName(tmpcutname,self.weightname_+"*W_nParton_weight")
                 self.tmpplot.DrawTrees(self.filedict_[tmpfiletype],self.treename_,self.variable_,0,self.xtitle_,self.ytitle_,"%s:%s"%(self.scalefactortxtfilename_,tmpfiletype),self.lumi_,tmpfiletype,self.histograms_,self.multiplicitylabel_,ttbarregionsignal)
              elif(tmpfiletype == "data"):
                 self.tmpplot.DrawTrees(self.filedict_[tmpfiletype],self.treename_,self.variable_,0,self.xtitle_,self.ytitle_,1.0,1.0,tmpfiletype,self.histograms_,self.multiplicitylabel_,ttbarregionsignal)
              elif(tmpfiletype == "QCD"):
                 self.tmpplot.SetCutWeightName(tmpcutname+"&&((EWK_W_2jets_l_tagjet2_deltaR<EWK_W_2jets_l_tagjet1_deltaR?EWK_W_2jets_l_tagjet2_deltaR:EWK_W_2jets_l_tagjet1_deltaR)>1.0)",self.weightname_)
                 self.tmpplot.DrawTrees(self.filedict_[tmpfiletype],self.treename_,self.variable_,0,self.xtitle_,self.ytitle_,1.0,1.0,tmpfiletype,self.histograms_,self.multiplicitylabel_,ttbarregionsignal)
          
          if fitpattern == "QCDfraction":

             wjet1D = TH1D("wjet1D","wjet1D",self.bin_,self.min_,self.max_)

             firstbin = 1 
             lastbin = self.histograms_["data"].GetNbinsX()

             dataentries = self.histograms_["data"].Integral(firstbin,lastbin)
             print "data Entries: " + str(dataentries)
             self.histograms_["QCD"].Scale(dataentries/self.histograms_["QCD"].Integral(firstbin,lastbin+1))
             wjet1D = self.histograms_["WJets"] + self.histograms_["W1Jets"] + self.histograms_["W2Jets"] + self.histograms_["W3Jets"] + self.histograms_["W4Jets"]
             wjet1D.Scale(dataentries/wjet1D.Integral(firstbin,lastbin+1))
             
             constrainfaction = 0.
             tconstrain1D = TH1D("tconstrain", "tconstrain", self.bin_, self.min_, self.max_)
             if len(self.constrains_) > 0:   
               for icons in self.constrains_:
                   tconstrain1D.Add(self.histograms_[icons])
               #tconstrain1D.Scale(dataentries/tconstrain1D.Integral(firstbin,lastbin))
               constrainfaction = tconstrain1D.Integral(firstbin,lastbin)/dataentries
               print "TTbar constrainfaction: " + str(constrainfaction)
               tconstrain1D.Scale(dataentries/tconstrain1D.Integral(firstbin,lastbin+1))
             
             mc = TObjArray()
             mc.Add(self.histograms_["QCD"])
             mc.Add(wjet1D)

             if len(self.constrains_) > 0:
                mc.Add(tconstrain1D)
             
             self.fit_ = TFractionFitter(self.histograms_["data"], mc)
             self.fit_.Constrain(1,0.0,1.0)
             self.fit_.Constrain(2,0.0,1.0)
             if len(self.constrains_) > 0:
                #self.fit_.Constrain(3,constrainfaction - 0.0001*constrainfaction,constrainfaction + 0.0001*constrainfaction)
                self.fit_.Constrain(3,0.0,1.0)
             
             self.fit_.SetRangeX(firstbin,lastbin)

             status = self.fit_.Fit()
             
             print "fit status: " + str(status)
             
             self.SetUpPlotEnviroment()

             if (self.batch_):
                gROOT.SetBatch()

             canvas = TCanvas("c1","c1",10,10,700,700)
             lgnd = TLegend(0.6,0.6,0.90,0.9)
             lgnd.SetFillColor(kWhite)

             result = self.fit_.GetPlot()
             result.SetFillColor(kYellow)
             self.histograms_["data"].SetMinimum(0)
             self.histograms_["data"].Draw("Ep")
             result.Draw("histsame")
             
             frac_value = array('d', [0.])
             frac_error = array('d', [0.])

             self.fit_.GetResult(0,frac_value,frac_error)
             
             integralanalysisbin = self.histograms_["data"].FindBin(self.metcut_)

             dataentriesanalysisbin = self.histograms_["data"].Integral(integralanalysisbin, lastbin)
             qcdintegralanalysisbin = self.histograms_["QCD"].Integral(integralanalysisbin, lastbin)
             wjetsintegralanalysisbin = wjet1D.Integral(integralanalysisbin, lastbin)

             qcdfrac_valuemetcut = frac_value[0] * qcdintegralanalysisbin / dataentriesanalysisbin

             print "QCD: frac_value= " + str(qcdfrac_valuemetcut) + "+/-" + str(frac_error[0]) + " NEvts=" + str(dataentries*qcdfrac_valuemetcut) + "+/-" + str(dataentries*frac_error[0])
             self.qcdfraction_ = qcdfrac_valuemetcut
             #self.qcdfraction_ = frac_value[0]
             self.qcdfractionerror_ = frac_error[0]
             self.histograms_["QCD"].Scale(frac_value[0])
             self.histograms_["QCD"].SetLineWidth(2)
             self.histograms_["QCD"].SetLineColor(kBlue)
             self.histograms_["QCD"].Draw("histesame")

             self.fit_.GetResult(1,frac_value,frac_error)
             wjetsfrac_valuemetcut = frac_value[0] * wjetsintegralanalysisbin / dataentriesanalysisbin
             print "WJets: frac_value= " + str(wjetsfrac_valuemetcut) + "+/-" + str(frac_error[0]) + " NEvts=" + str(dataentries*wjetsfrac_valuemetcut) + "+/-" + str(dataentries*frac_error[0])
             #self.histograms_["WJets"].Scale(frac_value[0])
             #self.histograms_["WJets"].SetLineWidth(2)
             #self.histograms_["WJets"].SetLineColor(kRed)
             #self.histograms_["WJets"].Draw("histesame")
             wjet1D.Scale(frac_value[0])
             wjet1D.SetLineWidth(2)
             wjet1D.SetLineColor(kRed)
             wjet1D.Draw("histesame")

             if len(self.constrains_) > 0:
                self.fit_.GetResult(2,frac_value,frac_error)
                tconstrain1D.Scale(frac_value[0])
                #tconstrain1D.Scale(frac_value[0]*dataentries/tconstrain1D.Integral(firstbin,lastbin+1))
                tconstrain1D.SetLineWidth(2)
                tconstrain1D.SetLineColor(kGreen)
                tconstrain1D.Draw("histsame")

             lgnd.AddEntry(result,"TemplatePrediction","f")
             lgnd.AddEntry(self.histograms_["data"], "data","p")
             lgnd.AddEntry(self.histograms_["QCD"], "QCD","l")
             #lgnd.AddEntry(self.histograms_["WJets"], "WJetsMC","l")
             lgnd.AddEntry(wjet1D, "WJetsMC","l")
             if len(self.constrains_) > 0:
                #lgnd.AddEntry(tconstrain1D, "Fixed Processes", "l")
                lgnd.AddEntry(tconstrain1D, "Other Processes", "l")
            
             chi2ndof = -999.0
             if len(self.constrains_) > 0:
                print "FitChiSquare/ndof= " + str(self.fit_.GetChisquare()/(self.bin_-3))
                chi2ndof = self.fit_.GetChisquare()/(self.bin_-3)
             else:
                print "FitChiSquare/ndof= " + str(self.fit_.GetChisquare()/(self.bin_-2))
                chi2ndof = self.fit_.GetChisquare()/(self.bin_-2)
             print "FitProbatility= " + str(self.fit_.GetProb())

             latex = TLatex(0.60,0.50,"#chi2/ndof=%s"%(round(chi2ndof,2)))
             latex.SetNDC()
             latex.SetTextSize(0.035)
             
             self.histograms_["data"].SetMarkerStyle(20)
             self.histograms_["data"].SetMarkerSize(1)
             self.histograms_["data"].Draw("Esame")
             lgnd.Draw()
             latex.Draw()
            
             if len(self.constrains_) > 0:
                self.channel_ = self.channel_ + "constrainotherprocess"

             self.variable_ = self.variable_.replace(".","_")
             self.savelabel_ = self.savelabel_.replace(".","_")

             canvas.SaveAs("QCDFractionFit/"+self.channel_+"_"+self.variable_+self.savelabel_+"_qcdfraction.png")
             canvas.SaveAs("QCDFractionFit/"+self.channel_+"_"+self.variable_+self.savelabel_+"_qcdfraction.pdf")
             canvas.SaveAs("QCDFractionFit/"+self.channel_+"_"+self.variable_+self.savelabel_+"_qcdfraction.eps")

      def SetUpPlotEnviroment(self):
          if os.path.isfile('tdrstyle.C'):
             gROOT.ProcessLine('.L tdrstyle.C')
             ROOT.setTDRStyle()
             print "Found tdrstyle.C file, using this style."
             HasCMSStyle = "True"
             if os.path.isfile('CMSTopStyle.cc'):
                gROOT.ProcessLine('.L CMSTopStyle.cc+')
                style = CMSTopStyle()
                style.setupICHEPv1()
                print "Found CMSTopStyle.cc file, use TOP style if requested in xml file."
