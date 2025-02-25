#include <iostream>
#include <stdexcept>
#include "list.h"

bool List::is_empty() const {
    if(!first) return true;
    else return false;
}
int List::getLength() const {
    return this->length;
}
void List::push(int e) {
    Node* node = new Node(); 
    node->elem = e;
    
    if(is_empty()) { 
        first = last = node;
    }
    else {
        first->prev = node;
        node->next = first;
        first = node;
    }
    length++;
}
void List::push_back(int e) {
    Node* node = new Node(); 
    node->elem = e;
    
    if(is_empty()) { 
        first = last = node;
    }
    else {
        last->next = node;
        node->prev = last;
        last = node;
    }
    length++;
};
int List::pop() {
    if(is_empty()) throw std::out_of_range("list is already empty!");
    
    const int tmp = first->elem;   
    Node* node = first;
    if(length == 1) {
        last = nullptr; 
    }
    else {
        first->next->prev = nullptr;
        first = first->next;
    }
    delete node;
    length--;
    return tmp;
}
int List::pop_back() {
    if(is_empty()) throw std::out_of_range("list is already empty!");
    
    const int tmp = last->elem;   
    Node* node = last;
    if(length == 1) {
        first = nullptr; 
    }
    else {
        last->prev->next = nullptr;
        last = last->prev;
    }
    delete node;
    length--;
    return tmp;
}
void List::print() {
    if (is_empty()) {
        std::cout << "list is empty!\n";
        return;
    }
    Node* node = first;
    while(node != last) {
        std::cout << "(" << node->elem << ") <-> ";
        node = node->next;                
    }
    std::cout << "(" << node->elem << ")\n";                
}
void List::clear() {
    if(!is_empty()) {
        Node* node = first;
        while(node != last) {
            Node* tmp = node;
            node = node->next;
            delete tmp;
        }
        delete node;
        first = last = nullptr;
    }
}
void List::insert_at(int e, int i) {
    if(i > length || i < 1) throw std::out_of_range("invalid index");
    else if(i == 1) push(e);
    else if(i == length + 1) push_back(e);
    else {
        Node* tmp = first;
        for(int j = 2; j < i; j++) { // loops i - 2 times to get node before inserted idx
            tmp = tmp->next;            
        }
        Node* node = new Node();
        node->elem = e;
        node->next = tmp -> next;
        tmp->next = node;
        node->prev = node->next->prev;
        node->next->prev = node;
        length++;
    }
}
void List::delete_at(int i) {
    if(i > length || i < 1) throw std::out_of_range("invalid index");
    else if(i == 1) pop();
    else if(i == length) pop_back();
    else {
        Node* tmp = first;
        for(int j = 1; j < i; j++) { // loops i - 1 times to get to the i'th element
            tmp = tmp->next;            
        }
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
        length--;
    }
}
void List::delete_by_value(int e) {
    Node* curr = first;
    while(curr) {
        Node* tmp = curr;
        curr = curr->next;
        if(tmp->elem == e) {
            length--;
            if(tmp == first) pop();
            else if(tmp == last) pop_back();
            else {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;                                
            }
        }
    }
}
// int get_at()
// reverse()