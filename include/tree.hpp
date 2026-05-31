#include <string>

class Node
{
    std::string key;
    std::string value;
    unsigned int h;
    Node* left;
    Node* right;
    Node(std::string key);
    unsigned int height();
    int bfactor();
    void fixheight();
};