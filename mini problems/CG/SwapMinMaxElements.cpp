#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


int iGetRandomNum(int iMaxIn){
    int iSign = rand() % 2;
    int iNum = rand() % iMaxIn;
    if(iSign == 1){
        return iNum;
    }
    else{
        return -iNum;
    }
}



int main()
{
    srand(time(NULL));
    bool bCheck = false;
    int iN,iMax = 0,iMin = 0;
    cout << "BB razmer spiska" << endl;
    cin >> iN;
    
    int iMaxIn;
    cout << "max random" << endl;
    cin >> iMaxIn;
    int iA = 0, iB = -1 * iMaxIn;
    vector<int> iList(iN);
    
    cout << "do swapa" << endl;
    for(int i=0; i < iList.size();i++){
        
        
        iList[i] = iGetRandomNum(iMaxIn);
        cout.width(4);
        cout<<i+1;
        cout.width(4);
        cout << iList[i] << endl;
        
        if(iList[i]<0 && iList[i]< iA && iList[i] % 2 == 0 && iList[i]!=iB ){
                 iA = iList[i];
                 iMax = i;
                 bCheck = true;
            }
        if(iList[i]<0 && iList[i]> iB  && iList[i] % 2 == 0 && iList[i]!=iA ){
                 iB = iList[i];
                 iMin = i;
                 bCheck = true;
        }
    }
    
    if (bCheck == false){
        cout <<"Zamena ne proizochla";
        }
    else
    {   
        int iTemp = iList[iMax];
        iList[iMax] = iList[iMin];
        iList[iMin] = iTemp;
        cout << "posle swapa elementov " << iA << " i " << iB << " V echeikah "<< iMax + 1  <<" i "<< iMin + 1 << endl;
        for(int i=0; i < iList.size();i++){
            cout.width(4);
            cout<<i+1;
            cout.width(4);
            cout << iList[i] << endl;
            }
        }
    
    
    return 0;
}
