#include<iostream>
#include<ctime>
using namespace std;
int lim = 10;


int getRandomNum(int lim){
    int sign = rand() % 2;
    int num = rand() % lim;
    if (sign == 0) return num;
    else return -num;
}


void generatePrint(int**arr,int n, int m){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            arr[i][j] = getRandomNum(lim);
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
    

bool checkPolojSlolb(int**arr,int n, int m){
    cout << "V stolbce est polojitelniy element pod nomerom" << endl;
    bool polojLinesPositive = false;
    for (int i = 0; i < n; ++i){
        bool currentLinePositive = false;
        for (int j = 0; j < m; ++j){
            if(arr[j][i] >= 0) {currentLinePositive = true; polojLinesPositive = true;}
        }
        if (currentLinePositive) cout << i << endl;
    }
    if (polojLinesPositive) return true;
    else return false;
}


int main(){
    srand(time(NULL));
    
    cout << "input n and m" << endl;
    int n = 5, m = 5;
    // cin >> n >> m;
    cout << "input max random" << endl;
    // cin >> lim >> m;
    
    int **arr = new int*[n];
    for (int i = 0; i < n; ++i){
        arr[i] = new int[m];
    }
    
    generatePrint(arr,n,m);
    bool polojitelniyEl = checkPolojSlolb(arr,n,m);
    if(!polojitelniyEl) cout << "polojitelnix elementov ne bilo v stolbcah" << endl;
}
