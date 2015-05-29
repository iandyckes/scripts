//  object#:   no number -> ee, 2 -> MuMu
//
//  e.g. samplehisto -> histogram of ee dilepton mass
//       samplehisto2 -> histogram of MuMu dilepton mass

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TColor.h"
#include "THStack.h"
#include "TPad.h"
#include "TStyle.h"
#include "TString.h"
#include "TMath.h"
#include "TFitResultPtr.h"
#include "TMatrixDSym.h"

using namespace std;

//----------Global Variables---------------//
int mll_minbin=0;  //  Why not 50?
int mll_maxbin=200;
int mll_binsize=5;
int met_minbin=0;  //
int met_maxbin=200;
int met_binsize=2;
int corecutoff=60;
int sumet_minbin=0;
int sumet_maxbin=2500;
int sumet_binsize=5;
//-----------------------------------------//


void h_format(TH1F *histo)
{

  TString name=histo->GetName();
  Color_t color=kMagenta+4;

  histo->Rebin(2);
  histo->SetMarkerSize(0.5);

  if(name.Contains("dy"))     //long because first, needs more formatting
	{
	  color=kCyan;
	  histo->SetFillColor(color);

	  histo->GetXaxis()->SetRangeUser(0,200);  //350
	  histo->GetYaxis()->SetRangeUser(1e-1,5e6);//1e0,5e7
	  
	  histo->GetXaxis()->SetTitle("met_{ll} (GeV)"); 
	  histo->GetYaxis()->SetTitle("Events / 2 GeV");
	}
  // else if(name.Contains("singlet"))
  // 	{color=kGreen-3;
  // 	  histo->SetFillColor(color);}
  else if(name.Contains("wz"))
	{color=kBlue;
	  histo->SetFillColor(color);}
  else if(name.Contains("zz"))
	{color=kRed;
	  histo->SetFillColor(color);}
  // else if(name.Contains("ttbar"))
  // 	{color=kYellow;
  // 	  histo->SetFillColor(color);}
  else if(name.Contains("ww"))
	{color=kBlue-3;
	  histo->SetFillColor(color);}
  // else if(name.Contains("ttv"))
  // 	{color=kGray+1;
  // 	  histo->SetFillColor(color);}
  // else if(name.Contains("vvv"))
  // 	{color=kGray+3;
  // 	  histo->SetFillColor(color);}
  else if(name.Contains("data"))
	{
	  color=kBlack;
	  histo->SetMarkerStyle(8);
	}

  histo->SetMarkerColor(color);
  histo->SetLineColor(kBlack);
 
}


void overflow(TH1F *histo)
{
  double uncertainty=0.;
  int overflowbin=-1;
  TString name=histo->GetName();

  if( name.Contains("met") )
	{overflowbin=((met_maxbin - met_minbin)/met_binsize)+1;}

  histo->SetBinContent(overflowbin,histo->GetBinContent(overflowbin)+histo->IntegralAndError(overflowbin,-1,uncertainty));

  histo->SetBinError(overflowbin,sqrt(pow(histo->GetBinError((overflowbin)),2) + pow(uncertainty,2)));
}


 /*
double find_width(TH1F *histo)
{
  int maxbin = 0;
  maxbin = histo->GetMaximumBin();
  double max = 0;
  max = histo->GetBinContent(maxbin);
  double half_max = 0;
  half_max = pow( 10, 0.5*TMath::Log10(max) );

  int half_maxbin = 0;
  int half_maxbin_low = 0;  
  int half_maxbin_high = 0;  
  int percent_low = 1.00;  //determine if bin content is close enought to half_max
  int percent_high = 0.95;  //determine if bin content is close enought to half_max


  int i = maxbin;
  bool again = true;
  while(again && i<=histo->GetNbinsX())
	{
	  if(TMath::Abs( half_max - histo->GetBinContent(i) ) < percent_low*half_max)
		{
		  half_maxbin_low = i;
		  half_maxbin_high = i;
		  again=false;
		  i++;
		  while(TMath::Abs( half_max - histo->GetBinContent(i) ) < percent_high*half_max && i<=histo->GetNbinsX())
			{half_maxbin_high=i;
			  i++;}
		}
	  else
		{
		  i++;
		}
	}
  
  half_maxbin = (half_maxbin_high + half_maxbin_low)/2;
  double width = 0;
  width = (half_maxbin - maxbin)*histo->GetBinWidth(maxbin);
  cout<<"maxbin = "<<maxbin<<endl;
  cout<<"max = "<<max<<endl;
  cout<<"half_max = "<<half_max<<endl;
  cout<<"half_maxbin_low = "<<half_maxbin_low<<endl;
  cout<<"half_maxbin_high = "<<half_maxbin_high<<endl;
  cout<<"half_maxbin = "<<half_maxbin<<endl;
  return width;
}
 */
