#include <iostream>
#include "tree.h"

int main(void){

    Tree t;
    t.insert(15);
    t.insert(10);
    t.insert(20);
    t.insert(12);
    t.insert(5);
    t.insert(7);
    t.insert(-1);
    t.insert(1);
    t.insert(8);
    t.insert(6);
    t.insert(-5);
    t.insert(22);
    t.insert(19);
    t.insert(14);
    t.insert(11);

    std::cout << (t.bfs(6)? "true\n" : "false\n");
    std::cout << (t.bfs(9)? "true\n" : "false\n");

    return 0;
}