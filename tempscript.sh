#!/bin/bash
ALL="9 2 3 5 7 1 6 0 4 8"
make
if      [[ $1 == "-v1" ]]
then
./push
else if [[ $1 == "-v2" ]]
then
echo Dwa
else if [[ $1 == "-v3" ]]
then
echo Tri
else if [ 1 == 1 ]
then
((C=0))
((N=10))
while [ $C -ne $N ]
do
	ARR[$C]=$(($C))
	((C++))
done
((P=5))
while [ $P -ne 0 ]
do
((C=0))
while [ $C -ne $N ]
do
	((R=$(($RANDOM%N))))
	((B=${ARR[$R]}))
	((ARR[$R]=${ARR[$C]}))
	((ARR[$C]=$B))
	((C++))
done
((P--))
done
ALL="${ARR[*]}"
fi fi fi fi

#Check OS fedora or MacOS
OS=$(cat /etc/os-release | grep ID=fedora)
if [[ $OS == "ID=fedora" ]]
then
	./push_swap $ALL | ./checker_linux $ALL
else if [ 1 == 1 ]
then
	echo $(./push_swap $ALL | ./checker_Mac $ALL)
fi fi