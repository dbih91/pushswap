#!/bin/bash

# README
# ./test.sh <Numbers> <HOW MUCH TIMES> <INCLUDE NEGATIVE NUMBERS>
if [ -e Makefile ]
then
	PATH_TO="./"
else
	PATH_TO="../"
fi
cd $PATH_TO
PUSH_SWAP="./push_swap"


# Include negative numbers                                               # ??? #
	NEG=1
	CHECKER_TEST=0

# Hello
echo -e \
"\033[1m\033[32m            ::::::::                      :::   
           :+:   :+:                     :+:    
          +:+   +:+ +:+   +:+  +:++:++: +:+:+:+ 
         :#+   :#+ :#+   :#+ :#+       :#+  :#+ 
        +#++#++#  +#+   +#+  +#+#+#+  +#+  +#+  
       #+#       #+#  +#+#       #+# #+#  #+#   
      ###        ##### ##  #######  ###  ###  :::  ::::: :: ::::::::
                         :+:   :+: :+:  :+:  :+: :+:   :+: :+:   :+:
                        +:+       +:+  +:+  +:+ +:+   +:+ +:+   +:+ 
                        #:+#:#+  :#+  :#+  :#+ :#+  #:#+ :#+   :#+  
                            +#+  #+#+#+#+#+#   +#+# #+# +##+##+#    
                     #+#   #+#                         #+#          
                     #######                          ###   
"
echo -e \
"      ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    ::::::: 
    :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+:
   +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+ 
  +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:  
 +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+          
#+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#    
 ######    ######  ############## ###    ### ###   ######    ####### \033[0m"
sleep 0.75s

# Compile
make

# Arguments
V=0
if [ 1 == $(echo $1 | wc -w) ]
then
	if [ 1 == $(echo $2 | wc -w) ]
	then
		TIMES=$2
	else
		TIMES="1000000000"
	fi
	N=$1
else
	N=$((100))
	TIMES="1000000000"
fi

# Get Checker OS
OS=$(ls /etc | grep os-release)
if [[ $OS == "os-release" ]]
then
	CHECKER="./checker_linux"
else
	CHECKER="./checker_Mac"
fi

while [ 1 ]
do
# Varuables init
AVG="0";MAX="0";ITR="1";RET="OK";C=0

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
else if [[ $N == 100 ]]
then
	LIMIT="700"
	#LIMIT="650"
else
	LIMIT="999999999"
fi fi

#############################
# Start of Cycle of testing #
#############################
while [[ $TIMES > 0 ]]
do

# If MAX
if [[ $NOW > $LIMIT ]]
then
	mkdir -p test_output
	echo "NOW: $NOW LIMIT: $LIMIT"
	echo -en "\n\n\n /        push_swap        \\ \n   Now     $NOW\n   Average $AVG\n   Maximum $MAX\n   Repeats $ITR\n \    cclarice's tester    /" > "test_output/Info_$ITR.txt"
	echo $(./push_swap $ALL) > "test_output/Returns_$ITR.txt"
	echo $ALL > "test_output/output_$ITR.txt"
	sleep 2.5s
fi

# If Test returns KO
if [[ $RET != OK ]]
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
if  [ 1 == $CHECKER_TEST ]
then
	# Checker Branch
	echo
	echo Original:
	$PUSH_SWAP $ALL | $CHECKER $ALL
	echo Your:
	$PUSH_SWAP $ALL | ${PATH_TO}checker $ALL
	sleep 0.1s
else
	# Testing Branch
	NOW=$((0+$($PUSH_SWAP $ALL | wc -w)))
	RET=$($PUSH_SWAP $ALL | $CHECKER $ALL)
	if [[ (($NOW -gt $MAX)) ]]
	then
		MAX=($NOW)
	fi
	AVG=$(echo "scale=6;($AVG*($ITR-1)+$NOW)/$ITR" | bc)
	ITR=$(($ITR + 1))
	echo -en "\033[1m\n\n\n /        push_swap        \\ \n   Numbers $N\n   Now     $NOW\n   Average $AVG\n   Maximum $MAX\n   Repeats $ITR\n \    cclarice's tester    /\033[0m\n"
fi
TIMES=$(($TIMES - 1))
done
TIMES=$2
N=$(($N + 1))
done
echo End of test
echo $MAX is greater than $LIMIT
echo Last row of numbers:
echo $ALL