#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
int main(const int argc, const char *argv[]){
  (void)argc;
  std::string FILE=std::string(*(argv+1));
  std::ifstream ifs(FILE);
  if(!ifs){
    std::cerr<<"ifs error"<<std::endl;
    exit(1);
  }
  int ROW,COL;
  ifs>>ROW>>COL;
  std::vector<std::vector<int>> Freq(ROW);
  std::vector<std::vector<double>> TF(ROW);
  std::vector<double> IDF(COL);
  for(int i=0;i<ROW;i++){
    Freq[i].resize(COL);
    TF[i].resize(COL);
  }
  for(int i=0;i<ROW;i++)
    for(int ell=0;ell<COL;ell++)
      Freq[i][ell]=0;
  int tmp,cn;
  double f;
  for(int i=0;i<ROW;i++){
    ifs>>tmp;
    double denominator=0.0;
    for(int k=0;k<tmp;k++){
      ifs>>cn>>f;
      Freq[i][cn]=f;
      denominator+=f;
    }
    for(int ell=0;ell<COL;ell++)
      TF[i][ell]=Freq[i][cn]/denominator;
  }
  for(int k=0;k<COL;k++){
    double df=0.0;
    for(int i=0;i<ROW;i++){
      if(Freq[i][k]>0)
	df++;
    }
    IDF[k]=log(ROW/df)+1.0;
  }
  std::ofstream ofs("tfidf1_"+FILE);
  ofs<<ROW<<" "<<COL<<std::endl;
  for(int i=0;i<ROW;i++){
    int c=0;
    for(int k=0;k<COL;k++){
      if(Freq[i][k]>0)
	c++;
    }
    ofs<<c<<" ";
    for(int k=0;k<COL;k++){
      double tmp=TF[i][k]*IDF[k];
      if(Freq[i][k]>0){
	ofs<<k<<" ";
	ofs<<std::fixed<<std::setprecision(20)<<tmp<<" ";
      }
    }
    ofs<<std::endl;
  }
  return 0;
}
