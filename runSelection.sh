#!/bin/sh

g++ -o genRandomData genRandomData.cpp
g++ -o selectionSort selectionSort.cpp

rm result_selection.txt

for i in `seq 1 100`
do
  dataNum=`expr 500 \* ${i}`
  echo ${dataNum} | ./genRandomData
  ./selectionSort >> result_selection.txt
  echo $dataNum
done
