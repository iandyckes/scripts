#include "TROOT.h"
#include "TSystem.h"
//#include "ScanChain.h"

void doAll()
{

  gSystem->AddIncludePath(" -I./");
  gROOT->ProcessLine(".L ScanChain.cc++");
  miniBabyMaker looper;
  looper.ScanChain();

  return;
}
