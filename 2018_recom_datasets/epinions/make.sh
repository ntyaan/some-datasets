#!/bin/sh
iconv -c data/ratings_data.txt | sed -e '1d' -e '$d' > data/ratings_data_reserve.txt; sed  -i '1s/^/1 100 4\n/' data/ratings_data_reserve.txt
g++ -std=c++17 epinions_make.cxx ; ./a.out
awk '{print $2" "$1" "$3}' data/ratings_rowmajor.txt | sort -k1n > data/ratings_colmajor.txt
g++ -std=c++17 epinions.cxx ; ./a.out
rm a.out
