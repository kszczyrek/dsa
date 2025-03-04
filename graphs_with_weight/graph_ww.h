#pragma once
#include <limits>
#include <vector>
#include <list>

const float infinity = std::numeric_limits<float>::max();

class Graph {
    private:
        
        struct egde {
            unsigned to;
            float w;

            egde(const unsigned to, const float w) 
            : to(to), w(w) {}
        };

        std::vector<std::list<egde>> adj;

        bool hasUnvisited(const std::vector<bool>& seen, const std::vector<float>& dists) {
            bool isThereReachableUnvisitedVertex = false;
            for(int i = 0; i < adj.size(); i++) {
                   if(!seen[i] && dists[i] < infinity) {
                        isThereReachableUnvisitedVertex = true;
                        break;
                   } 
            }
            return isThereReachableUnvisitedVertex;
        }

        unsigned getLowestUnvisited(const std::vector<bool>& seen, const std::vector<float>& dists) {
            int idx = -1;
            float lowestDist = infinity;
            for (int i = 0; i < adj.size(); i++) {
                if(seen[i])     
                    continue;

                if(lowestDist > dists[i]) {
                    lowestDist = dists[i];
                    idx = i;
                }
            }
            return idx;
        }

        void printPath(const std::list<unsigned>& path) {
            for(auto it = path.begin(); it != std::prev(path.end()); it++) {
                char vertex = *it;
                std::cout << (char)(65 + vertex) << " -> ";
            }
            std::cout << (char)(path.back() + 65) << "\n"; 
        }

    public:

        void addVertex(){
            adj.push_back(std::list<egde>());
        }

        void addEgde(const unsigned from, const unsigned to, const float weight) {
            if(from < adj.size() && to < adj.size()) {
                egde e(to, weight);
                adj[from].push_back(e);
            }
        }

        void dijkstraShortestPath(const unsigned source, const unsigned destination) {
            const unsigned graphSize = adj.size();
            
            if(source >= graphSize || destination >= graphSize) {
                return;
                throw "Invalid source or destination\n";
            }
            
            std::vector<bool> seen(graphSize, false);
            std::vector<float> dists(graphSize, infinity);
            std::vector<int> prev(graphSize, -1);

            dists[source] = {0.00};

            while(hasUnvisited(seen, dists)) {
                const unsigned curr = getLowestUnvisited(seen, dists);
                seen[curr] = true;

                for(egde neighbour : adj[curr]) {
                    if(seen[neighbour.to]) continue;
                
                    const float dist = dists[curr] + neighbour.w;
                    if(dist < dists[neighbour.to]) {
                        prev[neighbour.to] = curr;
                        dists[neighbour.to] = dist;
                    }
                }
            }

            unsigned curr = destination;
            if(dists[destination] != infinity) {
                std::list<unsigned> path;
                path.push_front(destination);

                while(prev[curr] != -1) {
                    path.push_front(prev[curr]);
                    curr = prev[curr];
                }
                printPath(path);
            } 
            else {
                std::cout << "There is no path to this vertex!\n";
            }
        }
};