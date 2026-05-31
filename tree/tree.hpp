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
    int count;
    Node(const std::string& key,const std::string& value);
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
    //bool kmp(const std::string& value,const std::string& word);
    Node* RotateRight(Node *p);
    Node* RotateLeft(Node *p);
    Node* balance(Node *p);
    Node* insert(Node *p,const std::string& key,const std::string& value);
    Node* find(Node *p,const std::string& key);
    Node* MostPopular(Node *p,Node *best)const;
    void clear(Node *p);
    void print(Node *p,int& number)const;
    public:
    bool get(const std::string& key,std::string& value);
    bool getMostPopular(std::string& key,std::string& value,int& count);
    std::string& operator[](const std::string& key);
    void print()const;
    void increment(const std::string& key);
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;
    AVLTree();
    ~AVLTree();
};
