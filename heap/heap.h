#pragma once

#include <vector>
#include <iostream>

class minHeap {
    protected:
        
        std::vector<int> heap;        

        virtual void heapifyUp(const int idx);
        virtual void heapifyDown(const int idx);
        int parent(int idx) const;
        int leftChild(int idx) const;
        int rightChild(int idx) const;

    public:
        
        void insert(int e);
        void deleteRoot();
};

class maxHeap : public minHeap {
    void heapifyUp(const int idx) override;
    void heapifyDown(const int idx) override;

};