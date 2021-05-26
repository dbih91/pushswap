#!/bin/bash
make
./push_swap 6 8 4 7 9 5 1 0
./push_back 6 8 4 7 9 5 1 0 | ./checker_linux 6 8 4 7 9 5 1 0