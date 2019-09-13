#!/bin/bash
read -p "Enter the file : " File
read -p "Enter the search : " search

if [ -e "$File" ]
then
	occurence=$(grep -io "$search" "$File" | wc -l )
	if [ $occurence -gt 0 ]
	then
		echo "Total number of occurence of word $search is : " $occurence
		read -p "Enter the word to be replaced : " replace
		sed -i 's/\<'"$search"'\>/'"$replace"'/g' $File
		echo "Done"
		cat $File
	fi
else
	echo "File not found "
fi
