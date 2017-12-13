#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#define REP(i,n) for(int i=(0);i<(n);i++)
using namespace std;
const int centers_number = 4;

int main(){
  ifstream ifs("documents.txt");
  if(!ifs){
    cout<<"could not file"<<endl;
    exit(1);
  }
  vector<double> Label;
  Label.resize(centers_number);
  std::string str;
  int value;
  while(ifs){
    ifs>>str>>value;
    switch (value){
    case 0:
      Label[0]++;
      break;
    case 1:
      Label[1]++;
      break;
    case 2:
      Label[2]++;
      break;
    case 3:
      Label[3]++;
      break;
    }
  }
  int tmp=Label[0], row=0;
  //cran:995,471
  Label[3]--;
  REP(i,centers_number){
    row+=Label[i];
    std::cout<<Label[i]<<" ";
  }std::cout<<std::endl;
  ofstream ofs_correct("classic4_corect.txt");
  REP(i,centers_number){
    if(i==0){
      REP(j,Label[i]){
        ofs_correct<<1<<" ";
      }REP(j,row-Label[i]){
        ofs_correct<<0<<" ";
      }ofs_correct<<endl;
    }
    else if(i+1==centers_number){
      REP(j,row-Label[i]){
        ofs_correct<<0<<" ";
      }REP(j,Label[i]){
        ofs_correct<<1<<" ";
      }ofs_correct<<endl;
    }
    else{
      REP(j,tmp){
        ofs_correct<<0<<" ";
      }REP(j,Label[i]){
        ofs_correct<<1<<" ";
      }REP(j,row-(Label[i]+tmp)){
        ofs_correct<<0<<" ";
      }ofs_correct<<endl;
      tmp+=Label[i];
    }         
  }
  return 0;
}
