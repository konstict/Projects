#include <iostream>
#include <queue>
using namespace std;


bool primeNumber(int number){
    for(int i = 1+1; i < number; ++i){
        if(number % i == 0) return false;
    }
    return true;
}


int problem1(){
    int n = 0;
    cout << "Input natural n" << endl;
    cin >> n;
    if(n < 1) return 1;
    
    for (int i = 1; i <= n; ++i){
        if (primeNumber(i)) cout << i << endl;
    }
    
    return 0;
}


int problem2(){
    int n = 0;
    cout << "Input natural n" << endl;
    cin >> n;
    if(n < 1) return 1;
    
    int count = 0;
    int sumDigit = 0;
    while(n != 0){
        count++;
        sumDigit += n - (n/10)*10;
        n /= 10;
    }
    
    cout << count << ' ' << sumDigit << endl;
    return 0;
}


int problem3(){
    int numMonth = 0;
    cout << "Number of month" << endl;
    cin >> numMonth;
    if(numMonth < 1) return 1;
    
    int seasons[4][3] = {{1,2,12}, {3,4,5}, {6,7,8}, {9,10,11}};
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 3; ++j){
            if(seasons[i][j] == numMonth) cout << numMonth << ' ' << i+1 << endl;
        }
    }
    return 0;
}


int problem4(){
    int n = 0;
    cout << "Input natural n" << endl;
    cin >> n;
    if(n < 1) return 1;
    
    queue<int> *st = new queue<int>;
    int currentDigit = 0;
    while(n != 0){
        currentDigit = n % 10;
        st->push(currentDigit);
        n /= 10;
    }
    
    while(!st->empty()){
        cout << st->front();
        st->pop();
    }
    cout << endl;
    return 0;
}


int problem5(){
    string text = "";
    cout << "Input text in English :)" << endl;
    getline(cin, text);
    
    int countSmall = 0, countBig = 0;
    for(int i = 0; i < text.size(); ++i){
        int numStr = (int)text[i]; // Номера букв в текущей кодировке, можно проделать и
        //для кириллицы условия, но я сделал только для английских
        if(numStr >= 65 and numStr <= 90) countBig++;
        else if(numStr >= 97 and numStr <= 122) countSmall++;
    }
    
    cout << "Small: " << countSmall << " Big: " << countBig << endl;
    return 0;
}


int main() {
    // Методы нужно коментить, чтобы выбирать какие запускать задачки
    // problem1();
    // problem2();
    // problem3();
    // problem4();
    problem5();
    return 0;
}
