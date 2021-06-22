#!/bin/bash
make
AVG=$(($2 * 10))
MAX="0"
ITR="1"
RET="OK"
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
while [[ $MAX < 700 ]]  #[ $RET != KO ]
do
if [[ $RET != "OK" ]]
then
break
fi
# RANDOM GENERATOR #
((C=0))
((N=500))
if [ $2 ]; then
	((N=$2)); fi
((P=1))
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

ALL="${ARR[*]}"

#ALL="54 33 18 48 57 83 65 75 16 96 7 58 20 17 14 84 23 74 52 5 29 47 26 78 79 24 87 89 97 60 62 64 99 49 88 8 53 39 67 69 41 25 31 61 6 90 27 45 70 38 12 51 50 28 71 86 32 10 55 44 73 36 15 3 34 92 46 76 85 94 11 42 68 98 22 56 35 66 13 0 82 59 40 9 4 91 63 72 81 2 80 43 37 95 77 21 93 19 1 30"
#ALL="40 59 89 79 75 27 76 32 25 6 35 33 29 72 45 2 47 94 97 10 86 16 38 92 68 11 54 63 1 99 69 56 95 73 51 80 55 65 17 8 43 93 46 77 88 84 61 4 98 31 36 28 90 15 53 81 96 58 41 67 19 78 57 7 34 5 74 82 42 64 85 70 83 14 0 26 22 18 62 39 21 60 52 87 48 9 44 66 13 24 12 91 20 23 50 30 3 49 37 71"
#ALL="49 41 81 65 50 91 97 38 77 39 61 24 10 34 46 32 60 27 26 47 96 40 43 85 99 4 17 72 37 63 75 9 1 56 89 80 29 87 16 36 35 53 45 19 8 84 5 74 48 12 58 70 93 11 92 23 73 25 66 14 82 95 44 22 64 15 7 94 54 55 0 30 90 21 59 42 2 13 76 83 67 86 98 28 31 52 20 71 68 79 69 57 78 6 51 18 3 62 88 33"
#ALL="2 36 63 25 50 51 48 85 68 98 79 29 62 76 59 33 86 65 97 56 52 66 3 20 32 37 44 55 82 67 41 92 72 91 0 95 77 93 10 24 34 22 47 96 28 9 26 8 88 61 64 13 7 39 18 45 17 40 69 87 81 11 71 30 27 57 99 53 94 15 49 31 6 42 90 60 23 43 73 1 54 21 5 74 46 83 12 16 89 70 38 80 75 35 14 4 58 78 84 19"
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
break
else if [ 1 == 1 ]
then
#echo $ALL
#Check OS fedora or MacOS
OS=$(ls /etc | grep os-release)
if [[ $OS == "os-release" ]]
then
	NOW=$(./push_swap $ALL | wc -w)
	if [[ $NOW > $MAX ]]
	then
		MAX=($NOW)
	fi
	#AVG=$((($AVG * (ITR - 1) + $NOW) / ITR))
	AVG=$(echo "scale=10;($AVG*($ITR-1)+$NOW)/$ITR" | bc)
	ITR=$(($ITR + 1))
	RET=$(./push_swap $ALL | ./checker_linux $ALL)
	#echo Ret $RET
	echo -e "\033[2J   Now $NOW\n   Avg $AVG\n   Max $MAX\n   Itr $ITR"
	#RET="KO"
else if [ 1 == 1 ]
then
	./push_swap $ALL | wc -w
#	./push_swap $ALL | ./checker_Mac $ALL
fi fi fi fi fi fi fi fi
done
echo $ALL
echo ERROR
#echo $ALL