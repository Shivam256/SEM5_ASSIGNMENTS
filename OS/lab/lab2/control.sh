echo "Enter first number"
read a
echo "Enter secong number"
read b

if [ "$a" -eq "$b" ]
then
    echo "Numbers are equal"
else
    echo "Numbers are not equal"
fi