#!/bin/sh
#movielens1M: READMEにユーザ数6040 映画数3900 評価数1,000,209って書いてあるが正確には映画数は3706
sed -e "s/::/ /g" data/ratings.dat > data/ratings_rowmajor.dat
g++ -std=c++17 movielens_1m_make.cxx ; ./a.out
awk '{print $2" "$1" "$3}' data/ratings_rowmajor.txt | sort -k1n > data/ratings_colmajor.txt
g++ -std=c++17 movielens_1m.cxx ; ./a.out
