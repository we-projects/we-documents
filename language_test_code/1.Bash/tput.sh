#!/bin/bash

tput clear

tput cup 3 16
tput setaf 3
echo "XYX Corp LTD."
tput sgr0
tput cup 5 14
tput rev
echo "M A I N - M E N U"
tput sgr0
tput cup 7 15
echo "1. User Management"
tput cup 8 15
echo "2. service Management"
tput cup 9 15
echo "3. Process Management"
tput cup 10 15
echo "4. Backup"
tput bold
tput cup 12 14
read -p "Enter your choice [1-4] " choice
tput clear
echo $choice
tput sgr0
tput rc

#printf "\033c"

exit 0
