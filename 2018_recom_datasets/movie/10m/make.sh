#!/bin/sh
#README.html に This data set contains 10000054 ratings and 95580 tags applied to 10681 movies by 71567 users of the online movie recommender serviceって書いてあるけど実はユーザ数69878 映画数10677(65433-54456)の評価しかされていない
sed -e "s/::/ /g" data/ratings.dat > data/ratings_rowmajor.dat
g++ -std=c++17 movielens_10m_make.cxx ; ./a.out
awk '{print $2" "$1" "$3}' data/ratings_rowmajor.txt | sort -k1n > data/ratings_colmajor.txt
g++ -std=c++17 movielens_10m.cxx ; ./a.out