void range(TH1F *histo, double &value, double &error, double min)
{
  value = histo->IntegralAndError(histo->FindBin(min),-1,error);	  
}

double err_ratio(double data, double data_err, double MC, double MC_err)
{
  double error=TMath::Sqrt(pow(data_err/MC,2) + pow( data*MC_err/pow(MC,2) ,2) );

  return error;
}

void integrals(TH1F* mc_histo, TH1F* data_histo)
{
  double mc_error1 = 0;
  double mc1 = 0;
  range(mc_histo, mc1, mc_error1, 40.);
  double mc_error2 = 0;
  double mc2 = 0;
  range(mc_histo, mc2, mc_error2, 60.);
  double mc_error3 = 0;
  double mc3 = 0;
  range(mc_histo, mc3, mc_error3, 80.);

  double data_error1 = 0;
  double data1 = 0;
  range(data_histo, data1, data_error1, 40.);
  double data_error2 = 0;
  double data2 = 0;
  range(data_histo, data2, data_error2, 60.);
  double data_error3 = 0;
  double data3 = 0;
  range(data_histo, data3, data_error3, 80.);

  int w=25;
  TString name=mc_histo->GetName();
  if (name.Contains("inc")){cout<<"\n"<<setw(63)<<"INCLUSIVE"<<endl;}
  else if (name.Contains("tar0")){cout<<"\n"<<setw(63)<<"NO JETS"<<endl;}
  else if (name.Contains("tar2")){cout<<"\n"<<setw(63)<<"2 JETS"<<endl;}
  
  cout<<setw(w)<<""<<setw(w)<<"Above 40 GeV"<<setw(w)<<"Above 60 GeV"<<setw(w)<<"Above 80 GeV"<<endl;
  cout<<setw(w)<<"MC"<<setw(w)<<Form("%.2f +/- %.2f",mc1, mc_error1)<<setw(w)<<Form("%.2f +/- %.2f",mc2, mc_error2)<<setw(w)<<Form("%.2f +/- %.2f",mc3, mc_error3)<<endl;
  cout<<setw(w)<<"Data"<<setw(w)<<Form("%.2f +/- %.2f",data1, data_error1)<<setw(w)<<Form("%.2f +/- %.2f",data2, data_error2)<<setw(w)<<Form("%.2f +/- %.2f",data3, data_error3)<<endl;
  cout<<setw(w)<<"Data/MC"<<setw(w)<<Form("%.2f +/- %.2f",data1/mc1, err_ratio(data1, data_error1, mc1, mc_error1) )<<setw(w)<<Form("%.2f +/- %.2f",data2/mc2, err_ratio(data2, data_error2, mc2, mc_error2) )<<setw(w)<<Form("%.2f +/- %.2f",data3/mc3, err_ratio(data3, data_error3, mc3, mc_error3) )<<endl;
  
}

//----------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------//






