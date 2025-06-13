#include <iostream>
using namespace std;


string regeniracia(int n, string clova){
 int b;
 for(int i=0; i < n; i++){
  int veroyatnost = rand() % 100;
  if (veroyatnost < 70) {
   b = 65 + rand() % 57;
   clova[i] = (char)b;
  }
  else{
   clova[i] = ' ';
  } 
 }
 return clova;
}


string elita(int n, string clova){
    string super(n, ' ');
    int mesto = 0;
    for(int i=0; i < n; i++){
     int g;
     g = (int)clova[i];
     if(g > 80 && g < 91){
      g += 32;
      super[mesto] = (char)g;
      mesto = mesto + 1 ;
     }
     else if(g > 80+32 && g < 91+32){
         super[mesto] = (char)g;
         mesto = mesto + 1;
        }
    }
    super.resize(mesto);
    return super;
}


string bogoSort(string clova){
    for(int i = 0; i < clova.size(); ++i){
        for(int j = 0; j < clova.size()-i-1; ++j){
            if(clova[j] > clova[j+1]){
                swap(clova[j], clova[j+1]);
            }
        }
    }
    return clova;
}


int main() {
 srand(time(NULL));
 
 int n;
 cout << "bb n ";
 cin >> n;
 
 string clova(n, ' ');
 
 clova = regeniracia(n,clova);
 cout << "size = " << clova.size() << endl;
 cout << clova << endl;
 
 clova = elita(n,clova);
 cout << "size = " << clova.size() << endl;
 cout << clova << endl;

 clova = bogoSort(clova);
 cout << clova << endl;
 return 0;
}
