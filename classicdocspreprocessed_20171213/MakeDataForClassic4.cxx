#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<vector>
#define REP(i,n) for(int i=(0);i<(n);i++)
using namespace std;

int main(){
  ifstream ifs("docbyterm.txt");
  if(!ifs){
    cout<<"could not file"<<endl;
    exit(1);
  }
  int row,col;
  double tmp;
  ifs>>row>>col>>tmp;
  //データ番号一つが抜けてるため
  row--;
  vector< vector<double> > A;
  A.resize(row);
  for( int i=0; i<row; i++ ){
    A[i].resize(col);
  }
  REP(i,row){
    REP(k,col){
      A[i][k]=0.0;
    }
  }
  int tmpr,tmpc,a=0;
  while(ifs){
    ifs>>tmpr>>tmpc>>tmp;
    //データ番号1552が抜けてる
    if(tmpr>1552){
      A[tmpr-2][tmpc-1]=tmp;
    }else if(tmpr<1552){
      A[tmpr-1][tmpc-1]=tmp;
    }
    else{
      exit(1);
    }a++;
  }
  ofstream ofs("classic4.txt");
  ofs<<row<<" "<<col<<"\n";
  REP(k,row){
    REP(l,col){
      if(A[k][l]>0)
	ofs<<k<<" "<<l<<" "<<A[k][l]<<endl;
    }
  }
  return 0;
}
