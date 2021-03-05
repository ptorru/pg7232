# Introduction

The aim of this lab is to learn how to use some basic tools for *Data Wrangling*.

In simple terms *Data Wrangling* ( I term I found from the (MIT Missing Semester course)[https://missing.csail.mit.edu/2020/data-wrangling/]) is the act of manipulating data in text form in order to for example:
* Extract information
* Create input for a program

There are a lot of different tools, with many different parameters, however we will be focusing on this ones:

* grep:  Used to filter information
* sed:   Is a command line text editor!
* sort:  Sorts...
* uniq:  Counts lines with repeated occurrences
* tail:  Prints the last lines of a file
* head:  Prints the first lines of a file
* paste: Joints two files together.



# The Exercise: Reboot test log analysis
```bash
time fwdownload.py main_12_3.hex
time fwdownload.py main_14_1.hex
```
* How many iterations are there in the test?
* What is the average time taken for each download version?
* Were all the downloads successful?
