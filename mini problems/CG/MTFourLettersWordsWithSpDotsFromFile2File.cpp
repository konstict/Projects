#include <iostream>
#include <fstream>
using namespace std;


string regeniracia(int n){
 int b;
 string clova = string(n, ' ');
 for(int i=0; i < n; i++){
  int veroyatnost = rand() % 100;
  if (veroyatnost < 80) {
   b = 97 + rand() % 25;
   clova[i] = (char)b;
  }
  else if (veroyatnost < 95){
   clova[i] = ' ';
  } 
  else{
   clova[i] = '.';
  }
 }
 return clova;
}


void zarodilsa(string nazvanie, int n){
  ofstream f1 = ofstream(nazvanie);
  f1 << regeniracia(n);
  f1.close();
}


void otbor(string nazvanie, string neznaniye){
  ifstream f1 = ifstream(nazvanie);
  ofstream f2 = ofstream(neznaniye);
  string templar;
  string temp;
  if (f1.is_open()){
    while (getline(f1, temp)){
      for(int i = 0; i < temp.size(); ++i){
        if (temp[i] != ' ' and temp[i] != '.'){
          templar.push_back(temp[i]);
        }
        else{
          if (templar.size() > 4) f2 << templar << ' ';
           
          templar = "";
        }
      }
    }
  }
}


int main() {
  srand(time(NULL));

  cout << "BB n" << endl;
  int n = 100;
  cin >> n;

  zarodilsa("f1.txt", n);
  otbor("f1.txt", "f2.txt");
  return 0;
}
