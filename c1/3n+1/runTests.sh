#!/bin/bash

make release

echo "timing on inputs"
echo "-----------------"

echo "time ./a.out < input/sample.txt > output/sample.txt"
time ./a.out < input/sample.txt > output/sample.txt && echo ""

echo "time ./a.out < input/small_n100_min1_max99999.txt > output/small.txt"
time ./a.out < input/small_n100_min1_max99999.txt > output/small.txt && echo ""

echo "time ./a.out < input/small_n200_min1_max100000.txt > output/small.txt"
time ./a.out < input/small_n200_min1_max100000.txt > output/big.txt && echo ""

echo "time ./a.out < input/big_n1000_min1_max99999.txt > output/big.txt"
time ./a.out < input/big_n1000_min1_max99999.txt > output/big.txt && echo ""

echo "time ./a.out < input/big_n1000_min1_max200000.txt.txt > output/big.txt"
time ./a.out < input/big_n1000_min1_max200000.txt > output/big.txt && echo ""
