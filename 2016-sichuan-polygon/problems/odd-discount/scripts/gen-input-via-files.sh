# parameter 1 is generator execution command line from the root of the package
# parameter 2 is test input file path from the root of the package or several paths separated with ":"
# parameter 3 is the test index or several indices separated with ":"

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

rm -rf tmp-for-input-generation
mkdir tmp-for-input-generation
cd tmp-for-input-generation

eval $1

if [ "$?" -ne "0" ]
then
    echo "Executed "../$1", but it returns non-zero exit code"
    read
fi

paths=($(echo $2 | tr ":" "\n"))
indices=($(echo $3 | tr ":" "\n"))

for (( i = 0 ; i < ${#paths[@]} ; i++ ))
do
rm -f "../${paths[$i]}"

cp "${indices[$i]}" "../${paths[$i]}" 2> /dev/nul
cp "0${indices[$i]}" "../${paths[$i]}" 2> /dev/nul
cp "00${indices[$i]}" "../${paths[$i]}" 2> /dev/nul

if [ "$?" -ne "0" ]
then
    echo "Can't copy ${indices[$i]} to ../${paths[$i]}"
    read
fi

if [ ! -f "../${paths[$i]}" ]
then
    echo "Can't find ../${paths[$i]}"
    read
fi

echo "Test #${indices[$i]} has been generated and copied to ${paths[$i]}"

done

cd ..
rm -rf tmp-for-input-generation
