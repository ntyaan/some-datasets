#include <iostream>
#include <fstream>
#include <unordered_map>  
#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

const std::string data_file = "data/BX-Book-Ratings_reserve.txt";
constexpr int SIZE = 1149780;

int main(void){
  //データ読み込み
  std::ifstream ifs(data_file);
  if(ifs.fail()){
    std::cerr<<"file error"<<std::endl;
    exit(1);
  }
  //map
  std::unordered_map<std::string, int> mp_users, mp_books;
  std::vector<int> Values;
  std::vector<std::string> Users, Items;
  std::string str1, str2;
  int value, index1=0, index2=0;
  //最後の行+1を読み込んでしまうのでSIZE分で回す(元がバイナリファイルで変換したから？)
  //while(!ifs.eof()){
  for(int i=0;i<SIZE;i++){
    ifs >> str1 >> str2 >> value;
    if(value!=0){
      Users.push_back(str1);
      Items.push_back(str2);
      Values.push_back(value);

      //ユーザ番号の変換
      auto it_user = mp_users.find(str1);
      if(it_user==mp_users.end()){
	mp_users[str1] = index1;
	index1++;
      }
      //映画番号の変換
      auto it_book = mp_books.find(str2);
      if(it_book==mp_books.end()){
	mp_books[str2] = index2;
	index2++;
      }
    }
  }
  ifs.close();
  std::cout<<"評価数:"<<Values.size()<<"\tユーザ数:"
	   <<index1<<"\t映画数:"<<index2<<std::endl;
  //欠番を詰める
  std::ofstream ofs_row("data/ratings_rowmajor.txt");
  for(int i=0;i<(int)Values.size();i++){
    ofs_row<<mp_users[Users[i]]<<" "
	   <<mp_books[Items[i]]<<" "
	   <<Values[i]<<std::endl;
  }
  ofs_row.close();
  return 0;
}
