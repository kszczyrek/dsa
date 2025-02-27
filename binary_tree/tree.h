#pragma once

class Tree {
    private:
        struct Node {
            int elem;
            Node* right;
            Node* left;
            Node()
            : right(nullptr), left(nullptr) {}
            Node(const int& elem) 
            : elem(elem), right(nullptr), left(nullptr) {}
        };
        Node* root = nullptr;
        void r_preRecurseTraversal(Node* curr) const;
        void r_recurseTraversal(Node* curr) const;
        void r_postRecurseTraversal(Node* curr) const;
        bool r_dfs(int& e, Node* curr);
    public:
    //void clear();
    void insert(int e);
    void r_insert(int e, Node* curr);
    void preRecurseTraversal(); 
    void recurseTraversal(); 
    void postRecurseTraversal(); 
    bool dfs(int e); 
    //bool bfs(int e);
    //void delete(int e);
    //int getHeight();
    //void compare(Tree b);
};