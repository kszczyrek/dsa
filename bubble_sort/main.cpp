#include <iostream>
#include <vector>
#include <ctime>
#include <memory>

void bubbleSort(std::vector<int>& arr) {
    int temp;
    bool isArraySorted;
    for (int i = arr.size() - 1; i > 0; i--) { 
        isArraySorted = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isArraySorted = false;
            }
        }
        if (isArraySorted) break; //Optimalization - if no operations were made inside a nested loop is mean array is sorted so we exit the program
    }
}

// worst case (n(n+1))/2 operation, so 
// time complexity O(n^2)
// space complexity O(1)

int main(void){
    const int ARR_SIZE = 20;
    const int NUM_RANGE = 100;
    srand(time(nullptr));
    std::unique_ptr<std::vector<int>> arr_ptr = std::make_unique<std::vector<int>>();
    for (int i = 0; i < ARR_SIZE; i++) {
        arr_ptr->emplace_back(rand()%NUM_RANGE + 1);
    }
    for(const auto& v : *arr_ptr) {std::cout << v << " ";} std::cout<<std::endl;
    bubbleSort(*arr_ptr);
    for(const auto& v : *arr_ptr) {std::cout << v << " ";} std::cout<<std::endl;    
    return 0;
}