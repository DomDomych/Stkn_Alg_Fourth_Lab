#include <string>

class Node
{
    std::string key;
    unsigned int height;
    Node* left;
    Node* right;
    Node(std::string key);
    unsigned int height();
    int bfactor();
    void fixheight();
};