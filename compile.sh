#!/bin/bash
gcc test_find_median_for_chunk.c $(ls *.c | grep -v -E "main.c|test_find_median_for_chunk.c") -o test_median -I. -ILibft_GNL_Printf/includes -LLibft_GNL_Printf -lft
