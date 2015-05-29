//c stuff
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

//root stuff
#include "TSystem.h"
#include "TChain.h"
#include "TChainElement.h"
#include "TFile.h"
#include "TTree.h"
#include "TBenchmark.h"
#include "TDirectory.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TString.h"

//stuff from include
#include "ScanTEST.h"

using namespace std;

//3.14159265358979323846

miniBabyMaker::miniBabyMaker()
{
  babyFileName_ = "/nfs-4/userdata/iand/test_baby.root";

  babyTree_ = NULL;
  babyFile_ = NULL;

  MakeBabyNtuple();

}

miniBabyMaker::miniBabyMaker(string dirname)
{
  //  babyFileName_ = "/nfs-4/userdata/iand/test_baby.root";
  babyFileName_ = dirname+"/baby.root";

  babyTree_ = NULL;
  babyFile_ = NULL;

  MakeBabyNtuple();

}

// miniBabyMaker::miniBabyMaker( string babyfilename = "test" )
// {
//   babyFileName_ = Form("%s_baby.root", babyfilename.c_str());

//   babyTree_ = NULL;
//   babyFile_ = NULL;

//   MakeBabyNtuple();

// }

miniBabyMaker::~miniBabyMaker(){
  delete babyFile_;
}

int miniBabyMaker::ScanTEST(string dirname){

  // // Benchmark
  // TBenchmark *bmark = new TBenchmark();
  // bmark->Start("benchmark");

  // // Loop over events to Analyze
  // long i_permilleOld = 0;
  // unsigned long nEventsTotal = 0;
  // unsigned long nDuplicates = 0;
  // unsigned long nBadEvents  = 0;
  // unsigned long nEventsPass = 0;
  // unsigned long nEventsChain = chain->GetEntries();
  // if( nEvents >= 0 ) nEventsChain = nEvents;
  // TObjArray *listOfFiles = chain->GetListOfFiles();
  // TIter fileIter(listOfFiles);
  // TFile *currentFile = 0;

  //read in corrmet txt file
  string filename;
  filename=dirname+"/formatted_met_corrections.txt";
  fstream fin(filename.c_str());

  //bad data (sci notation)
  bool bad = true;

  int run;
  int lumi;
  ULong64_t event;
  float pfMet;
  float pfMetphi;
  float pfMetT0pc;
  float pfMetT0pcphi;
  float pfMetT0pcT1;
  float pfMetT0pcT1phi;
  float pfMetT0pcT1Txy;
  float pfMetT0pcT1Txyphi;
  float pfMetT0pcTxy;
  float pfMetT0pcTxyphi;
  float pfMetT0rt;
  float pfMetT0rtphi;
  float pfMetT0rtT1;
  float pfMetT0rtT1phi;
  float pfMetT0rtT1Txy;
  float pfMetT0rtT1Txyphi;
  float pfMetT0rtTxy;
  float pfMetT0rtTxyphi;
  float pfMetT1;
  float pfMetT1phi;
  float pfMetT1Txy;
  float pfMetT1Txyphi;

  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-
  //Start file loop
  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-
  string line;
  while( getline (fin, line) )
	{
	  fin >> run >> lumi >> event >> pfMet >> pfMetphi >> pfMetT0pc >> pfMetT0pcphi >> pfMetT0pcT1 >> pfMetT0pcT1phi >> pfMetT0pcT1Txy >> pfMetT0pcT1Txyphi >> pfMetT0pcTxy >> pfMetT0pcTxyphi >> pfMetT0rt >> pfMetT0rtphi >> pfMetT0rtT1 >> pfMetT0rtT1phi >> pfMetT0rtT1Txy >>  pfMetT0rtT1Txyphi >> pfMetT0rtTxy >> pfMetT0rtTxyphi >> pfMetT1 >> pfMetT1phi >> pfMetT1Txy >> pfMetT1Txyphi;
	  //cout <<"run:      " << run     <<endl
	  //	 <<"lumi:     " << lumi    <<endl
	  //	 <<"event:    " << event   <<endl
	  //	 <<"pfMet:    " << pfMet   <<endl
	  //	 <<"pfMetphi: " << pfMetphi<<endl;

	  Initialize();

	  //fill branches
	  run_     = run;
	  lumi_    = lumi;
	  event_   = event;

	  pfMet_    = pfMet;
	  pfMetphi_ = pfMetphi;
	  pfMetT0pc_ =  pfMetT0pc;
	  pfMetT0pcphi_ =  pfMetT0pcphi;
	  pfMetT0pcT1_ =  pfMetT0pcT1;
	  pfMetT0pcT1phi_ =  pfMetT0pcT1phi;
	  pfMetT0pcT1Txy_ =  pfMetT0pcT1Txy;
	  pfMetT0pcT1Txyphi_ =  pfMetT0pcT1Txyphi;
	  pfMetT0pcTxy_ =  pfMetT0pcTxy;
	  pfMetT0pcTxyphi_ =  pfMetT0pcTxyphi;
	  pfMetT0rt_ =  pfMetT0rt;
	  pfMetT0rtphi_ =  pfMetT0rtphi;
	  pfMetT0rtT1_ =  pfMetT0rtT1;
	  pfMetT0rtT1phi_ =  pfMetT0rtT1phi;
	  pfMetT0rtT1Txy_ =  pfMetT0rtT1Txy;
	  pfMetT0rtT1Txyphi_ =  pfMetT0rtT1Txyphi;
	  pfMetT0rtTxy_ =  pfMetT0rtTxy;
	  pfMetT0rtTxyphi_ =  pfMetT0rtTxyphi;
	  pfMetT1_ =  pfMetT1;
	  pfMetT1phi_ =  pfMetT1phi;
	  pfMetT1Txy_ =  pfMetT1Txy;
	  pfMetT1Txyphi_ =  pfMetT1Txyphi;
	  
	  FillBabyNtuple();
	  
	  if(event == 1 && bad)
	   	{cout <<  "\nBAD BAD BAD BAD BAD"  /*run << "   " << lumi << "   " << event << "   "  << pfMet << "  " << pfMetphi*/ << endl;
		  bad = false;}
	}
  /*
  // //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-
  // //Start file loop
  // //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-
  while ( (currentFile = (TFile*)fileIter.Next()) ) 
	{

	  //Get File Content
	  //fix this
	  TFile *file = new TFile( currentFile->GetTitle() ); 
	  TTree *tree = dynamic_cast<TTree*>(file->Get("T1"));
	  cout<<"Loading file: "<<currentFile->GetTitle()<<endl;
  
	  //   	fix this
	  zmet.Init(tree);
	  unsigned int nEventsTree = tree->GetEntries(); 
	  for( unsigned long event = 0; event < nEventsTree; ++event) 
		{
  
		  //	   fix this
		  Get Event Content
			if( nEventsTotal >= nEventsChain ) continue;
		  tree->LoadTree(event);
		  zmet.GetEntry(event);
		  ++nEventsTotal;
		  
		  // pogress
		  long i_permille = (long)floor(1000 * nEventsTotal / double(nEventsChain));
		  if (i_permille != i_permilleOld) 
			{
			  printf("  \015\033[32m ---> \033[1m\033[31m%4.1f%%" "\033[0m\033[32m <---\033[0m\015", i_permille/10.);
			  fflush(stdout);
			  i_permilleOld = i_permille;
			}

		  
		  //~-~-~-~-~-~-~-~-~-//
		  //Analysis Code Here//
		  //~-~-~-~-~-~-~-~-~-//
		  
		  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
		  //event variables
		  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
		  
		  
		}
	  
	  //Clean Up
	  delete tree;
	  file->Close();
	}

  
  if ( nEventsChain != nEventsTotal )
	{
	  cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", (int)nEventsChain, (int)nEventsTotal ) << endl;
	}
  
  return
	bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << nBadEvents   << " Events Failed goodrun" << endl;
  cout << nEventsPass  << " Events Passing" << endl;
  cout << nDuplicates  << " Duplicate events in data" << endl;
  */
  // cout << endl;
  // cout << "------------------------------" << endl;
  // cout << "CPU  Time:	" << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  // cout << "Real Time:	" << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  // cout << endl;
  // delete bmark;

  cout<<"Writing baby to: "<<babyFileName_<<endl;
  // babyFile_->cd();
  babyFile_->Write();
  babyFile_->Close();
  return 0;
  
}

