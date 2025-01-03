#include <iostream>
#include <stdlib.h>
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
    queueNode(){
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
    int time;
    string name;

    queue(int v, string name){
        this->begin = nullptr;
        this->end = nullptr;
        this->time = v;
        this->name = name;
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

    queueNode<T>* pop(){
        queueNode<T>* temp = this->begin;
        if(this->empty() == false){
            if (begin->next != nullptr){
                begin->next->previos = nullptr;
            }
        }
        this->begin = begin->next;
        return temp;
    }
};


int ids = 0;
class car{
public:
    int id;
    int time;
    car(){
        id = ids;
        time = 0;
        ++ids;
    }
};


void start(queue<car*> &origin, car& car){
    origin.push(&car);
}


void iterat(queue<car*> &origin, queue<car*> &destination){
    while(!origin.empty()){
        cout << "У автомобиля " << origin.peek()->val->id << " было завершено " << origin.name << " за " << origin.time << " секунд" << endl;
        origin.peek()->val->time += origin.time;
        destination.push(origin.pop()->val);
    }
}


int main(){
    queue<car*> kuzov(5, "Сборка кузова");
    queue<car*> engineStage(3, "Установка двигателя");
    queue<car*> koleso(2, "Установка колес"); 
    queue<car*> electronical(4, "Установка электроники"); 
    queue<car*> checker(2, "Финишная проверка");
    car a, b;
    car *cars[2] = {&a, &b};

    for(int i = 0; i < 2; ++i){
        start(kuzov, *cars[i]);
    }

    iterat(kuzov, engineStage);
    iterat(engineStage, kuzov);
    iterat(kuzov, koleso);
    iterat(koleso, electronical);
    iterat(electronical, checker);
    
    for(int i = 0; i < 2; ++i){
        cout << "На сборку автомобиля " << cars[i]->id << " было затрачено " << cars[i]->time << " секунд" << endl;
    }
    
    return 0;
}

// *Задача на очереди*
// Описание задачи
// Этапы сборки: Конвейер включает несколько этапов: сборка кузова, установка двигателя, установка колес, установка электроники и финишная проверка.
// Время на каждом этапе: Каждый этап имеет фиксированное время обработки для каждого автомобиля. Все автомобили проходят через все этапы.
// Моделирование работы конвейера: Мы будем обрабатывать автомобили по очереди. Как только автомобиль завершает один этап, он передается на следующий.

// Этапы:
// Сборка кузова: Время обработки 5 секунд.
// Установка двигателя: Время обработки 3 секунды.
// Установка колес: Время обработки 2 секунды.
// Установка электроники: Время обработки 4 секунды.
// Финишная проверка: Время обработки 2 секунды.

// - Каждый этап должно происходить в отдельной очереди.
// - После прохождения каждого этапа автомобилем необходимо писать в консоль "Автомобиль <ID автомобиля> прошел сборку кузова за <затраченное время> секунд."
// - Также необходимо в конце написать в консоль сколько времени было затрачено на сборку каждого автомобиля (сумма затрат на каждый этап сборки), 
// например "На сборку автомобиля <ID автомобиля> было затрачено 16 секунд".
// Также необходимо в конце написать сколько всего времени заняла работа, например "Время сборки всех автомобилей 122 секунд".