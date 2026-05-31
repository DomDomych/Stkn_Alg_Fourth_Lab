#pragma once

#include <string>

class Node
{
    private:
    std::string key;
    std::string value;
    Node* left;
    Node* right;
    unsigned int h;

    Node(const std::string& key,const std::string& value);
    Node() = default;
    ~Node() = default;
    friend class AVLTree;
};

class AVLTree
{
    private:
    Node* root;
    unsigned int height(Node *p);
    int bfactor(Node *p);
    void fixheight(Node *p);

    Node* RotateRight(Node *p);
    Node* RotateLeft(Node *p);
    Node* balance(Node *p);
    Node* insert(Node *p,const std::string& key,const std::string& value);
    Node* find(Node *p,const std::string& key);
    void clear(Node* p);
    public:
    bool get(const std::string& key,std::string& value);
    std::string& operator[](const std::string& key);
    AVLTree();
    ~AVLTree();
};
