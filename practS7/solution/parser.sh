#!/usr/bin/env bash

LOGS=$1
TIME=$2

## Question one: total number of downloads
# Let's try to answer first the number of downloads.
echo "Number of Downloads:"
grep -ic "12\.3" $LOGS
grep -ic "14\.1" $LOGS

echo "why the number for 12.3 does not match 14.1?"


## Question two: average download time?
##               was every download within limits?
# Step 1 select only the version after downloading
grep -A2 -e "Device info after" $LOGS

# Step 2 select only the lines we care about
grep -A2 -e "Device info after" $LOGS | grep "Build"

# Step 3 use sed to extract the build number and add a comma at the end
grep -A2 -e "Device info after" $LOGS | grep "Build" | sed -r "s/Build-Number:(.*)\(RC0\)/\1, / "

# Step 4 similarly, extract in two columns the minutes and seconds for each dowload.
grep -i "real" $TIME | sed -r "s/(\s*)real(\s*)(.*)m(.*)s/\3, \4/" > times_clean.txt

# Full solution
grep -A2 -e "Device info after" $LOGS | grep "Build" | sed -r "s/Build-Number:(.*)\(RC0\)/\1, / " > log_clean.txt
grep -i "real" $TIME | sed -r "s/(\s*)real(\s*)(.*)m(.*)s/\3, \4/" > times_clean.txt

# Final step in this script, join two files into a single csv
paste log_clean.txt times_clean.txt > join.csv

## Question 3: Did the test run as we expected?

# Use sed to get the odd lines, all of them should have a 14.1
cat log_clean.txt | sed -n 'p;n' | grep -c "14.1"

# Used sed to get the even lines, all of them should have a 12.3
cat log_clean.txt | sed -n 'n;p' | grep -c "12.3"

echo "Both numbers should match..."