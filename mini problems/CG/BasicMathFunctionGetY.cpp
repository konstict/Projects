#include<iostream>
using namespace std;


int getY(int X){
    if(X < -1){
        return X*X+3*X;
    }
    else if(X > 10){
        return 2*X+5;
    }
    else{
        return X;
    }
}


int main(){
    int X;
    
    cout << "Input X" << endl;
    cin >> X;
    
    cout << "X = " << X << " Y = " << getY(X) << endl;
    
    return 0;
}