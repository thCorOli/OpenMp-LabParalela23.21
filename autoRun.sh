#!/bin/bash

# Number of times to run the C program
NUM_RUNS=5

# Parameters for the C program
PARAM1=2
PARAM2=3
# Add more parameters as needed

# Loop to run the C program multiple times
for ((i = 1; i <= NUM_RUNS; i++)); do
    ./mainNaive "$PARAM1" "$PARAM2"
done
