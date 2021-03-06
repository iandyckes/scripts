#include "TROOT.h"

int run(int which, int file){

  babyMaker *mylooper = new babyMaker();

  char* filename = (file == 0 ? "merged_ntuple_*.root" : Form("merged_ntuple_%i.root", file));
  cout << filename << endl;
  
  char* suffix = file == 0 ? "" : Form("_%i", file);

  //TTbar
  if (which == 0){
    TChain *ttbar = new TChain("Events");
    ttbar->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/merged/%s", filename));
    mylooper->looper(ttbar, Form("ttbar", suffix), -1);
  }

  //T5tttt 1200, 1000, 800
  if (which == 1){
    TChain *t5ww_1 = new TChain("Events");
    t5ww_1->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/T5Full_T5Full-1200-1000-800-Decay-MGMMatch50/merged/%s", filename));
    mylooper->looper(t5ww_1, Form("t5ww_1200_1000_800%s", suffix), -1);
  }

  //T5tttt 1500, 800, 100
  if (which == 2){
    TChain *t5ww_2 = new TChain("Events");
    t5ww_2->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/5Full_T5Full-1500-800-100-Decay-MGMMatch50/merged/%s", filename));
    mylooper->looper(t5ww_2, Form("t5ww_1500_800_100%s", suffix), -1);
  }

  //T1tttt
  if (which == 3){
    TChain *t1tttt = new TChain("Events");
    t1tttt->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola/merged/%s", filename));
    mylooper->looper(t1tttt, Form("t1tttt_1200_800%s", suffix), -1);
  }

  if (which == 4){
    TChain *t1tttt = new TChain("Events");
    t1tttt->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola/merged/%s", filename));
    mylooper->looper(t1tttt, Form("t1tttt_1500_100%s", suffix), -1);
  }

  //ttw
  if  (which == 5){
    TChain *ttw = new TChain("Events");
    ttw->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/TTWJets_Tune4C_13TeV-madgraph-tauola/merged/%s", filename));
    mylooper->looper(ttw, Form("ttw%s", suffix), -1);
  }

  //ttz
  if (which == 6){
    TChain *ttz = new TChain("Events");
    ttz->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/TTZJets_Tune4C_13TeV-madgraph-tauola/merged/%s", filename));
    mylooper->looper(ttz, Form("ttz%s", suffix), -1);
  }

  //WH
  if (which == 7){
    TChain *wh = new TChain("Events");
    wh->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/WH_ZH_HToWW_M-125_13TeV_pythia6/merged/%s", filename));
    mylooper->looper(wh, Form("wh%s", suffix), -1);
  }

  //WW
  if (which == 8){
    TChain *ww = new TChain("Events");
    ww->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/WWTo2L2Nu_CT10_13TeV-powheg-pythia8-tauola/merged/%s", filename));
    mylooper->looper(ww, Form("ww%s", suffix), -1);
  }

  //WZ
  if (which == 9){
    TChain *wz = new TChain("Events");
    wz->Add(Form("/hadoop/cms/store/group/snt/csa14/MC_CMS3_V07-00-04/WZJetsTo3LNu_Tune4C_13TeV-madgraph-tauola/merged/%s", filename));
    mylooper->looper(wz, Form("wz%s", suffix), -1);
  }

}

