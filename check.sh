#!/bin/bash

dump=$1
limit=$2

if [ -z "$dump" ]
then
  echo "First argument - cycle to start with, second argument - cycle to stop on."
fi

if [ -z "$dump" ]
then
 dump=1
	echo "Default start = " $dump
else
	echo "start = " $dump
fi

if [ -z "$limit" ]
then
	limit=-1
	echo "No limit"
else
	echo "limit = " $limit
fi

rm -rf res1
rm -rf res2
rm -rf difference

i=0
./corewar -dump $dump champs/kamelkaze.cor > res1
./reference_binaries/corewar -d $dump champs/kamelkaze.cor > res2
diff res1 res2 > difference
i=$(ls -l difference | cut -d " " -f8 | bc)
while [ "$i" -eq 0 ]
do
	dump=$(($dump + 1))
	./corewar -dump $dump champs/kamelkaze.cor > res1
	./reference_binaries/corewar -d $dump champs/kamelkaze.cor > res2
	diff res1 res2 > difference
	i=$(ls -l difference | cut -d " " -f8 | bc)
	if [ $dump == $limit ]
	then
		echo "Yay! Done, no difference!"
		exit
	fi
done
echo "First error on cycle " $dump
cat difference

