#!/bin/sh
g++ -std=c++17 jester_make.cxx ; ./a.out
awk '{print $2" "$1" "$3}' data/ratings_rowmajor.txt | sort -k1n > data/ratings_colmajor.txt
g++ -std=c++17 jester.cxx ; ./a.out
