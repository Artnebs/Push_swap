#!/bin/bash

echo "Running tests..."

# Basic tests
echo "Test 1: ./push_swap 2 1 3 6 5 4"
./push_swap 2 1 3 6 5 4

echo "Test 2: ./push_swap 1 2 3 4 5"
./push_swap 1 2 3 4 5

echo "Test 3: ./push_swap 3 2 1"
./push_swap 3 2 1

# Performance tests
echo "Test 4: 100 random numbers"
seq 1 100 | shuf | xargs ./push_swap

echo "Test 5: 500 random numbers"
seq 1 500 | shuf | xargs ./push_swap

echo "All tests complete!"
