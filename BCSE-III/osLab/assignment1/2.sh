#!/bin/bash
printf "Total number of files in current directory "
find $1 -type f | wc -l

printf "Directory wise file statistics\n"
find $1 -type d -print0 | while read -d '' -r dir; do
    files=("$dir"/*)
    printf "%s \t %d\n" "$dir" "${#files[@]}"
done
printf "\n\nRecent files\n"
year=$(date +%Y)
month=$(date +%m)
day=$(date +%d)
day=$((day-2))
touch --date "$year-$month-$day" /tmp/202173assgn1problem1
find $1 -type f -newer /tmp/202173assgn1problem1
rm /tmp/202173assgn1problem1
printf "\nExiting, thank you\n"
