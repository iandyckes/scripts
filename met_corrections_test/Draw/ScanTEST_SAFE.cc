//c stuff
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <map>
#include <vector>
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
#include "ScanTEST.h"
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

void miniBabyMaker::new_map(vector<TString> key_vec, TString type, map<TString, TH1F*> &type_map)
{
  int size = key_vec.size();
  //cout << "\nsize = " << size << endl;
  for(int i=0; i < size; i++)
	{
	  //cout << "\ni = " << i << endl; 
	  //cout << "\nvar_vec[i] = " << var_vec[i] << endl; 
	  TString key = key_vec[i];
	  TString name = "h_"+key_vec[i]+"_"+type;
	  //cout << "\nkey = " << key << endl;
	  //cout << "\nname = " << name << endl;
	  type_map[key] = new TH1F(type,name,350,0,350);  //fill with key
	  //	  type_map.at(name)->SetDirectory(rootdir);
	  type_map.at(key)->Sumw2();
	}
}

int miniBabyMaker::ScanTEST(TChain* chain, string goodeventlist_name,int nEvents)
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
  TString file_name="not working";
  //-----------------------------------------
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  //-----------------------------------------

  //----------------------------------------------------------
  vector<TString> key_vec;
  key_vec.push_back("pfMet");
  key_vec.push_back("pfMetT0pc");
  key_vec.push_back("pfMetT0pcT1");
  key_vec.push_back("pfMetT0pcT1Txy");
  key_vec.push_back("pfMetT0pcTxy");
  key_vec.push_back("pfMetT0rt");
  key_vec.push_back("pfMetT0rtT1");
  key_vec.push_back("pfMetT0rtT1Txy");
  key_vec.push_back("pfMetT0rtTxy");
  key_vec.push_back("pfMetT1");
  key_vec.push_back("pfMetT1Txy");

  //cout << "\nkey_vec = " << key_vec[0] << endl;
  map<TString,TH1F*> data_map, dy_map, ww_map, wz_map, zz_map;

  new_map(key_vec,"data", data_map);
  new_map(key_vec,"dy", dy_map);
  new_map(key_vec,"ww", ww_map);
  new_map(key_vec,"wz", wz_map);
  new_map(key_vec,"zz", zz_map);

  map<TString,double> var_map;
  //data_map.at("pfMet")->Draw();
  //----------------------------------------------------------

  //---------------------------------------------------------
  eventFilter goodevents;
  //  goodevents.loadBadEventList("/home/users/iandyckes/DrawPlots/output_SF_INC.txt");
  goodevents.loadBadEventList(goodeventlist_name);

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
		  
		  file_name = currentFile->GetTitle();

		  //Fill var_map
		  //-------------------------------------
		  var_map["pfMet"]=cmet.pfMet();
		  var_map["pfMetT0pc"]=cmet.pfMetT0pc();
		  var_map["pfMetT0pcT1"]=cmet.pfMetT0pcT1();
		  var_map["pfMetT0pcT1Txy"]=cmet.pfMetT0pcT1Txy();
		  var_map["pfMetT0pcTxy"]=cmet.pfMetT0pcTxy();
		  var_map["pfMetT0rt"]=cmet.pfMetT0rt();
		  var_map["pfMetT0rtT1"]=cmet.pfMetT0rtT1();
		  var_map["pfMetT0rtT1Txy"]=cmet.pfMetT0rtT1Txy();
		  var_map["pfMetT0rtTxy"]=cmet.pfMetT0rtTxy();
		  var_map["pfMetT1"]=cmet.pfMetT1();
		  var_map["pfMetT1Txy"]=cmet.pfMetT1Txy();
		  //-------------------------------------

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

		  double Lumi = 19500.;//95.4;  //pb^-1
		  double k = 1;//(6120547.0/6215662.0)/0.629918;  //From rescaling new to old from 0-20 GeV yeilds
		  double mc_scale = -1;	
		  mc_scale =(1/k)* goodevents.geteventweight( cmet.run(), cmet.lumi(), cmet.event() ); //may have to change event data type in goodevents.cc/h


		  DorkyEventIdentifier id = { cmet.run(), cmet.event(), cmet.lumi() };
		  if ( is_duplicate( id ) ){
			//cout << "Found duplicate." << endl;
			nDuplicates++;
			continue;
		  }
		  // cout << "new event" << endl;


		  if( file_name.Contains("Double") || file_name.Contains("EMu") || file_name.Contains("MuE"))   //edited
			{
			  // DorkyEventIdentifier id = { cmet.run(), cmet.event(), cmet.lumi() };
			  // if ( is_duplicate( id ) ){
			  // 	//cout << "Found duplicate." << endl;
			  // 	nDuplicates++;
			  // 	continue;
			  // }
			  // // cout << "new event" << endl;
 
			  fill_map(data_map, var_map, weight_data ); 
			}
	   
		  else if( file_name.Contains("WW") )
			{ 
			  //fillHist(h_met_ww, cmet.pfMet(), mc_scale*cross_WW*Lumi/N_WW ); 
			  fill_map(ww_map, var_map, mc_scale*cross_WW*Lumi/N_WW ); 
			}
		  else if( file_name.Contains("WZ") )
			{
			  if( file_name.Contains("3LNu") )
				{
				  // fillHist(h_met_wz, cmet.pfMet(),mc_scale*cross_WZJetsTo3LNu*Lumi/N_WZJetsTo3LNu ); 
				  fill_map(wz_map, var_map,mc_scale*cross_WZJetsTo3LNu*Lumi/N_WZJetsTo3LNu ); 
				}
			  else if( file_name.Contains("2QLNu") )
				{
				  //fillHist(h_met_wz, cmet.pfMet(), mc_scale*cross_WZJetsTo2QLNu *Lumi/N_WZJetsTo2QLNu  ); 
				  fill_map(wz_map, var_map, mc_scale*cross_WZJetsTo2QLNu *Lumi/N_WZJetsTo2QLNu  ); 
				}
			  else if( file_name.Contains("2L2Q") )
				{
				  //fillHist(h_met_wz, cmet.pfMet(), mc_scale*cross_WZJetsTo2L2Q*Lumi/N_WZJetsTo2L2Q );
				  fill_map(wz_map, var_map, mc_scale*cross_WZJetsTo2L2Q*Lumi/N_WZJetsTo2L2Q );
				}			  
			}
		  else if( file_name.Contains("ZZ") )
			{ 
			  if( file_name.Contains("2L2Q") )
				{
				  //fillHist(h_met_zz, cmet.pfMet(), mc_scale*cross_ZZJetsTo2L2Q*Lumi/N_ZZJetsTo2L2Q );
				  fill_map(zz_map, var_map, mc_scale*cross_ZZJetsTo2L2Q*Lumi/N_ZZJetsTo2L2Q );
				} 
			  else if( file_name.Contains("2L2Nu") )
				{
				  //fillHist(h_met_zz, cmet.pfMet(), mc_scale*cross_ZZJetsTo2L2Nu*Lumi/N_ZZJetsTo2L2Nu );
				  fill_map(zz_map, var_map, mc_scale*cross_ZZJetsTo2L2Nu*Lumi/N_ZZJetsTo2L2Nu );
				} 
			  else if( file_name.Contains("4L") )
				{
				  //fillHist(h_met_zz, cmet.pfMet(), mc_scale*cross_ZZJetsTo4L*Lumi/N_ZZJetsTo4L );
				  fill_map(zz_map, var_map, mc_scale*cross_ZZJetsTo4L*Lumi/N_ZZJetsTo4L );
				} 
			}
		  else if( file_name.Contains("DY") )
			{
			  //fillHist(h_met_dy, cmet.pfMet(), mc_scale*cross_DY*Lumi/N_DY ); 
			  fill_map(dy_map, var_map, mc_scale*cross_DY*Lumi/N_DY ); 
			}

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

  dy_map.at("pfMetT0pc")->Draw();//Change to key

  //Write to file
  //First time it goes through, it recreates the file.
  //Every other time it just updates it.
  //Can't comment out data from doAll!!!!
  //TFile *OutputFile;
  TFile *pfMet_File;
  TFile *pfMetT0pc_File;
  TFile *pfMetT0pcT1_File;
  TFile *pfMetT0pcT1Txy_File;
  TFile *pfMetT0pcTxy_File;
  TFile *pfMetT0rt_File;
  TFile *pfMetT0rtT1_File;
  TFile *pfMetT0rtT1Txy_File;
  TFile *pfMetT0rtTxy_File;
  TFile *pfMetT1_File;
  TFile *pfMetT1Txy_File;

  cout << file_name << endl;

  if(file_name.Contains("MuE") )   //MuE because file iterator ends on it
	{ 
	  // OutputFile = new TFile("rawmet_histos.root","RECREATE");
	  pfMet_File = new TFile("pfMet_histos.root","RECREATE");
	  pfMetT0pc_File = new TFile("pfMetT0pc_histos.root","RECREATE");
	  pfMetT0pcT1_File = new TFile("pfMetT0pcT1_histos.root","RECREATE");
	  pfMetT0pcT1Txy_File = new TFile("pfMetT0pcT1Txy_histos.root","RECREATE");
	  pfMetT0pcTxy_File = new TFile("pfMetT0pcTxy_histos.root","RECREATE");
	  pfMetT0rt_File = new TFile("pfMetT0rt_histos.root","RECREATE");
	  pfMetT0rtT1_File = new TFile("pfMetT0rtT1_histos.root","RECREATE");
	  pfMetT0rtT1Txy_File = new TFile("pfMetT0rtT1Txy_histos.root","RECREATE");
	  pfMetT0rtTxy_File = new TFile("pfMetT0rtTxy_histos.root","RECREATE");
	  pfMetT1_File = new TFile("pfMetT1_histos.root","RECREATE");
	  pfMetT1Txy_File = new TFile("pfMetT1Txy_histos.root","RECREATE");
	  cout << "\nRecreate" << endl;
	}
  else
	{ 
	  //OutputFile = new TFile("rawmet_histos.root","UPDATE"); 
	  pfMet_File = new TFile("pfMet_histos.root","UPDATE");
	  pfMetT0pc_File = new TFile("pfMetT0pc_histos.root","UPDATE");
	  pfMetT0pcT1_File = new TFile("pfMetT0pcT1_histos.root","UPDATE");
	  pfMetT0pcT1Txy_File = new TFile("pfMetT0pcT1Txy_histos.root","UPDATE");
	  pfMetT0pcTxy_File = new TFile("pfMetT0pcTxy_histos.root","UPDATE");
	  pfMetT0rt_File = new TFile("pfMetT0rt_histos.root","UPDATE");
	  pfMetT0rtT1_File = new TFile("pfMetT0rtT1_histos.root","UPDATE");
	  pfMetT0rtT1Txy_File = new TFile("pfMetT0rtT1Txy_histos.root","UPDATE");
	  pfMetT0rtTxy_File = new TFile("pfMetT0rtTxy_histos.root","UPDATE");
	  pfMetT1_File = new TFile("pfMetT1_histos.root","UPDATE");
	  pfMetT1Txy_File = new TFile("pfMetT1Txy_histos.root","UPDATE");	
	  cout << "\nUpdate" << endl;
	}

  //OutputFile->cd();

  //Don't write histo unless looping on correct file
  //Otherwise, you'll replace it with a blank histo
  cout << "\nFILE NAME = " << file_name << endl;

  if( file_name.Contains("MuE") ){
	//h_met_data->Write();
	map_to_file(data_map, pfMet_File, "pfMet");
	map_to_file(data_map, pfMetT0pc_File, "pfMetT0pc");
	map_to_file(data_map, pfMetT0pcT1_File, "pfMetT0pcT1");
	map_to_file(data_map, pfMetT0pcT1Txy_File, "pfMetT0pcT1Txy");
	map_to_file(data_map, pfMetT0pcTxy_File, "pfMetT0pcTxy");
	map_to_file(data_map, pfMetT0rt_File, "pfMetT0rt");
	map_to_file(data_map, pfMetT0rtT1_File, "pfMetT0rtT1");
	map_to_file(data_map, pfMetT0rtT1Txy_File, "pfMetT0rtT1Txy");
	map_to_file(data_map, pfMetT0rtTxy_File, "pfMetT0rtTxy");
	map_to_file(data_map, pfMetT1_File, "pfMetT1");
	map_to_file(data_map, pfMetT1Txy_File, "pfMetT1Txy");
  }
  else if( file_name.Contains("WW") ){
	//h_met_ww->Write(); 
	map_to_file(ww_map, pfMet_File, "pfMet");
	map_to_file(ww_map, pfMetT0pc_File, "pfMetT0pc");
	map_to_file(ww_map, pfMetT0pcT1_File, "pfMetT0pcT1");
	map_to_file(ww_map, pfMetT0pcT1Txy_File, "pfMetT0pcT1Txy");
	map_to_file(ww_map, pfMetT0pcTxy_File, "pfMetT0pcTxy");
	map_to_file(ww_map, pfMetT0rt_File, "pfMetT0rt");
	map_to_file(ww_map, pfMetT0rtT1_File, "pfMetT0rtT1");
	map_to_file(ww_map, pfMetT0rtT1Txy_File, "pfMetT0rtT1Txy");
	map_to_file(ww_map, pfMetT0rtTxy_File, "pfMetT0rtTxy");
	map_to_file(ww_map, pfMetT1_File, "pfMetT1");
	map_to_file(ww_map, pfMetT1Txy_File, "pfMetT1Txy");
  }
  else if( file_name.Contains("WZ") ){
	//h_met_wz->Write();
	map_to_file(wz_map, pfMet_File, "pfMet");
	map_to_file(wz_map, pfMetT0pc_File, "pfMetT0pc");
	map_to_file(wz_map, pfMetT0pcT1_File, "pfMetT0pcT1");
	map_to_file(wz_map, pfMetT0pcT1Txy_File, "pfMetT0pcT1Txy");
	map_to_file(wz_map, pfMetT0pcTxy_File, "pfMetT0pcTxy");
	map_to_file(wz_map, pfMetT0rt_File, "pfMetT0rt");
	map_to_file(wz_map, pfMetT0rtT1_File, "pfMetT0rtT1");
	map_to_file(wz_map, pfMetT0rtT1Txy_File, "pfMetT0rtT1Txy");
	map_to_file(wz_map, pfMetT0rtTxy_File, "pfMetT0rtTxy");
	map_to_file(wz_map, pfMetT1_File, "pfMetT1");
	map_to_file(wz_map, pfMetT1Txy_File, "pfMetT1Txy");
  }
  else if( file_name.Contains("ZZ") ){
	//h_met_zz->Write(); 
	map_to_file(zz_map, pfMet_File, "pfMet");
	map_to_file(zz_map, pfMetT0pc_File, "pfMetT0pc");
	map_to_file(zz_map, pfMetT0pcT1_File, "pfMetT0pcT1");
	map_to_file(zz_map, pfMetT0pcT1Txy_File, "pfMetT0pcT1Txy");
	map_to_file(zz_map, pfMetT0pcTxy_File, "pfMetT0pcTxy");
	map_to_file(zz_map, pfMetT0rt_File, "pfMetT0rt");
	map_to_file(zz_map, pfMetT0rtT1_File, "pfMetT0rtT1");
	map_to_file(zz_map, pfMetT0rtT1Txy_File, "pfMetT0rtT1Txy");
	map_to_file(zz_map, pfMetT0rtTxy_File, "pfMetT0rtTxy");
	map_to_file(zz_map, pfMetT1_File, "pfMetT1");
	map_to_file(zz_map, pfMetT1Txy_File, "pfMetT1Txy");
  }
  else if( file_name.Contains("DY") ){
	//h_met_dy->Write(); 
	map_to_file(dy_map, pfMet_File, "pfMet");
	map_to_file(dy_map, pfMetT0pc_File, "pfMetT0pc");
	map_to_file(dy_map, pfMetT0pcT1_File, "pfMetT0pcT1");
	map_to_file(dy_map, pfMetT0pcT1Txy_File, "pfMetT0pcT1Txy");
	map_to_file(dy_map, pfMetT0pcTxy_File, "pfMetT0pcTxy");
	map_to_file(dy_map, pfMetT0rt_File, "pfMetT0rt");
	map_to_file(dy_map, pfMetT0rtT1_File, "pfMetT0rtT1");
	map_to_file(dy_map, pfMetT0rtT1Txy_File, "pfMetT0rtT1Txy");
	map_to_file(dy_map, pfMetT0rtTxy_File, "pfMetT0rtTxy");
	map_to_file(dy_map, pfMetT1_File, "pfMetT1");
	map_to_file(dy_map, pfMetT1Txy_File, "pfMetT1Txy");
  }

  //OutputFile->Close();

  pfMet_File->Close();
  pfMetT0pc_File->Close();
  pfMetT0pcT1_File->Close();
  pfMetT0pcT1Txy_File->Close();
  pfMetT0pcTxy_File->Close();
  pfMetT0rt_File->Close();
  pfMetT0rtT1_File->Close();
  pfMetT0rtT1Txy_File->Close();
  pfMetT0rtTxy_File->Close();
  pfMetT1_File->Close();
  pfMetT1Txy_File->Close();

  return 0;



}




