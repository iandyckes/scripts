#include "TROOT.h"
#include "TSystem.h"
#include "TChain.h"
//#include "ScanChain.h"

void doAll()
{

  gSystem->AddIncludePath(" -I./");
  gROOT->ProcessLine(".L ./GoodEventFilter/badEventFilter/src/badEventFilter.cc++");
  gROOT->ProcessLine(".L eventFilter.cc++");
  gROOT->ProcessLine(".L ScanChain.cc++");
  
  TChain *ch_data = new TChain("T1");
  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron/DoubleElectron.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleMu/DoubleMu.root");
  ch_data->Add("/nfs-4/userdata/iand/EMu/EMu.root");
  
  TChain *ch_ww = new TChain("T1");
  ch_ww->Add("/nfs-4/userdata/iand/WW/WW.root");

  TChain *ch_wz = new TChain("T1");
  ch_wz->Add("/nfs-4/userdata/iand/WZJetsTo2L2Q/WZJetsTo2L2Q.root");
  ch_wz->Add("/nfs-4/userdata/iand/WZJetsTo2QLNu/WZJetsTo2QLNu.root");
  ch_wz->Add("/nfs-4/userdata/iand/WZJetsTo3LNu/WZJetsTo3LNu.root");

  TChain *ch_zz = new TChain("T1");
  ch_zz->Add("/nfs-4/userdata/iand/ZZJetsTo2L2Nu/ZZJetsTo2L2Nu.root");
  ch_zz->Add("/nfs-4/userdata/iand/ZZJetsTo2L2Q/ZZJetsTo2L2Q.root");
  ch_zz->Add("/nfs-4/userdata/iand/ZZJetsTo4L/ZZJetsTo4L.root");

  TChain *ch_dy = new TChain("T1");
  ch_dy->Add("/nfs-4/userdata/iand/DYJetsToLL/DYJetsToLL.root");

  miniBabyMaker looper;
  looper.ScanChain(ch_data);
  looper.ScanChain(ch_ww);
  looper.ScanChain(ch_wz);
  looper.ScanChain(ch_zz);
  looper.ScanChain(ch_dy);
  
  return;
}
