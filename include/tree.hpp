#include <string>

class Node
{
    private:
    std::string key;
    std::string value;
    unsigned int h;
    Node* left;
    Node* right;
    public:
    
    Node(const std::string& key,const std::string& value);

    unsigned int height();
    int bfactor();
    void fixheight();
};