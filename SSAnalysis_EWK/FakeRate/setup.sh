#! /bin/bash

tag="V00-00-09"
direxample="fake_rate_output"

if [ ! -d $direxample ]; then
	echo "directory $direxample does not exist, creating link to /nfs-7/userdata/$USER/$direxample/$tag."
	mkdir -p /nfs-6/userdata/$USER/$direxample/$tag
	ln -s /nfs-6/userdata/$USER/$direxample/
else
	echo "directory $direxample already exists."		
fi

