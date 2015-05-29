// -*- C++ -*-
#ifndef mettreestuff_H
#define mettreestuff_H
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

#define PARANOIA

using namespace std; 
class mettreestuff {
private: 
protected: 
	unsigned int index;
	int	run_;
	TBranch *run_branch;
	bool run_isLoaded;
	int	lumi_;
	TBranch *lumi_branch;
	bool lumi_isLoaded;
	Long64_t	event_;
	TBranch *event_branch;
	bool event_isLoaded;
	float	pfMet_;
	TBranch *pfMet_branch;
	bool pfMet_isLoaded;
	float	pfMetphi_;
	TBranch *pfMetphi_branch;
	bool pfMetphi_isLoaded;
	float	pfMetT0pc_;
	TBranch *pfMetT0pc_branch;
	bool pfMetT0pc_isLoaded;
	float	pfMetT0pcphi_;
	TBranch *pfMetT0pcphi_branch;
	bool pfMetT0pcphi_isLoaded;
	float	pfMetT0pcT1_;
	TBranch *pfMetT0pcT1_branch;
	bool pfMetT0pcT1_isLoaded;
	float	pfMetT0pcT1phi_;
	TBranch *pfMetT0pcT1phi_branch;
	bool pfMetT0pcT1phi_isLoaded;
	float	pfMetT0pcT1Txy_;
	TBranch *pfMetT0pcT1Txy_branch;
	bool pfMetT0pcT1Txy_isLoaded;
	float	pfMetT0pcT1Txyphi_;
	TBranch *pfMetT0pcT1Txyphi_branch;
	bool pfMetT0pcT1Txyphi_isLoaded;
	float	pfMetT0pcTxy_;
	TBranch *pfMetT0pcTxy_branch;
	bool pfMetT0pcTxy_isLoaded;
	float	pfMetT0pcTxyphi_;
	TBranch *pfMetT0pcTxyphi_branch;
	bool pfMetT0pcTxyphi_isLoaded;
	float	pfMetT0rt_;
	TBranch *pfMetT0rt_branch;
	bool pfMetT0rt_isLoaded;
	float	pfMetT0rtphi_;
	TBranch *pfMetT0rtphi_branch;
	bool pfMetT0rtphi_isLoaded;
	float	pfMetT0rtT1_;
	TBranch *pfMetT0rtT1_branch;
	bool pfMetT0rtT1_isLoaded;
	float	pfMetT0rtT1phi_;
	TBranch *pfMetT0rtT1phi_branch;
	bool pfMetT0rtT1phi_isLoaded;
	float	pfMetT0rtT1Txy_;
	TBranch *pfMetT0rtT1Txy_branch;
	bool pfMetT0rtT1Txy_isLoaded;
	float	pfMetT0rtT1Txyphi_;
	TBranch *pfMetT0rtT1Txyphi_branch;
	bool pfMetT0rtT1Txyphi_isLoaded;
	float	pfMetT0rtTxy_;
	TBranch *pfMetT0rtTxy_branch;
	bool pfMetT0rtTxy_isLoaded;
	float	pfMetT0rtTxyphi_;
	TBranch *pfMetT0rtTxyphi_branch;
	bool pfMetT0rtTxyphi_isLoaded;
	float	pfMetT1_;
	TBranch *pfMetT1_branch;
	bool pfMetT1_isLoaded;
	float	pfMetT1phi_;
	TBranch *pfMetT1phi_branch;
	bool pfMetT1phi_isLoaded;
	float	pfMetT1Txy_;
	TBranch *pfMetT1Txy_branch;
	bool pfMetT1Txy_isLoaded;
	float	pfMetT1Txyphi_;
	TBranch *pfMetT1Txyphi_branch;
	bool pfMetT1Txyphi_isLoaded;
public: 
void Init(TTree *tree) {
  tree->SetMakeClass(1);
	run_branch = 0;
	if (tree->GetBranch("run") != 0) {
		run_branch = tree->GetBranch("run");
		if (run_branch) {run_branch->SetAddress(&run_);}
	}
	lumi_branch = 0;
	if (tree->GetBranch("lumi") != 0) {
		lumi_branch = tree->GetBranch("lumi");
		if (lumi_branch) {lumi_branch->SetAddress(&lumi_);}
	}
	event_branch = 0;
	if (tree->GetBranch("event") != 0) {
		event_branch = tree->GetBranch("event");
		if (event_branch) {event_branch->SetAddress(&event_);}
	}
	pfMet_branch = 0;
	if (tree->GetBranch("pfMet") != 0) {
		pfMet_branch = tree->GetBranch("pfMet");
		if (pfMet_branch) {pfMet_branch->SetAddress(&pfMet_);}
	}
	pfMetphi_branch = 0;
	if (tree->GetBranch("pfMetphi") != 0) {
		pfMetphi_branch = tree->GetBranch("pfMetphi");
		if (pfMetphi_branch) {pfMetphi_branch->SetAddress(&pfMetphi_);}
	}
	pfMetT0pc_branch = 0;
	if (tree->GetBranch("pfMetT0pc") != 0) {
		pfMetT0pc_branch = tree->GetBranch("pfMetT0pc");
		if (pfMetT0pc_branch) {pfMetT0pc_branch->SetAddress(&pfMetT0pc_);}
	}
	pfMetT0pcphi_branch = 0;
	if (tree->GetBranch("pfMetT0pcphi") != 0) {
		pfMetT0pcphi_branch = tree->GetBranch("pfMetT0pcphi");
		if (pfMetT0pcphi_branch) {pfMetT0pcphi_branch->SetAddress(&pfMetT0pcphi_);}
	}
	pfMetT0pcT1_branch = 0;
	if (tree->GetBranch("pfMetT0pcT1") != 0) {
		pfMetT0pcT1_branch = tree->GetBranch("pfMetT0pcT1");
		if (pfMetT0pcT1_branch) {pfMetT0pcT1_branch->SetAddress(&pfMetT0pcT1_);}
	}
	pfMetT0pcT1phi_branch = 0;
	if (tree->GetBranch("pfMetT0pcT1phi") != 0) {
		pfMetT0pcT1phi_branch = tree->GetBranch("pfMetT0pcT1phi");
		if (pfMetT0pcT1phi_branch) {pfMetT0pcT1phi_branch->SetAddress(&pfMetT0pcT1phi_);}
	}
	pfMetT0pcT1Txy_branch = 0;
	if (tree->GetBranch("pfMetT0pcT1Txy") != 0) {
		pfMetT0pcT1Txy_branch = tree->GetBranch("pfMetT0pcT1Txy");
		if (pfMetT0pcT1Txy_branch) {pfMetT0pcT1Txy_branch->SetAddress(&pfMetT0pcT1Txy_);}
	}
	pfMetT0pcT1Txyphi_branch = 0;
	if (tree->GetBranch("pfMetT0pcT1Txyphi") != 0) {
		pfMetT0pcT1Txyphi_branch = tree->GetBranch("pfMetT0pcT1Txyphi");
		if (pfMetT0pcT1Txyphi_branch) {pfMetT0pcT1Txyphi_branch->SetAddress(&pfMetT0pcT1Txyphi_);}
	}
	pfMetT0pcTxy_branch = 0;
	if (tree->GetBranch("pfMetT0pcTxy") != 0) {
		pfMetT0pcTxy_branch = tree->GetBranch("pfMetT0pcTxy");
		if (pfMetT0pcTxy_branch) {pfMetT0pcTxy_branch->SetAddress(&pfMetT0pcTxy_);}
	}
	pfMetT0pcTxyphi_branch = 0;
	if (tree->GetBranch("pfMetT0pcTxyphi") != 0) {
		pfMetT0pcTxyphi_branch = tree->GetBranch("pfMetT0pcTxyphi");
		if (pfMetT0pcTxyphi_branch) {pfMetT0pcTxyphi_branch->SetAddress(&pfMetT0pcTxyphi_);}
	}
	pfMetT0rt_branch = 0;
	if (tree->GetBranch("pfMetT0rt") != 0) {
		pfMetT0rt_branch = tree->GetBranch("pfMetT0rt");
		if (pfMetT0rt_branch) {pfMetT0rt_branch->SetAddress(&pfMetT0rt_);}
	}
	pfMetT0rtphi_branch = 0;
	if (tree->GetBranch("pfMetT0rtphi") != 0) {
		pfMetT0rtphi_branch = tree->GetBranch("pfMetT0rtphi");
		if (pfMetT0rtphi_branch) {pfMetT0rtphi_branch->SetAddress(&pfMetT0rtphi_);}
	}
	pfMetT0rtT1_branch = 0;
	if (tree->GetBranch("pfMetT0rtT1") != 0) {
		pfMetT0rtT1_branch = tree->GetBranch("pfMetT0rtT1");
		if (pfMetT0rtT1_branch) {pfMetT0rtT1_branch->SetAddress(&pfMetT0rtT1_);}
	}
	pfMetT0rtT1phi_branch = 0;
	if (tree->GetBranch("pfMetT0rtT1phi") != 0) {
		pfMetT0rtT1phi_branch = tree->GetBranch("pfMetT0rtT1phi");
		if (pfMetT0rtT1phi_branch) {pfMetT0rtT1phi_branch->SetAddress(&pfMetT0rtT1phi_);}
	}
	pfMetT0rtT1Txy_branch = 0;
	if (tree->GetBranch("pfMetT0rtT1Txy") != 0) {
		pfMetT0rtT1Txy_branch = tree->GetBranch("pfMetT0rtT1Txy");
		if (pfMetT0rtT1Txy_branch) {pfMetT0rtT1Txy_branch->SetAddress(&pfMetT0rtT1Txy_);}
	}
	pfMetT0rtT1Txyphi_branch = 0;
	if (tree->GetBranch("pfMetT0rtT1Txyphi") != 0) {
		pfMetT0rtT1Txyphi_branch = tree->GetBranch("pfMetT0rtT1Txyphi");
		if (pfMetT0rtT1Txyphi_branch) {pfMetT0rtT1Txyphi_branch->SetAddress(&pfMetT0rtT1Txyphi_);}
	}
	pfMetT0rtTxy_branch = 0;
	if (tree->GetBranch("pfMetT0rtTxy") != 0) {
		pfMetT0rtTxy_branch = tree->GetBranch("pfMetT0rtTxy");
		if (pfMetT0rtTxy_branch) {pfMetT0rtTxy_branch->SetAddress(&pfMetT0rtTxy_);}
	}
	pfMetT0rtTxyphi_branch = 0;
	if (tree->GetBranch("pfMetT0rtTxyphi") != 0) {
		pfMetT0rtTxyphi_branch = tree->GetBranch("pfMetT0rtTxyphi");
		if (pfMetT0rtTxyphi_branch) {pfMetT0rtTxyphi_branch->SetAddress(&pfMetT0rtTxyphi_);}
	}
	pfMetT1_branch = 0;
	if (tree->GetBranch("pfMetT1") != 0) {
		pfMetT1_branch = tree->GetBranch("pfMetT1");
		if (pfMetT1_branch) {pfMetT1_branch->SetAddress(&pfMetT1_);}
	}
	pfMetT1phi_branch = 0;
	if (tree->GetBranch("pfMetT1phi") != 0) {
		pfMetT1phi_branch = tree->GetBranch("pfMetT1phi");
		if (pfMetT1phi_branch) {pfMetT1phi_branch->SetAddress(&pfMetT1phi_);}
	}
	pfMetT1Txy_branch = 0;
	if (tree->GetBranch("pfMetT1Txy") != 0) {
		pfMetT1Txy_branch = tree->GetBranch("pfMetT1Txy");
		if (pfMetT1Txy_branch) {pfMetT1Txy_branch->SetAddress(&pfMetT1Txy_);}
	}
	pfMetT1Txyphi_branch = 0;
	if (tree->GetBranch("pfMetT1Txyphi") != 0) {
		pfMetT1Txyphi_branch = tree->GetBranch("pfMetT1Txyphi");
		if (pfMetT1Txyphi_branch) {pfMetT1Txyphi_branch->SetAddress(&pfMetT1Txyphi_);}
	}
  tree->SetMakeClass(0);
}
void GetEntry(unsigned int idx) 
	// this only marks branches as not loaded, saving a lot of time
	{
		index = idx;
		run_isLoaded = false;
		lumi_isLoaded = false;
		event_isLoaded = false;
		pfMet_isLoaded = false;
		pfMetphi_isLoaded = false;
		pfMetT0pc_isLoaded = false;
		pfMetT0pcphi_isLoaded = false;
		pfMetT0pcT1_isLoaded = false;
		pfMetT0pcT1phi_isLoaded = false;
		pfMetT0pcT1Txy_isLoaded = false;
		pfMetT0pcT1Txyphi_isLoaded = false;
		pfMetT0pcTxy_isLoaded = false;
		pfMetT0pcTxyphi_isLoaded = false;
		pfMetT0rt_isLoaded = false;
		pfMetT0rtphi_isLoaded = false;
		pfMetT0rtT1_isLoaded = false;
		pfMetT0rtT1phi_isLoaded = false;
		pfMetT0rtT1Txy_isLoaded = false;
		pfMetT0rtT1Txyphi_isLoaded = false;
		pfMetT0rtTxy_isLoaded = false;
		pfMetT0rtTxyphi_isLoaded = false;
		pfMetT1_isLoaded = false;
		pfMetT1phi_isLoaded = false;
		pfMetT1Txy_isLoaded = false;
		pfMetT1Txyphi_isLoaded = false;
	}

void LoadAllBranches() 
	// load all branches
{
	if (run_branch != 0) run();
	if (lumi_branch != 0) lumi();
	if (event_branch != 0) event();
	if (pfMet_branch != 0) pfMet();
	if (pfMetphi_branch != 0) pfMetphi();
	if (pfMetT0pc_branch != 0) pfMetT0pc();
	if (pfMetT0pcphi_branch != 0) pfMetT0pcphi();
	if (pfMetT0pcT1_branch != 0) pfMetT0pcT1();
	if (pfMetT0pcT1phi_branch != 0) pfMetT0pcT1phi();
	if (pfMetT0pcT1Txy_branch != 0) pfMetT0pcT1Txy();
	if (pfMetT0pcT1Txyphi_branch != 0) pfMetT0pcT1Txyphi();
	if (pfMetT0pcTxy_branch != 0) pfMetT0pcTxy();
	if (pfMetT0pcTxyphi_branch != 0) pfMetT0pcTxyphi();
	if (pfMetT0rt_branch != 0) pfMetT0rt();
	if (pfMetT0rtphi_branch != 0) pfMetT0rtphi();
	if (pfMetT0rtT1_branch != 0) pfMetT0rtT1();
	if (pfMetT0rtT1phi_branch != 0) pfMetT0rtT1phi();
	if (pfMetT0rtT1Txy_branch != 0) pfMetT0rtT1Txy();
	if (pfMetT0rtT1Txyphi_branch != 0) pfMetT0rtT1Txyphi();
	if (pfMetT0rtTxy_branch != 0) pfMetT0rtTxy();
	if (pfMetT0rtTxyphi_branch != 0) pfMetT0rtTxyphi();
	if (pfMetT1_branch != 0) pfMetT1();
	if (pfMetT1phi_branch != 0) pfMetT1phi();
	if (pfMetT1Txy_branch != 0) pfMetT1Txy();
	if (pfMetT1Txyphi_branch != 0) pfMetT1Txyphi();
}

