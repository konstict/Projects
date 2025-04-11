#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


int getRandomNum(int lim){
    int sign = rand()%2;
    int num = rand()%lim;
    if(sign == 0) return -num;
    else return num;
}


int lim = 10;
void generate(vector< vector <vector<int>>*> &list){
    for(int i = 0; i < list.size(); ++i){
        for(int j = 0; j < list[i]->size(); ++j){
            for(int k = 0; k < list[j]->size(); ++k){
                (*list[i]) [j][k] = getRandomNum(lim);
            }
        }
    }
}


void printList(vector< vector <vector<int>>*> &list){
    for(int i = 0; i < list[0]->size(); ++i){
        for(int j = 0; j < list[i]->size(); ++j){
            cout.width(5);
            cout << (*list[0])[i][j];
        }
        cout.width(5);
        cout << '|';
        for(int j = 0; j < list[i]->size(); ++j){
            cout.width(5);
            cout << (*list[1])[i][j];
        }
        cout << endl;
        
    }
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < list[0]->size(); ++i){
        for(int j = 0; j < list[i]->size(); ++j){
            cout.width(5);
            cout << (*list[2])[i][j];
        }
        cout.width(5);
        cout << '|';
        for(int j = 0; j < list[i]->size(); ++j){
            cout.width(5);
            cout << (*list[3])[i][j];
        }
        cout << endl;
        
    }
}


void print2List(vector<vector<int>> list){
    for(int i = 0; i < list.size(); ++i){
        for(int j = 0; j < list[i].size(); ++j){
            cout << list[i][j];
        }
        cout << endl;
    }
}


void swapBlocksOfVector(vector< vector <vector<int>>> &list, int first, int second){
    vector <vector<int>> temp = list[first];
    // print2List(list[first]);
    // print2List(list[second]);
    list[first] = list[second];
    list[second] = temp;
    // print2List(list[first]);
    // print2List(list[second]);
}


int main() {
    srand(time(NULL));
    int n = 5;
    // cout << "BB n" << endl;
    // cin >> n;
    // cout << "BB max random" << endl;
    // cin >> lim;
    
    int lenght = 2*n;
    vector< vector<vector<int>>* > list(4);
    for (int i = 0; i < list.size(); ++i){
        list[i] = new vector<vector<int>>(n, vector<int>(n));
    }
    
    generate(list);
    cout << "iznachalniy arraylist" << endl;
    printList(list);
    
    // 0-1 1-3 3-2 2-0
    vector<vector<int>> targetList = {{0,2}, {1,0}, {2,3}, {3,1}}; // po etomu spisku budem swapat`
    
    vector< vector <vector<int>>*> nList(0);
    for(int i = 0; i < targetList.size(); ++i){
        int firstIndex = targetList[i][0];
        int secondIndex = targetList[i][1];
        vector <vector<int>>* insertingList = list[secondIndex];
        
        nList.push_back(insertingList);
        // swapBlocksOfVector(list, firstIndex, secondIndex);
        // cout << endl;
    }
    
    cout << endl << "swapnutiy arraylist" << endl;
    printList(nList);
    
    return 0;
}
