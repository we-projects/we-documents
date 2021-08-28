#!/bin/bash

#root_pd=(`echo $result | cut -d '|' -f1`)
#net=(`echo $result | cut -d '|' -f2`)


#root_pd=${root_pd//'&'/' '}


setup() {


    line_num=$(ifconfig | cut -d ':' -f1 | cut -d ' ' -f1 | sed '/^\s*$/d' | wc -l)
    ifconfig | cut -d ':' -f1 | cut -d ' ' -f1 | sed '/^\s*$/d' > tzl

    #cat tzl
    #echo line_num=$line_num

    result=` \
        zenity --forms \
        --title "linux校园网客户端--配置  " \
        --text "提示：网卡请选择有线网卡，一般是以enp开头" \
        --add-password "root密码: " \
        --add-list "认证网卡: " \
        --show-header \
        --column-values "设备: " \
        --list-values "enp3s0|wlp2s0|lo" \
        --ok-label "确定" \
        --cancel-label "取消" \
        `

    result=(`echo ${result//' '/'%blank'}`)

    echo $result > setup_info

}

setup;

cat setup_info

exit;
