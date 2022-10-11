#this eill check of string is palindrome or not
echo "Enter the string:"
read inp

len=${#inp}
echo lenght of string is $len

res=1

for ((i=0;i<$[$len/2 + 1];i++)); do 
    # echo "${inp:$i:1}"
    # echo $i
    # echo "${inp:$i:1}"
    # echo "${inp:$[len-i-1]:1}"
    a="${inp:$i:1}"
    b="${inp:$[len-i-1]:1}"

    if [ "$a" != "$b" ]
    then
        res=0
    fi
    # echo "${inp:${len-i}:1}"
    # if [${inp:$i:1} != ${inp:${len-i-1}:1}]; then
    #     res=false
    #     break
    # fi
done

if [ $res = 1 ]
then
    echo "yes"
else 
    echo "no"
fi