echo "Enter the string:"
read a

echo "The lenght of string is ${#a}"

echo "Enter two string to be adeed"
read b
read c


d=${b}-${c}

echo "The concatenation is $d"

echo "substring operation"
echo "Enter the string"
read k
# echo "Enter the length"
# read m

echo "The result is ${k:1:5}"

