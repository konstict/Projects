#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


int GetRandomNum(){
    return rand() % 2;
}


vector<int> GenerateArray(vector<int> &arr){
    for (int i = 0; i < arr.size(); ++i) 
    {
        arr[i] = GetRandomNum();
    }
    return arr;
}


void PrintArray(vector<int> arr){
    for (int i = 0; i < arr.size(); ++i) 
    {
        cout << arr[i] << endl;
    }
}


void SortArray(vector<int> &arr){
    int numbers[] = {0,0};
    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] == 0 ? numbers[0]++ : numbers[1]++;
    }
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (numbers[1] > 0)
        {
            numbers[1]--;
            arr[i] = 1;
        }
        else
        {
            numbers[0]--;
            arr[i] = 0;
        }
    }
}


int main()
{
    srand(time(NULL));
    
    int size = 5, max = 10;
    // cout << "BB razmer spiska" << endl;
    // cin >> size;
    // cout << "max random" << endl;
    // cin >> max;
    
    vector<int> arr(size);
    GenerateArray(arr);
    
    cout << "array do sorta" << endl;
    PrintArray(arr);
    
    SortArray(arr);
    cout << "array posle sorta" << endl;
    PrintArray(arr);
    
    return 0;
}
