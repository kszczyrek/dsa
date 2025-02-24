#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>

// quickSort2() to bardziej zwiezla wersja i miesci sie w jednej funkcji 
// quickSort() to moja pierwsza udana implementacje - zostawie ja sobie na pamiatke 

// time complexity - worst case O(n^2), average case O(nlog n), best case O(n log n)
// space complexity O(1)

void quickSort2(std::vector<int>& arr, const int startIdx, const int pivot) {
    if(startIdx < pivot) {
        int j = startIdx;

        int i = j - 1;                          // jesli tablica nie jest jednoelementowa to soft sortujemy ja wzgledem a[p] 
        while (j != pivot) {                    // tzn kladziemy a[p] we wlasciwym miejscu i wszystko  // przed a[p] jest mniejsze od a[p] a wszystko po a[p] wieksze od a[p]
            if (arr[pivot] > arr[j]) {          // przed a[p] jest mniejsze od a[p] a wszystko po a[p] wieksze od a[p]          
                i++;                            
                std::swap(arr[i], arr[j]);      // ogolnie te petle mozna napisac forem ale sie uparlem na pierwsza wersje
            }                               
        j++;                                
        }               
        i++;              
        std::swap(arr[i], arr[pivot]);

        quickSort2(arr, startIdx, i - 1);
        quickSort2(arr, i + 1, pivot);
    }
}

int partition(std::vector<int>& arr, int j, int p) {
        int i = j - 1;                      // jesli tablica nie jest jednoelementowa to soft sortujemy ja wzgledem a[p] 
        while (j != p) {                    // tzn kladziemy a[p] we wlasciwym miejscu i wszystko  // przed a[p] jest mniejsze od a[p] a wszystko po a[p] wieksze od a[p]
            if (arr[p] > arr[j]) {          // przed a[p] jest mniejsze od a[p] a wszystko po a[p] wieksze od a[p]          
                i++;                        
                std::swap(arr[i], arr[j]);
            }                               
        j++;                                
        }               
        i++;              
        std::swap(arr[i], arr[p]);
        return i;
}

void qs(std::vector<int>& arr, int j, int p) {
    if(j < p) {
        const int pivotIdx = partition(arr, j, p);
        qs(arr, j, pivotIdx - 1);
        qs(arr, pivotIdx + 1, p);
    }
}

void quickSort(std::vector<int>& arr) {
    qs(arr, 0, arr.size() - 1);
}


int main(void){

    const int ARR_SIZE = 6;
    std::unique_ptr<std::vector<int>> arr_ptr = std::make_unique<std::vector<int>>();
    for (int i = 0; i < ARR_SIZE; i++) {
        arr_ptr->push_back(i);
    }

    std::random_device rd;                                  // przetasowujemy tablice
    std::mt19937 g(rd());                                   
    std::shuffle(arr_ptr->begin(), arr_ptr->end(), g);
    for (const auto& v : *arr_ptr) {
        std::cout << v << " ";
    }
    std::cout << "\n";
    quickSort2(*arr_ptr, 0, arr_ptr->size() - 1);
    for (const auto& v : *arr_ptr) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    return 0;
}