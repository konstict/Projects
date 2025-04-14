#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


int getRandomNum(int lim){ // random number with random sign
    int sign = rand()%2;
    int num = rand()%lim;
    if(sign == 0) return -num;
    else return num;
}


int lim = 10;
void generate(vector< vector <vector<int>>*> &list){ // generate full arraylist of random numbers
    int sizeY = list[0]->size();
    int sizeX = list[0][0].size();
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < sizeY; ++j){
            for(int k = 0; k < sizeX; ++k){
                (*list[i]) [j][k] = getRandomNum(lim);
            }
        }
    }
}


void printList(vector< vector <vector<int>>*> &list){ // print 3-m arraylist
    int sizeY = list[0]->size();
    int sizeX = list[0][0].size();
    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
            cout.width(5);
            cout << (*list[0])[i][j];
        }
        cout.width(5);
        cout << '|';
        for(int j = 0; j < sizeX; ++j){
            cout.width(5);
            cout << (*list[1])[i][j];
        }
        cout << endl;
        
    }
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < sizeY; ++i){
        for(int j = 0; j < sizeX; ++j){
            cout.width(5);
            cout << (*list[2])[i][j];
        }
        cout.width(5);
        cout << '|';
        for(int j = 0; j < sizeX; ++j){
            cout.width(5);
            cout << (*list[3])[i][j];
        }
        cout << endl;
        
    }
}


void print2List(vector<vector<int>> list){ // print 2-m arraylist
    for(int i = 0; i < list.size(); ++i){
        for(int j = 0; j < list[i].size(); ++j){
            cout << list[i][j];
        }
        cout << endl;
    }
}


void swapBlocksOfVector(vector< vector <vector<int>>> &list, int first, int second){ // swapping in existing arraylist
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
    
    // user giving numbers
    int lenght = 10;
    cout << "BB n" << endl;
    cin >> lenght;
    cout << "BB max random" << endl;
    cin >> lim;

    // creating arraylist
    vector< vector<vector<int>>* > list(4);
    for(int i = 0; i < 4; ++i){
        list[i] = new vector<vector<int>>(lenght, vector<int>(lenght));
    }

    // generate and print first arraylist
    generate(list);
    cout << "first arraylist" << endl;
    printList(list);
    
    // 0-1 1-3 3-2 2-0
    vector<vector<int>> targetList = {{0,2}, {1,0}, {2,3}, {3,1}}; // po etomu spisku budem swapat`

    // swapping arraylist
    vector< vector <vector<int>>*> nList(0);
    for(int i = 0; i < targetList.size(); ++i){
        int firstIndex = targetList[i][0];
        int secondIndex = targetList[i][1];
        vector <vector<int>>* insertingList = list[secondIndex];
        
        nList.push_back(insertingList);
        // swapBlocksOfVector(list, firstIndex, secondIndex);
    }

    // pring last - swapped arraylist
    cout << endl << "swaped arraylist" << endl;
    printList(nList);
    
    return 0;
}
