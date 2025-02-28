#include <iostream>
#include "graph.h"

int main() {
    Graph<float> g(5.40, 5);
    
    g.addGraph(69.420);
    
    g.addEgdes(0, 1);
    g.addEgdes(1, 0);
    g.addEgdes(1, 2);
    g.addEgdes(1, 3);
    g.addEgdes(1, 4);
    g.addEgdes(2, 4);
    g.addEgdes(3, 5);
    g.addEgdes(4, 2);
    g.addEgdes(4, 3);
    g.addEgdes(5, 0);
    
    g.printVals();
    g.printEgdes();
    return 0;
}