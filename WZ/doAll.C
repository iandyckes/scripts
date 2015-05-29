{
  gROOT->ProcessLine(".L CORE/CMS3_CORE.so");
  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch_ttbar = new TChain("t"); 
  ch_ttbar->Add("/nfs-7/userdata/ss2015/ssBabies/v1.15/TTBAR_multiIso.root");
  //ScanChain(ch_ttbar); 

  TChain *ch_wz = new TChain("t"); 
  ch_wz->Add("/nfs-7/userdata/ss2015/ssBabies/v1.15/WZ_multiIso.root");
  ScanChain(ch_wz); 
}
