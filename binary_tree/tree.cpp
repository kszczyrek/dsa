#include <iostream>
#include "tree.h"

void Tree::insert(int e) {
    if(!root) {
        Node* node = new Node(e);
        root = node;
        return;
    }
    r_insert(e, root);
}

void Tree::r_insert(int e, Node* curr) {
    if(e < curr->elem && !curr->left) {
        Node* node = new Node(e);
        curr->left = node;        
    } else if(e >= curr->elem && !curr->right) {
        Node* node = new Node(e);
        curr->right = node;                
    } else if(e < curr->elem) {
        return r_insert(e, curr->left);
    } else {
        return r_insert(e, curr->right);
    }
}

void Tree::preRecurseTraversal() {
    if(!root) return;
    else r_preRecurseTraversal(root);
}

void Tree::recurseTraversal() {
    if(!root) return;
    else r_recurseTraversal(root);
} 

void Tree::postRecurseTraversal() {
    if(!root) return;
    else r_postRecurseTraversal(root);
}

void Tree::r_preRecurseTraversal(Node* curr) const {
    if(curr) {
        std::cout << curr->elem << "\n";
        r_preRecurseTraversal(curr->left);
        r_preRecurseTraversal(curr->right);
    }
}

void Tree::r_recurseTraversal(Node* curr) const {
    if(curr) {
        r_recurseTraversal(curr->left);
        std::cout << curr->elem << "\n";
        r_recurseTraversal(curr->right);
    }
}

void Tree::r_postRecurseTraversal(Node* curr) const {
    if(curr) {
        r_postRecurseTraversal(curr->left);
        r_postRecurseTraversal(curr->right);
        std::cout << curr->elem << "\n";
    }

}

bool Tree::dfs(int e) {
    return r_dfs(e, root);
}


bool Tree::r_dfs(int& e, Node* curr) {
    if(!curr) {
        return false;
    } else if(curr->elem == e) { 
        std::cout << curr->elem << "\n";
        return true;
    } else if(curr->elem > e) {
        std::cout << curr->elem << "\n";
        return r_dfs(e, curr->left);
    } else {
        std::cout << curr->elem << "\n";
        return r_dfs(e, curr->right); 
    }        
}