	int &run()
	{
		if (not run_isLoaded) {
			if (run_branch != 0) {
				run_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch run_branch does not exist!\n");
				exit(1);
			}
			run_isLoaded = true;
		}
		return run_;
	}
	int &lumi()
	{
		if (not lumi_isLoaded) {
			if (lumi_branch != 0) {
				lumi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch lumi_branch does not exist!\n");
				exit(1);
			}
			lumi_isLoaded = true;
		}
		return lumi_;
	}
	Long64_t &event()
	{
		if (not event_isLoaded) {
			if (event_branch != 0) {
				event_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch event_branch does not exist!\n");
				exit(1);
			}
			event_isLoaded = true;
		}
		return event_;
	}
	float &pfMet()
	{
		if (not pfMet_isLoaded) {
			if (pfMet_branch != 0) {
				pfMet_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMet_branch does not exist!\n");
				exit(1);
			}
			pfMet_isLoaded = true;
		}
		return pfMet_;
	}
	float &pfMetphi()
	{
		if (not pfMetphi_isLoaded) {
			if (pfMetphi_branch != 0) {
				pfMetphi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetphi_branch does not exist!\n");
				exit(1);
			}
			pfMetphi_isLoaded = true;
		}
		return pfMetphi_;
	}
	float &pfMetT0pc()
	{
		if (not pfMetT0pc_isLoaded) {
			if (pfMetT0pc_branch != 0) {
				pfMetT0pc_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0pc_branch does not exist!\n");
				exit(1);
			}
			pfMetT0pc_isLoaded = true;
		}
		return pfMetT0pc_;
	}
	float &pfMetT0pcphi()
	{
		if (not pfMetT0pcphi_isLoaded) {
			if (pfMetT0pcphi_branch != 0) {
				pfMetT0pcphi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0pcphi_branch does not exist!\n");
				exit(1);
			}
			pfMetT0pcphi_isLoaded = true;
		}
		return pfMetT0pcphi_;
	}
	float &pfMetT0pcT1()
	{
		if (not pfMetT0pcT1_isLoaded) {
			if (pfMetT0pcT1_branch != 0) {
				pfMetT0pcT1_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0pcT1_branch does not exist!\n");
				exit(1);
			}
			pfMetT0pcT1_isLoaded = true;
		}
		return pfMetT0pcT1_;
	}
	float &pfMetT0pcT1phi()
	{
		if (not pfMetT0pcT1phi_isLoaded) {
			if (pfMetT0pcT1phi_branch != 0) {
				pfMetT0pcT1phi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0pcT1phi_branch does not exist!\n");
				exit(1);
			}
			pfMetT0pcT1phi_isLoaded = true;
		}
		return pfMetT0pcT1phi_;
	}
	float &pfMetT0pcT1Txy()
	{
		if (not pfMetT0pcT1Txy_isLoaded) {
			if (pfMetT0pcT1Txy_branch != 0) {
				pfMetT0pcT1Txy_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0pcT1Txy_branch does not exist!\n");
				exit(1);
			}
			pfMetT0pcT1Txy_isLoaded = true;
		}
		return pfMetT0pcT1Txy_;
	}
	float &pfMetT0pcT1Txyphi()
	{
		if (not pfMetT0pcT1Txyphi_isLoaded) {
			if (pfMetT0pcT1Txyphi_branch != 0) {
				pfMetT0pcT1Txyphi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0pcT1Txyphi_branch does not exist!\n");
				exit(1);
			}
			pfMetT0pcT1Txyphi_isLoaded = true;
		}
		return pfMetT0pcT1Txyphi_;
	}
	float &pfMetT0pcTxy()
	{
		if (not pfMetT0pcTxy_isLoaded) {
			if (pfMetT0pcTxy_branch != 0) {
				pfMetT0pcTxy_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0pcTxy_branch does not exist!\n");
				exit(1);
			}
			pfMetT0pcTxy_isLoaded = true;
		}
		return pfMetT0pcTxy_;
	}
	float &pfMetT0pcTxyphi()
	{
		if (not pfMetT0pcTxyphi_isLoaded) {
			if (pfMetT0pcTxyphi_branch != 0) {
				pfMetT0pcTxyphi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0pcTxyphi_branch does not exist!\n");
				exit(1);
			}
			pfMetT0pcTxyphi_isLoaded = true;
		}
		return pfMetT0pcTxyphi_;
	}
	float &pfMetT0rt()
	{
		if (not pfMetT0rt_isLoaded) {
			if (pfMetT0rt_branch != 0) {
				pfMetT0rt_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0rt_branch does not exist!\n");
				exit(1);
			}
			pfMetT0rt_isLoaded = true;
		}
		return pfMetT0rt_;
	}
	float &pfMetT0rtphi()
	{
		if (not pfMetT0rtphi_isLoaded) {
			if (pfMetT0rtphi_branch != 0) {
				pfMetT0rtphi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0rtphi_branch does not exist!\n");
				exit(1);
			}
			pfMetT0rtphi_isLoaded = true;
		}
		return pfMetT0rtphi_;
	}
	float &pfMetT0rtT1()
	{
		if (not pfMetT0rtT1_isLoaded) {
			if (pfMetT0rtT1_branch != 0) {
				pfMetT0rtT1_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0rtT1_branch does not exist!\n");
				exit(1);
			}
			pfMetT0rtT1_isLoaded = true;
		}
		return pfMetT0rtT1_;
	}
	float &pfMetT0rtT1phi()
	{
		if (not pfMetT0rtT1phi_isLoaded) {
			if (pfMetT0rtT1phi_branch != 0) {
				pfMetT0rtT1phi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0rtT1phi_branch does not exist!\n");
				exit(1);
			}
			pfMetT0rtT1phi_isLoaded = true;
		}
		return pfMetT0rtT1phi_;
	}
	float &pfMetT0rtT1Txy()
	{
		if (not pfMetT0rtT1Txy_isLoaded) {
			if (pfMetT0rtT1Txy_branch != 0) {
				pfMetT0rtT1Txy_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0rtT1Txy_branch does not exist!\n");
				exit(1);
			}
			pfMetT0rtT1Txy_isLoaded = true;
		}
		return pfMetT0rtT1Txy_;
	}
	float &pfMetT0rtT1Txyphi()
	{
		if (not pfMetT0rtT1Txyphi_isLoaded) {
			if (pfMetT0rtT1Txyphi_branch != 0) {
				pfMetT0rtT1Txyphi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0rtT1Txyphi_branch does not exist!\n");
				exit(1);
			}
			pfMetT0rtT1Txyphi_isLoaded = true;
		}
		return pfMetT0rtT1Txyphi_;
	}
	float &pfMetT0rtTxy()
	{
		if (not pfMetT0rtTxy_isLoaded) {
			if (pfMetT0rtTxy_branch != 0) {
				pfMetT0rtTxy_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0rtTxy_branch does not exist!\n");
				exit(1);
			}
			pfMetT0rtTxy_isLoaded = true;
		}
		return pfMetT0rtTxy_;
	}
	float &pfMetT0rtTxyphi()
	{
		if (not pfMetT0rtTxyphi_isLoaded) {
			if (pfMetT0rtTxyphi_branch != 0) {
				pfMetT0rtTxyphi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT0rtTxyphi_branch does not exist!\n");
				exit(1);
			}
			pfMetT0rtTxyphi_isLoaded = true;
		}
		return pfMetT0rtTxyphi_;
	}
	float &pfMetT1()
	{
		if (not pfMetT1_isLoaded) {
			if (pfMetT1_branch != 0) {
				pfMetT1_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT1_branch does not exist!\n");
				exit(1);
			}
			pfMetT1_isLoaded = true;
		}
		return pfMetT1_;
	}
	float &pfMetT1phi()
	{
		if (not pfMetT1phi_isLoaded) {
			if (pfMetT1phi_branch != 0) {
				pfMetT1phi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT1phi_branch does not exist!\n");
				exit(1);
			}
			pfMetT1phi_isLoaded = true;
		}
		return pfMetT1phi_;
	}
	float &pfMetT1Txy()
	{
		if (not pfMetT1Txy_isLoaded) {
			if (pfMetT1Txy_branch != 0) {
				pfMetT1Txy_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT1Txy_branch does not exist!\n");
				exit(1);
			}
			pfMetT1Txy_isLoaded = true;
		}
		return pfMetT1Txy_;
	}
	float &pfMetT1Txyphi()
	{
		if (not pfMetT1Txyphi_isLoaded) {
			if (pfMetT1Txyphi_branch != 0) {
				pfMetT1Txyphi_branch->GetEntry(index);
				#ifdef PARANOIA
				#endif // #ifdef PARANOIA
			} else { 
				printf("branch pfMetT1Txyphi_branch does not exist!\n");
				exit(1);
			}
			pfMetT1Txyphi_isLoaded = true;
		}
		return pfMetT1Txyphi_;
	}

