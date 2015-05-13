#! /bin/bash

function make_txt
{
#directory=/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleMu_Run2012A-recover-06Aug2012-v1_AOD/
directory=$1
output=$2

#mkdir $output

for i in $directory*.root; do 
	base=`basename $i`
	slash='/'
	outfile=$output$slash$base
	root -b -q "GetCorrectionsTEST.cc+(\"$i\", \"$outfile\")";
done

cat $2/*.txt >> $output/met_corrections.txt #FOR MINIAOD!!!!!
#cat $2/ntuple*.txt >> $output/met_corrections.txt   #FOR CMS3!!!!!  SAFER!!!!

sed "s/\*//g" $output/met_corrections.txt | grep -v "Row" | sed '/^$/d' | awk '{$1=""; sub("  ", " "); print}' | grep -v "overw" > $output/formatted_met_corrections.txt
#sed "s/\*//g" $output/met_corrections.txt | grep -v "Row" | sed '/^$/d' | awk '{$1=""; $2=""; sub("  ", " "); print}' | grep -v "overw" > $output/formatted_met_corrections.txt  #cuts off first column.

# #mv ntuple*.txt ./unmerged_txt_0/
# mv *296F*-00*.txt unmerged_txt_0/
# mv *met_corrections.txt ./unmerged_txt_0/

# mv *2670*-00*.txt unmerged_txt_1/
# mv *met_corrections.txt ./unmerged_txt_1/

#mv *.txt ./dy_0/
mv *.txt ./dy_1/

}


#make_txt "/hadoop/cms/phedex/store/mc/Phys14DR/QCD_Pt_30to80_bcToE_Tune4C_13TeV_pythia8/MINIAODSIM/PU20bx25_PHYS14_25_V1-v1/00000/" "."
#make_txt "/hadoop/cms/phedex/store/mc/Phys14DR/QCD_Pt_30to80_bcToE_Tune4C_13TeV_pythia8/MINIAODSIM/PU20bx25_PHYS14_25_V1-v1/10000/" "."

#make_txt "/hadoop/cms/phedex/store/mc/Phys14DR/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU20bx25_PHYS14_25_V1-v1/00000/" "."
make_txt "/hadoop/cms/phedex/store/mc/Phys14DR/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola/MINIAODSIM/PU20bx25_PHYS14_25_V1-v1/10000/" "."

#make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/WWJetsTo2L2Nu_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "."
#make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/WWJetsTo2L2Nu_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/WW"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/WZJetsTo2L2Q_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/WZJetsTo2L2Q"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/WZJetsTo2QLNu_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1_AODSIM/" "/nfs-4/userdata/iand/WZJetsTo2QLNu"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/WZJetsTo3LNu_TuneZ2_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/WZJetsTo3LNu"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/ZZJetsTo2L2Nu_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v3_AODSIM/" "/nfs-4/userdata/iand/ZZJetsTo2L2Nu"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/ZZJetsTo2L2Q_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/ZZJetsTo2L2Q"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/ZZJetsTo4L_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/ZZJetsTo4L"


# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012A-13Jul2012-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012A-13Jul2012-v1_AOD"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012A-recover-06Aug2012-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012A-recover-06Aug2012-v1_AOD"
#make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleMu_Run2012B-13Jul2012-v4_AOD/" "/nfs-4/userdata/iand/DoubleMu_Run2012B-13Jul2012-v4_AOD"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012C-24Aug2012-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012C-24Aug2012-v1_AOD"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012C-EcalRecover_11Dec2012-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012C-EcalRecover_11Dec2012-v1_AOD"
#make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleMu_Run2012C-PromptReco-v2_AOD/" "/nfs-4/userdata/iand/DoubleMu_Run2012C-PromptReco-v2_AOD"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012D-16Jan2013-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012D-16Jan2013-v1_AOD"
#make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleMu_Run2012D-PromptReco-v1_AOD/" "/nfs-4/userdata/iand/DoubleMu_Run2012D-PromptReco-v1_AOD"


