#pragma once
#include <vector>
#include <list>
#include <stdexcept>
#include <iostream>

template<typename T>
class Graph{
    private:
        size_t size;
        std::vector<std::list<float>> adj; //adjency list(tablica przechowujaca listy z polaczeniami pomiedzy grafami)
        std::vector<T> vals;           //tablica przechowujaca wartosci grafow

        //konstruktory dla graph
    public:
        Graph() : size(0) {}

        Graph(const T& val) : size(1) {
            vals.push_back(val);
            adj.emplace_back(std::list<T>());
        }

        Graph(const T& val, const size_t count) : size(count) {
            for (size_t i = 0; i < count; i++) {
                vals.push_back(val);
                adj.emplace_back(std::list<T>());
            }
        }
        
        size_t getSize() const {
            return size;
        }

        void addGraph(const T& val) {
            adj.emplace_back(std::list<T>());
            vals.push_back(val);
            size++;
        }

        void addEgdes(const unsigned u, const unsigned v) {
            if(u <= adj.size() && v <= adj.size()) {    // check if connected graphs exist
                adj[u].push_back(v);
            }
            else {
                throw std::out_of_range("Graphs that you want to connect don't exist\n");
            }
        }

        void printVals() const {
            for(int i = 0; i < (int)vals.size(); i++) {
                char vertex = 65 + i;
                std::cout << "Wartosc " << vertex << ". = " << vals[i] << "\n";  
            }
        }

        void printEgdes() const {
            for(int i = 0; i < (int)adj.size(); i++) {
                char vertex = 65 + i;
                std::cout << "Wierzcholek " << vertex << " dazy do {";
                for (const auto& v : adj[i]) {
                    char vertex2 = 65 + v;
                    std::cout << vertex2 << ", ";
                }  
                std::cout << "}\n";
            }            
        }

};