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
  //file_short.resize(file_short.length()-11);
  file_short.resize(file_short.length()-5);  //removes ".root" from end

  cout << file << endl;
  cout << file_short << endl;
  //cout.setf(ios::fixed, ios::floatfield);
  //cout.setf(cout.setf(ios::showpoint);

  std::string gtype = "em";

  gROOT -> ProcessLine(Form("TFile filea(\"%s\",\"READ\");",file.c_str()));
   //gROOT -> ProcessLine("TFile filea(\"corrMet.root\",\"READ\");");

  gROOT -> ProcessLine("TTree * treea = (TTree*)filea.Get(\"Events\");");

  gROOT -> ProcessLine("treea->SetScanField(0);"); 

  gROOT -> ProcessLine(Form("treea->Scan(\"EventAuxiliary.id().run():EventAuxiliary.id().luminosityBlock():EventAuxiliary.id().event()   \",\"\",\"precision=20, colsize=20\"); > %s.txt", file_short.c_str() ));  //FOR MINIAOD
  //gROOT -> ProcessLine(Form("treea->Scan(\"evt_run:event_lumiBlock:evt_event  \",\"\",\"precision=20, colsize=20\"); > %s.txt", file_short.c_str() ));  //FOR CMS3

  // gROOT -> ProcessLine("treea->Scan(\"PFMET.pt():PFMET.phi()\")");  

}
