dump=0
i=0
./corewar -dump $dump bee_gees.cor jumper.cor > res1
./vm_champs/corewar -d $dump bee_gees.cor jumper.cor > res2
diff res1 res2 > diff
i=$(ls -l diff | cut -d " " -f8 | bc)
while [ "$i" -eq 0 ]
do
	dump=$(($dump + 1))
	./corewar -dump $dump bee_gees.cor jumper.cor > res1
	./vm_champs/corewar -d $dump bee_gees.cor jumper.cor > res2
	diff res1 res2 > diff
	i=$(ls -l diff | cut -d " " -f8 | bc)
done
echo "First error with dump = " $dump
cat diff
