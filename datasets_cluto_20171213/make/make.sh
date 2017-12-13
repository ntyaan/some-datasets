#!/bin/s
#unzip make/make.zip
#rm make/make.zip
#unzip datasets_cluto_20171213.zip
#rm datasets_cluto_20171213.zip
dir="CLUTO"
g++ -std=c++17 -Wall -Wextra make/sparse.cxx -o make/sparse.out
mkdir $dir
if [ $? = 1 ]; then
    rm -rf $dir
    exit 1
fi
files=`find . -name "*.mat" -type f | sed -e "s/.mat//" -e "s/.\///"`
for file in $files; do
    mkdir $dir"/"$file
    echo $file
    i=0
    new_file=$dir"/"$file"/"$file"_rowsize.txt"
    cat $file".mat" | while read line || [ -n "${line}" ]; do i=$((i+1)); [ $i = 1 ] && echo $line || echo $(((`echo $line | wc -w`)/2)) >>  $new_file; done
    make/sparse.out $file $new_file
    g++ -std=c++17 -Wall -Wextra make/$file.cxx -o make/c.out
    make/c.out
done
rm -f make/*.out
