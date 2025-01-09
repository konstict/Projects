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

    bool insert(int num){
        int size = this->size();
        int left = 0, right = size-1, mid=0;
        while(left <= right){
            mid = (left+right)/2;
            if(setList[mid] < num){
                left = mid+1;
            }
            else if(setList[mid] > num){
                right = mid-1;
            }
            else{
                return false;
            }
        }
        if(mid != size-1 and mid != 0){
            setList.insert(next(setList.begin() + mid), move(num));
        }
        else{
            if(mid == size-1){
                if(num > setList[size-1]){
                    setList.push_back(num);
                }
                else{
                    setList.insert(next(setList.begin() + mid-1), move(num));
                }
            }   
            else if(mid == 0){
                if(num < setList[0]){ 
                    setList.insert(setList.begin(), num);
                }
                else{
                    setList.insert(next(setList.begin() + mid), move(num));
                }
            }
        }
        return true;
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
    vector<int> vec{1,3,5};
    set a(vec);

    a.insert(0);
    a.insert(2);
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