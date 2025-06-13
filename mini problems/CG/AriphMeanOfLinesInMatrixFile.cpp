#include <iostream>
#include <fstream>
using namespace std;


void regeniracia(int n, int m){
  ofstream f1 = ofstream();
  f1.open("f1.txt"); 
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      f1 << rand() % 100 << ' '; 
    }
    f1 << endl;
  }
  f1.close();
}


void garvardVOdesse(){
  ifstream f1 = ifstream("f1.txt");
  ofstream f2 = ofstream("f2.txt");

  string stroka;
  if(f1.is_open()){
    while(getline(f1, stroka)){
      f2 << stroka;
      
      int summa = 0;
      int kolvo = 0;

      int tekushChislo = 0;

      for(int i = 0; i < stroka.size(); ++i){
        if(stroka[i] == ' '){
          summa += tekushChislo;
          tekushChislo = 0;
          kolvo++;
        }
        else{
          tekushChislo *= 10;
          tekushChislo += (int)stroka[i] - 48;
        }
      }
      f2 << summa/kolvo << endl;
    }
  }
  f1.close();
  f2.close();  
}


int main() {
  int n,m;
  srand(time(NULL));
  cout << "BB n ";
  cin >> n;
  cout << "BB m ";
  cin >> m;
  
  regeniracia(n,m);
  garvardVOdesse();
  return 0;
}
