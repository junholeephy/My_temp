from ROOT import *
import sys, os, math
import numpy as np
sys.path.append("/Users/leejunho/Desktop/git/python3Env/group_study/project_pre/func")
from c0_READ_PATH_FILE import read_file_name

class FractionFitter:
    def __init__(self,fileList):
        self.filelist = fileList 
        #pass

    def Read_Data_n_MC(self):
        return_list = []
        for i in range(len(self.filelist)):
            tfile = TFile(read_file_name(self.filelist[i])[2],"READ")
            return_list.append(tfile)
        #print(return_list)
        return return_list

    def MakeHistoROOT(self):
        tfile_list = self.Read_Data_n_MC() 
        #Templates = TObjArray(3)
        



def main():
    Infile_list = ["../PseudoData/Ntuple_delphes_VBSsignal.root","../Template/Ntuple_delphes_VBS_SS_WW_LL_template.root","../Template/Ntuple_delphes_VBS_SS_WW_TL_template.root","../Template/Ntuple_delphes_VBS_SS_WW_TT_template.root"]
    Fit_test = FractionFitter(Infile_list)
    Fit_test.MakeHisto()


if __name__=="__main__":
    main()

