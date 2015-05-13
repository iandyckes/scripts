#ifndef SCANCHAINTEST_H
#define SCANCHAINTEST_H

#include <string>

//root stuff
#include "TFile.h"
#include "TTree.h"

class miniBabyMaker
{
public:
  miniBabyMaker();
  miniBabyMaker(std::string dirname);
  // miniBabyMaker( std::string babyfilename );
  ~miniBabyMaker();
  
  int ScanTEST(std::string dirname);

private:
  
  void MakeBabyNtuple();
  void Initialize();
  void FillBabyNtuple();

  //Tree pointer
  TTree * babyTree_;

  //histo file pointer
  std::string babyFileName_;
  TFile * babyFile_;

  //add branches
  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
  //event variables
  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
  int run_;
  int lumi_;
  ULong64_t event_;


};
#endif
