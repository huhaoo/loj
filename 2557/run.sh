cd 2557
file="placement"
g++ 2557.cpp -o 2557 -O2 -lm -std=c++11
for i in {1..10}; do
	./2557 $file$i.in $file$i.out $file$i.ans
done