#include <iostream>
#include <queue>
#include <stack>
using namespace std;


template<typename T>
struct node {
    T val;
    node<T> *left, *right;
    bool visited = false;
    
    node() : val(NULL), left(nullptr), right(nullptr), parent(nullptr) {}
    node(T val) : val(val) {}
    node(node<T>* left, node<T>* right) : val(NULL), left(left), right(right) {}
    node(node<T>* left, node<T>* right,  T val) : val(val), left(left), right(right) {}
};


template<typename T>
class tree{
private:
    node<T>* root;


    void allsNoVisited(){
        node<T> * tempRoot = this->root;
        queue<node<T>*> q;
        q.push(tempRoot);
        while(!q.empty()){
            if(q.front()->left){
                q.front()->visited = false;
                q.pop();
            }
            if(q.front()->right){
                q.front()->visited = false;
                q.pop();
            }
        }
    }

    
public:
    tree() : root(nullptr) {}
    tree(node<T>* root) : root(root) {}


    node<T>* getRoot(){
        return this->root;
    }
    

    void setRoot(node<T> *node){
        this->root = node;
    }


    void printBFS(){
        node<T>* tempRoot = this->root;
        queue<node<T>*> q;
        q.push(tempRoot);
        while(!q.empty()){
            cout << q.front()->val << endl;
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
    }


    void printDFS(){
        node<T>* tempRoot = this->root;
        stack<node<T>*> s;
        s.push(tempRoot);
        while(!s.empty()){
            if(s.top()->left){
                
            }
        }
    }


    void insert(T element){
        node<T>* tempRoot = this->root;
        node<T>* tempNew = new node<T>(element);
        if(!tempRoot){
            this->setRoot(tempNew);
        }
        while(tempRoot){
            if(element <= tempRoot->val){
                if(tempRoot->left){
                    tempRoot = tempRoot->left;
                }
                else{
                    tempRoot->left = tempNew;
                    break;
                }
            }
            if(element > tempRoot->val){
                if(tempRoot->right){
                    tempRoot = tempRoot->right;
                }
                else{
                    tempRoot->right = tempNew;
                    break;
                }
            }
        }
    }


    bool find(T element){
        node<T>* tempRoot = this->root;
        while(tempRoot){
            if(tempRoot->val == element){
                return true;
            }
            else if(element < tempRoot->val){
                tempRoot = tempRoot->left;
            }
            else{
                tempRoot = tempRoot->right;
            }
        }
        return false;
    }


    int countNodes(){
        int valueOfNodes = 0;
        node<T>* tempRoot = this->root;
        queue<node<T>*> q;
        q.push(tempRoot);
        while(!q.empty()){
            valueOfNodes++;
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
        return valueOfNodes;
    }
};


int main(){

    node<int> *nodes[1] = {new node<int>(1)};
    tree<int> a;

    a.insert(5);
    a.insert(0);
    a.insert(-5);
    a.insert(7);
    
    cout << a.find(5) << a.find(95) << endl;

    cout << a.countNodes() << endl;
    
    a.printDFS();

    return 0;
}

// Обходы  
// Обход в ширину   +
// Обход в глубину 

// 1. Базовые методы
// Эти методы являются основой для работы с деревьями.

// 1.1. Вставка узла (insert)      +
// Добавляет новый элемент в бинарное дерево поиска (BST).
// void insert(int value);
// 🔹 Используется в: построении BST, восстановлении дерева.

// 1.2. Поиск элемента (find)      +
// Ищет элемент в BST.
// bool find(int value);
// 🔹 Используется в: поиске элемента в BST.

// 1.3. Удаление узла (remove)
// Удаляет узел из BST.
// void remove(int value);
// 🔹 Используется в: изменении структуры дерева.

// 1.4. Подсчет количества узлов (countNodes)     +
// Возвращает общее количество узлов в дереве.
// int countNodes();
// 🔹 Используется в: задачах на количество узлов.

// 1.5. Подсчет высоты дерева (height)
// Возвращает высоту дерева.
// int height();
// 🔹 Используется в: проверке сбалансированности дерева, вычислении диаметра.