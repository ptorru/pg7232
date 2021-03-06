---
title: Practice Week 7 - Data Wrangling
created: '2021-03-06T10:38:11.532Z'
modified: '2021-03-06T13:39:08.874Z'
---

# Practice Week 7 - Data Wrangling

## Introduction

The aim of this Practice session is to learn how to use some basic tools for *Data Wrangling* or Data Manipulation.

In simple terms *Data Wrangling* (Term I found from the [MIT Missing Semester course](https://missing.csail.mit.edu/2020/data-wrangling/)) is the act of manipulating data in text form in order to:
* Extract information
* Create input for a program

The text we would usually manipulate in embedded systems may come from:
* Serial Output Messages
* Test/Host programm Messages
* Kernel Logs

```
               ┌───────────────┐
               │               │
               │   Host        │
               │   CPU         │
               │               │
┌──────────┐   │  ┌────────┐   │   ┌─────────────┐
│ Embedded │   │  │ Clean  │   │   │ Useful      │
│   CPU    ├───┼──► Parse  ├───┼───► Information │
│          │   │  │ Process│   │   │             │
└──────────┘   │  └────────┘   │   └─────────────┘
               │               │
               └───────────────┘
```
[Tool Credit: asciiflow](https://asciiflow.com/)

## Regular Expressions
Regular Expressions, also known as regex or regexp, are a string that specify a text search pattern. 

The goal is to be able to describe a text pattern in order to match and thus find the location of this pattern in a given text.

This enables a way of being able to "parse" incoming text, that may have regular patterns but does not contain the same characters, in the same exact positions, all the time.

```
Regular Expressions enable the quick construction
of text parsers.
```

An example of this would be an output message from a program reporting the runtime of an operation in terms of minutes and seconds. As a programmer you would not print this thinking on keeping the same ammount of characters all the time. 

```
What happens if at some point your message needs one more 
character than the number of characters you have allocated?
```

Many of the tools we will see next make use of regular expressions, thus our interest on describing them.


# *Bashing* tools
There are a lot of different tools, with many different parameters, however we will be focusing on this ones:

* grep:  Used to filter information
* sed:   Is a command line text editor!
* sort:  Sorts...
* uniq:  Counts lines with repeated occurrences
* tail:  Prints the last lines of a file
* head:  Prints the first lines of a file
* paste: Joints two files together.


## Grep
```bash
# Try me...
echo """
My data is great
one line 
at a time
""" | grep "time"

# This is the response...
at a time
```

## Sed
```bash
# Seds Substitution command:
# s/ <regex to match> / <thing to substitute with> /
echo "My part is not great" | sed "s/part/foo/"

# Response
My foo is not great

```

## Paste
```bash
echo "line from file 1" > file1
echo "line file 2" > file2
# Paste works with files
paste -d "," file1 file2

# Response
line from file 1,line file 2

```

# Consideration
The objective is to be able to program a computer to "parse" and extract information out of text, which can be runtime logs etc. This allows for on-the-fly debugging but it can also be used to enable test automation.

Bash offer these facilitites we mentioned, they are just there so we can very quickly put them in a script. However the same can be achieved with any other programming languange, specially those with regex libraries like Perl or Python.


# The Exercise: Reboot test log analysis

Consider the following *test.sh* script
```bash
#!/usr/bin/env bash
for number in {1..500}
do
  time fwdownload.py main_12_3.hex 
  time fwdownload.py main_14_1.hex
done
```

We invoke the script using the following command
```bash
# Keeping stdout in log.txt and stderr in times.txt
./test.sh >> log.txt 2>> times.txt
```

* How many iterations are there in the test?
* What is the average time taken for each download version?
* Were all the downloads successful?

## Don't forget!
You have many options, bash, perl, python. I dare say: Java? Rust? Lisp? Choose the tool that gives you best tactical and strategic ROI.

# References
* [Microsoft's Regex Cheatsheet](https://docs.microsoft.com/en-us/dotnet/standard/base-types/regular-expression-language-quick-reference)
* [Wikipedia on Regular Expressions](https://docs.microsoft.com/en-us/dotnet/standard/base-types/regular-expression-language-quick-reference)
* [MIT Missing Semester course](https://missing.csail.mit.edu/2020/data-wrangling/)

# Acronyms
* ROI: Return of Investment
* regex: Regular Expressions
