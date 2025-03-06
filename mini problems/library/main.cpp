#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;


struct Book{
    public:

    string nameBook;
    string nameAuthor;
    int yearCreation;

    Book() : nameBook(""), nameAuthor(""), yearCreation(0) {}
    Book(
        string InameBook,
        string InameAuthor,
        int IyearCreation
    ) : nameBook(InameBook), nameAuthor(InameAuthor), yearCreation(IyearCreation) {}


    void printBook(){
        cout << "name " << this->nameBook << " author " << this->nameAuthor << " year " << this->yearCreation;
    }
};


class Library{
    public:
    Library(){

    }


    long unsigned int getSize(){
        return this->books.size();
    }


    void addBook(Book *book){
        int number = this->books.size() + 1;
        books.insert({number, book});
    }


    void removeBook(int idBook){
        books.erase(idBook);
    }


    Book* findBook(int idBook){
        return books.find(idBook)->second;
    }


    void listBook(){
        for(int i = 1; i < books.size() + 1; ++i){
            cout << "id " << i << ' ';
            books[i]->printBook();
            cout << endl;
        }
    }


    private:
    unordered_map<int, Book*> books;
};


struct Command{
    string command;
    string argument;

    Command() : command(""), argument("") {}
    Command(string com, string arg) : command(com), argument(arg) {}


    void inputTextToCommand(string text){
        this->command = "";
        this->argument = "";
        bool arg = false;
        for(int i = 0; i < text.size(); ++i){
            if(arg == false and text[i] == ' '){
                arg = true;
            }
            else{
                if(arg == false){
                    this->command.push_back(text[i]);
                }
                else{
                    this->command.push_back(text[i]);
                }
            }
        }
    }
};


class Console{
    public:
    Console(){}

    private:
};


int main(){
    Library lib;

    lib.addBook(new Book("Ведьмак - Последнее желание", "Анджей Сапковски", 1990));
    lib.addBook(new Book("Ведьмак - Меч предназначения", "Анджей Сапковски", 1990));
    lib.addBook(new Book("Ведьмак - Кровь эльфов", "Анджей Сапковски", 1990));

    // lib.listBook();
    // cout << lib.getSize() << endl;
    // cout << lib.findBook(1)->nameBook << endl;

    Console program;

    // Command com;
    // com.inputTextToCommand("find anjey sapkovski vedmak");
    // com.inputTextToCommand("findsdssd anjey sapkovski vedmakov");
    // cout << com.command << " arg: " << com.argument << endl;


    // while(true){

    // }

    return 0;
}


// Задача: Управление библиотекой

// Что использовать:

// ООП: классы Book (книга) и Library (библиотека).
// Паттерны:
// Одиночка (Singleton) – для Library.
// Фабрика (Factory Method) – для создания Book.
// Структуры данных: хеш-таблица (unordered_map<int, Book>).
// Файл: чтение/запись книг (формат JSON или CSV).
// Функции системы:

// addBook(Book book): добавить книгу. +
// removeBook(int id): удалить книгу. +
// findBook(int id): найти книгу. +
// listBooks(): вывести все книги. +
// saveToFile() / loadFromFile(): сохранить и загрузить библиотеку.
// Задача:
// Реализовать классы, использовать паттерны, хранить книги в хеш-таблице, сохранять их в файл и загружать при старте программы.