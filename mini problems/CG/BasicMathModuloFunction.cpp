#include <iostream>
#include <cmath>
using namespace std;


int getOstatok(float y, float a, float b){
    // cout<<(log10(y*y*y-a*b)-1);
    return (int)(log10(y * y * y - a * b) - 1) % 7;
}


int main() {

    float y,a,b;
    cout << "Ввeдите y, a, b\n";
    cin >> y >> a >> b;
    int z = getOstatok(y,a,b);
    cout << "Остаток равен " << fabs(z) << endl;
    
    if(z == 0){
        z = 2;
    }
    else{
        z = z % 2;
    }
    switch(z){
        case 0: cout << "Остаток четный"; break;
        case 1: cout << "Остаток нечеткий"; break;
        case 2: cout << "Остаток равен 0"; break;
    }
    
    return 0;
}
