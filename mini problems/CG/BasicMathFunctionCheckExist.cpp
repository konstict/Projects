#include <iostream>
#include <math.h>
using namespace std;


bool checkExist(float X, float Y){
    if(fabs(X) <= 0.5 and fabs(Y) <= 1.0){
        if( fabs(Y) < fabs(fabs(X*2)-1) ){
            return true;
        }
    }
    return false;
}


int main() {
    float X, Y;
    
    cout << "X = " << endl;
    cin >> X;
    cout << "Y = " << endl;
    cin >> Y;
    
    bool isExist = checkExist(X, Y);
    
    cout << "Tochka ( " << X << " ; " << Y << " ) ";
    isExist == true ? cout << "Prinadlezit" : cout << "Ne Prinadlezit";
    cout << endl;
    
    return 0;
}
