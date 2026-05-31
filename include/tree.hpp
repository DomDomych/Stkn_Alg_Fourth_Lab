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
    Node* insert(Node *p,std::string key,std::string value);
    
    public:
    AVLTree();
};
