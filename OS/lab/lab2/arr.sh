arr=(shivam 1 2 3 4 rahul)

echo ${arr[@]}
echo "The lenght of arrays is ${#arr}"

echo "Iterating through an array"
i=1
n=${#arr}

while [ $i -le $n ]
do
    echo "current element: ${arr[i]}"
    i=$((i+1))
done