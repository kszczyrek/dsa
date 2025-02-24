#include <iostream>
#include <stdexcept>

// Kolejka to struktura danych typu FIFO (first in first out) jest ona oparta na liscie jednokierunkowej
// powinna ona zawierac trzy funkcje:
//      queue() - ustawia element na poczatku kolejki (tail)  
//      deque() - usuwa element z konca kolejki wraz z odczytaniem jej wartosci (head)
//      peak() - odczytuje element z konca kolejki (head)


// TODO
// [] error handling for peaking at dequeueing empty queue

struct Node {
    int elem;
    Node* next = nullptr;
};

class Queue {
    private:
        Node* tail = nullptr;
        Node* head = nullptr;
        int length = 0;
    public:
        void queue(const int& val) {
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
        int dequeue() {
            if(head) {
                Node* tmp = head;
                head = head->next;
                if (length == 1) tail = head; // tail = nullptr
                length--;
                const int tmpVal = tmp->elem;
                delete tmp;
                return tmpVal;
            }
            else {
                throw std::out_of_range("Queue is empty!");
            }
        }
        int peak() const {
            return (head ? head->elem : throw std::out_of_range("Queue is empty!")); 
        }
        int getLength() const {
            return length;
        }
};



int main(void){

    Queue q;
    // std::cout << q.dequeue() << "\n";
    // std::cout << q.peak() << "\n";
    q.queue(50);
    q.queue(100);
    q.queue(150);
    std::cout << "Deleting " << q.dequeue() << " from queue\n";
    std::cout << "Deleting " << q.dequeue() << " from queue\n";
    std::cout << "Deleting " << q.dequeue() << " from queue\n";

    return 0;
}