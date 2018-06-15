#!/bin/sh
sed -e "s/,/ /g" data/ratings.dat > data/ratings_rowmajor.dat
g++ -std=c++17 libimseti_make.cxx ; ./a.out
awk '{print $2" "$1" "$3}' data/ratings_rowmajor.txt | sort -k1n > data/ratings_colmajor.txt
g++ -std=c++17 libimseti.cxx ; ./a.out
rm a.out
