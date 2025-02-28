#include "heap.h"

int minHeap::parent(int idx) const {
    return (idx-1)/2;
}

int minHeap::leftChild(int idx) const {
    return 2 * idx + 1;
}

int minHeap::rightChild(int idx) const {
    return 2 * idx + 2;
}

void minHeap::heapifyUp(const int idx) {
    const int parentIdx = parent(idx);
    if(idx == 0) {
        return;
    }
    if(heap[idx] >= heap[parentIdx]) {
        return;
    }
    else {
        const int tmp = heap[idx];
        heap[idx] = heap[parentIdx];
        heap[parentIdx] = tmp;
        heapifyUp(parentIdx); 
    }
}

void minHeap::insert(int e) {
    heap.push_back(e);
    heapifyUp(heap.size()-1);
}

void minHeap::heapifyDown(const int idx) {
    const int lIdx = leftChild(idx);
    const int rIdx = rightChild(idx);
    if(idx >= (int)heap.size() || lIdx >= (int)heap.size()) {
        return;
    }
    if((rIdx >= (int)heap.size() || heap[lIdx] <= heap[rIdx]) && heap[idx] > heap[lIdx]) {
        const int tmp = heap[lIdx];
        heap[lIdx] = heap[idx];
        heap[idx] = tmp;
        heapifyDown(lIdx);
    } 
    else if(rIdx < (int)heap.size() && heap[idx] > heap[rIdx]) {
        const int tmp = heap[rIdx];
        heap[rIdx] = heap[idx];
        heap[idx] = tmp;
        heapifyDown(rIdx);
    }
    else {
        return;
    }
}

void minHeap::deleteRoot() {
    const int size = heap.size();
    if(heap.empty()) {
        std::cout << "Error - heap is already empty!\n";
    } 
    else if(size == 1) {
        heap.pop_back();
    }
    else {
        const int tmp = heap[0];
        heap[0] = heap[size - 1];
        heap[size - 1] = tmp;

        heap.pop_back();
        heapifyDown(0);
    }
}

void maxHeap::heapifyUp(int idx) {
    const int parentIdx = parent(idx);
    if(idx == 0) {
        return;
    }
    if(heap[idx] <= heap[parentIdx]) {
        return;
    }
    else {
        const int tmp = heap[idx];
        heap[idx] = heap[parentIdx];
        heap[parentIdx] = tmp;
        heapifyUp(parentIdx); 
    }
}

void maxHeap::heapifyDown(int idx) {
    const int lIdx = leftChild(idx);
    const int rIdx = rightChild(idx);
    if(idx >= (int)heap.size() || lIdx >= (int)heap.size()) {
        return;
    }
    if((rIdx >= (int)heap.size() || heap[lIdx] >= heap[rIdx]) && heap[idx] < heap[lIdx]) {
        const int tmp = heap[lIdx];
        heap[lIdx] = heap[idx];
        heap[idx] = tmp;
        heapifyDown(lIdx);
    } 
    else if(rIdx < (int)heap.size() && heap[idx] < heap[rIdx]) {
        const int tmp = heap[rIdx];
        heap[rIdx] = heap[idx];
        heap[idx] = tmp;
        heapifyDown(rIdx);
    }
    else {
        return;
    }
}

// int smallerIdx = lIdx;
// if (rIdx < (int)heap.size() && heap[rIdx] < heap[lIdx]) {
//     smallerIdx = rIdx;
// }

// if (heap[idx] > heap[smallerIdx]) {
//     std::swap(heap[idx], heap[smallerIdx]);
//     heapifyDown(smallerIdx);
//}

// Ladniejsza wersja warunku ktora wybiera mniejsze/wieksze dziecko od razu przez co drugi warunek jest ladniejszy - uproszczona logika