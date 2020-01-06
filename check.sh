kukl=$1 
if [ -z "$kukl" ]
then
	kukl=-1
	echo "HE BBOD | kukl = " $kukl
else
	echo "BBOD | kukl = " $kukl
fi

dump=0
i=0
./corewar -dump $dump jumper.cor jumper.cor mortel.cor > res1
./vm_champs/corewar -d $dump jumper.cor jumper.cor mortel.cor > res2
diff res1 res2 > diff
i=$(ls -l diff | cut -d " " -f8 | bc)
while [ "$i" -eq 0 ]
do
	dump=$(($dump + 1))
	# echo "dump eby4uu' = " $dump
	./corewar -dump $dump jumper.cor jumper.cor mortel.cor > res1
	./vm_champs/corewar -d $dump jumper.cor jumper.cor mortel.cor > res2
	diff res1 res2 > diff
	i=$(ls -l diff | cut -d " " -f8 | bc)
	if [ $dump == $kukl ]
	then
		echo "dump == kukl"
		exit
	fi
done
echo "First error with dump = " $dump
cat diff

