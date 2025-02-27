#include <iostream>
#include <stdexcept>
#include "queue.h"

// Kolejka to struktura danych typu FIFO (first in first out) jest ona oparta na liscie jednokierunkowej
// powinna ona zawierac trzy funkcje:
//      queue() - ustawia element na poczatku kolejki (tail)  
//      deque() - usuwa element z konca kolejki wraz z odczytaniem jej wartosci (head)
//      peak() - odczytuje element z konca kolejki (head)


// TODO
// [] error handling for peaking at dequeueing empty queue

int main(void){

    Queue<float> q;
    // std::cout << q.dequeue() << "\n";
    // std::cout << q.peak() << "\n";
    q.queue(-60.5f);
    q.queue(100.12f);
    q.queue(150.12f);
    std::cout << "Deleting " << q.dequeue() << " from queue\n";
    std::cout << "Deleting " << q.dequeue() << " from queue\n";
    std::cout << "Deleting " << q.dequeue() << " from queue\n";

    return 0;
}