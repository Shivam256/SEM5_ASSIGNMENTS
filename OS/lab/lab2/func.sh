Hello () {
    echo "hello to this great day!"
}

DoSomething () {
    mkdir $1
    touch $1/$2
}

ReturnSomething () {
    i=1
    sum=0

    echo "Enter $1 numbers:"
    while [ $i -le $1 ]
    do
        read num
        sum=$((sum + num))
        i=$((i+1))
    done

    return sum
}

# DoSomething test hello.txt

ReturnSomething $1
ret=$?

echo "The sum of numbers is $ret"