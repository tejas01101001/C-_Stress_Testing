#!/bin/bash

# Author: Tejas Khairnar 
# Date: 23/08/2021 

# Get the number of testcases as the input
echo -e "\e[1m\e[35mEnter the number of testcases: "
read num_testcases

# Compile all the codes
g++ sol.cpp -o sol
g++ brute.cpp -o brute
g++ test.cpp -o tester

echo -e "\e[1m\e[33mAll codes are compiled"

# Define the flag variable 
declare -i flag=0

# Efficiently check the difference between the two codes
for(( i=0; i<$num_testcases; i++))
do
    ./tester > input.txt
    ./sol < input.txt > output.txt
    ./brute < input.txt > brute.txt
    if cmp --silent -- output.txt brute.txt; then
        echo -e "\e[1m\e[32mTestcase $((i+1)) is correct"
    else
        echo -e "\e[1m\e[31mTestcase $((i+1)) is incorrect"
        code output.txt
        code brute.txt
        code input.txt
        flag=1
        break
    fi
done
if [ $flag -eq 0 ]; then
    echo -e "\e[1m\e[34mAll testcases are correct"
fi