#!/bin/bash

usage(){
	echo "Usage: $0 ext1 ext2"
	exit 1
}

if [ $# -ne 2 ]; then
	usage >&2
fi

for file in *.$1; do
	if [ -f $file ]; then
		mv ${file} ${file%$1}$2
	fi
done
