kukl=$1 
if [ -z "$kukl" ]
then
	kukl=-1
	echo "HE BBOD | kukl = " $kukl
else
	echo "BBOD | kukl = " $kukl
fi

dump=25000
i=0
./corewar -dump $dump bee_gees.cor mortel.cor > res1
./vm_champs/corewar -d $dump bee_gees.cor mortel.cor > res2
diff res1 res2 > diff
i=$(ls -l diff | cut -d " " -f8 | bc)
while [ "$i" -eq 0 ]
do
	dump=$(($dump + 100))
	echo "dump eby4uu' = " $dump
	./corewar -dump $dump bee_gees.cor mortel.cor > res1
	./vm_champs/corewar -d $dump bee_gees.cor mortel.cor > res2
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

