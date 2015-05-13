#! /bin/bash

#How to use:
#Pass entries_func the following parameters from the twiki: sample location on hadoop, number of events, xsec, filter eff, and k.
#run ./check_numbers.sh

function entries_func
{
directory=$1
entries=$2
xsec=$3
filter_eff=$4
k=$5

echo root -b -q -l "count_events.C+( \"$directory\", $entries, $xsec, $filter_eff, $k )"
root -b -q -l "count_events.C+( \"$directory\", $entries, $xsec, $filter_eff , $k)"
}



baseD="/hadoop/cms/store/group/snt/phys14";
version="V07-02-03"

# entries_func "$baseD/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/$version/" 1986177 7475 1 1
# entries_func "$baseD/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/$version/" 2001071 587.1 1 1
# entries_func "$baseD/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/$version/" 1997744 167 1 1
# entries_func "$baseD/QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/$version/" 1000065 28.25 1 1
# entries_func "$baseD/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/$version/" 500550 8.195 1 1
# entries_func "$baseD/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/$version/" 199627 0.7346 1 1
# entries_func "$baseD/QCD_Pt-1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/$version/" 200295 0.1091 1 1
# entries_func "$baseD/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v2/$version/" 200079 0.102 1 1
# entries_func "$baseD/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1/$version/" 200453 0.00644 1 1
# entries_func "$baseD/QCD_Pt-3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1/$version/" 200200 0.000163 1 1
# entries_func "$baseD/QCD_Pt-15to3000_Tune4C_Flat_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1/$version/" 1000099 2429000000 1 1

# entries_func "$baseD/QCD_Pt_20to30_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v2/$version/" 999926 675900000 0.00075 1
# entries_func "$baseD/QCD_Pt_30to80_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/$version/" 1852166 185900000 0.00272 1
# entries_func "$baseD/QCD_Pt_80to170_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v2/$version/" 1000671 3495000 0.01225 1
# entries_func "$baseD/QCD_Pt_170toInf_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/$version/" 1000221 128500 0.0406 1
entries_func "$baseD/QCD_Pt-5to10_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/$version/" 2000154 80710000000 0.024 1
entries_func "$baseD/QCD_Pt-10to20_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/$version/" 2000084 8838000000 0.143 1
entries_func "$baseD/QCD_Pt-20to30_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v2/$version/" 1987127 677300000 0.007 1
entries_func "$baseD/QCD_Pt-30to80_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/$version/" 2000838 185900000 0.056 1
entries_func "$baseD/QCD_Pt-80to170_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/$version/" 1959507 3529000 0.158 1

# entries_func "$baseD/QCD_Pt-20toInf_MuEnrichedPt15_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v3/$version/" 4777926 866600000 0.00044 1
# #entries_func "$baseD/QCD_Pt-30to50_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v2/$version/" 3745711 164300000 0.00816 1
# entries_func "$baseD/QCD_Pt-50to80_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8/V07-02-03/" 3896725 21810000 0.01522 1
# entries_func "$baseD/QCD_Pt-50to80_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v1/$version/" 3896725 21810000 0.01522 1  #-08 version
# entries_func "$baseD/QCD_Pt-80to120_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v1/$version/" 3470979 2999000 0.02424 1
