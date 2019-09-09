#!/bin/bash

if [ $# -gt 0 ]; then
        printf "%s\t\t%s\t%s\t%s\n" "File" "printf" "scanf" "int"
        for file in "$@"
        do
                printfCount=$(cat $file | grep -io "printf(" | wc -l)
                scanfCount=$(cat $file | grep -io "scanf(" | wc -l)
                intCount=$(cat $file | grep -io "int " | wc -l)
                printf "%s\t%s\t%s\t%s\n" $file $printfCount $scanfCount $intCount
        done
else
        printf "Insufficient arguments\n"
fi