void miniBabyMaker::MakeBabyNtuple()
{

  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  rootdir->cd();

  babyFile_ = new TFile(Form("%s", babyFileName_.c_str()), "RECREATE");
  babyFile_->cd();
  babyTree_ = new TTree("T1", "mini baby for Z-Analysis");


  //add branches
  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
  //event variables
  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
  babyTree_->Branch("run",      &run_,         "run/I" );
  babyTree_->Branch("lumi",     &lumi_  );
  babyTree_->Branch("event",    &event_ );

  babyTree_->Branch("pfMet",    &pfMet_,       "pfMet/F" );
  babyTree_->Branch("pfMetphi", &pfMetphi_,    "pfMetphi/F" );
  babyTree_->Branch("pfMetT0pc",    &pfMetT0pc_,       "pfMetT0pc/F" );
  babyTree_->Branch("pfMetT0pcphi", &pfMetT0pcphi_,    "pfMetT0pcphi/F" );
  babyTree_->Branch("pfMetT0pcT1",    &pfMetT0pcT1_,       "pfMetT0pcT1/F" );
  babyTree_->Branch("pfMetT0pcT1phi", &pfMetT0pcT1phi_,    "pfMetT0pcT1phi/F" );
  babyTree_->Branch("pfMetT0pcT1Txy",    &pfMetT0pcT1Txy_,       "pfMetT0pcT1Txy/F" );
  babyTree_->Branch("pfMetT0pcT1Txyphi", &pfMetT0pcT1Txyphi_,    "pfMetT0pcT1Txyphi/F" );
  babyTree_->Branch("pfMetT0pcTxy",    &pfMetT0pcTxy_,       "pfMetT0pcTxy/F" );
  babyTree_->Branch("pfMetT0pcTxyphi", &pfMetT0pcTxyphi_,    "pfMetT0pcTxyphi/F" );
  babyTree_->Branch("pfMetT0rt",    &pfMetT0rt_,       "pfMetT0rt/F" );
  babyTree_->Branch("pfMetT0rtphi", &pfMetT0rtphi_,    "pfMetT0rtphi/F" );
  babyTree_->Branch("pfMetT0rtT1",    &pfMetT0rtT1_,       "pfMetT0rtT1/F" );
  babyTree_->Branch("pfMetT0rtT1phi", &pfMetT0rtT1phi_,    "pfMetT0rtT1phi/F" );
  babyTree_->Branch("pfMetT0rtT1Txy",    &pfMetT0rtT1Txy_,       "pfMetT0rtT1Txy/F" );
  babyTree_->Branch("pfMetT0rtT1Txyphi", &pfMetT0rtT1Txyphi_,    "pfMetT0rtT1Txyphi/F" );
  babyTree_->Branch("pfMetT0rtTxy",    &pfMetT0rtTxy_,       "pfMetT0rtTxy/F" );
  babyTree_->Branch("pfMetT0rtTxyphi", &pfMetT0rtTxyphi_,    "pfMetT0rtTxyphi/F" );
  babyTree_->Branch("pfMetT1",    &pfMetT1_,       "pfMetT1/F" );
  babyTree_->Branch("pfMetT1phi", &pfMetT1phi_,    "pfMetT1phi/F" );
  babyTree_->Branch("pfMetT1Txy",    &pfMetT1Txy_,       "pfMetT1Txy/F" );
  babyTree_->Branch("pfMetT1Txyphi", &pfMetT1Txyphi_,    "pfMetT1Txyphi/F" );

}

