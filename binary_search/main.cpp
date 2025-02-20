#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

// Here is my binary search implementation both recursive and iterative
// - this algorithm searches for a number in a sorted array and return 
// it's index or -1 if he didnt find it in array
// time complexity O(log n)
// space complexity O(1)

int binarySearch(const std::vector<int>& arr, const int& n) {
    int rightPivot = arr.size()-1;
    int leftPivot = 0;
    while(leftPivot <= rightPivot) {
        int mid = (leftPivot + rightPivot)/2;
        if(arr[mid] > n) {         // continue searching in left subaaray
            rightPivot = mid - 1;
        }
        else if(arr[mid] < n) {    // continue searching in right subaaray
            leftPivot = mid + 1;
        }
        else {
            return mid;            // number found
        }

    }
    return -1;                     // number not found
}

int r_binarySearch(const std::vector<int>&arr, const int& n, int l, int r) {
    int mid = (l+r)/2;
    if(l <= r) { 
        if(arr[mid] < n) { return r_binarySearch(arr, n, mid + 1, r); }
        else if(arr[mid] > n) { return r_binarySearch(arr, n, l, mid - 1); }
        else { return mid; } // znaleziono n
    }
    else { return -1; } // nie znaleziono n
}

int main(void) {

    const int ARR_SIZE = 8;
    const int NUM_RANGE = 20;
    std::vector<int> v;
    v.reserve(ARR_SIZE);

    srand(time(nullptr));
    for (int i = 0; i < ARR_SIZE; i++) {
        v.emplace_back(rand()%NUM_RANGE);
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << v[i] << "\n";
    }

    for (int i = 0; i < NUM_RANGE - 1; i++) {
    std::cout << i << " .znajduje sie na indeksie: " << r_binarySearch(v, i, 0, v.size()-1) << std::endl;
    }

    return 0;
}

