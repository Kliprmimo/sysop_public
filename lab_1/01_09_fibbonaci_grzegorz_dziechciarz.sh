#!/bin/bash
first=0
second=1
for ((i=0; i<$1; i++))
do
        echo "$first"
        prev=$first
        first=$(($second+$first))
        second=$prev
done
        