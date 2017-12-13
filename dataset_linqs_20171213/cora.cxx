#include<iostream> 
#include<fstream>
#include<string> 
#include<vector>
using namespace std;
constexpr int cols=1433;
constexpr int rows=2708;
constexpr int C=7;
vector<string> list_label={"Case_Based", "Genetic_Algorithms",
			   "Neural_Networks", "Probabilistic_Methods",
			   "Reinforcement_Learning", "Rule_Learning",
			   "Theory"};

int main(){
  vector<int> c(rows);
  vector<vector<double>> vec(rows);
  for(int i=0;i<rows;i++)
    vec[i].resize(cols);
  string str;
  ifstream ifs_cora("cora/cora.content");
  for(int i=0;i<rows;i++){
    ifs_cora>>str;
    for(int j=0;j<cols;j++)
      ifs_cora>>vec[i][j];
    ifs_cora>>str;
    if(str==list_label[0])
      c[i]=0;
    else if(str==list_label[1])
      c[i]=1;
    else if(str==list_label[2])
      c[i]=2;
    else if(str==list_label[3])
      c[i]=3;
    else if(str==list_label[4])
      c[i]=4;
    else if(str==list_label[5])
      c[i]=5;
    else if(str==list_label[6])
      c[i]=6;
    else{
      cerr<<i<<endl; 
      exit(1);
    }
  }
  ifs_cora.close();
  ofstream ofs_c("cora_correct.txt");
  for(int i=0;i<C;i++){
    for(int k=0;k<rows;k++){
      if(i==c[k])
	ofs_c<<1<<" ";
      else
	ofs_c<<0<<" ";
    }
    ofs_c<<endl;
  }
  vector<int> size(rows);
  for(int i=0;i<rows;i++){
    size[i]=0;
    for(int j=0;j<cols;j++){
      if(vec[i][j]>0)
	size[i]++;
    }
  }
  ofs_c.close();
  ofstream ofs("sparse_cora.txt");
  ofs<<rows<<" "<<cols-1<<endl;
  for(int i=0;i<rows;i++){
    ofs<<size[i]<<" ";
    for(int j=0;j<cols;j++){
      if(vec[i][j]>0){
	if(j<444)
	  ofs<<j<<" "<<vec[i][j]<<" ";
	else if(j>444)
	  ofs<<j-1<<" "<<vec[i][j]<<" ";
	else
	  cerr<<j<<endl;
      }
    }
    ofs<<endl;
  }
  ofs.close();
  ifstream ifs("cora_correct.txt");
  int tmp,sum=0;
  for(int i=0;i<C;i++)
    for(int j=0;j<rows;j++){
      ifs>>tmp;
      sum+=tmp;
    }
  cout<<sum<<endl;
  return 0;
}


