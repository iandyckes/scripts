#ifndef SCANTEST_H
#define SCANTEST_H

#include <string>
#include <map>
#include <vector>

//root stuff
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TString.h"
class miniBabyMaker
{
public:
  miniBabyMaker();
  // miniBabyMaker( std::string babyfilename );
  ~miniBabyMaker();
  
  void new_map(vector<TString> var_vec, TString type, map<TString,TH1F*> &type_map);
  int ScanTEST(TChain* chain, string goodeventlist_name_ee, string goodeventlist_name_mumu, string goodeventlist_name_emu,int nEvents = -1);
  void fillHist( TH1F* &hist, double variable, const double weight );
  void fill_map( map<TString, TH1F*> &m, double pfMet , const double weight );
  void fill_map( map<TString, TH1F*> &m, map<TString, double> var , const double weight );
  void map_to_file( map<TString, TH1F*> m, TFile* outfile, TString var_check);

private:
  
  //  void MakeBabyNtuple();
  //  void Initialize();
  //  void FillBabyNtuple();

  //Tree pointer
  TTree * babyTree_;

  //histo file pointer
  //  std::string babyFileName_;
  //  TFile * babyFile_;

  //add branches
  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
  //event variables
  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
  // int run_;
  // int lumi_;
  // ULong64_t event_;

  // float pfMet_;
  // float pfMetphi_;
  // float pfMetT0pc_;
  // float pfMetT0pcphi_;
  // float pfMetT0pcT1_;
  // float pfMetT0pcT1phi_;
  // float pfMetT0pcT1Txy_;
  // float pfMetT0pcT1Txyphi_;
  // float pfMetT0pcTxy_;
  // float pfMetT0pcTxyphi_;
  // float pfMetT0rt_;
  // float pfMetT0rtphi_;
  // float pfMetT0rtT1_;
  // float pfMetT0rtT1phi_;
  // float pfMetT0rtT1Txy_;
  // float pfMetT0rtT1Txyphi_;
  // float pfMetT0rtTxy_;
  // float pfMetT0rtTxyphi_;
  // float pfMetT1_;
  // float pfMetT1phi_;
  // float pfMetT1Txy_;
  // float pfMetT1Txyphi_;
};
#endif
