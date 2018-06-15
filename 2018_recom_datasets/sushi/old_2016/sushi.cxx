#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<random>
#define REP(i,n) for(int i=(0);i<(n);i++)
using namespace std;
int main(void){
  vector< vector<int> > A;
  A.resize(5000);
  for( int i=0; i<5000; i++ ){
    A[i].resize(100);
  }
  ifstream ifs("sushi3b.5000.10.score");
  int tmp;
  REP(i,5000){
    REP(j,100){
      ifs>>tmp;
      tmp++;
      A[i][j]=tmp;
    }}
  string str="sushi_"+to_string(5000)+"_"+to_string(100)+".dat";
  ofstream ofs1(str);
  REP(i,5000){
    REP(j,100){
      ofs1<<A[i][j]<<" ";
    }ofs1<<endl;
  }
  return 0; 
}


  /*
  vector<vector<double>> EvaluatedValues,Relation;
  EvaluatedValues.resize(RowNum);
  Relation.resize(RowNum);
  REP(i,RowNum){
    EvaluatedValues[i].resize(ColNum);
    Relation[i].resize(ColNum);
  }
  */
