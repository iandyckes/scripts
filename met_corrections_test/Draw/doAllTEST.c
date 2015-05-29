#include "TROOT.h"
#include "TSystem.h"
#include "TChain.h"
//#include "ScanTEST.h"

void doAllTEST()
{

  gSystem->AddIncludePath(" -I./");
  gROOT->ProcessLine(".L ./GoodEventFilter/badEventFilter/src/badEventFilter.cc++");
  gROOT->ProcessLine(".L eventFilter.cc++");
  gROOT->ProcessLine(".L ScanTEST.cc++");
  
  TChain *ch_data = new TChain("T1");
  //  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron/DoubleElectron.root");  //Which is this a double of?
  //  ch_data->Add("/nfs-4/userdata/iand/DoubleMu/DoubleMu.root"); // <------------------------accidentally erased

  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron_Run2012A-13Jul2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron_Run2012A-recover-06Aug2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron_Run2012B-13Jul2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron_Run2012C-24Aug2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron_Run2012C-EcalRecover_11Dec2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron_Run2012C-PromptReco-v2_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron_Run2012D-16Jan2013-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleElectron_Run2012D-PromptReco-v1_AOD/baby.root");

  ch_data->Add("/nfs-4/userdata/iand/DoubleMu_Run2012A-13Jul2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleMu_Run2012A-recover-06Aug2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleMu_Run2012B-13Jul2012-v4_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleMu_Run2012C-24Aug2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleMu_Run2012C-EcalRecover_11Dec2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleMu_Run2012C-PromptReco-v2_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleMu_Run2012D-16Jan2013-v2_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/DoubleMu_Run2012D-PromptReco-v1_AOD/baby.root");

  ch_data->Add("/nfs-4/userdata/iand/MuEG_Run2012A-13Jul2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/MuEG_Run2012A-recover-06Aug2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/MuEG_Run2012B-13Jul2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/MuEG_Run2012C-24Aug2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/MuEG_Run2012C-EcalRecover_11Dec2012-v1_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/MuEG_Run2012C-PromptReco-v2_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/MuEG_Run2012D-16Jan2013-v2_AOD/baby.root");
  ch_data->Add("/nfs-4/userdata/iand/MuEG_Run2012D-PromptReco-v1_AOD/baby.root");

  //ch_data->Add("/nfs-4/userdata/iand/EMu/EMu.root"); //This one has to be last I think.  Which is this a double of?
  
  TChain *ch_ww = new TChain("T1");
  ch_ww->Add("/nfs-4/userdata/iand/WW/baby.root");

  TChain *ch_wz = new TChain("T1");
  ch_wz->Add("/nfs-4/userdata/iand/WZJetsTo2L2Q/baby.root");
  ch_wz->Add("/nfs-4/userdata/iand/WZJetsTo2QLNu/baby.root");
  ch_wz->Add("/nfs-4/userdata/iand/WZJetsTo3LNu/baby.root");

  TChain *ch_zz = new TChain("T1");
  ch_zz->Add("/nfs-4/userdata/iand/ZZJetsTo2L2Nu/baby.root");
  ch_zz->Add("/nfs-4/userdata/iand/ZZJetsTo2L2Q/baby.root");
  ch_zz->Add("/nfs-4/userdata/iand/ZZJetsTo4L/baby.root");

  TChain *ch_dy = new TChain("T1");
  ch_dy->Add("/nfs-4/userdata/iand/DYJetsToLL/DYJetsToLL.root");


  string data_eventlist_ee = "/home/users/iandyckes/DrawPlots/data_goodevents_ee.txt";
  string data_eventlist_mumu = "/home/users/iandyckes/DrawPlots/data_goodevents_mumu.txt";
  string data_eventlist_emu = "/home/users/iandyckes/DrawPlots/data_goodevents_emu.txt";
  string ww_eventlist_ee = "/home/users/iandyckes/DrawPlots/ww_goodevents_ee.txt";
  string ww_eventlist_mumu = "/home/users/iandyckes/DrawPlots/ww_goodevents_mumu.txt";
  string ww_eventlist_emu = "/home/users/iandyckes/DrawPlots/ww_goodevents_emu.txt";
  string wz_eventlist_ee = "/home/users/iandyckes/DrawPlots/wz_goodevents_ee.txt";
  string wz_eventlist_mumu = "/home/users/iandyckes/DrawPlots/wz_goodevents_mumu.txt";
  string wz_eventlist_emu = "/home/users/iandyckes/DrawPlots/wz_goodevents_emu.txt";
  string zz_eventlist_ee = "/home/users/iandyckes/DrawPlots/zz_goodevents_ee.txt";
  string zz_eventlist_mumu = "/home/users/iandyckes/DrawPlots/zz_goodevents_mumu.txt";
  string zz_eventlist_emu = "/home/users/iandyckes/DrawPlots/zz_goodevents_emu.txt";
  string dy_eventlist_ee = "/home/users/iandyckes/DrawPlots/zjets_goodevents_ee.txt";
  string dy_eventlist_mumu = "/home/users/iandyckes/DrawPlots/zjets_goodevents_mumu.txt";
  string dy_eventlist_emu = "/home/users/iandyckes/DrawPlots/zjets_goodevents_emu.txt";

  miniBabyMaker looper;
  looper.ScanTEST(ch_data, data_eventlist_ee, data_eventlist_mumu, data_eventlist_emu);
  looper.ScanTEST(ch_ww, ww_eventlist_ee, ww_eventlist_mumu, ww_eventlist_emu);
  looper.ScanTEST(ch_wz, wz_eventlist_ee, wz_eventlist_mumu, wz_eventlist_emu); 
  looper.ScanTEST(ch_zz, zz_eventlist_ee, zz_eventlist_mumu, zz_eventlist_emu);
  looper.ScanTEST(ch_dy, dy_eventlist_ee, dy_eventlist_mumu, dy_eventlist_emu);
  
  return;
}
