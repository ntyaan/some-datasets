#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

constexpr int ROW = 69878;
constexpr int COL = 10677;
constexpr int SIZE =  10000054;

//Eu個以上評価しているユーザに絞る
constexpr int Eu = 600;
//Ei人以上に評価されているアイテムに絞る
constexpr int Ei = 300;

const std::string data_file1 = "data/ratings_rowmajor.txt";
const std::string data_file2 = "data/ratings_colmajor.txt";

int main(void){
  //各ユーザが評価したアイテム数
  VectorXd UserIndexSize = VectorXd::Zero(ROW);
  //各アイテムを評価したユーザ数
  VectorXd ItemIndexSize = VectorXd::Zero(COL);
  //評価値
  VectorXd ElemRowMajor = VectorXd::Zero(SIZE);
  VectorXd ElemColMajor = VectorXd::Zero(SIZE);
  //アイテムの番号
  VectorXd ItemIndexRowMajor = VectorXd::Zero(SIZE);
  //ユーザの番号
  VectorXd UserIndexColMajor = VectorXd::Zero(SIZE);
  //データ読み込み
  std::ifstream ifs1(data_file1);
  if(ifs1.fail()){
    std::cerr<<"file1 error"<<std::endl;
    exit(1);
  }
  std::ifstream ifs2(data_file2);
  if(ifs2.fail()){
    std::cerr<<"file2 error"<<std::endl;
    exit(1);
  }
  //削っていないユーザなら0そうでなければ-1
  VectorXd User = VectorXd::Zero(ROW);
  //削っていないアイテムなら0そうでなければ-1
  VectorXd Item = VectorXd::Zero(COL);
  //ユーザ番号，アイテム番号，評価値
  int uid, iid;
  double rate;
  for(int i=0;i<SIZE;i++){
    if(ifs1){
      ifs1 >> uid >> iid >> rate;
      //ユーザサイズ計算
      UserIndexSize(uid)++;
      //データ入力
      ItemIndexRowMajor(i)=iid;
      ElemRowMajor(i)=rate;
    }

    if(ifs2){
      ifs2 >> iid >> uid >> rate;
      //アイテムサイズ計算
      ItemIndexSize(iid)++;
      //データ入力
      UserIndexColMajor(i)=uid;
      ElemColMajor(i)=rate;
    }
  }
  ifs1.close();
  ifs2.close();
  //各ユーザが評価したアイテム数コピー
  VectorXd UserIndexSizecp = UserIndexSize;
  //各アイテムを評価したユーザ数コピー
  VectorXd ItemIndexSizecp = ItemIndexSize;
  //削ったユーザ数，削ったアイテム数，ループ終了判定
  int uu=0,ii=0,tmpu=0,tmpi=0;
  while(1){
    int usersizesum=0;
    for(int k=0;k<ROW;k++){
      //削るべきユーザであれば
      if(UserIndexSizecp(k)<Eu&&User(k)!=-1){
        User(k)=-1;
	uu++;
	for(int i=usersizesum;i<usersizesum+UserIndexSize(k);i++)
	  ItemIndexSizecp(ItemIndexRowMajor(i))--;
      }
      usersizesum+=UserIndexSize(k);
    }

    int itemindexsum=0;
    for(int ell=0;ell<COL;ell++){    
      //削るべきアイテムであれば
      if(ItemIndexSizecp(ell)<Ei&&Item(ell)!=-1){
        Item(ell)=-1;
	ii++;
	for(int i=itemindexsum;i<itemindexsum+ItemIndexSize(ell);i++)
	  UserIndexSizecp(UserIndexColMajor(i))--;
      }
      itemindexsum+=ItemIndexSize(ell);
    }
    //削るべきユーザ、アイテムがなければループを抜ける
    if(tmpu==uu&&tmpi==ii)break;
    tmpu=uu;tmpi=ii;
    std::cout<<tmpu<<" "<<tmpi<<" "<<std::endl;
  }
  
  //出力ファイル名
  std::string out_file = "movielens10m"
    +std::to_string(ROW-uu)+"_"+std::to_string(COL-ii)+".txt";
  int index=0, sum=0;
  //欠番を詰める
  std::map<int, int> RealUserIndex, RealItemIndex;
  int realindex=0;
  for(int i=0;i<ROW;i++){
    if(User(i)==0){
      RealUserIndex.insert(std::make_pair(i, realindex));
      realindex++;
    }
  }
  realindex=0;
  for(int i=0;i<COL;i++){
    if(Item(i)==0){
      RealItemIndex.insert(std::make_pair(i, realindex));
      realindex++;
    }
  }
  std::ofstream ofs_e(out_file);
  for(int k=0;k<ROW;k++){
    //削っていないユーザのみ
    if(User(k)==0){
      //ユーザ番号でソートしたものを対象に
      for(int ell=0;ell<UserIndexSize(k);ell++){
	//削っていない映画のみ
	if(Item(ItemIndexRowMajor(index))==0){
	  ofs_e << RealUserIndex.at(k) << " "
		<< RealItemIndex.at(ItemIndexRowMajor(index)) << " "
		<< ElemRowMajor(index)<<std::endl;
	  sum++;
	}
	index++;
      }
    }
    else{
      //ファイル行番号を数える
      for(int ell=0;ell<UserIndexSize(k);ell++)
	index++;
    }
  }
  std::cout<<sum<<" "<<ROW-uu<<" "<<COL-ii<<std::endl;
  return 0;
}
