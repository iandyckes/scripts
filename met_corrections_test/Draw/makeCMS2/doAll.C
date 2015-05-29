{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("T1"); 
  ch->Add("/home/users/iandyckes/CMSSW_5_3_18/met_corrections_test/DoubleElectron/DoubleElectron.root");
  ScanChain(ch); 
}