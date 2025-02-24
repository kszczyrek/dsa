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

void insertionSort(std::vector<int> arr) {
    for(int i = 1; i < arr.size(); i++) {
        int tmp = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
        printArray(arr);
    }
}

// ta implementacja nie jest optymalna i prawdopodobnie jest to bardziej bubble sort niz insertion sort
void weakInsertionSort(std::vector<int> arr) {
    for(int i = 1; i < arr.size(); i++) {
        for(int j = i; j > 0; j--) {
            if(arr[j - 1] > arr[j]) std::swap(arr[j - 1], arr[j]);
        }
        printArray(arr);
    }
}

int main(void){
    const int ARR_LENGTH = 5;
    std::vector<int> arr;
    for (int i = 0; i < ARR_LENGTH; i++) {
        arr.push_back(i);
    }
    std::random_device rd;                                  
    std::mt19937 g(rd());                                   
    std::shuffle(arr.begin(), arr.end(), g);
    printArray(arr);
    weakInsertionSort(arr);
    std::cout << "\n\n";
    printArray(arr);
    insertionSort(arr);
    return 0;
    return 0;
}