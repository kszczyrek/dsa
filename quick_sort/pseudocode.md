quickSort(arr[1,n], lo, hi)  # lo, hi - const 

if(lo < hi)

    j = lo                   # j - is iterating throught entire subarrays
    i = lo - 1               # i - is for iterator for part of the array smaller than arr[hi] and ends at arr[hi] finalplace 
    
    while(j < hi)                   # start weakSort
        if(arr[hi] > arr[j])
            i++
            swap(arr[i], arr[j])
        j++
    
    i++
    swap(arr[i], arr[hi])                    # finish weakSort

    quickSort(arr, lo, i - 1)
    quickSort(arr, i + 1, hi)

    # this isnt fully optimal quickSort because if the array is reverse sorted then it will be O(n^2)
    # we could pick pivot from the middle number from arr[lo], arr[hi], arr[(lo+hi)/2] instead
    # it should prevent from worst case more often but it still can occur

