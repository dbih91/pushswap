#!/bin/bash

# Compile
make

# Arguments
if [ 1 != $(echo $2 | wc -w) ]
then
	if [ 1 != $(echo $1 | wc -w) ]
	then
		N=100
	else
		N=$1
	fi
	V=0
else
	if [ $1 == "-v*" ]
	then
		V=$1
	else
		V=0
	fi
	N=$2
fi

# Get Checker OS
OS=$(ls /etc | grep os-release)
if [[ $OS == "os-release" ]]
then
	CHECKER="./checker_linux"
else
	CHECKER="./checker_Mac"
fi

# Varuables init
AVG="0";MAX="0";ITR="1";RET="OK";C=0

# Include negative numbers                                               # ??? #
NEG=0
# Create a row of numbers
while [ $C -ne $N ]
do
	ARR[$C]=$(($C))
	if [ $NEG -ne 0 ]; then
		if [ $(($RANDOM%2)) -ne 0 ]; then
			ARR[$C]=$(($C * -1))
		fi
	fi
	((C++))
done

# Get Limit
if [[ $N == 500 ]]
then
	LIMIT="5500"
else if [[ $N > 99 ]]
then
	LIMIT="700"
else
	LIMIT="88888888"
fi fi

#############################
# Start of Cycle of testing #
#############################
while [ 1 ]
do

# If MAX
if [[ $NOW > $LIMIT ]]
then
	echo -en "\n\n\n /    cclarice's tester    \\ \n   Now     $NOW\n   Average $AVG\n   Maximum $MAX\n   Repeats $ITR\n \        push_swap        /" > "output/Info_$ITR.txt"
	echo $(./push_swap ALL) > "output/Returns_$ITR.txt"
	echo $ALL > "output/output_$ITR.txt"
fi

# If Test returns KO
if [[ $RET == KO ]]
then
	echo Your algorithm are broken!!!
	echo Case:
	echo $ALL
	exit
fi

# Mesh field of numbers	
P=1 # Number of meshing
while [ $P -ne 0 ]
do
	C=0
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
ALL="${ARR[*]}" # ALL is random field of numbers

# Start of two branches
if  [ $V == "-v*" ]
then
	# Visual branch
	./push_swap $V $ALL
	exit
else
	# Testing branch
	NOW=$(./push_swap $ALL | wc -w)
	RET=$(./push_swap $ALL | $CHECKER $ALL)
	if [[ (($NOW -gt $MAX)) ]]
	then
		MAX=($NOW)
	fi
	AVG=$(echo "scale=6;($AVG*($ITR-1)+$NOW)/$ITR" | bc)
	ITR=$(($ITR + 1))
	echo -en "\n\n\n /    cclarice's tester    \\ \n   Now     $NOW\n   Average $AVG\n   Maximum $MAX\n   Repeats $ITR\n \        push_swap        /"
	#echo -e "\n   Ret $RET\n   Now $NOW\n   Avg $AVG\n   Max $MAX\n   Itr $ITR"
fi
done
echo End of test
echo $MAX is greater than $LIMIT
echo Last row of numbers:
echo $ALL