void miniBabyMaker::Initialize()
{

  //add branches
  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
  //event variables
  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
  run_      = 0;
  lumi_     = 0;
  event_    = 0;

  pfMet_    = -999.9;
  pfMetphi_ = -999.9;
  pfMetT0pc_ = -999.9 ;
  pfMetT0pcphi_ = -999.9;
  pfMetT0pcT1_ =  -999.9;
  pfMetT0pcT1phi_ = -999.9;
  pfMetT0pcT1Txy_ =  -999.9;
  pfMetT0pcT1Txyphi_ =  -999.9;
  pfMetT0pcTxy_ =  -999.9;
  pfMetT0pcTxyphi_ =  -999.9;
  pfMetT0rt_ =  -999.9;
  pfMetT0rtphi_ =  -999.9;
  pfMetT0rtT1_ =  -999.9;
  pfMetT0rtT1phi_ =  -999.9;
  pfMetT0rtT1Txy_ =  -999.9;
  pfMetT0rtT1Txyphi_ =  -999.9;
  pfMetT0rtTxy_ =  -999.9;
  pfMetT0rtTxyphi_ =  -999.9;
  pfMetT1_ =  -999.9;
  pfMetT1phi_ =  -999.9;
  pfMetT1Txy_ =  -999.9;
  pfMetT1Txyphi_ =  -999.9;
}

void miniBabyMaker::FillBabyNtuple()
{
  babyTree_->Fill();
}

