#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


int randNum = 5;
int randome(){
    int sign = rand() % 2;
    if (sign == 0) return rand() % randNum;
    else return -rand() % randNum;
}


int n, m;
void generatePrintAndFindMax(vector<vector<int>> &bern, vector<int>& maximalki, int &maximalka){
    for(int i=0;i<n ;i++){ 
        for(int j=0 ;j<m ;j++){
            
            cout.width(3);
            bern[i][j] = randome();
            cout << bern[i][j];
            
            if(bern[i][j] > maximalka){
                maximalka = bern[i][j]; // 🤣🤣😂
                maximalki = vector<int>(0);
                maximalki.push_back(i);
            }
            else if(bern[i][j] == maximalka){
                maximalki.push_back(i);
            }
        }
        cout << endl;
    }
}


void printInfo(vector <vector<int>> bern, vector<int> maximalki, int maximalka){
    cout << endl;
    for(int i=0;i<n ;i++){ 
        for(int j=0 ;j<m ;j++){
            cout.width(3);
            cout << bern[i][j];
        }
        cout << endl;
    }
    cout << endl << "maximalki v sleduyushih strokah: " << endl;
    for(int i = 0; i < maximalki.size(); ++i) cout << maximalki[i];
    cout << endl << "maximalka ravna " << maximalka << endl;
}


void sortingAllMaxesByBubble(vector <vector<int>>& bern, vector<int>& maximalki){
    for(int a = 0; a < maximalki.size(); ++a){
        int fir = maximalki[a];
        for(int i = 0; i < m-1; i++){
            for(int j = 0; j  < m - i - 1; j++){
                if (bern[fir][j] < bern[fir][j+1]){
                    swap(bern[fir][j], bern[fir][j+1]);
                }
            }
        }
    }
}


void input(){
    cout << "bb n "; 
    cin >> n;
    cout << "bb m ";
    cin >> m;
}


int main(){
    srand(time(0));
    input();
    
    vector <vector<int>> bern(n, vector<int>(m));
    vector<int> maximalki;
    int maximalka = -randNum;
    
    generatePrintAndFindMax(bern, maximalki, maximalka);
    sortingAllMaxesByBubble(bern, maximalki);
    printInfo(bern, maximalki, maximalka);
    
    return 0;
}
