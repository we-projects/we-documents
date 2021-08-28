#!/bin/bash

#cat out.txt | cut -d ' ' -f3 > testss.txt

test=$(tail -1 out.txt | cut -d ' ' -f3)

zenity --info \
--text=$test

