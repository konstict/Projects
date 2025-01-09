#include <iostream>
#include <vector>
using namespace std;

class set{
private:
    vector<int> setList;

public:
    set(){}
    set(vector<int> arr){
        for(int i = 0; i < arr.size(); ++i){
            setList.push_back(arr[i]);
        }
    }

    int *operator[](int i){
        return &setList[i];
    }

    int size(){
        return this->setList.size();
    }

    bool isEmpty(){
        return this->setList.empty();
    }

    void contains(){
        if(this->isEmpty()){
            cout << "Empty set";
        }
        else{
            for(int i = 0; i < this->size(); ++i){
                cout << this->setList[i] << ' ';
            }
        }
        cout << endl;
    }

    void insert(){
        
    }

    bool erase(int num){
        int left = 0, right = this->size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(setList[mid] < num){
                left = mid+1;
            }
            else if(setList[mid] > num){
                right = mid-1;
            }
            else{
                setList.erase(setList.begin()+mid);
                return true;
            }
        }
        return false;
    }
};

int main(){
    vector<int> vec{1,2,3,4};
    set a(vec);

    a.erase(4);
    a.contains();
    return 0;
}

// 5. множество (set) https://metanit.com/cpp/tutorial/7.13.php 
// следующие методы: конструктор, insert, contains, size, isEmpty, erase

// задачи на множества:
// - преобразование списка или массива в множество
// - пересечение множеств
// - разность множеств
// - объединение множеств
// - проверка подмножества (входит ли одно множество целиком частью другого)