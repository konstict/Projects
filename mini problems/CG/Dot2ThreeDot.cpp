#include <iostream>
#include <vector>
using namespace std;


string preobrazovanie(string str){
    string newStr = "";
    for(int i = 0; i < str.size(); ++i){
        newStr.push_back(str[i]);
        if (str[i] == '.'){
            newStr.push_back(str[i]);
            newStr.push_back(str[i]);
        }
    }
    return newStr;
}


int main() {
    string str = "";
    cout << "BB stroky" << endl;
    getline(cin, str);
    cout << "Do: " << str << endl;
    string newStr = preobrazovanie(str);
    cout << "Posle: " << newStr << endl;
}
