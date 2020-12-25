#!/usr/bin/env bash

# https://leetcode.com/problems/valid-phone-numbers

# Read from the file file.txt and output all valid phone numbers to stdout.
grep -E '^(\([[:digit:]]{3}\) |[[:digit:]]{3}-)[[:digit:]]{3}-[[:digit:]]{4}$' file.txt
