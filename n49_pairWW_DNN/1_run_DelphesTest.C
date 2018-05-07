{
    gInterpreter->AddIncludePath("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/Delphes");
    gSystem->Load("libDelphes");
    gROOT->ProcessLine(".L Delphes_test.C+");
    Delphes_test();

}


