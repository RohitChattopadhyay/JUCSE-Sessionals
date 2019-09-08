#!/bin/bash

read -p "Enter file path   : "  filePath
read -p "Enter search term : "  searchKey

trap exit_nicely INT

function exit_nicely() {
        echo "Exiting program, thank you"
        exit 1
}
if [ -e "$filePath" ]; then
        occurenceCount=$(grep -io "$searchKey" "$filePath" | wc -l)
        if [ $occurenceCount -gt 0 ]; then
                printf "Total Number of occurrences: %s\n" $occurenceCount
                printf "Line No\t|\tFrequency\n"
                echo "--------------------------"
                grep  -ion "$searchKey" "$filePath" | cut -d : -f 1 | uniq -c | awk
'{print $2,"\t|\t",$1}'
        else
                echo "String not found in file"
        fi
else
        echo "File Not Found"
fi
exit_nicely
