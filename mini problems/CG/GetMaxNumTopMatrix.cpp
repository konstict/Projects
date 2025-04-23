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
        for (int j = 0; j < arr.size(); ++j){
            arr[i][j] = getRandom();
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


int maxTop(vector<vector<int>> arr){
    int max = -lim;
    int size = arr.size();
    for (int i = 0; i < size+1 / 2; ++i){
        for (int j = i; j < size-i; ++j){
            // cout << arr[i][j] << ' ';
            if (arr[i][j] > max) max = arr[i][j];
        }
        // cout << endl;
    }
    return max;
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
    cout << "Max element sverhu = " << maxTop(arr);
}
