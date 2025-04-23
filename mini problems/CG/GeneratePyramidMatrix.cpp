#include<iostream>
#include<vector>
using namespace std;


int lim = 10;
int getRandom(){
    int sign = rand() % 2;
    int num = rand() % lim;
    if (sign == 0) return num;
    else return -num;
}


void generateArr(vector<vector<int>> &arr){
    for (int i = 0; i < arr.size(); ++i){
        for (int j = 0; j < i+1; ++j){
            int toLeft = arr.size()-1-i;
            int mirror = arr.size()-j-1;
            int num = arr.size()-j;
            arr[i][mirror-toLeft] = num;
        }
    }
}


void printArr(vector<vector<int>> arr){
    for (vector<int> Y : arr){
        for (int X : Y){    
        cout.width(3);
            cout << X << ' ';
        }
        cout << endl;
    }
}


int main(){
    srand(time(NULL));
    cout << "BB limit " << endl;
    cin >> lim;
    int size = 4;
    cout << "BB razmer " << endl;
    cin >> size;
    vector<vector<int>> arr(size, vector<int>(size));
    generateArr(arr);
    printArr(arr);
}

// 4 0 0 0
// 3 4 0 0
// 2 3 4 0
// 1 2 3 4
