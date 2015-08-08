#!/bin/sh

g++ -o genRandomData genRandomData.cpp
g++ -o insertionSort insertionSort.cpp

rm result_insertion.txt

for i in `seq 1 100`
do
  dataNum=`expr 500 \* ${i}`
  echo ${dataNum} | ./genRandomData
  ./insertionSort >> result_insertion.txt
  echo $dataNum
done
