#!/bin/bash
#===============================================================
#	File Name:    Change-wallpage.sh
#	Author:       sunowsir
#	Mail:         sunowsir@protonmail.com
#	Created Time: 2018年10月10日 星期三 19时32分58秒
#===============================================================

path="/home/sunowsir/Pictures/girls/"

while true 
do

    name=$(( (RANDOM % 31133) + 1))
    name="${name}.jpg"
    gsettings set org.gnome.desktop.background picture-uri file://${path}${name}
    sleep 60

done