void miniBabyMaker::fillHist( TH1F* &hist, double variable, const double weight )
//void miniBabyMaker::fillHist( TH1F* hist, double variable, const double weight )
{
  float min = hist->GetXaxis()->GetXmin();
  float max = hist->GetXaxis()->GetXmax();

  if (variable > max) variable = hist->GetBinCenter(hist->GetNbinsX());
  if (variable < min) variable = hist->GetBinCenter(1);

  hist->Fill(variable, weight);
}

void miniBabyMaker::fill_map( map<TString, TH1F*> &m, double pfMet , const double weight )
{
  //typedef std::map<TString, TH1F*>::iterator iter;
  std::map<TString, TH1F*>::iterator iter;
  for(iter = m.begin(); iter != m.end(); iter++ )
	{
	  // if (iter->first == "h_pfMet_data")
	  // 	{fillHist(iter->second, pfMet, weight);}
	  TString key = iter->first;
	  if (key == "pfMet")
		{fillHist(iter->second, pfMet, weight);}
	}
}

void miniBabyMaker::fill_map( map<TString, TH1F*> &m, map<TString, double> var , const double weight )
{
  std::map<TString, TH1F*>::iterator iter;
  for(iter = m.begin(); iter != m.end(); iter++ )
	{
	  TString key = iter->first;
	  fillHist(iter->second, var.at(key), weight);
	}
}

void miniBabyMaker:: map_to_file( map<TString, TH1F*> m, TFile* outfile, TString key) //pass by ref?
{
  // typedef std::map<TString, TH1F*>::iterator iter;
  std::map<TString, TH1F*>::iterator iter;
  for(iter = m.begin(); iter != m.end(); iter++ )
	{
	  TH1F *temp = iter->second;
	  TString hist_name = iter->first;
		  
	  if (hist_name == key){
		outfile->cd();
		temp->Write();}
	}  
}
