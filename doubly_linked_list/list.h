#pragma once


class List {
    private:
        struct Node{
            Node* next = nullptr;
            Node* prev = nullptr;
            int elem;
        };
        Node* first = nullptr;
        Node* last = nullptr;
        int length = 0;
    public:
        bool is_empty() const;
        int getLength() const;
        void push(int e);
        void push_back(int e);
        int pop();
        int pop_back();
        void print();
        void clear();
        void insert_at(int e, int i);
        void delete_at(int i);
        void delete_by_value(int e);
};
