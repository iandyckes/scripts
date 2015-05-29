#include "TROOT.h"
#include "TSystem.h"
//#include "ScanChain.h"

void doAllTEST(string dirname)
{

  gSystem->AddIncludePath(" -I./");
  gROOT->ProcessLine(".L /home/users/iandyckes/CMSSW_5_3_18/met_corrections_test/IanTmp/ScanTEST.cc++");
  miniBabyMaker looper(dirname);
  looper.ScanTEST(dirname);

  return;
}
