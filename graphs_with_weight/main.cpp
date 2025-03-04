#include <iostream>
#include "graph_ww.h"

int main(void){

    Graph g;

    for(int i = 0; i < 6; i++) {
        g.addVertex();
    }

    g.addEgde(0, 1, 1.00);
    g.addEgde(0, 2, 5.00);
    g.addEgde(1, 2, 7.00);
    g.addEgde(1, 3, 6.00);
    g.addEgde(2, 3, 1.00);
    g.addEgde(3, 2, 1.00);
    g.addEgde(2, 4, 1.00);

    g.dijkstraShortestPath(0, 3);

    return 0;
}