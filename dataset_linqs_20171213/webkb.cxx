#include<iostream> 
#include<fstream>
#include<string> 
#include<vector>
using namespace std;
constexpr int cols=1703;
constexpr int rows=877;
constexpr int C=5;
vector<int> list={265, 187, 195, 230};
vector<string> list_label={"course", "faculty",
			   "student", "project",
			   "staff"};

int main(){
  vector<int> c(rows);
  vector<vector<double>> vec(rows);
  for(int i=0;i<rows;i++)
    vec[i].resize(cols);
  string str;
  ifstream ifs_wisconsin("WebKB/wisconsin.content");
  for(int i=0;i<list[0];i++){
    ifs_wisconsin>>str;
    for(int j=0;j<cols;j++)
      ifs_wisconsin>>vec[i][j];
    ifs_wisconsin>>str;
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
    else{
      cerr<<"wisconsin:"<<i<<endl; 
      exit(1);
    }
  }
  ifs_wisconsin.close();
  ifstream ifs_texas("WebKB/texas.content");
  for(int i=list[0];i<list[0]+list[1];i++){
    ifs_texas>>str;
    for(int j=0;j<cols;j++)
      ifs_texas>>vec[i][j];
    ifs_texas>>str;
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
    else{
      cerr<<"texas:"<<i<<endl; 
      exit(1);
    }
  }
  ifs_texas.close();
  ifstream ifs_cornell("WebKB/cornell.content");
  for(int i=list[0]+list[1];i<list[0]+list[1]+list[2];i++){
    ifs_cornell>>str;
    for(int j=0;j<cols;j++)
      ifs_cornell>>vec[i][j];
    ifs_cornell>>str;
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
    else{
      cerr<<"cornell:"<<i<<endl; 
      exit(1);
    }
  }
  ifs_cornell.close();
  ifstream ifs_washington("WebKB/washington.content");
  for(int i=list[0]+list[1]+list[2];i<list[0]+list[1]+list[2]+list[3];i++){
    ifs_washington>>str;
    for(int j=0;j<cols;j++)
      ifs_washington>>vec[i][j];
    ifs_washington>>str;
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
    else{
      cerr<<"washington:"<<i<<endl; 
      exit(1);
    }
  }
  ifs_washington.close();
  ofstream ofs_c("webkb_correct.txt");
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
  ofstream ofs("sparse_webkb.txt");
  ofs<<rows<<" "<<cols<<endl;
  for(int i=0;i<rows;i++){
    ofs<<size[i]<<" ";
    for(int j=0;j<cols;j++){
      if(vec[i][j]>0)
	ofs<<j<<" "<<vec[i][j]<<" ";
    }
    ofs<<endl;
  }
  ofs.close();
  ifstream ifs("webkb_correct.txt");
  int tmp,sum=0;
  for(int i=0;i<C;i++)
    for(int j=0;j<rows;j++){
      ifs>>tmp;
      sum+=tmp;
    }
  cout<<sum<<endl;
  return 0;
}


