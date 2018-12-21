#!/bin/bash -x

test(){
	echo true
}

output=$(test)
echo $?

echo $output
