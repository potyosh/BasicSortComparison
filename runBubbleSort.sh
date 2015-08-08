#!/bin/sh

g++ -o genRandomData genRandomData.cpp
g++ -o bubbleSort bubbleSort.cpp

# echo 100 | ./genRandomData
# ./bubbleSort >> result_bubble.txt

rm result_bubble.txt

for i in `seq 1 100`
do
  dataNum=`expr 500 \* ${i}`
  echo ${dataNum} | ./genRandomData
  ./bubbleSort >> result_bubble.txt
  echo $dataNum
done
