#!/bin/sh
sed -e 's/ //g' -e 's/;//g' -e 's/\"/ /g' -e 's/\\//g' -e '1,1d' -e 's/ //' data/BX-Book-Ratings.csv | iconv -c > data/BX-Book-Ratings_reserve.txt
g++ -std=c++17 bookcrossing_make.cxx ; ./a.out
awk '{print $2" "$1" "$3}' data/ratings_rowmajor.txt | sort -k1n > data/ratings_colmajor.txt
g++ -std=c++17 bookcrossing.cxx ; ./a.out






#sed -e 's/ //g' -e 's/;/,/g' -e 's/\"/ /g' -e 's/\\//g' -e '1,1d' -e 's/ //g' BX-Book-Ratings.csv | iconv -c > test.csv 
