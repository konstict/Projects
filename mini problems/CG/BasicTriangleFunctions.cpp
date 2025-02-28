#include <iostream>
#include <cmath>
#define pi 3.1415926535
using namespace std;


void perimetr(int x, int y, int z)
{
    cout<<"периметр этого треугольника равен "<<x+y+z;
}


void square(int x, int y, int z)
{
    int p;
    p = (x+y+z)/2;
    cout<<"площадь этого треугольника равен "<<sqrt(p*(p-x)*(p-y)*(p-z));
}


float angle(int x, int y, int z, int k)
{
    float fx,fy,fz;
    fx = (float)x;
    fy = (float)y;
    fz = (float)z;
    //if(2*fx*fy == 0) {cout << "Деление на 0"; return -1;}
    float ugol = acos(((fx*fx)+(fy*fy)-(fz*fz))/(2*fx*fy))*(180/pi);
    
    return ugol ;
}


int main()
{
    int x,y,z,k;
    cout<<"Ввести три числа x, y, z - длины сторон треугольника. Они должны удовлетворять аксиоме треугольника\n";
    cin >>x>>y>>z;
    if(x+y<= z || x+z<= y || y+z <= x){
        cout<<"Не удовлетворяет аксиоме треугольника, введите другие значения";
        return 0;
    }
    cout<<"введите k\nпри k=1 вычислить периметр треугольника\nпри k=2 – площадь треугольника\nпри k=3 – угол между сторонами x и y\nпри k=4 – угол  между сторонами y и z\nиначе – угол между сторонами x и z\n";
    cin >>k;
    
    switch(k){
        case 1: perimetr(x,y,z); break;
        case 2: square(x,y,z); break;
        case 3: cout << "Угол между x и y равен " << angle(x,y,z,3);  break;
        case 4: cout << "Угол между y и z равен " << angle(y,z,x,4); break;
        default: cout << "Угол между x и z равен " << angle(x,z,y,5); break;
        
    }
    return 0;
}
