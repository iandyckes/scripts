{
  string tag = "V00-00-09";

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *qcd = new TChain("t"); 
  //qcd->Add( Form("../fake_rate_output/%s/qcd_MuEnriched.root",tag.c_str()) );
  //qcd->Add( Form("../fake_rate_output/%s/qcd_EMEnriched.root",tag.c_str()) );
  //qcd->Add( Form("../fake_rate_output/%s/qcd_EMEnriched-noBCtoE.root",tag.c_str()) ); //OVERLAP W/ EMENRICHED BABY
  //qcd->Add( Form("../fake_rate_output/%s/qcd_BCtoE_only.root",tag.c_str()) );         //OVERLAP W/ EMENRICHED BABY
  qcd->Add( Form("../fake_rate_output/%s/wjets.root",tag.c_str()) );
  //qcd->Add( Form("../fake_rate_output/%s/dy.root",tag.c_str()) );

  // ScanChain(qcd,"./rate_histos_qcd.root",""); 
  ScanChain(qcd,"./rate_histos_qcd_noSIP.root","noSIP"); 
  // ScanChain(qcd,"./rate_histos_qcd_ptRel.root","ptRel"); 
  // ScanChain(qcd,"./rate_histos_qcd_ptRel_noSIP.root","ptRel_noSIP");

  // ScanChain(qcd,"./rate_histos_qcd_lowPtRel.root","lowPtRel"); 
  // ScanChain(qcd,"./rate_histos_qcd_noSIP_lowPtRel.root","noSIP_lowPtRel"); 

  // ScanChain(qcd,"./rate_histos_qcd_extrPtRel.root","extrPtRel"); 

  // ScanChain(qcd,"./rate_histos_qcd_doBonly.root","doBonly"); 
  // ScanChain(qcd,"./rate_histos_qcd_noSIP_doBonly.root","noSIP_doBonly"); 
  // ScanChain(qcd,"./rate_histos_qcd_ptRel_doBonly.root","ptRel_doBonly"); 
  // ScanChain(qcd,"./rate_histos_qcd_ptRel_noSIP_doBonly.root","ptRel_noSIP_doBonly"); 

  // ScanChain(qcd,"./rate_histos_qcd_doConly.root","doConly"); 
  // ScanChain(qcd,"./rate_histos_qcd_noSIP_doConly.root","noSIP_doConly"); 
  // ScanChain(qcd,"./rate_histos_qcd_ptRel_doConly.root","ptRel_doBonly"); 
  // ScanChain(qcd,"./rate_histos_qcd_ptRel_noSIP_doConly.root","ptRel_noSIP_doBonly"); 

  // ScanChain(qcd,"./rate_histos_qcd_doLightonly.root","doLightonly"); 
  // ScanChain(qcd,"./rate_histos_qcd_noSIP_doLightonly.root","noSIP_doLightonly");
  // ScanChain(qcd,"./rate_histos_qcd_ptRel_doLightonly.root","ptRel_doBonly"); 
  // ScanChain(qcd,"./rate_histos_qcd_ptRel_noSIP_doLightonly.root","ptRel_noSIP_doBonly"); 

  TChain *qcd_nonEnriched = new TChain("t"); 
  qcd_nonEnriched->Add( Form("../fake_rate_output/%s/qcd_nonEnriched.root",tag.c_str()) );
  
  // ScanChain(qcd_nonEnriched,"./rate_histos_qcdnonEnriched.root",""); 
  // ScanChain(qcd_nonEnriched,"./rate_histos_qcdnonEnriched_noSIP.root","noSIP"); 
  // ScanChain(qcd_nonEnriched,"./rate_histos_qcd_doBonly.root","doBonly"); 
  // ScanChain(qcd_nonEnriched,"./rate_histos_qcd_doConly.root","doConly"); 
  // ScanChain(qcd_nonEnriched,"./rate_histos_qcd_doLightonly.root","doLightonly"); 

  TChain *ttbar = new TChain("t"); 
  ttbar->Add( Form("../fake_rate_output/%s/ttbar.root",tag.c_str()) ); 
  // ScanChain(ttbar, "./rate_histos_ttbar.root",""); 
  // ScanChain(ttbar, "./rate_histos_ttbar_noSIP.root","noSIP"); 
  // ScanChain(ttbar,"./rate_histos_ttbar_doBonly.root","doBonly"); 
  // ScanChain(ttbar,"./rate_histos_ttbar_doConly.root","doConly"); 
  // ScanChain(ttbar,"./rate_histos_ttbar_doLightonly.root","doLightonly"); 
  // ScanChain(ttbar,"./rate_histos_ttbar_extrPtRel.root","extrPtRel"); 
  
}
