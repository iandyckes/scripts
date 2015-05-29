#include <iostream>
#include <string>

// #include "TCut.h"
#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"
//#include "TString.h"
// #include "TChain.h"


using namespace std;

void GetCorrectionsTEST(string file, string outputfile)
{

  string file_short = outputfile;
  file_short.resize(file_short.length()-11);

  cout << file << endl;
  cout << file_short << endl;
  //cout.setf(ios::fixed, ios::floatfield);
  //cout.setf(cout.setf(ios::showpoint);

  std::string gtype = "em";

  gROOT -> ProcessLine(Form("TFile filea(\"%s\",\"READ\");",file.c_str()));
   //gROOT -> ProcessLine("TFile filea(\"corrMet.root\",\"READ\");");

  gROOT -> ProcessLine("TTree * treea = (TTree*)filea.Get(\"Events\");");

  gROOT -> ProcessLine("treea->SetScanField(0);"); 

  gROOT -> ProcessLine(Form("treea->Scan(\"EventAuxiliary.id().run():EventAuxiliary.id().luminosityBlock():EventAuxiliary.id().event():PFMET.pt():PFMET.phi():pfMetT0pc.pt():pfMetT0pc.phi():pfMetT0pcT1.pt():pfMetT0pcT1.phi():pfMetT0pcT1Txy.pt():pfMetT0pcT1Txy.phi():pfMetT0pcTxy.pt():pfMetT0pcTxy.phi():pfMetT0rt.pt():pfMetT0rt.phi():pfMetT0rtT1.pt():pfMetT0rtT1.phi():pfMetT0rtT1Txy.pt():pfMetT0rtT1Txy.phi():pfMetT0rtTxy.pt():pfMetT0rtTxy.phi():pfMetT1.pt():pfMetT1.phi():pfMetT1Txy.pt():pfMetT1Txy.phi()   \",\"\",\"precision=20, colsize=20\"); > %s.txt", file_short.c_str() ));
  // gROOT -> ProcessLine("treea->Scan(\"PFMET.pt():PFMET.phi()\")");

}
