#!/bin/bash
make re
((C=0))
while [ $C -ne 16 ]
do
	ARR[$C]="$(($RANDOM%16+1))"
	((A=0))
	((D=0))
	while [ $A -lt $C ]
	do
		if [ ${ARR[$C]} -eq ${ARR[$A]} ]
		then
			((D=1))
		fi
		((A=$A+1))
	done
	if [ $D -eq 0 ]
	then
		((C=$C+1))
	fi
	echo ${ARR[*]}
done
ALL="${ARR[*]}"
./push_swap $ALL













#
#	BERY SLOW METHOD
#
#((C=1))
#echo Genarating Numbers
#while [ $C == 1 ]
#do
#	((A=0))
#	((B=0))
#	((C=0))
#	ARR[0]="$(($RANDOM%16))"
#	ARR[1]="$(($RANDOM%16))"
#	ARR[2]="$(($RANDOM%16))"
#	ARR[3]="$(($RANDOM%16))"
#	ARR[4]="$(($RANDOM%16))"
#	ARR[5]="$(($RANDOM%16))"
#	ARR[6]="$(($RANDOM%16))"
#	ARR[7]="$(($RANDOM%16))"
#	ARR[8]="$(($RANDOM%16))"
#	ARR[9]="$(($RANDOM%16))"
#	ARR[10]="$(($RANDOM%16))"
#	ARR[11]="$(($RANDOM%16))"
#	ARR[12]="$(($RANDOM%16))"
#	ARR[13]="$(($RANDOM%16))"
#	ARR[14]="$(($RANDOM%16))"
#	ARR[15]="$(($RANDOM%16))"
#	while [ $A -lt 16 ]
#	do
#		while [ $B -lt 16 ]
#		do
#			if [ ${ARR[$A]} -eq ${ARR[$B]} ]
#			then
#				if [ $A -ne $B ]
#				then
#					((C=1))
#				fi
#			fi
#			((B=$B+1))
#		done
#		((A=$A+1))
#		((B=0))
#	done
#done