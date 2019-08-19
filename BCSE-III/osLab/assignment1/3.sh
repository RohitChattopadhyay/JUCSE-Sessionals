#!/bin/bash

stats=$(stat $1)
searchstring="Blocks: "
rest=${stats#*$searchstring}
sIdx=$(( ${#stats} - ${#rest}))
searchstring="IO Block"
rest=${stats#*$searchstring}
eIdx=$((${#stats} - $sIdx - ${#searchstring} - ${#rest}))
printf "%s occupies %d blocks.\n" "$1" ${stats:sIdx:eIdx}
printf "Exiting, thank you\n"

