#include <iostream>
#include <ctime>
int lim = 100;

void fillRandomArr(int *start, int *end) {
    for (int *ptr = start; ptr <= end; ptr++) {
        *ptr = rand() % lim;
    }
}

void print(int *start, int* end, int row=-1) {
    for (int i = 1, *ptr = start; ptr <= end; i++, ptr++) {
       std::cout << *ptr << '\t';
       
       if (i % row == 0 && row != -1) {
           std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int max(int *start, int* end) {
    int max = *start;

    for (int* ptr = start; ptr <= end; ptr++) {
        if (max < *ptr) {
            max = *ptr;
        }
    }

    return max;
}

int equal(int* start, int* end, int val) {
    int count = 0;

    for (int* ptr = start; ptr <= end; ptr++) {
        if (*ptr == val) {
            count++;
        }
    }

    return count;
}

int main() {
    srand(time(NULL));
    
    int n = 5, m = 5;
    std::cout << "Input N M" << std::endl;
    std::cin >> n >> m;
    std::cout << "Random do" << std::endl;
    std::cin >> lim;

   int arr[n][m];
   int* begin = *arr;
   int* end = *arr + (n * m - 1);

   fillRandomArr(begin, end);
   print(begin, end, n);
   
   int maxEl = max(begin, end);
   int countMaxEl = equal(begin, end, maxEl);
   std::cout << "Max: " << maxEl << std::endl;
   std::cout << "Count: " << countMaxEl;


    return 0;
}
