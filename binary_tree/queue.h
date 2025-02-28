#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class Queue {
    private:
        struct Node {
            T elem;
            Node* next = nullptr;
        };
        Node* tail = nullptr;
        Node* head = nullptr;
        int length = 0;
    public:
        void queue(const T& val);
        T dequeue();
        T peak() const;
        int getLength() const;
};

template<typename T>
void Queue<T>::queue(const T& val) {
    Node* node = new Node();
    node->elem = val;
    if(tail) {
        tail->next = node;
        tail = node;
    }
    else {
        tail = head = node;
    }
    length++;
}
template<typename T>
T Queue<T>::dequeue() {
    if(head) {
        Node* tmp = head;
        head = head->next;
        if (length == 1) tail = head; // tail = nullptr
        length--;
        const T tmpVal = tmp->elem;
        delete tmp;
        return tmpVal;
    }
    else {
        throw std::out_of_range("Queue is empty!");
    }
}
template<typename T>
T Queue<T>::peak() const {
    return (head ? head->elem : throw std::out_of_range("Queue is empty!")); 
}
template<typename T>
int Queue<T>::getLength() const {
    return length;
}