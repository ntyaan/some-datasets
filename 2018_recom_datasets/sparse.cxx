#include <iostream>
#include <fstream>
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::VectorXd;
#define REP(i,n) for(int i=(0);i<(n);i++)

int main(const int argc, const char *argv[]){
  std::string argv0=argv[1];
  int row = atoi(argv[2]);
  int col = atoi(argv[3]);
  MatrixXd A = MatrixXd::Zero(row, col);
  VectorXd B = VectorXd::Zero(row);
  std::ifstream ifs(argv0);
  if(ifs.fail()){
    std::cerr<<"argv0 error\n"
	     <<"./a.out datasetname/datasetfile(.txt) rows cols"
	     <<std::endl;
    exit(1);
  }
  int uid, iid;
  double value; 
  while(!ifs.eof()){
    ifs>>uid>>iid>>value;
    A(uid,iid)=value;
  }
  ifs.close();
  std::string str="";
  for(int i=0;i<(int)argv0.size()-4;i++){
    if(argv0[i]=='/')
      str+="/sparse_";
    else
      str+=argv0[i];
  }
  
  std::ofstream ofs(str+".txt");
  ofs<<row<<" "<<col<<std::endl;
  REP(i,row){
    REP(j,col){
      if(A(i,j))
      B(i)++;
    }
    ofs<<B[i]<<" ";
    REP(j,col){
      if(A(i,j))
	ofs<<j<<" "<<A(i,j)<<" ";
    }
    ofs<<std::endl;
  }
  return 0;
}
