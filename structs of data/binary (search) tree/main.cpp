#include <iostream>
#include <queue>
#include <stack>
using namespace std;


template<typename T>
struct node {
    T val;
    node<T> *left, *right;
    bool visited = false;
    
    node() : left(nullptr), right(nullptr) {}
    node(T val) : val(val) {}
    node(node<T>* left, node<T>* right) : left(left), right(right) {}
    node(node<T>* left, node<T>* right,  T val) : val(val), left(left), right(right) {}
};


template<typename T>
class tree{
private:
    node<T>* root;


    void allNoVisited(){
        node<T> *tempRoot = this->root;
        queue<node<T>*> q;
        q.push(tempRoot);
        while(!q.empty()){
            q.front()->visited = false;
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
    }

    
    void insertBFS(node<T>* rootEl){
        queue<node<T>*> q;
        q.push(rootEl);
        while(!q.empty()){
            if(q.front() != rootEl) this->insert(q.front()->val);
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
    }


    bool removeNode(node<T> *removeEl, node<T> *parent){
        if(parent->left == removeEl){
            parent->left = nullptr;
        }
        else if(parent->right == removeEl){
            parent->right = nullptr;
        }
        else{
            return false;
        }
        insertBFS(removeEl);
        return true;
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
            cout << q.front()->val << ' ';
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
        cout << endl;
    }


    void printDFS(){
        node<T>* tempRoot = this->root;
        stack<node<T>*> s;
        s.push(tempRoot);
        if(s.top()) cout << s.top()->val << ' ';
        while(!s.empty()){
            s.top()->visited = true;
            if(s.top()->left and !s.top()->left->visited){
                cout << s.top()->left->val << ' ';
                s.push(s.top()->left);
            }
            else if(s.top()->right and !s.top()->right->visited){
                cout << s.top()->right->val << ' ';
                s.push(s.top()->right);
            }
            else{
                s.pop();
            }
        }
        cout << endl;
        allNoVisited();
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


    bool remove(T element){
        node<T> *tempRoot = this->root;

        queue<node<T>*> pathParents;
        node<T> *parent = tempRoot;
        pathParents.push(parent);

        while(tempRoot){
            if(tempRoot->val == element){
                return this->removeNode(tempRoot, pathParents.front());
            }
            else if(element < tempRoot->val){
                pathParents.push(tempRoot->left);
                pathParents.pop();

                tempRoot = tempRoot->left;
            }
            else{
                pathParents.push(tempRoot->right);
                pathParents.pop();

                tempRoot = tempRoot->right;
            }
        }
        return false;
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


    int countHeight(){
        int maxHeight = 0;
        node<T> *tempRoot = this->root;
        stack<node<T>*> s;
        s.push(tempRoot);
        while(!s.empty()){
            s.top()->visited = true;
            if(s.top()->left and !s.top()->left->visited){
                s.push(s.top()->left);
            }
            else if(s.top()->right and !s.top()->right->visited){
                s.push(s.top()->right);
            }
            else{
                if(maxHeight < s.size()) maxHeight = s.size();
                s.pop();
            }
        }
        this->allNoVisited();
        return maxHeight;
    }


};


int main(){

    node<int> *nodes[1] = {new node<int>(1)};
    tree<int> a;

    a.insert(5);
    a.insert(0);
    a.insert(-5);
    a.insert(7);
    a.insert(67);
    a.insert(37);
    a.insert(-7);
    a.insert(-7);
    a.insert(10);
    
    cout << a.find(5) << a.find(95) << endl;

    cout << a.countNodes() << endl;
    cout << a.countHeight() << endl;
    
    cout << a.remove(10);
    cout << endl;

    a.printDFS();
    // a.printBFS();


    return 0;
}

// Обходы  
// Обход в ширину   +
// Обход в глубину   +

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

// 1.5. Подсчет высоты дерева (height)          +
// Возвращает высоту дерева.
// int height();
// 🔹 Используется в: проверке сбалансированности дерева, вычислении диаметра.