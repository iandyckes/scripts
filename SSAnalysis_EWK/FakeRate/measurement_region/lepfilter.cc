#include "lepfilter.h"
lepfilter ss;
namespace samesign {
	const float &met() { return ss.met(); }
	const float &metPhi() { return ss.metPhi(); }
	const float &trackerMet() { return ss.trackerMet(); }
	const float &trackerMetPhi() { return ss.trackerMetPhi(); }
	const float &sumet() { return ss.sumet(); }
	const float &metSig() { return ss.metSig(); }
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
	const float &njets() { return ss.njets(); }
	const float &ht() { return ss.ht(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets() { return ss.jets(); }
	const vector<float> &jets_disc() { return ss.jets_disc(); }
	const TString &sample() { return ss.sample(); }
	const int &nFOs() { return ss.nFOs(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &p4() { return ss.p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &mc_p4() { return ss.mc_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &mc_motherp4() { return ss.mc_motherp4(); }
	const int &id() { return ss.id(); }
	const int &idx() { return ss.idx(); }
	const float &d0() { return ss.d0(); }
	const float &dZ() { return ss.dZ(); }
	const float &d0_err() { return ss.d0_err(); }
	const int &motherID() { return ss.motherID(); }
	const int &mc_id() { return ss.mc_id(); }
	const float &iso() { return ss.iso(); }
	const bool &passes_id() { return ss.passes_id(); }
	const bool &passes_id_ptrel() { return ss.passes_id_ptrel(); }
	const bool &FO() { return ss.FO(); }
	const bool &FO_ptrel() { return ss.FO_ptrel(); }
	const bool &FO_NoIso() { return ss.FO_NoIso(); }
	const float &ip3d() { return ss.ip3d(); }
	const float &ip3derr() { return ss.ip3derr(); }
	const int &type() { return ss.type(); }
	const float &mt() { return ss.mt(); }
	const float &ptrelv0() { return ss.ptrelv0(); }
	const float &ptrelv1() { return ss.ptrelv1(); }
	const float &el_sigmaIEtaIEta_full5x5() { return ss.el_sigmaIEtaIEta_full5x5(); }
	const float &el_etaSC() { return ss.el_etaSC(); }
	const float &el_dEtaIn() { return ss.el_dEtaIn(); }
	const float &el_dPhiIn() { return ss.el_dPhiIn(); }
	const float &el_hOverE() { return ss.el_hOverE(); }
	const float &el_ecalEnergy() { return ss.el_ecalEnergy(); }
	const float &el_eOverPIn() { return ss.el_eOverPIn(); }
	const bool &el_conv_vtx_flag() { return ss.el_conv_vtx_flag(); }
	const int &el_exp_innerlayers() { return ss.el_exp_innerlayers(); }
	const int &el_charge() { return ss.el_charge(); }
	const int &el_sccharge() { return ss.el_sccharge(); }
	const int &el_ckf_charge() { return ss.el_ckf_charge(); }
	const bool &el_threeChargeAgree() { return ss.el_threeChargeAgree(); }
	const int &mu_pid_PFMuon() { return ss.mu_pid_PFMuon(); }
	const float &mu_gfit_chi2() { return ss.mu_gfit_chi2(); }
	const float &mu_gfit_ndof() { return ss.mu_gfit_ndof(); }
	const int &mu_gfit_validSTAHits() { return ss.mu_gfit_validSTAHits(); }
	const int &mu_numberOfMatchedStations() { return ss.mu_numberOfMatchedStations(); }
	const int &mu_validPixelHits() { return ss.mu_validPixelHits(); }
	const int &mu_nlayers() { return ss.mu_nlayers(); }
}
