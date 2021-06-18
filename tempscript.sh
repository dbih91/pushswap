#!/bin/bash

# RANDOM GENERATOR #
((C=0))
((N=500))
if [ $2 ]; then
	((N=$2)); fi
while [ $C -ne $N ]
do
	ARR[$C]=$(($C))
	if [ 1 -ne 1 ]; then
	if [ $(($RANDOM%2)) -ne 0 ]; then
	ARR[$C]=$(($C * -1))
	fi fi
	((C++))
done
((P=3))
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
# RANDOM GENERATOR #

ALL="9 2 3 5 7 1 6 0 4 8"

ALL="${ARR[*]}"

make
if      [[ $1 == "-v1" ]]
then
./push_swap $1 $ALL
else if [[ $1 == "-v2" ]]
then
./push_swap $1 $ALL
else if [[ $1 == "-v3" ]]
then
./push_swap $1 $ALL
else if [[ $1 == "-v4" ]]
then
./push_swap $1 $ALL
else if [[ $1 == "-v5" ]]
then
./push_swap $1 $ALL
else if [ 1 == 1 ]
then

#Check OS fedora or MacOS
OS=$(ls /etc | grep os-release)
if [[ $OS == "os-release" ]]
then
	./push_swap $ALL | ./checker_linux $ALL
else if [ 1 == 1 ]
then
	./push_swap $ALL | ./checker_Mac $ALL
fi fi fi fi fi fi fi fi