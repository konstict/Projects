#include <iostream>
using namespace std;

template<typename T>
class node{
    public:
    T value;
    node<T> *next;

    node(T value){
        this->value = value;
        this->next = nullptr;
    }
};

template<typename T>
class nodelist{
    private:

    int sizen;
    node<T> *first;
    public:

    nodelist(){
        first = nullptr;
        this->sizen = 0;
    }

    int size(){
        return this->sizen;
    }

    void printAll(){
        node<T>* f = first;
        for(int i = 0; i < sizen; ++i){
            cout << f->value << endl;
            // cout << f << endl;
            // cout << f->next << endl;
            f = f->next;
        }
    }

    void addLast(T value){
        sizen++;
        node<T>* a = new node<T>(value);
        if (sizen > 1){
            node<T>* f = first;
            for(int i = 0; i < sizen-2; ++i){
                f = f->next;
            }
            f->next = a;
        }
        else{
            this->first = a;
        }
    }

    void deleteLast(){
        sizen--;
        node<T>* f = first;
        for(int i = 0; i < sizen-1; ++i){
            f = f->next;
        }
        f->next = nullptr;
        if(sizen==0){
            first = nullptr;
        }
    }

    void addFirst(T value){
        sizen++;
        node<T>* a = new node<T>(value);
        a->next = first;
        first = a;
    }

    void deleteFirst(){
        sizen--;
        this->first = first->next;
    }

    void insert(int n, T value){
        sizen++;
        node<T>* a = new node<T>(value);
        node<T>* f = first;
        for(int i = 0; i < n-1; ++i){
            f = f->next;
        }
        if(n!=0){
            a->next = f->next;
            f->next = a;
        }
        else{
            a->next = first;
            first = a;
        }
    }

    void removeAt(int n){
        sizen--;
        node<T>* f = first;
        for(int i = 0; i < n-1; ++i){
            f = f->next;
        }
        if(n!=0){
            f->next = f->next->next;
        }
        else{
            this->first = first->next;
        }
    }

    int remove(T value){
        node<T>* f = first;
        for(int i = 0; i < sizen; ++i){
            if(f->value == value){
                removeAt(i);
                return 1;
            }
            f = f->next;
        }
        cout << "Ne nashel" << endl;
        return 0;
    }

    node<T>* swap(bool j, node<T>* previos, node<T>* current, node<T>* next){
        // T val = b->value;
        // b->value = c->value;
        // c->value = val;
        node<T>* nextaNext = next->next;
        next->next = current;
        current->next = nextaNext;
        if(previos->next != this->first){
            previos->next = next;
        }
        else{
            this->first = next;
        }
        return previos->next;
    }

    void sort(){
        node<T>* f;
        node<T>* g;

        for(int i = 0; i < sizen; ++i){
            f = first;
            g->next = first;
            for(int j = 0; j < sizen-1; ++j){
                if(f->value > f->next->value) {
                    f = swap(g, f, f->next);
                }
                else{
                    f = f->next;
                }
                g = g->next;
            }
        }
    }

    void deleteIf(bool (*func)(T)){
        node<T>* obj = first;
        for(int i = 0; i < sizen; ++i){
            if(func(obj->value) == true){
                obj = removeAt(i);
        if(n!=0){
            f->next = f->next->next;
        }
        else{
            this->first = first->next;
        }
                i--;
            }
            obj = obj->next;
        }
    }
};

bool myFunk(int param){
    return param > 10;
}

int main(){
    nodelist<int> a;
    a.addLast(4);
    a.addLast(3);
    a.addLast(2);
    a.addLast(1);
    a.addLast(12);
    a.addLast(15);
    a.deleteIf(myFunk);
    a.printAll();

    return 0;
}

// Задача 1:
// Реализовать связный список:
// - реализовать вставку элемента в начало - addFirst() +
// - реализовать вставку элемента в конец - addLast() +
// - реализовать вставку элемента по определенному индексу - insert() +
// - реализовать удаление элемента из начала - deleteFirst() +
// - реализовать удаление элемента из конца - deleteLast() +
// - реализовать удаление элемента по определенному индексу - removeAt() +
// - реализовать удаление элемента по равенству значения переданному - remove() +
// - реализовать печать всех элементов списка - printAll() +
// - реализовать метод size() +
// - метод sort() +
