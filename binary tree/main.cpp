#include <iostream>
#include <queue>
#include <stack>
using namespace std;


template<typename T>
struct node {
    T val;
    node<T> *left, *right;
    node<T>* parent;
    
    node() : val(NULL), left(nullptr), right(nullptr), parent(nullptr) {}
    node(T val) : val(val) {}
    node(node<T>* left, node<T>* right, node<T>* parent) : val(NULL), left(left), right(right), parent(parent) {}
    node(node<T>* left, node<T>* right, node<T>* parent, T val) : val(val), left(left), right(right), parent(parent) {}
};


template<typename T>
class tree{
private:
    node<T>* root;
public:
    tree() : root(nullptr) {}
    tree(node<T>* root) : root(root) {}


    node<T>* getRoot(){
        return this->root;
    }
    

    void setRoot(node<T> *node){
        this->root = node;
    }


    void traversBFSPrint(){
        node<T>* tempRoot = this->root;
        queue<node<T>*> q;
        // while(tempRoot){
            
        // }
    }


    void insert(T element){
        node<T>* tempRoot = this->root;
        node<T>* tempNew = new node<T>(element);
        if(!tempRoot){
            this->setRoot(tempNew);
        }
        else{
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
};


int main(){

    node<int> *nodes[1] = {new node<int>(1)};
    tree<int> a;

    a.insert(5);
    a.insert(0);
    a.insert(-5);
    a.insert(7);
    
    cout << a.find(5) << endl;



    return 0;
}


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

// 1.4. Подсчет количества узлов (countNodes)
// Возвращает общее количество узлов в дереве.
// int countNodes();
// 🔹 Используется в: задачах на количество узлов.

// 1.5. Подсчет высоты дерева (height)
// Возвращает высоту дерева.
// int height();
// 🔹 Используется в: проверке сбалансированности дерева, вычислении диаметра.