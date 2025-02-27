#include <iostream>
#include "tree.h"

int main(void){

    Tree t;
    t.insert(10);
    t.insert(15);
    t.insert(20);
    t.insert(12);
    t.insert(5);
    t.insert(7);
    t.insert(-1);
    t.insert(1);
    t.insert(8);
    t.insert(6);
    t.insert(3);
    t.insert(22);
    t.insert(19);

    // t.preRecurseTraversal();
    // std::cout << "\n\n";
    // t.recurseTraversal();
    // std::cout << "\n\n";
    // t.postRecurseTraversal();
     std::cout << (t.dfs(100)? "true\n" : "false\n");
    return 0;
}