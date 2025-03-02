#pragma once
#include <vector>
#include <list>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "queue.h"

template<typename T>
class Graph{
    private:
        size_t size;
        std::vector<std::list<unsigned>> adj; //adjency list(tablica przechowujaca listy z polaczeniami pomiedzy grafami)
        std::vector<T> vals;           //tablica przechowujaca wartosci grafow

        bool r_dfs(const T& e, const unsigned curr, std::vector<bool>& seen, std::vector<unsigned>& path) {
            path.push_back(curr); 

            if (vals[curr] == e) { 
                printPath(e, path); 
                return true;
            }

            seen[curr] = true;

            for (const auto& neighbour : adj[curr]) {
                if (seen[neighbour]) continue;  // Jeśli sąsiad nie był jeszcze odwiedzony
                if (r_dfs(e, neighbour, seen, path)) return true;   
            }

            path.pop_back();
            return false;
        }

        void printPath(const T& e, std::vector<unsigned>& path) {
            std::cout << "Sciezka do elementu " << e << " jest nastepujaca: \n";
            size_t lastIdx = path.size() - 1;
            for (int i = 0; i < (int)lastIdx; i++) {
                char vertex = 65 + path[i];
                std::cout << vertex << " -> ";
            }
            std::cout << (char)(65 + path[lastIdx]) << "\n"; 
        }

    public:
        //konstruktory dla graph
        Graph() : size(0) {}

        Graph(const T& val) : size(1) {
            vals.push_back(val);
            adj.emplace_back(std::list<T>());
        }

        Graph(const T& val, const size_t count) : size(count) {
            for (size_t i = 0; i < count; i++) {
                vals.push_back(val);
                adj.emplace_back(std::list<unsigned>());
            }
        }
        
        size_t getSize() const {
            return size;
        }

        void addGraph(const T& val) {
            adj.emplace_back(std::list<unsigned>());
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
        
        bool dfs(const T& e) {
            
            std::vector<bool> seen(adj.size(), false);
            std::vector<unsigned> path = {};
            path.reserve(adj.size());

            return r_dfs(e, 0, seen, path);
        }

        bool bfs(const T& e) {
            
            bool found = false;
            std::vector<bool> seen(adj.size(), false);
            std::vector<int> prev(adj.size(), -1);
            std::vector<unsigned> path;
            unsigned curr = 0;
            Queue<unsigned> q;

            q.queue(0);
            seen[0] = true;

            while(q.length) {
                
                curr = q.dequeue();

                if(vals[curr] == e) {
                    found = true;
                    path.push_back(curr);
                    break;
                }
                
                for(const auto& graphs : adj[curr]) {
                    
                    if(!seen[graphs]) {
                     
                        seen[graphs] = true;
                        prev[graphs] = curr;
                        q.queue(graphs);
                    }
                }

            } 



            while(prev[curr] != -1) {
                path.push_back(prev[curr]);      
                curr = prev[curr];
            }
            if(found) {
                std::reverse(path.begin(), path.end());
                printPath(e, path);
                return true;
            }    

            return false;
        }
};