#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

//sed -e "s/::/ /g" ratings.dat > ratings_rowmajor.dat
//を実行後
const std::string data_file = "data/ratings_rowmajor.dat";

constexpr int SIZE = 17359346;
int main(void){
  //データ読み込み
  std::ifstream ifs1(data_file);
  if(ifs1.fail()){
    std::cerr<<"file error"<<std::endl;
    exit(1);
  }
  //評価値
  VectorXd ItemElem = VectorXd::Zero(SIZE);
  //アイテムの番号
  VectorXd ItemIndex = VectorXd::Zero(SIZE);
  //ユーザの番号
  VectorXd UserIndex = VectorXd::Zero(SIZE);
  //各ユーザが評価したアイテム数
  VectorXd UserIndexSize = VectorXd::Zero(SIZE);
  //各アイテムを評価したユーザ数
  VectorXd ItemIndexSize = VectorXd::Zero(SIZE);
  //ユーザ番号，アイテム番号，評価値，タイムスタンプ，
  int uid, iid;
  double rate;
  for(int i=0;i<SIZE;i++){
    ifs1 >> uid >> iid >> rate;
    //ユーザサイズ計算
    UserIndexSize(uid-1)++;
    //アイテムサイズ計算
    ItemIndexSize(iid-1)++;
    //データ入力
    ItemElem(i)=rate;
    ItemIndex(i)=iid-1;
    UserIndex(i)=uid-1;
  }
  ifs1.close();
  //欠番を詰める
  std::ofstream ofs1("data/ユーザ欠番.txt");
  std::ofstream ofs2("data/profile欠番.txt");
  std::map<int, int> RealUserIndex, RealItemIndex;
  int ROW=0,COL=0;
  for(int i=0;i<SIZE;i++){
    if(UserIndexSize(i)>0){
      RealUserIndex.insert(std::make_pair(i, ROW));
      ROW++;
    }
    else
      if(135359>i)
	ofs1<<i<<std::endl;
    if(ItemIndexSize(i)>0){
      RealItemIndex.insert(std::make_pair(i, COL));
      //std::cout<<COL<<" "<<i<<std::endl;
      COL++;
    }
    else
      if(168791>i)
	ofs2<<i<<std::endl;
  }
  std::cout<<ROW<<" "<<COL<<std::endl;
  //出力
  std::ofstream ofs_row("data/ratings_rowmajor.txt");
  int sum=0;
  for(int i=0;i<SIZE;i++){
    for(int sz=0;sz<UserIndexSize(i);sz++)
      ofs_row<<RealUserIndex.at(i)
	     <<" "<<RealItemIndex.at(ItemIndex(sum+sz))
	     <<" "<<ItemElem(sum+sz)<<std::endl;
    sum+=UserIndexSize(i);
  }
  return 0;
}
