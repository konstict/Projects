#include <iostream>
using namespace std;

template<typename T>
class queueNode{
    public:
    T val;
    queueNode<T>* next;
    queueNode<T>* previos;
    queueNode(T param){
        val = param;
        next = nullptr;
        previos = nullptr;
    }
};

template<typename T>
class queue{
    private:
    queueNode<T>* begin;
    queueNode<T>* end;

    public:
    queue(){
        this->begin = nullptr;
        this->end = nullptr;
    }

    bool empty(){
        return begin==nullptr;
    }

    void push(T param){
        queueNode<T>* newEnd = new queueNode<T>(param);
        newEnd->previos = end;
        if(this->empty() == true){
            this->begin = newEnd;
        }
        else{
            end->next = newEnd;
        }
        this->end = newEnd;
    }

    queueNode<T>* peek(){
        return this->begin;
    }

    void pop(){
        if(!this->empty()){
            if (begin->next != nullptr){
                begin->next->previos = nullptr;
            }
        }
        this->begin = begin->next;
    }
};

int main(){
    queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    a.pop();
    cout << a.peek()->val;
    return 0;
}
