echo Enter first number
read a
echo Enter second number
read b
echo $a and $b
echo "These are the operations:\n1-addition\n2-substraction\n3-multiplication\n4-division"
echo Enter your operation number
read op

case $op in
    "1") echo "addition $[$a + $b]"
    ;;
    "2") echo "substraction $[$a - $b]"
    ;;
    "3") echo "multiplication $[$a*$b]"
    ;;
    "4") echo "division $[$a/$b]"
    ;;
esac
