#include "tree.hpp"


Node::Node(const std::string& key,const std::string& value):
        key(key),                                               
        value(value),                                              
        left(nullptr),                                            
        right(nullptr),                                                            
        h(1)
        {};


unsigned int Node::height()
{
    return h;
}

int Node::bfactor()
{
    unsigned int hl = left? left->height():0;
    unsigned int hr = right? right->height():0;

    return static_cast<int>(hl)-static_cast<int>(hr);
}


