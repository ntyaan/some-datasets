# some-datasets
- CLUTO : [http://glaros.dtc.umn.edu/gkhome/cluto/cluto/download](http://glaros.dtc.umn.edu/gkhome/cluto/cluto/download)

|データ名|クラスタ数[C]|文書数[N]|単語数[M]|
|:---|:---|:---|:---|
|**[cacmcisi](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/cacmcisi/sparse_cacmcisi.txt)**|2|4663|14409|
|**[classic](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/classic/sparse_classic.txt)**|4|7094|41681|
|**[cranmed](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/cranmed/sparse_cranmed.txt)**|2|2431|41681|
|**[fbis](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/fbis/sparse_fbis.txt)**|17|2463|2000|
|**[hitech](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/hitech/sparse_hitech.txt)**|6|2301|126321|
|**[k1a](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/k1a/sparse_k1a.txt)**|20|2340|21839|
|**[k1b](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/k1b/sparse_k1b.txt)**|6|2340|21839|
|**[la1](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/la1/sparse_la1.txt)**|6|3204|31472|
|**[la2](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/la2/sparse_la2.txt)**|6|3075|31472|
|**[la12](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/la12/sparse_la12.txt)**|6|6279|31472|
|**[mm](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/mm/sparse_mm.txt)**|2|2521|126354|
|**[new3](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/new3/sparse_new3.txt)**|44|9558|83487|
|**[ohscal](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/ohscal/sparse_ohscal.txt)**|10|11162|11465|
|**[re0](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/re0/sparse_re0.txt)**|13|1504|2886|
|**[re1](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/re1/sparse_re1.txt)**|25|1657|3758|
|**[reviews](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/reviews/sparse_reviews.txt)**|5|4069|126354|
|**[sports](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/sports/sparse_sports.txt)**|7|8580|126355|
|**[tr11](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/tr11/sparse_tr11.txt)**|9|414|6429|
|**[tr12](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/tr12/sparse_tr12.txt)**|8|313|5804|
|**[tr23](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/tr23/sparse_tr23.txt)**|6|204|5832|
|**[tr31](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/tr31/sparse_tr31.txt)**|7|927|10128|
|**[tr41](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/tr41/sparse_tr41.txt)**|10|878|7454|
|**[tr45](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/tr45/sparse_tr45.txt)**|10|690|8261|
|**[wap](https://github.com/ntyaan/some-datasets/blob/master/datasets_cluto_20171213/CLUTO/wap/sparse_wap.txt)**|20|1560|8460|

- classic4 : [http://www.dataminingresearch.com/index.php/2010/09/classic3-classic4-datasets](http://www.dataminingresearch.com/index.php/2010/09/classic3-classic4-datasets)

docbyterm.txtの一行目
```doxbyterm.txt
7095 5896 247158
```

となっているが正しくは文書数7094
docbyterm.txt20301行目から

```doxbyterm.txt
1551 671 1
1553 1689 1
```
となっていてデータ番号1552が抜けている。
同様にdocuments.txtの5657行目から

```
cran.000994 2
cran.000996 2
```
となっていて第二クラスの995番が抜けている。


