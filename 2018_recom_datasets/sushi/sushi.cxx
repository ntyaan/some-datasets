#include <iostream>
#include <fstream>
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::VectorXd;

constexpr int ROW = 5000;
constexpr int COL = 100;
//Eu個以上評価しているユーザに絞る
constexpr int Eu = 0;
//Ei人以上に評価されているアイテムに絞る
constexpr int Ei = 0;

const std::string data_file = "data/sushi3b.5000.10.score";

int main(void){
  //既評価なら1そうでなければ0
  MatrixXd Data_binary = MatrixXd::Zero(ROW, COL);
  //評価データ
  MatrixXd Data = MatrixXd::Zero(ROW, COL);
  std::ifstream ifs(data_file);
  if(ifs.fail()){
    std::cerr<<"file error"<<std::endl;
    exit(1);
  }
  double rate;
  for(int i=0;i<ROW;i++){
    for(int j=0;j<COL;j++){
      ifs >> rate;
      rate++;
      Data(i,j)=rate;
      if(rate!=0)
	Data_binary(i,j)=1;
    }
  }

  //削っていないユーザなら0そうでなければ-1
  VectorXd User = VectorXd::Zero(ROW);
  //削っていないアイテムなら0そうでなければ-1
  VectorXd Item = VectorXd::Zero(COL);
  //削ったユーザ数，削ったアイテム数，ループ終了判定
  int uu=0,ii=0,tmpu=0,tmpi=0;
  while(1){
    for(int k=0;k<ROW;k++){
      int sum1=0;
      
      //ユーザkの評価したアイテム数を数える
      for(int ell=0;ell<COL;ell++)
        sum1+=Data_binary(k, ell);

      //削るべきユーザであれば
      if(sum1<Eu&&User(k)!=-1){
        uu++; User(k)=-1;
	for(int ell=0;ell<COL;ell++)
          Data_binary(k, ell)=0;
      }
    }
    
    for(int ell=0;ell<COL;ell++){
      int sum2=0;

      //アイテムellを評価したユーザ数を数える
      for(int k=0;k<ROW;k++){
        sum2+=Data_binary(k, ell);
      }

      //削るべきアイテムであれば
      if(sum2<Ei&&Item(ell)!=-1){
        ii++; Item(ell)=-1;
        for(int k=0;k<ROW;k++)
          Data_binary(k, ell)=0;
      }
    }
    std::cout<<uu<<" "<<ii<<" "<<std::endl;
    //削るべきユーザ、アイテムがなければループを抜ける
    if(tmpu==uu&&tmpi==ii)break;
    tmpu=uu;tmpi=ii;
  }
  //出力ファイル名
  std::string out_file = "sushi"
    +std::to_string(ROW-uu)+"_"+std::to_string(COL-ii)+".txt";
  int sum=0, kk=0, ellell=0;
  std::ofstream ofs_e(out_file);
  for(int k=0;k<ROW;k++){
    //削っていないユーザのみ
    if(User[k]==0){
      for(int ell=0;ell<COL;ell++){
	//削っていないアイテムのみ
	if(Item(ell)==0){
	  //非ゼロのみ
	  if(Data(k, ell)>0){
	    ofs_e << k+kk << " " << ell+ellell
		  << " " << Data(k, ell) << std::endl;
	    sum++; 
	  }
	}
	else
	  ellell++;
      }
    }
    else
      kk++;
  }
  std::cout<<sum<<" "<<ROW-uu<<" "<<COL-ii<<std::endl;
  return 0;
}
