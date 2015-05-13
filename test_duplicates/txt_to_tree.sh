#! /bin/bash

function txt_to_tree
{
directory=$1

root -b -q "/home/users/iandyckes/CMSSW_5_3_18/met_corrections_test/IanTmp/doAllTEST.C(\"$1\")";

}

txt_to_tree "./"
# txt_to_tree "/nfs-4/userdata/iand/WZJetsTo2L2Q"




