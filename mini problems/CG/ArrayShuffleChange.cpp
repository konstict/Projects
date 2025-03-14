#include <iostream>
#include <ctime>
using namespace std;


int getRandomNum(int n, int maxNum){
    int sign = rand() % 2;
    int num = rand() % maxNum;
    if(sign == 1){
        return num;
    }
    else{
        return -num;
    }
}


void printOldNewArray(int array[], int N, int min){
    bool signPlus = false;
    for(int i = 0; i < N; ++i){
        cout.setf(ios::showpos);
        cout.width(5);
        cout << array[i] << "     ";
        if (array[i] > 0){
            signPlus = true;
            array[i] = min;
        }
        cout << array[i]<< endl;
    }
    if(!signPlus){
        cout << "Plusov ne bilo" << endl;
    }
}


int main() {
    srand(time(NULL));
    
    int n = 10;
    cout << "Vvedite razmer massiva ";
    cin >> n ;
    cout << endl;
    
    int maxNum = 100;
    cout << "Vvedite maximalnoe chislo v massive ";
    cin >> maxNum;
    cout << endl;
    
    int array[n];
    int minNum = maxNum;
    for(int i = 0; i < n; i++){
        array[i] =  getRandomNum(n, maxNum);
        if (array[i] < minNum){
            minNum = array[i];
        }
    }
    
    printOldNewArray(array, n, minNum);
    
    return 0;
}
