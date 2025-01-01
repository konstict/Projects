#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class list{
private:
    int sizen = 0;
    T* array;

public:
    list(){
        
    }

    list(int sizen){
        this->sizen = sizen;
        T *array1 = new T[sizen];
        this->array = array1;
    }

    ~list(){
        delete[] array;
    }

    T& operator[] (int num){
        if (num > this->sizen or num < 0)
            cout << "Out of range, norm delay" << endl;
        return this->array[num];
    }

    int size(){
        return this->sizen;
    }

    void printAll(){
        if (sizen != 0){
            for (int i = 0; i < this->sizen; ++i){
                cout << this->array[i] << endl;
            }
        }
        else{
            cout << "Empty list" << endl;
        }
    }
    
    void printAllOneLine(){
        if (sizen != 0){
            for (int i = 0; i < 9; ++i){
                cout << this->array[i] << " ";
            }
            cout << endl;
        }
        else{
            cout << "Empty list" << endl;
        }
    }

    void addLast(T p){
        sizen++;
        T *array1 = new T[sizen];
        for(int i = 0; i < this->sizen-1; ++i){
            array1[i] = this->array[i];
        }
        this->array = array1;
        this->array[sizen-1] = p;
    }
    
    void addFirst(T p){
        sizen++;
        T *array1 = new T[sizen];
        for (int i = 0; i < this->sizen-1; ++i){
            array1[i+1] = this->array[i];
        }
        this->array = array1;
        this->array[0] = p;
    }

    void deleteLast(){
        sizen--;
        T* array1 = new T[sizen];
        for(int i = 0; i < this->sizen; ++i){
            array1[i] = this->array[i];
        }
        this->array = array1;
    }

    void deleteFirst(){
        sizen--;
        T* array1 = new T[sizen];
        for(int i = 0; i < this->sizen; ++i){
            array1[i] = this->array[i+1];
        }
        this->array = array1;
    }
    
    void insert(int n, T p){
        sizen++;
        T* array1 = new T[sizen];
        for(int i = 0; i < n; ++i){
            array1[i] = this->array[i];
        }
        array1[n] = p;
        for(int i = n; i < this->sizen; ++i){
            array1[i+1] = this->array[i];
        }
        this->array = array1;
        this->array[n] = p;
    }

    void remove(int n){
        sizen--;
        T* array1 = new T[sizen];
        for(int i = 0; i < n; ++i){
            array1[i] = this->array[i];
        }
        for(int i = n; i < this->sizen; ++i){
            array1[i] = this->array[i+1];
        }
        this->array = array1;
    }
};

int main(){
    list<int> a(0);

    a.addFirst(1);
    a.printAllOneLine();
    a.addLast(2);
    a.printAllOneLine();
    a.addLast(3);
    a.printAllOneLine();
    a.insert(1,5);
    a.insert(1,6);
    a.deleteLast();
    a.deleteFirst();
    a.printAllOneLine();
    
    return 0;
}