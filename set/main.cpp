#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class set{
private:
    vector<T> setList;

public:
    set(){}
    
    set(vector<T> arr){
        for(int i = 0; i < arr.size(); ++i){
            setList.push_back(arr[i]);
        }
    }

    template<size_t N>
    set(T (&arr)[N]){
        for(int i = 0; i < N; ++i){
            setList.push_back(arr[i]);
        }
    }

    int* operator[](int i){
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

    bool insert(T element){ // time O(n)
        for(int i = 0; i < setList.size(); ++i){
            if(setList[i] == element){
                return false;
            }
        }
        setList.push_back(element);
        return true;
    }

    bool erase(T element){ // time O(n)
        for(int i = 0; i < setList.size(); ++i){
            if(setList[i] == element){
                setList.erase(setList.begin() + i);
                return true;
            }
        }
        return false;
    }

    set<T> operator+(set<T> second){ // time O(n*n)
        set<T> res;
        int sizeF = this->size()-1;
        int sizeS = second.size()-1;
        for(int i = 0; i < sizeF; ++i){
            for(int j = 0; j < sizeS; ++j){
                if(this->setList[i] == second.setList[j]){
                    res.insert(setList[i]);
                }
            }
        }
        return res;
    }

    // operator-(set<T> second){
    //     set<T> res;
    //     return res;
    // }

    // operator&(set<T> second){
    //     set<T> res;
    //     return res;
    // }

    // operator==(set<T> second){
    //     set<T> res;
    //     return res;
    // }
};

int main(){
    int arr[] = {3,4,5};

    set<int> a({1,2,3});
    set<int> b(arr);
    set<int> c = a+b;

    a.contains();
    b.contains();
    c.contains();

    return 0;
}

// Очень простейшее множество (без хеш)

// 5. множество (set) https://metanit.com/cpp/tutorial/7.13.php 
// следующие методы: конструктор, insert, contains, size, isEmpty, erase  +

// задачи на множества:
// - преобразование списка или массива в множество +
// - пересечение множеств
// - разность множеств
// - объединение множеств
// - проверка подмножества (входит ли одно множество целиком частью другого)