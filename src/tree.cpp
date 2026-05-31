#include <tree.hpp>
#include <string>

unsigned int Node::height()
{
    return height;
}

int Node::bfactor()
{
    return *left.height()-(*right.height());
}

void Node::fixheight()
{
    unsigned int hl = *left.height();
    unsigned int hr = *right.height();
    height = (hl>hr?hl:hr)+1;
    return;
}