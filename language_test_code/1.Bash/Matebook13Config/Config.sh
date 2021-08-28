#!/bin/bash

# tlp

sudo apt-get install -y tlp;

if [[ ${?} -ne 0 ]];
then
    sudo apt-get install -y -f; 
    sudo apt-get install -y tlp;
fi


sudo mv /etc/default/tlp /etc/default/tlp.bak.old;
sudo cp ./tlp /etc/default/;


# 盒盖睡眠中断

ServerDir="/etc/systemd/system";
ServerFile="disable-USB-wakeup.service";

if [[ -f ${ServerDir}/${ServerFile} ]];
then
    sudo mv ${ServerDir}/${ServerFile} ${ServerDir}/disable-USB-wakeup.service.bak.old;
fi

sudo cp ./${ServerFile} ${ServerDir};

sudo systemctl enable disable-USB-wakeup.service
sudo systemctl start disable-USB-wakeup.service
