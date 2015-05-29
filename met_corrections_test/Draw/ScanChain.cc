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
#include "TH1F.h"

//stuff from include
#include "ScanChain.h"
#include "mettreestuff.cc"
#include "./GoodEventFilter/badEventFilter/include/badEventFilter.h"
#include "eventFilter.h"

using namespace std;

//3.14159265358979323846

miniBabyMaker::miniBabyMaker()
{
  // babyFileName_ = "test_baby.root";

  // babyTree_ = NULL;
  // babyFile_ = NULL;

  // MakeBabyNtuple();
  
}

// miniBabyMaker::miniBabyMaker( string babyfilename = "test" )
// {
//   babyFileName_ = Form("%s_baby.root", babyfilename.c_str());

//   babyTree_ = NULL;
//   babyFile_ = NULL;

//   MakeBabyNtuple();

// }

miniBabyMaker::~miniBabyMaker(){
  // delete babyFile_;
}

int miniBabyMaker::ScanChain(TChain* chain, int nEvents)
{

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Loop over events to Analyze
  long i_permilleOld = 0;
  unsigned long nEventsTotal = 0;
  unsigned long nDuplicates = 0;
  unsigned long nBadEvents  = 0;
  unsigned long nEventsPass = 0;
  unsigned long nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;
 

  //-----------------------------------------
  TString name="not working";
  //-----------------------------------------
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  //-----------------------------------------

  TH1F *h_met_data = new TH1F("h_met_data", "Data MET INC", 350,0,350);//200,0,2000
  h_met_data->SetDirectory(rootdir);
  h_met_data->Sumw2();

  TH1F *h_met_ww = new TH1F("h_met_ww", "WW MET INC", 350,0,350);//200,0,2000
  h_met_ww->SetDirectory(rootdir);
  h_met_ww->Sumw2();

  TH1F *h_met_wz = new TH1F("h_met_wz", "wZ MET INC", 350,0,350);//200,0,2000
  h_met_wz->SetDirectory(rootdir);
  h_met_wz->Sumw2();

  TH1F *h_met_zz = new TH1F("h_met_zz", "ZZ MET INC", 350,0,350);//200,0,2000
  h_met_zz->SetDirectory(rootdir);
  h_met_zz->Sumw2();

  TH1F *h_met_dy = new TH1F("h_met_dy", "DY MET INC", 350,0,350);//200,0,2000
  h_met_dy->SetDirectory(rootdir);
  h_met_dy->Sumw2();

  //-----------------------------------------

  //-----------------------------------------
  //  TFile *InputFile = new TFile("met_ratio.root","read");
  //  TH1F *h_met_ratio = (TH1F*) InputFile->Get("h_met_data_clone")->Clone("h_met_ratio");  //clone_scaled
  //-----------------------------------------


  eventFilter goodevents;
  goodevents.loadBadEventList("/home/users/iandyckes/DrawPlots/output_SF_INC.txt");

  ofstream failed_events;
  failed_events.open("failed_events.txt");

  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-
  //Start file loop
  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-
  while ( (currentFile = (TFile*)fileIter.Next()) ) 
	{

	  // Get File Content
	  //fix this
	  TFile *file = new TFile( currentFile->GetTitle() ); 
	  TTree *tree = dynamic_cast<TTree*>(file->Get("T1"));
	  cout<<"Loading file: "<<currentFile->GetTitle()<<endl;
	  
	  //fix this
	  cmet.Init(tree);
	  unsigned int nEventsTree = tree->GetEntries(); 
	  for( unsigned long event = 0; event < nEventsTree; ++event) 
		{
		  
		  // fix this
		  // Get Event Content
		  if( nEventsTotal >= nEventsChain ) continue;
		  tree->LoadTree(event);
		  cmet.GetEntry(event);
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
		  if(goodevents.geteventweight( cmet.run(), cmet.lumi(), cmet.event() ) < 0. )
			{
			  //cout << "bad event" << endl;
			  continue;}
		  // cout << "good event" << endl;
		  
		  name = currentFile->GetTitle();
		  
		  double weight_data = 1.;

		  long N_DY = 30447014;  //off, wc -l agrees with number
		  long N_WZJetsTo3LNu = 2017979;
		  long N_WZJetsTo2QLNu = 2908657;
		  long N_WZJetsTo2L2Q = 3187371;//wc -l agrees with number. 3215990 online.  
		  long N_ZZJetsTo2L2Q = 1936727;
		  long N_ZZJetsTo2L2Nu = 954911;
		  long N_ZZJetsTo4L = 4807893;
		  long N_WW = 1933235;
		  // long N_DoubleE = 2371172;
		  // long N_DoubleMu = 722728; // <-correct.  434433
		  // long N_EMu = 1039557;

		  double cross_DY = 3532.8149;        //pb
		  double cross_WZJetsTo3LNu = 1.0575;
		  double cross_WZJetsTo2QLNu = 7.375;
		  double cross_WZJetsTo2L2Q = 2.206;
		  double cross_ZZJetsTo2L2Q = 2.4487;
		  double cross_ZZJetsTo2L2Nu = 0.365;
		  double cross_ZZJetsTo4L = 0.176908;
		  double cross_WW = 5.8123;

		  double Lumi = 95.4;  //pb^-1
		  double k = (6120547.0/6215662.0)/3.14398;  //From rescaling new to old from 0-20 GeV yeilds
		  double mc_scale = -1;	
		  mc_scale =(1/k)* goodevents.geteventweight( cmet.run(), cmet.lumi(), cmet.event() ); //may have to change event data type in goodevents.cc/h

		  if( name.Contains("Double") || name.Contains("EMu") )
			{
			  DorkyEventIdentifier id = { cmet.run(), cmet.event(), cmet.lumi() };
			  if ( is_duplicate( id ) ){
				//cout << "Found duplicate." << endl;
				nDuplicates++;
				continue;
			  }
			  // cout << "new event" << endl;
			  fillHist(h_met_data, cmet.pfMet(), weight_data ); 
			}
	   
		  else if( name.Contains("WW") )
			{ fillHist(h_met_ww, cmet.pfMet(), mc_scale*cross_WW*Lumi/N_WW ); }
		  else if( name.Contains("WZ") )
			{
			  if( name.Contains("3LNu") )
				{ fillHist(h_met_wz, cmet.pfMet(),mc_scale*cross_WZJetsTo3LNu*Lumi/N_WZJetsTo3LNu ); }
			  else if( name.Contains("2QLNu") )
				{ fillHist(h_met_wz, cmet.pfMet(), mc_scale*cross_WZJetsTo2QLNu *Lumi/N_WZJetsTo2QLNu  ); }
			  else if( name.Contains("2L2Q") )
				{ fillHist(h_met_wz, cmet.pfMet(), mc_scale*cross_WZJetsTo2L2Q*Lumi/N_WZJetsTo2L2Q ); }			  
			}
		  else if( name.Contains("ZZ") )
			{ 
			  if( name.Contains("2L2Q") )
				{ fillHist(h_met_zz, cmet.pfMet(), mc_scale*cross_ZZJetsTo2L2Q*Lumi/N_ZZJetsTo2L2Q );} 
			  else if( name.Contains("2L2Nu") )
				{ fillHist(h_met_zz, cmet.pfMet(), mc_scale*cross_ZZJetsTo2L2Nu*Lumi/N_ZZJetsTo2L2Nu );} 
			  else if( name.Contains("4L") )
				{ fillHist(h_met_zz, cmet.pfMet(), mc_scale*cross_ZZJetsTo4L*Lumi/N_ZZJetsTo4L );} 
			}
		  else if( name.Contains("DY") )
			{ fillHist(h_met_dy, cmet.pfMet(), mc_scale*cross_DY*Lumi/N_DY ); }

		  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
		  //event variables
		  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

		}
	  // Clean Up
	  delete tree;
	  file->Close();
	}


  if ( nEventsChain != nEventsTotal )
	{
	  cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", (int)nEventsChain, (int)nEventsTotal ) << endl;
	}

  // return
  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << nBadEvents   << " Events Failed goodrun" << endl;
  cout << nEventsPass  << " Events Passing" << endl;
  cout << nDuplicates  << " Duplicate events in data" << endl;

  cout << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time:	" << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time:	" << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  delete bmark;

  //cout<<"Writing baby to: "<<babyFileName_<<endl;
  // babyFile_->cd();
  //  babyFile_->Write();
  //babyFile_->Close();
  //  return 

  //Write to file
  //First time it goes through, it recreates the file.
  //Every other time it just updates it.
  //Can't comment out data from doAll!!!!
  TFile *OutputFile;

  cout << name << endl;

  if( name.Contains("EMu") )   //EMu because file iterator ends on it
	{ 
	  OutputFile = new TFile("rawmet_histos.root","RECREATE");
	  cout << "\nRecreate" << endl;
	}
  else
	{ 
	  OutputFile = new TFile("rawmet_histos.root","UPDATE"); 
	  cout << "\nUpdate" << endl;
	}

  OutputFile->cd();

  //Don't write histo unless looping on correct file
  //Otherwise, you'll replace it with a blank histo
  if( name.Contains("EMu") )
	{ h_met_data->Write(); }
  else if( name.Contains("WW") )
	{ h_met_ww->Write(); }
  else if( name.Contains("WZ") )
	{ h_met_wz->Write(); }
  else if( name.Contains("ZZ") )
	{ h_met_zz->Write(); }
  else if( name.Contains("DY") )
	{ h_met_dy->Write(); }

  OutputFile->Close();

  failed_events.close();
  
  return 0;
}
/*
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
  run_      = -999;
  lumi_     = -999;
  event_    = -999;

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
*/
/*
void miniBabyMaker::FillBabyNtuple()
{
  babyTree_->Fill();
}
*/

void miniBabyMaker::fillHist( TH1F* &hist, double variable, const double weight )
{
  float min = hist->GetXaxis()->GetXmin();
  float max = hist->GetXaxis()->GetXmax();

  if (variable > max) variable = hist->GetBinCenter(hist->GetNbinsX());
  if (variable < min) variable = hist->GetBinCenter(1);

  hist->Fill(variable, weight);
}
