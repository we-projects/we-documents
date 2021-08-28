#!/bin/bash

num=0
sum=0

if [[ x$1 == x  ]];then
    MAX=10
    else
        MAX=$1
fi

for((i=2;i<$MAX;i++));
do
    flag=1

    for((j=2;j*j<=$i;j++));
    do

        if [[ `expr $i % $j` == 0 ]];then
            flag=0
            break;
        fi

    done

    if [[ $flag == 1 ]];then
        echo $i
        ((sum=$sum+$i))
        ((num=$num+1))
    fi

done

echo "numbers: "$num
echo "sum:     "$sum