int DrawPlotsTEST(TString variable)
{
  TFile *InputFile;
  TString plot_title;

  if(variable == "pfMet")
	{
	  InputFile = new TFile("pfMet_histos.root","read");
	  plot_title = "Data vs MC pfMet";
	}
  else if(variable == "pfMetT0pc")
	{
	  InputFile = new TFile("pfMetT0pc_histos.root","read");
	  plot_title = "Data vs MC pfMetT0pc";
	}
  else if(variable == "pfMetT0pcT1")
	{
	  InputFile = new TFile("pfMetT0pcT1_histos.root","read");
	  plot_title = "Data vs MC pfMetT0pcT1";
	}
  else if(variable == "pfMetT0pcT1Txy")
	{
	  InputFile = new TFile("pfMetT0pcT1Txy_histos.root","read");
	  plot_title = "Data vs MC pfMetT0pcT1Txy";
	}
  else if(variable == "pfMetT0pcTxy")
	{
	  InputFile = new TFile("pfMetT0pcTxy_histos.root","read");
	  plot_title = "Data vs MC pfMetT0pcTxy";
	}
  else if(variable == "pfMetT0rt")
	{
	  InputFile = new TFile("pfMetT0rt_histos.root","read");
	  plot_title = "Data vs MC pfMetT0rt";
	}
  else if(variable == "pfMetT0rtT1")
	{
	  InputFile = new TFile("pfMetT0rtT1_histos.root","read");
	  plot_title = "Data vs MC pfMetT0rtT1";
	}
  else if(variable == "pfMetT0rtT1Txy")
	{
	  InputFile = new TFile("pfMetT0rtT1Txy_histos.root","read");
	  plot_title = "Data vs MC pfMetT0rtT1Txy";
	}
  else if(variable == "pfMetT0rtTxy")
	{
	  InputFile = new TFile("pfMetT0rtTxy_histos.root","read");
	  plot_title = "Data vs MC pfMetT0rtTxy";
	}
  else if(variable == "pfMetT1")
	{
	  InputFile = new TFile("pfMetT1_histos.root","read");
	  plot_title = "Data vs MC pfMetT1";
	}
  else if(variable == "pfMetT1Txy")
	{
	  InputFile = new TFile("pfMetT1Txy_histos.root","read");
	  plot_title = "Data vs MC pfMetT1Txy";
	}
  
  //load histos
  TH1F *h_met_dy = (TH1F*) InputFile->Get("dy")->Clone("h_met_dy");
  TH1F *h_met_wz = (TH1F*) InputFile->Get("wz")->Clone("h_met_wz");
  TH1F *h_met_zz = (TH1F*) InputFile->Get("zz")->Clone("h_met_zz");
  TH1F *h_met_ww = (TH1F*) InputFile->Get("ww")->Clone("h_met_ww");
  TH1F *h_met_data = (TH1F*) InputFile->Get("data")->Clone("h_met_data");


  //-------------------------------------------------------------------------------------------------//

  //--------------------------------------Put in Vectors---------------------------------------------//

  vector<TH1F*> v_met;
  v_met.push_back(h_met_dy);
  v_met.push_back(h_met_wz);
  v_met.push_back(h_met_zz);
  v_met.push_back(h_met_ww);
  v_met.push_back(h_met_data);

  int size = v_met.size();
  /*
  //------------------------------------FSBG-------------------------------------------------------------//

  //loop through ee and mumu and subract eu*R.  Before formatting, overflow, summing, and stacking
  int size=v_mll_ee_inc.size();
  
  double Ree = 0.440978;
  double Rmumu = 0.524251;
  double R = Ree+Rmumu;

  for(int i=0; i<size; i++)
	{
	  v_met_ee_inc[i]->Add(v_met_emu_inc[i],-Ree);      //don't forget minus
	  v_met_mumu_inc[i]->Add(v_met_emu_inc[i],-Rmumu);  //can use clones to not permanently change
	  v_met_ee_tar0[i]->Add(v_met_emu_tar0[i],-Ree);      
	  v_met_mumu_tar0[i]->Add(v_met_emu_tar0[i],-Rmumu);  
	  v_met_ee_tar2[i]->Add(v_met_emu_tar2[i],-Ree);      
	  v_met_mumu_tar2[i]->Add(v_met_emu_tar2[i],-Rmumu);
	  v_met_ll_inc[i]->Add(v_met_emu2_inc[i], -R);
	  v_met_ll_tar0[i]->Add(v_met_emu2_tar0[i], -R);
	  v_met_ll_tar2[i]->Add(v_met_emu2_tar2[i], -R);
	  v_sumet_ee_inc[i]->Add(v_sumet_emu_inc[i],-Ree);      //don't forget minus
	  v_sumet_mumu_inc[i]->Add(v_sumet_emu_inc[i],-Rmumu);  //can use clones to not permanently change
	}
  
  //----------------------add ee and mumu----------------------------//
  for(int i=0; i<size; i++)
	{
	  v_mll_ee_inc[i]->Add(v_mll_mumu_inc[i]);
	  v_mll_ee_tar[i]->Add(v_mll_mumu_tar[i]);
	  v_met_ee_inc[i]->Add(v_met_mumu_inc[i]);     
	  v_met_ee_tar0[i]->Add(v_met_mumu_tar0[i]);      
	  v_met_ee_tar2[i]->Add(v_met_mumu_tar2[i]);      
	  v_sumet_ee_inc[i]->Add(v_sumet_mumu_inc[i]);
	}
  //---------------------------------------Format and Overflow---------------------------------------//
*/
	
  for(int i=0; i < size; i++)
	{
	  h_format(v_met[i]);	  
	  overflow(v_met[i]);	  
	}

  cout<<"\n End Formatting \n"<<endl;
  //-------------------------------------------------------------------------------------------------//

  //-------------------------------------  Sum  -----------------------------------------------------//
  

  TH1F *h_met_sum = (TH1F*) v_met[0]->Clone("h_met_sum");

  for(int i=1; i < size-1; i++)    //start at 1 so skip cloned, -1 so you don't add the data.
	{
	  h_met_sum->Add(v_met[i]);
	}

  cout<<"\n End Summing \n"<<endl;

  //--------------------------------------------------------------------------------//
  /*
  TFile *met2d_file = new TFile("met2d.root","recreate");
  met2d_file->cd();
  h_metsum_ll_inc->Write();
  h_metsum_ll_tar0->Write();
  h_metsum_ll_tar2->Write();
  v_met_ll_inc[size-1]->Write();
  v_met_ll_tar0[size-1]->Write();
  v_met_ll_tar2[size-1]->Write();
  met2d_file->Close();  
  */

  //-----------------------
  //Get rid of stat box
  gStyle->SetOptStat(0);
  // gStyle->SetOptFit(1111);
  //-----------------------


  //-------------------------Stacked Histograms--------------------------------------//

  //Declare Stacked Histogram
  THStack *hs_met = new THStack("hs_met","hs_met");

  //Add to Stacked Histograms
  for(int i=size-2; i >= 0; i--)  //Reverse,don't add data
	{
	  // v_met[i]->Scale(1/0.3312825167);
	  hs_met->Add(v_met[i]);
	}
    
  //-----------------------------------------------------------------------------------//
  //----------------------------------Drawing------------------------------------------//
  //-----------------------------------------------------------------------------------//  

  
  //---------------------MET ee INC------------------------------//
  //Canvas
  TCanvas *c1=new TCanvas("c1","Met",800,800);
  TPad *pad_h1 = new TPad("pad_h1","Histo Pad1",0., 0, 1., 0.8);
  TPad *pad_r1 = new TPad("pad_r1","Ratio Pad1",0., 0.8, 1., 1.);

  pad_h1->Draw();
  pad_r1->Draw();

  pad_h1->SetLogy();  //c1->pad_h

  pad_h1->cd();  //change pad

  v_met[0]->SetTitle(plot_title);
  v_met[0]->Draw();      //huh?
  hs_met->Draw("histsame");
 
  v_met[size-1]->Draw("same e1 x0");

  pad_h1->RedrawAxis();  //c1->pad_h
  
  // double width_mc = find_width(h_metsum_ee_inc);
  //double width_data = find_width(v_met_ee_inc[size-1]);
  //cout<<"\nINC MC Width = "<<width_mc<<endl;
  //cout<<"\nINC data Width = "<<width_data<<endl;
  //cout<<"\nINC Width difference = "<<width_data-width_mc<<endl;
  
  integrals(h_met_sum, v_met[size-1]);
  //-------------------------------Legend---------------------------------------//
  TLegend *leg1 = new TLegend(0.78, 0.63, 0.87, 0.89);
  leg1->SetLineColor(kWhite);
  leg1->SetTextFont(42); 
  leg1->SetTextSize(0.026);
  leg1->SetShadowColor(kWhite); 
  leg1->SetFillColor(kWhite); 
  leg1->AddEntry("h_met_data","data","ep");
  leg1->AddEntry("h_met_dy","Drell-Yan","F");
  leg1->AddEntry("h_met_wz","WZ","F");
  leg1->AddEntry("h_met_zz","ZZ","F");
  leg1->AddEntry("h_met_ww","WW","F");

  leg1->Draw();
  //-------------------------------------------------------------//
  //---------------------Ratio Pad-------------------------------//

  pad_r1->cd();

  TH1F *h_met_data_clone = (TH1F*) v_met[size-1]->Clone("h_met_data_clone");

  //  overflow(h_metsum_ee_inc);
  
  //Divide
  h_met_data_clone->Divide(h_met_data_clone,h_met_sum);

  h_met_data_clone->GetXaxis()->SetRangeUser(0,200); 
  h_met_data_clone->GetYaxis()->SetRangeUser(0,2);
  h_met_data_clone->GetYaxis()->SetNdivisions(4);
  h_met_data_clone->GetYaxis()->SetLabelSize(.12);
  h_met_data_clone->GetYaxis()->SetTitle("data/MC");

  pad_r1->SetGridy();

  h_met_data_clone->Draw();

  /*
  TH1F *h_met_data_clone_scaled = (TH1F*) h_met_data_clone->Clone("h_met_data_clone_scaled");
  
  double k = h_met_sum->Integral(0,-1) / v_met[size-1]->Integral(0,-1);
  h_met_data_clone_scaled->Scale( k );  
  
  TFile *metRatioFile = new TFile("met_ratio.root","recreate");
  metRatioFile->cd();
  h_met_data_clone->Write();
  h_met_data_clone_scaled->Write();
  cout << "\nk = "  << k << endl;
  metRatioFile->Close();  
  */
  double dataerror;
  double mcerror;
  cout <<  "\ndata/MC for 0-20 GeV: " << v_met[size-1]->IntegralAndError(v_met[size-1]->FindBin(0), v_met[size-1]->FindBin(20) , dataerror) / h_met_sum->IntegralAndError(h_met_sum->FindBin(0), h_met_sum->FindBin(20) , mcerror) << "\n(Should be close to 1 if corrected)" << endl;	  
  //-------------------------------------------------------------//
   

 
  
  /*
  c1->SaveAs("./3lep_pics/mll_inc.jpg");
  */
  
  return 0;
}
 
