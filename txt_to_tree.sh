#! /bin/bash

function txt_to_tree
{
directory=$1

root -b -q "/home/users/iandyckes/CMSSW_5_3_18/met_corrections_test/IanTmp/doAllTEST.C(\"$1\")";

}

txt_to_tree "/nfs-4/userdata/iand/WW"
txt_to_tree "/nfs-4/userdata/iand/WZJetsTo2L2Q"
txt_to_tree "/nfs-4/userdata/iand/WZJetsTo2QLNu"
txt_to_tree "/nfs-4/userdata/iand/WZJetsTo3LNu"
txt_to_tree "/nfs-4/userdata/iand/ZZJetsTo2L2Nu"
txt_to_tree "/nfs-4/userdata/iand/ZZJetsTo2L2Q"
txt_to_tree "/nfs-4/userdata/iand/ZZJetsTo4L"


#txt_to_tree "/nfs-4/userdata/iand/DoubleElectron_Run2012A-13Jul2012-v1_AOD"
#txt_to_tree "/nfs-4/userdata/iand/DoubleElectron_Run2012A-recover-06Aug2012-v1_AOD"
#txt_to_tree "/nfs-4/userdata/iand/DoubleMu_Run2012B-13Jul2012-v4_AOD"
#txt_to_tree "/nfs-4/userdata/iand/DoubleElectron_Run2012C-24Aug2012-v1_AOD"
#txt_to_tree "/nfs-4/userdata/iand/DoubleElectron_Run2012C-EcalRecover_11Dec2012-v1_AOD"
#txt_to_tree "/nfs-4/userdata/iand/DoubleMu_Run2012C-PromptReco-v2_AOD"
#txt_to_tree "/nfs-4/userdata/iand/DoubleElectron_Run2012D-16Jan2013-v1_AOD"
#txt_to_tree "/nfs-4/userdata/iand/DoubleMu_Run2012D-PromptReco-v1_AOD"

# MuEG_Run2012A-recover-06Aug2012-v1_AOD
# MuEG_Run2012B-13Jul2012-v1_AOD
# MuEG_Run2012C-24Aug2012-v1_AOD
# MuEG_Run2012C-EcalRecover_11Dec2012-v1_AOD
# MuEG_Run2012C-PromptReco-v2_AOD
# MuEG_Run2012D-16Jan2013-v2_AOD
# MuEG_Run2012D-PromptReco-v1_AOD



