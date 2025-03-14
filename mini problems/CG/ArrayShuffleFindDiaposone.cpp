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


void printArrayAndLastDiaposone(int array[], int N, int a, int b){
    
    int otvet = 0;
    for(int i = 0; i < N; ++i){
        cout.unsetf(ios::showpos);
        cout.width(5);
        
        cout << i + 1 << "\t";
        cout.setf(ios::showpos);
        cout << array[i] << endl;
        
        if(array[i] > a && array[i] < b){
            otvet = i;
            // cout<< "otvet" << endl;
        }
        
    }
        if(otvet == 0 ){
            cout << "Ни одно число не попала в заданный диапазон";
            
        }
        else{
            cout << "Последнее значение, в заданном диапазоне это " << array[otvet]  << " находится в ячейке " << otvet+1  << endl;
            
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
    
    
    int a = -10, b = 10;
    do {
    cout << "Введите диапазон от A до B" << endl << "A = ";
    cin >> a;
    cout << endl << "B = ";
    cin >> b;
    if(a > b) cout << "А > B, диапазон неправильный. Введите диапазон верно"<< endl;
    }
    while (a > b);
    
    
    int array[n];


    for(int i = 0; i < n; i++){
        array[i] =  getRandomNum(n, maxNum);
    }
    
    printArrayAndLastDiaposone(array, n, a , b);
    
    
    return 0;
}
