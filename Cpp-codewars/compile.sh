if [ $# -gt 1 ]
then
    echo "There is more than one argument";
elif [ -f "$1" ]
then
#    g++ $1 -lpthread -o Out/$1.out;
   g++ -std=c++17 $1 -o Out/$1.out; 
   echo "OUTPUT:";
    ./Out/$1.out;
else
    echo "There is no such file"
fi;
