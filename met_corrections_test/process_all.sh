#! /bin/bash

directory=/hadoop/cms/store/user/cwelke/correctedMET_data/DoubleMu_Run2012A-recover-06Aug2012-v1_AOD/

for i in $directory*.root; do 
	outfile=`basename $i`
	root -b -q "GetCorrections.cc+(\"$i\", \"$outfile\")";
done


cat /nfs-4/userdata/iand/ntuple*.txt >> /nfs-4/userdata/iand/met_corrections.txt 

sed "s/\*//g" /nfs-4/userdata/iand/met_corrections.txt | grep -v "Row" | sed '/^$/d' | awk '{$1=""; $2=""; sub("  ", " "); print}' | grep -v "overw" > /nfs-4/userdata/iand/formatted_met_corrections.txt
 
