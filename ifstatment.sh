echo "input $1"
if test $1 -eq 0
then
    echo "="
elif test $1 -gt 0
then
    echo ">"
else
    echo "<"
fi

cat $2 && echo "File exit" || echo "File not exit"
