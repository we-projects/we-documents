#!/bin/bash

echo -e "\033[1;32m安装tlp解决续航问题\033[0m"

sudo apt-get install -y tlp 

if [[ ${?} -ne 0 ]];
then
    sudo apt-get install -y -f
    sudo apt-get install -y tlp 
fi

sudo mv /etc/default/tlp /etc/default/tlp.bck
sudo cp ./tlp /etc/default/

echo -e "\033[1;32m解决合盖睡眠中断\033[0m"

sudo mv /etc/systemd/system/disable-USB-wakeup.service /etc/systemd/system/disable-USB-wakeup.service.bck 
sudo cp ./disable-USB-wakeup.service /etc/systemd/system/

sudo systemctl enable disable-USB-wakeup.service
sudo systemctl start disable-USB-wakeup.service
