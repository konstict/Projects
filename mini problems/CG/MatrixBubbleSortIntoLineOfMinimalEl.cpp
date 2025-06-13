#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


int randome(){
    int num = -5 + rand() % 10;
    return num;
}


int main(){
    srand(time(0));
    
    int n, m;
    cout << "bb n "; 
    cin >> n;
    cout << "bb m ";
    cin >> m;
    
    vector <vector<int>> bern(n, vector<int>(m));
    
    int minimalniy = bern[0][0];
    int fir = 0;
    for(int i=0;i<n ;i++){ 
        for(int j=0 ;j<m ;j++){
            cout.width(3);
            bern[i][j] = randome();
            cout << bern[i][j];
            if(bern[i][j] < minimalniy){
                minimalniy = bern[i][j]; // 🤣🤣😂
                fir = j;
            }
        }
        cout << endl;
    }
    
    cout << endl;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j  < n - i - 1; j++){
            if (bern[j][fir] > bern[j+1][fir]){
                swap(bern[j][fir], bern[j+1][fir]);
            }
        }
    }
    
    for(int i=0;i<n ;i++){ 
        for(int j=0 ;j<m ;j++){
            cout.width(3);
            cout << bern[i][j];
        }
        cout << endl;
    }
    cout << "minimalniy" << minimalniy << endl;
    
return 0;
}