int do(){

  gROOT->ProcessLine(".L ../../CORE/CMS3.cc+");
  gROOT->ProcessLine(".L ../../CORE/Base.cc+");
  gROOT->ProcessLine(".L ../../CORE/ElectronSelections.cc+");
  gROOT->ProcessLine(".L ../../CORE/MuonSelections.cc+");
  gROOT->ProcessLine(".L ../../CORE/MCSelections.cc+");
  gROOT->ProcessLine(".L ../../CORE/JetSelections.cc+");
  gROOT->ProcessLine(".L ../../CORE/IsolationTools.cc+");
  gROOT->ProcessLine(".L ../../CORE/SSSelections.cc+");
  //  gROOT->ProcessLine(".L ../../CORE/MetSelections.cc+");
  gROOT->ProcessLine(".L fakeratelooper.C++");   //looper.C++

  int file = 0;

  //run(0, file);
  //run(1, file);
  //run(2, file);
  //run(3, file);
  //run(4, file);
  //run(5, file);
  //run(6, file);
  //run(7, file);

  //run(8, file);
  //run(9, file);


  babyMaker *mylooper = new babyMaker();

  //QCD
  TChain *qcd = new TChain("Events");
  qcd->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-20toInf_MuEnrichedPt15_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v3/V07-02-03/merged_ntuple_1.root");//test w/ just 1 file
  
  // //QCD_MuEnriched for 08 version!
  // TChain *qcd_MuEnriched = new TChain("Events");
  // qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-20toInf_MuEnrichedPt15_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v3/V07-02-08/merged_ntuple_*.root");
  // //qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-30to50_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8/V07-02-08/merged_ntuple_*.root"); //bad I think
  // qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-30to50_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v2/V07-02-08/merged_ntuple_*.root");
  // //qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-50to80_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8/V07-02-03/merged_ntuple_*.root");
  // qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-50to80_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v1/V07-02-08/merged_ntuple_*.root");
  // qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-80to120_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v1/V07-02-08/merged_ntuple_*.root");

  //QCD_MuEnriched for 03 version!
  TChain *qcd_MuEnriched = new TChain("Events");
  qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-20toInf_MuEnrichedPt15_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v3/V07-02-03/merged_ntuple_*.root");
  qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-30to50_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v2/V07-02-03/merged_ntuple_*.root");
  qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-50to80_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8/V07-02-03/merged_ntuple_*.root");
  qcd_MuEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-80to120_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v1/V07-02-03/merged_ntuple_*.root");

  //QCD_EM_Enriched
  TChain *qcd_EMEnriched = new TChain("Events");
  qcd_EMEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt_20to30_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v2/V07-02-03/merged_ntuple_*.root");
  qcd_EMEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt_30to80_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-03/merged_ntuple_*.root");  //bad sample
  qcd_EMEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt_80to170_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v2/V07-02-03/merged_ntuple_*.root");
  qcd_EMEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt_170toInf_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-03/merged_ntuple_*.root");
  qcd_EMEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-5to10_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/V07-02-03/merged_ntuple_*.root");
  qcd_EMEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-10to20_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/V07-02-03/merged_ntuple_*.root");
  qcd_EMEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-20to30_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v2/V07-02-03/merged_ntuple_*.root");
  qcd_EMEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-30to80_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/V07-02-03/merged_ntuple_*.root");
  qcd_EMEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-80to170_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/V07-02-03/merged_ntuple_*.root");

  //QCD non-Enriched
  TChain *qcd_nonEnriched = new TChain("Events");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-15to30_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-30to50_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-50to80_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-80to120_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-120to170_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-170to300_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-06/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v2/V07-02-06/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_nonEnriched->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-15to3000_Tune4C_Flat_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");

  //QCD HT
  TChain *qcd_HT = new TChain("Events");
  qcd_HT->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT-100To250_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  //qcd_HT->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_HT->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1/V07-02-08/merged_ntuple_*.root");
  //qcd_HT->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_HT->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1/V07-02-08/merged_ntuple_*.root");
  //qcd_HT->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
  qcd_HT->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/V07-02-08/merged_ntuple_*.root");

  //ttbar
  TChain *ttbar = new TChain("Events");
  // ttbar->Add("/hadoop/cms/store/group/snt/phys14/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-05/merged_ntuple_*.root");
  ttbar->Add("/hadoop/cms/store/group/snt/phys14/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-06/merged_ntuple_*.root");

  //wjets
  TChain *wjets = new TChain("Events");
  wjets->Add("/hadoop/cms/store/group/snt/phys14/WJetsToLNu_13TeV-madgraph-pythia8-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");

  //dy
  TChain *dy = new TChain("Events");
  dy->Add("/hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_13TeV-madgraph-pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");

  
  //mylooper->looper(qcd,"qcd1", -1);
  // mylooper->looper(qcd_MuEnriched,"qcd_MuEnriched", -1);
  // mylooper->looper(qcd_EMEnriched,"qcd_EMEnriched", -1);
  // mylooper->looper(qcd_EMEnriched,"qcd_EMEnriched-noBCtoE", -1);
  // mylooper->looper(qcd_EMEnriched,"qcd_BCtoE_only", -1);
  // mylooper->looper(qcd_nonEnriched,"qcd_nonEnriched", -1);
  // mylooper->looper(qcd_HT,"qcd_HT", -1);
  // //mylooper->looper(ttbar,"ttbar-test", -1);
  mylooper->looper(wjets,"wjets", -1);
  mylooper->looper(dy,"dy", -1);

  //switch to newest version of all samples!!! 30to80_bcTOe still fucked up
}
