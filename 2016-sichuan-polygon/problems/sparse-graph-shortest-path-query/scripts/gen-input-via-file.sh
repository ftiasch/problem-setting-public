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

if [ "$3" = "" ]
then
    echo "Third parameter is empty"
    read
fi

rm -f "$2"

rm -rf tmp-for-input-generation
mkdir tmp-for-input-generation
cd tmp-for-input-generation

eval $1

if [ "$?" -ne "0" ]
then
    echo "Executed "../$1", but it returns non-zero exit code"
    read
fi

cp "$3" "../$2"

if [ "$?" -ne "0" ]
then
    echo "Can't copy $3 to ../$2"
    read
fi

if [ ! -f "../$2" ]
then
    echo "Can't find ../$2"
    read
fi

cd ..
rm -rf tmp-for-input-generation
