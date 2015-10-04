echo "greping application $1"
ps -A | grep Applications | grep -i --color=auto $1