  static void progress( int nEventsTotal, int nEventsChain ){
    int period = 1000;
    if(nEventsTotal%1000 == 0) {
      // xterm magic from L. Vacavant and A. Cerri
      if (isatty(1)) {
        if( ( nEventsChain - nEventsTotal ) > period ){
          float frac = (float)nEventsTotal/(nEventsChain*0.01);
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", frac);
          fflush(stdout);
        }
        else {
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", 100.);
          cout << endl;
        }
      }
    }
  }
  
};

#ifndef __CINT__
extern mettreestuff cmet;
#endif

namespace metcorrnamespace {
	int &run();
	int &lumi();
	Long64_t &event();
	float &pfMet();
	float &pfMetphi();
	float &pfMetT0pc();
	float &pfMetT0pcphi();
	float &pfMetT0pcT1();
	float &pfMetT0pcT1phi();
	float &pfMetT0pcT1Txy();
	float &pfMetT0pcT1Txyphi();
	float &pfMetT0pcTxy();
	float &pfMetT0pcTxyphi();
	float &pfMetT0rt();
	float &pfMetT0rtphi();
	float &pfMetT0rtT1();
	float &pfMetT0rtT1phi();
	float &pfMetT0rtT1Txy();
	float &pfMetT0rtT1Txyphi();
	float &pfMetT0rtTxy();
	float &pfMetT0rtTxyphi();
	float &pfMetT1();
	float &pfMetT1phi();
	float &pfMetT1Txy();
	float &pfMetT1Txyphi();
}
#endif
