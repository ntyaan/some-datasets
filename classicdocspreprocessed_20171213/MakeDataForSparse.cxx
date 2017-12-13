#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<vector>
#define REP(i,n) for(int i=(0);i<(n);i++)
int main(const int argc, const char *argv[]){
  (void)argc;
  std::string argv0=argv[1];
  int row,col;
  std::ifstream ifs1(argv0);
  if(!ifs1){exit(1);std::cout<<"argv0 error\n";}//input mat
  ifs1>>row>>col;
  std::vector< std::vector<double> > A;
  A.resize(row);
  REP(i,row)
    A[i].resize(col);
  REP(i,row){
    REP(j,col){
      A[i][j]=0.0;
    }
  }
  int index1, index2;
  double element;
  while(ifs1){
    ifs1 >> index1 >> index2 >> element;
    A[index1][index2]=element;
  }
  std::vector<int> B;
  B.resize(row);
  std::ofstream ofs("sparse_"+argv0);
  ofs<<row<<" "<<col<<"\n";
  REP(i,row){
    B[i]=0.0;
    REP(j,col){
      if(A[i][j]){
	B[i]++;
      }
    }
    ofs<<B[i]<<" ";
    REP(j,col){
      if(A[i][j])
	ofs<<j<<" "<<A[i][j]<<" ";
    }
    ofs<<"\n";
  }
    return 0;
}
