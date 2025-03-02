#include <iostream>
#include "graph.h"
#include <list>

int main() {
    Graph<float> g(5.40, 5);

    g.addGraph(69.420);
    
    g.addEgdes(0, 1);
    g.addEgdes(1, 0);
    g.addEgdes(1, 2);
    g.addEgdes(1, 3);
    g.addEgdes(1, 4);
    g.addEgdes(3, 5);
    g.addEgdes(4, 2);
    g.addEgdes(4, 3);
    g.addEgdes(5, 0);
    
    // g.printVals();
    // g.printEgdes();
    
    // std::cout << (g.dfs(69.420)? "Element znajduje sie w liscie!\n" : "Elementu nie ma na liscie\n");
    // std::cout << (g.dfs(5.40)? "Element znajduje sie w liscie!\n" : "Elementu nie ma na liscie\n");
    // std::cout << (g.dfs(0.00)? "Element znajduje sie w liscie!\n" : "Elementu nie ma na liscie\n");

    std::cout << (g.bfs(69.420)? "Element znajduje sie w liscie!\n" : "Elementu nie ma na liscie\n");
    std::cout << (g.bfs(0.00)? "Element znajduje sie w liscie!\n" : "Elementu nie ma na liscie\n");
    std::cout << (g.bfs(5.40)? "Element znajduje sie w liscie!\n" : "Elementu nie ma na liscie\n");
    std::cout << (g.bfs(55.40)? "Element znajduje sie w liscie!\n" : "Elementu nie ma na liscie\n");

    return 0;
}