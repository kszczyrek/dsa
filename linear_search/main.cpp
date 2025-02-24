#include <iostream>
#include <vector>

// najprostszy algorytm szukajacy
// time complexity O(n)
// space complexity O(1)

bool linearSearch(const std::vector<int>& arr, const int n) {
    for (const int& number : arr) {
        if (number == n) return true;
    }
    return false;
}

int main(void){

    const int SEEKED_NUM = 16;
    std::vector<int> v = {};
    std::cout << SEEKED_NUM << (linearSearch(v, SEEKED_NUM)? " is" : " is not") << " in the array.\n";
    return 0;
}