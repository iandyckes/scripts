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


cat $2/ntuple*.txt >> $output/met_corrections.txt 

sed "s/\*//g" $output/met_corrections.txt | grep -v "Row" | sed '/^$/d' | awk '{$1=""; $2=""; sub("  ", " "); print}' | grep -v "overw" > $output/formatted_met_corrections.txt
}

make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/WWJetsTo2L2Nu_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/WW"
make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/WZJetsTo2L2Q_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/WZJetsTo2L2Q"
make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/WZJetsTo2QLNu_8TeV-madgraph_Summer12_DR53X-PU_S10_START53_V7C-v1_AODSIM/" "/nfs-4/userdata/iand/WZJetsTo2QLNu"
make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/WZJetsTo3LNu_TuneZ2_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/WZJetsTo3LNu"
make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/ZZJetsTo2L2Nu_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v3_AODSIM/" "/nfs-4/userdata/iand/ZZJetsTo2L2Nu"
make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/ZZJetsTo2L2Q_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/ZZJetsTo2L2Q"
make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/ZZJetsTo4L_TuneZ2star_8TeV-madgraph-tauola_Summer12_DR53X-PU_S10_START53_V7A-v1_AODSIM/" "/nfs-4/userdata/iand/ZZJetsTo4L"


# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012A-13Jul2012-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012A-13Jul2012-v1_AOD"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012A-recover-06Aug2012-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012A-recover-06Aug2012-v1_AOD"
#make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleMu_Run2012B-13Jul2012-v4_AOD/" "/nfs-4/userdata/iand/DoubleMu_Run2012B-13Jul2012-v4_AOD"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012C-24Aug2012-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012C-24Aug2012-v1_AOD"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012C-EcalRecover_11Dec2012-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012C-EcalRecover_11Dec2012-v1_AOD"
#make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleMu_Run2012C-PromptReco-v2_AOD/" "/nfs-4/userdata/iand/DoubleMu_Run2012C-PromptReco-v2_AOD"
# make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleElectron_Run2012D-16Jan2013-v1_AOD/" "/nfs-4/userdata/iand/DoubleElectron_Run2012D-16Jan2013-v1_AOD"
#make_txt "/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleMu_Run2012D-PromptReco-v1_AOD/" "/nfs-4/userdata/iand/DoubleMu_Run2012D-PromptReco-v1_AOD"


