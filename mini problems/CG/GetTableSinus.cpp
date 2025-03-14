#include <iostream>
#include <math.h>
#include <iomanip>
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
    double magicDigit;
    double top, bot;
    double diff = 1;
    
    for(int i = 0; fabs(diff) >= EPS; ++i){
        magicDigit = 2*i+1;
        top = power(x, magicDigit);
        bot = fact(magicDigit);
        diff = power(-1,i) * (top / bot);
        res += diff;
    }
    
    return res;
}


template<typename T>
void input(string text, T& val){
    cout << text << endl;
    cin >> val;
}


void tableOfFuncAndNoMyFunc(double firstX, double lastX, double stepX, double(*myFunc)(double), double(*noMyFunc)(double) ){
    cout.setf(ios::fixed);
    cout << "  X" << "          moy sinus " << " bibl sinus"<< " raznica" << endl;
    
    double resultMyFunc = 0, resultNoMyFunc = 0, differenceOfMyFuncAndNoMyFunc = 0;
    int countOfX = 0.;
    for(double currentX = firstX; currentX <= lastX; currentX += stepX){
        countOfX += 1;      

        resultMyFunc =  myFunc(currentX);
        resultNoMyFunc = noMyFunc(currentX);
        differenceOfMyFuncAndNoMyFunc = resultMyFunc - resultNoMyFunc;
        cout <<"| "<< currentX << " | ";
        cout << resultMyFunc << " | ";
        cout << resultNoMyFunc << " | " ;
        cout << fabs(differenceOfMyFuncAndNoMyFunc) << " |" << endl;
    }
    cout << "Vsego bilo raz " << countOfX << endl;
}


int main(){
    double firstX = 0., lastX = 1., stepX = 0.001;
    
    input("Vvedite pervii X", firstX);
    input( "Vvedite konechniy X", lastX);
    input( "Vvedite Shag", stepX);
    
    tableOfFuncAndNoMyFunc(firstX, lastX, stepX, sinus, sin);
    
    return 0;
}
