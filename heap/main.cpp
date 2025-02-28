#include <iostream>
#include "heap.h"


int main(void){

    maxHeap m;
    m.insert(4);    
    m.insert(5);    
    m.insert(3);    
    m.insert(2);    
    m.insert(1);    
    m.insert(50);
    m.insert(100);
    m.deleteRoot();      
    m.deleteRoot(); 
    m.deleteRoot();   
    m.deleteRoot();   
   

    return 0;
}