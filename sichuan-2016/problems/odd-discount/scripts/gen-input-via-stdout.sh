if [ "$1" = "" ]
then
    echo "First parameter is empty"
    read
fi

if [ "$2" = "" ]
then
    echo "Second parameter is empty"
    read
fi

rm -f "$2"

eval $1 > $2

if [ "$?" -ne "0" ]
then
    echo "Executed "$1", but it returns non-zero exit code"
    read
fi

if [ ! -f "$2" ]
then
    echo "Executed "$1 > $2", but it didn't create file"
    read
fi
