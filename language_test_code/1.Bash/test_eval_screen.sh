#!/bin/bash

while read key value 
    do
        eval "${key}=${value}"
    done < test_eval

var=$1

res=`eval echo '$'"$var"`

echo $res
