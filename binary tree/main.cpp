#include <iostream>
using namespace std;


template<typename T>
struct node {
    T* val;
    node<T>* left, right;
    node<T>* parent;
    
    node() : val(NULL), left(nullptr), right(nullptr), parent(nullptr) {}
    node(node<T>* left, node<T>* right, node<T>* parent) : val(NULL), left(left), right(right), parent(parent) {}
    node(node<T>* left, node<T>* right, node<T>* parent, T val) : val(val), left(left), right(right), parent(parent) {}
};


template<typename T>
class tree{
private:
    node<T>* root;
public:
    tree(){}
    tree(node<T> root) : root(root) {}


    node<T>* getRoot(){
        return this->root;
    }
    

};


int main(){

    tree<int> a();


    return 0;
}


// 1. Базовые методы
// Эти методы являются основой для работы с деревьями.

// 1.1. Вставка узла (insert)
// Добавляет новый элемент в бинарное дерево поиска (BST).
// void insert(int value);
// 🔹 Используется в: построении BST, восстановлении дерева.

// 1.2. Поиск элемента (find)
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