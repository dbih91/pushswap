#!/bin/bash
make
((C=0))
((N=10))
while [ $C -ne $N ]
do
	ARR[$C]=$(($C))
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
ALL="${ARR[*]}"
echo ${ARR[*]}
./push_swap $ALL
make fclean

#while [ $C -ne $N ]
#do
#	ARR[$C]=$(($RANDOM%$M+1))
#	((A=0))
#	((D=0))
#	while [ $A -lt $C ]
#	do
#		if [ ${ARR[$A]} -eq $M ]
#		then
#			((M--))
#		fi
#		if [ ${ARR[$C]} -eq ${ARR[$A]} ]
#		then
#			echo "\033[1A[ ${#ARR[*]} | $M | $N ]"
#			((D=1))
#		fi
#		((A++))
#	done
#	if [ $D -eq 0 ]
#	then
#		((C++))
#	fi
#done