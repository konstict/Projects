#include <iostream>
using namespace std;


int fact(int a){
    int result = 1;
    for(int i = 1; i <= a; ++i){
        result *= i;
    }
    
    return result;
}


int main()
{
    int n;
    cout << "Input n" << endl;
    cin >> n;
    if(n < 1){
        return 0;
    }
    
    float res = 1;
    for(int i = 1; i <= n; ++i){
        res *= 2. + (1. / fact(i));
    }
    
    cout<< "Proizvedenie ravno "<< res;
    
    return 0;
}
