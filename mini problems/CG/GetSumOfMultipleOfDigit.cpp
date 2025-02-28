#include <iostream>
using namespace std;


bool input(int &a, int &b){
    cin >> a >> b;
    if(a > b){
        cout << "A bolshe B, nelzya" << endl;
        return false;
    }
    return true;
}


int getSumByKratniy(int a, int b, int kr){
    int result = 0;
    for(; a <= b ; a++){
        if(a > 0 and a % kr == 0){
            result += a;
        }
    }
    return result;
}


int main()
{
    int a,b;
    cout << "Input A and B" << endl; 
    if (input(a,b) == false) return 0;
    cout << "resultat = " << getSumByKratniy(a,b,4) << endl;
    return 0;
}
