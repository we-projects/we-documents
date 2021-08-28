#!/bin/bash



cat out.txt | cut -d " " -f 3 | sed 's/^/'#'&/g'| \
    zenity --progress \
        --title="linux校园网客户端--认证" \
        --text="认证中..." \
        --percentage=0 
if [ "$?" = -1 ] ; then 
    zenity --error \
        --text="更新被取消。" 
fi


