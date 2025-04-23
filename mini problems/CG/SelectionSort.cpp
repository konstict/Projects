#include <iostream>
#include <vector>
using namespace std;


int lim = 10;
int getrandom(){
    int m = rand() % lim;
    int znak = rand() % 2;
    if (znak == 0 ) return m;
    else return -m;
}

vector<int> generateArr(vector<int> arr, int n){
    
    for(int i=0; i < n; ++i){
     arr[i] = getrandom();
    }
    return arr;
}


void swapnup(int &a, int &b){
    int c;
    c = a;
    a = b;
    b = c;
}


vector<int> sortirovka(vector<int> arr, int n){
    for(int i=0; i < n; ++i){
        // current = arr[i]
        for(int j=i+1; j < n; ++j){
            if (arr[j] < arr[i]){
                swapnup(arr[i], arr[j]);
                
            }            
        }
    }
    return arr;
}


int main() {
    srand(time(NULL));
    int n;
    cout << "BB razmer "<< endl;
    cin >> n;
    cout << "BB limit "<< endl;
    cin >> lim;
    vector<int> arr(n);
    arr=generateArr(arr, n);
    int countMinus = 0;
    for(int i=0; i < n; ++i){
        cout << arr[i] << ' ';
        if (arr[i] < 0) ++countMinus; 
    }
    cout << "\notricatelnih " << countMinus  << endl;
    if(countMinus < n-countMinus){
        for(int i=0; i < n; ++i){
        if (arr[i] < 0) arr[i] = arr[i]*-1;
        }
        arr = sortirovka(arr,n );
        for(int i=0; i < n; ++i){
            cout << arr[i] << ' ';
        }
    }
    else cout << "otrizatelnih bolhe ";   
    return 0;
}
