#!/bin/sh

g++ -o genRandomData genRandomData.cpp
g++ -o shellSort shellSort.cpp

#echo 100 | ./genRandomData
#./shellSort >> result_shell.txt

rm result_shell.txt

for i in `seq 1 100`
do
  dataNum=`expr 500 \* ${i}`
  echo ${dataNum} | ./genRandomData
  ./shellSort >> result_shell.txt
  echo $dataNum
done
