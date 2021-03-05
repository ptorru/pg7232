#!/usr/bin/env bash

LOGS=$1
TIME=$2

echo "Number of Downloads:"
grep -ic "12\.3" $LOGS
grep -ic "14\.1" $LOGS

grep -A2 -e "Device info after" $LOGS | grep "Build" | sed -r "s/Build-Number:(.*)\(RC0\)/\1, / " > log_clean.txt
grep -i "real" $TIME | sed -r "s/(\s*)real(\s*)(.*)m(.*)s/\3, \4/" > times_clean.txt
paste log_clean.txt times_clean.txt > join.csv
