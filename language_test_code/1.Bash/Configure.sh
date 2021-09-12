#!/bin/bash

sudo apt-get install -y wget curl g++ gcc openssh-server fd tlp manpages-* 

wait;

sudo tlp start

wait;

wget -qO- https://raw.github.com/ma6174/vim/master/setup.sh | sh -x

wait;


