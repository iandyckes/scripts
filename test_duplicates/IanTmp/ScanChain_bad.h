#ifndef SCANCHAIN_H
#define SCANCHAIN_H

#include <string>

//root stuff
#include "TFile.h"
#include "TTree.h"

class miniBabyMaker
{
public:
  miniBabyMaker();
  // miniBabyMaker( std::string babyfilename );
  ~miniBabyMaker();
  
  int ScanChain();

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

  float pfMet_;
  float pfMetphi_;
  float pfMetT0pc_;
  float pfMetT0pcphi_;
  float pfMetT0pcT1_;
  float pfMetT0pcT1phi_;
  float pfMetT0pcT1Txy_;
  float pfMetT0pcT1Txyphi_;
  float pfMetT0pcTxy_;
  float pfMetT0pcTxyphi_;
  float pfMetT0rt_;
  float pfMetT0rtphi_;
  float pfMetT0rtT1_;
  float pfMetT0rtT1phi_;
  float pfMetT0rtT1Txy_;
  float pfMetT0rtT1Txyphi_;
  float pfMetT0rtTxy_;
  float pfMetT0rtTxyphi_;
  float pfMetT1_;
  float pfMetT1phi_;
  float pfMetT1Txy_;
  float pfMetT1Txyphi_;
};
#endif
