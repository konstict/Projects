#include <iostream>
#include <math.h>
#define EPS 1e-4
using namespace std;


double fact(int a){
    double result = 1;
    for(int i = 1; i <= a; ++i){
        result *= i;
    }
    return result;
}


double power(float a, int b){
    if(a == -1){
        if(b % 2 == 0){
            return 1;
        }
        else{
            return -1;
        }
    }
    double c = 1;
    for (int i=0; i < b ; i++){
        c = c*a;
    }
    return c;
}


double sinus(double x){
    double res = 0;
    double oldRes = 0;
    double magicDigit;
    double top, bot;
    double diff = 1;
    
    for(int i = 0; fabs(diff) >= EPS; ++i){
        magicDigit = 2*i+1;
        top = power(x, magicDigit);
        bot = fact(magicDigit);
        // if(res+power(-1,i)*(top/bot) != res+power(-1,i)*(top/bot)){return res;} - не нужное
        oldRes = res;
        res += power(-1,i) * (top / bot);
        diff = res - oldRes;
    }
    
    return res;
}


int main(){
    double x;
    cout << "Vvedite X " << endl;
    cin >> x;
    cout << "sin(X) = " << endl << sinus(x) << endl << sin(x);
    
    return 0;
}
