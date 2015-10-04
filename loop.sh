echo "input argu: $1"

for i in 1 2 3 4 5
do
    echo "$i * $1 = `expr $i \* $1`"
done


for (( i = 1; i <= 9; i++ )) ### Outer for loop ###
do
    for (( j = 1 ; j <= 9; j++ )) ### Inner for loop ###
        do
            tot=`expr $i + $j`
            tmp=`expr $tot % 2`
            if [ $tmp -eq 0 ]; then
                echo -e -n "\033[47m "
            else
                echo -e -n "\033[40m "
            fi
        done
    echo -e -n "\033[40m" #### set back background colour to black
    echo "" #### print the new line ###
done

i=0
while [ $i -le 10 ]
do
    echo $i
    echo -e "$i * $1 = `expr $i \* $1`\n"
    i=`expr $i + 1`
done
unset i

case $1 in
    "1") echo "1*1 = `expr 1 \* 1`";;
    "2") echo "2*2 = `expr 2 \* 2`";;
    "3") echo "3*3 = `expr 3 \* 3`";;
    "4") echo "4*4 = `expr 4 \* 4`";;
    "5") echo "5*5 = `expr 5 \* 5`";;
    *)   echo "Input mush less than 5";;
esac
