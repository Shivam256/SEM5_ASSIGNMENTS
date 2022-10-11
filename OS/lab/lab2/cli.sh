DIR="components"

if [ -d "$DIR" ]
then
    echo "directory exists!"
else
    mkdir components
fi

mkdir components/$1
touch components/$1/$1.component.jsx
touch components/$1/$1.styles.jsx