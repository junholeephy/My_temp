{
//    gInterpreter->AddIncludePath("/Users/leejunho/Desktop/MG5_aMC_v2_6_1/ExRootAnalysis/");
    gSystem->Load("libExRootAnalysis");
    gSystem->Load("/Users/leejunho/Downloads/root6_cmake/lib/libPhysics.so");
    gROOT->ProcessLine(".x VBSWW_Wminus_WlepAngle.C");
}
