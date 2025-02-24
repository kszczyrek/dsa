#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void printArray(const std::vector<int>& arr) {
    for(const int& v : arr) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

// selection sort: 
// time complexity O(n^2)
// space complexity O(1)

// znajdujemy najwiekszy element w nieposortowanej czesci tablicy i zamienia go z koncem nieposortowanej czesci tablicy
void selectionSort1(std::vector<int>& arr) { 
    const int length = arr.size();

    // szukamy najwiekszego elementu w nieposortowanej czesci tablicy
    for(int i = 0 ; i <  length - 1; i++) {
        int maxIdx = 0;
        for(int j = 1; j < length - i; j++) 
            if(arr[j] > arr[maxIdx]) maxIdx = j;

        // zamieniamy go z ostatnim nieposortowanym elementem
        std::swap(arr[maxIdx], arr[length - 1 - i]);
    }
}
// alternatywna wersja szuka najmniejszego elementu i zamienia go z pierwszym elementem
void selectionSort2(std::vector<int>& arr) { 
    const int length = arr.size();

    // szukamy najmnmiejszego elementu w nieposortowanej czesci tablicy
    for(int i = 0 ; i < length - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < length; j++) 
            if(arr[minIdx] > arr[j]) minIdx = j;

        // zamieniamy go z pierwszym nieposortowanym elementem 
        std::swap(arr[minIdx], arr[i]);
    }
}

int main(void){

    const int ARR_LENGTH = 50;
    std::vector<int> arr;
    for (int i = 0; i < ARR_LENGTH; i++) {
        arr.push_back(i);
    }
    std::random_device rd;                                  
    std::mt19937 g(rd());                                   
    std::shuffle(arr.begin(), arr.end(), g);
    printArray(arr);
    selectionSort1(arr);
    printArray(arr);
    return 0;
}