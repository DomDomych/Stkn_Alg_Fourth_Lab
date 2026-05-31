#include "tree.hpp"


Node::Node(const std::string& key,const std::string& value):
        key(key),                                               
        value(value),                                              
        left(nullptr),                                            
        right(nullptr),                                                            
        h(1)
        {};


unsigned int AVLTree::height(Node *p)
{
    
    return p?p->h:0;
}

int AVLTree::bfactor(Node *p)
{
    unsigned int hl = p->left? height(p->left):0;
    unsigned int hr = p->right? height(p->right):0;

    return static_cast<int>(hr)-static_cast<int>(hl);
}

void AVLTree::fixheight(Node *p)
{
    unsigned int hl = height(p->left);
    unsigned int hr = height(p->right);

    p->h = (hl>hr?hl:hr)+1;
}



