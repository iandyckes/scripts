#include "lepfilter.h"
lepfilter ss;
namespace samesign {
	const float &met() { return ss.met(); }
	const float &metPhi() { return ss.metPhi(); }
	const int &event() { return ss.event(); }
	const int &lumi() { return ss.lumi(); }
	const int &run() { return ss.run(); }
	const bool &filt_csc() { return ss.filt_csc(); }
	const bool &filt_hbhe() { return ss.filt_hbhe(); }
	const bool &filt_hcallaser() { return ss.filt_hcallaser(); }
	const bool &filt_ecaltp() { return ss.filt_ecaltp(); }
	const bool &filt_trkfail() { return ss.filt_trkfail(); }
	const bool &filt_eebadsc() { return ss.filt_eebadsc(); }
	const bool &is_real_data() { return ss.is_real_data(); }
	const float &scale1fb() { return ss.scale1fb(); }
	const float &xsec() { return ss.xsec(); }
	const float &kfactor() { return ss.kfactor(); }
	const float &gen_met() { return ss.gen_met(); }
	const float &gen_met_phi() { return ss.gen_met_phi(); }
	const int &njets() { return ss.njets(); }
	const int &hyp_class() { return ss.hyp_class(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4() { return ss.lep1_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4() { return ss.lep2_p4(); }
	const float &ht() { return ss.ht(); }
	const int &lep1_motherID() { return ss.lep1_motherID(); }
	const int &lep2_motherID() { return ss.lep2_motherID(); }
	const int &lep1_mc_id() { return ss.lep1_mc_id(); }
	const int &lep2_mc_id() { return ss.lep2_mc_id(); }
	const int &lep1_id() { return ss.lep1_id(); }
	const int &lep2_id() { return ss.lep2_id(); }
	const int &lep1_idx() { return ss.lep1_idx(); }
	const int &lep2_idx() { return ss.lep2_idx(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets() { return ss.jets(); }
	const vector<float> &btags_disc() { return ss.btags_disc(); }
	const vector<float> &jets_disc() { return ss.jets_disc(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &btags() { return ss.btags(); }
	const int &nbtags() { return ss.nbtags(); }
	const float &sf_dilepTrig_hpt() { return ss.sf_dilepTrig_hpt(); }
	const float &sf_dilepTrig_lpt() { return ss.sf_dilepTrig_lpt(); }
	const float &sf_dilepTrig_vlpt() { return ss.sf_dilepTrig_vlpt(); }
	const int &hyp_type() { return ss.hyp_type(); }
	const float &sf_dilep_eff() { return ss.sf_dilep_eff(); }
	const float &mt() { return ss.mt(); }
	const float &mt_l2() { return ss.mt_l2(); }
	const float &mt2() { return ss.mt2(); }
	const float &mtmin() { return ss.mtmin(); }
	const float &mGluino() { return ss.mGluino(); }
	const float &mLSP() { return ss.mLSP(); }
	const float &mSbottom() { return ss.mSbottom(); }
	const float &mChargino() { return ss.mChargino(); }
	const int &lep1_id_gen() { return ss.lep1_id_gen(); }
	const int &lep2_id_gen() { return ss.lep2_id_gen(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4_gen() { return ss.lep1_p4_gen(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4_gen() { return ss.lep2_p4_gen(); }
	const int &lep3_id() { return ss.lep3_id(); }
	const int &lep3_idx() { return ss.lep3_idx(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep3_p4() { return ss.lep3_p4(); }
	const int &lep3_quality() { return ss.lep3_quality(); }
	const float &lep1_iso() { return ss.lep1_iso(); }
	const float &lep2_iso() { return ss.lep2_iso(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &dilep_p4() { return ss.dilep_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4() { return ss.genps_p4(); }
	const vector<int> &genps_id() { return ss.genps_id(); }
	const vector<int> &genps_id_mother() { return ss.genps_id_mother(); }
	const vector<int> &genps_status() { return ss.genps_status(); }
	const vector<int> &genps_id_grandma() { return ss.genps_id_grandma(); }
	const bool &lep1_passes_id() { return ss.lep1_passes_id(); }
	const bool &lep2_passes_id() { return ss.lep2_passes_id(); }
	const float &lep1_dxyPV() { return ss.lep1_dxyPV(); }
	const float &lep2_dxyPV() { return ss.lep2_dxyPV(); }
	const float &lep1_dZ() { return ss.lep1_dZ(); }
	const float &lep2_dZ() { return ss.lep2_dZ(); }
	const float &lep1_d0_err() { return ss.lep1_d0_err(); }
	const float &lep2_d0_err() { return ss.lep2_d0_err(); }
	const float &lep1_ip3d() { return ss.lep1_ip3d(); }
	const float &lep2_ip3d() { return ss.lep2_ip3d(); }
	const float &lep1_ip3d_err() { return ss.lep1_ip3d_err(); }
	const float &lep2_ip3d_err() { return ss.lep2_ip3d_err(); }
	const int &nVetoElectrons7() { return ss.nVetoElectrons7(); }
	const int &nVetoElectrons10() { return ss.nVetoElectrons10(); }
	const int &nVetoElectrons25() { return ss.nVetoElectrons25(); }
	const int &nVetoMuons5() { return ss.nVetoMuons5(); }
	const int &nVetoMuons10() { return ss.nVetoMuons10(); }
	const int &nVetoMuons25() { return ss.nVetoMuons25(); }
	const TString &filename() { return ss.filename(); }
	const float &lep1_ptrel_v0() { return ss.lep1_ptrel_v0(); }
	const float &lep1_ptrel_v1() { return ss.lep1_ptrel_v1(); }
	const float &lep2_ptrel_v0() { return ss.lep2_ptrel_v0(); }
	const float &lep2_ptrel_v1() { return ss.lep2_ptrel_v1(); }
	const float &lep1_miniIso() { return ss.lep1_miniIso(); }
	const float &lep2_miniIso() { return ss.lep2_miniIso(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jet_close_lep1() { return ss.jet_close_lep1(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jet_close_lep2() { return ss.jet_close_lep2(); }
	const vector<int> &eleID_kfhits() { return ss.eleID_kfhits(); }
	const vector<float> &eleID_oldsigmaietaieta() { return ss.eleID_oldsigmaietaieta(); }
	const vector<float> &eleID_oldsigmaiphiiphi() { return ss.eleID_oldsigmaiphiiphi(); }
	const vector<float> &eleID_oldcircularity() { return ss.eleID_oldcircularity(); }
	const vector<float> &eleID_oldr9() { return ss.eleID_oldr9(); }
	const vector<float> &eleID_scletawidth() { return ss.eleID_scletawidth(); }
	const vector<float> &eleID_sclphiwidth() { return ss.eleID_sclphiwidth(); }
	const vector<float> &eleID_he() { return ss.eleID_he(); }
	const vector<float> &eleID_psEoverEraw() { return ss.eleID_psEoverEraw(); }
	const vector<float> &eleID_kfchi2() { return ss.eleID_kfchi2(); }
	const vector<float> &eleID_chi2_hits() { return ss.eleID_chi2_hits(); }
	const vector<float> &eleID_fbrem() { return ss.eleID_fbrem(); }
	const vector<float> &eleID_ep() { return ss.eleID_ep(); }
	const vector<float> &eleID_eelepout() { return ss.eleID_eelepout(); }
	const vector<float> &eleID_IoEmIop() { return ss.eleID_IoEmIop(); }
	const vector<float> &eleID_deltaetain() { return ss.eleID_deltaetain(); }
	const vector<float> &eleID_deltaphiin() { return ss.eleID_deltaphiin(); }
	const vector<float> &eleID_deltaetaseed() { return ss.eleID_deltaetaseed(); }
	const vector<float> &eleID_pT() { return ss.eleID_pT(); }
	const vector<bool> &eleID_isbarrel() { return ss.eleID_isbarrel(); }
	const vector<bool> &eleID_isendcap() { return ss.eleID_isendcap(); }
	const vector<float> &eleID_scl_eta() { return ss.eleID_scl_eta(); }
	const vector<float> &muID_dzPV() { return ss.muID_dzPV(); }
	const vector<float> &muID_ptSig() { return ss.muID_ptSig(); }
	const vector<float> &muID_ip3dSig() { return ss.muID_ip3dSig(); }
	const vector<float> &muID_medMuonPOG() { return ss.muID_medMuonPOG(); }
	const vector<float> &muID_pt() { return ss.muID_pt(); }
	const vector<float> &muID_eta() { return ss.muID_eta(); }
	const bool &lep1_isGoodLeg() { return ss.lep1_isGoodLeg(); }
	const bool &lep2_isGoodLeg() { return ss.lep2_isGoodLeg(); }
	const bool &lep1_isFakeLeg() { return ss.lep1_isFakeLeg(); }
	const bool &lep2_isFakeLeg() { return ss.lep2_isFakeLeg(); }
	const bool &truth_inSituFR() { return ss.truth_inSituFR(); }
	const bool &lep1_multiIso() { return ss.lep1_multiIso(); }
	const bool &lep2_multiIso() { return ss.lep2_multiIso(); }
	const float &lep1_sip() { return ss.lep1_sip(); }
	const float &lep2_sip() { return ss.lep2_sip(); }
}
