#include <iostream>
using namespace std;

template<typename T>
class stackNode
{
    public:
    T value;
    stackNode<T>* next;
    stackNode(T param){
        this->value = param;
    }
};


template<typename T>
class stack
{
private:
    stackNode<T>* top;

public:
    stack(){
        this->top = nullptr;
    }

    bool empty(){
        return top == nullptr;
    }

    stackNode<T>* peek(){
        return this->top;
    }

    void push(T param){
        stackNode<T>* newTop = new stackNode<T>(param);
        newTop->next = top;
        this->top = newTop;
    }

    void pop(){
        this->top = top->next;
    }
};


int main(){
    stack<int> a;
    cout << a.empty() << endl;
    a.push(1);
    a.push(2);
    a.pop();
    cout << a.peek()->value;
    return 0;
}

// в общем вот, сделать Stack со следующими методами
// boolean  empty() Tests if this stack is empty. +
// E  peek() Looks at the object at the top of this stack without removing it from the stack. +
// E  pop() Removes the object at the top of this stack and returns that object as the value of this function. +
// E  push(E item) Pushes an item onto the top of this stack. +