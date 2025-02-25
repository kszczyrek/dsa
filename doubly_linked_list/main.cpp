#include <iostream>
#include "list.h"

int main(void){

    List l;
    l.push(10);
    l.push(12);
    l.push_back(5);
    l.push_back(-420);
    l.print();
    l.insert_at(-69,4);
    l.insert_at(-69,2);
    l.print();
    l.delete_at(4);
    l.delete_at(3);
    l.print();
    l.delete_by_value(-69);
    l.print();
    return 0;
}