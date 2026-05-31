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

AVLTree::AVLTree()
{
    root = nullptr;
}

Node* AVLTree::RotateRight(Node *p)
{
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

Node* AVLTree::RotateLeft(Node *p)
{
    Node* q = p->right;
    p->right = q->left;
    q->left = p;
    fixheight(p);
    fixheight(q);
    return q;
}
Node* AVLTree::balance(Node *p)
{
    fixheight(p);
    if(bfactor(p)==2)
    {
        if(bfactor(p->right)<0){
            p->right = RotateRight(p->right);
        }
        return RotateLeft(p);
    }
    if(bfactor(p)==-2)
    {
        if(bfactor(p->left)>0)
        {
            p->left = RotateLeft(p->left);
        }
        return RotateRight(p);
    }
    return p;
}

Node* AVLTree::insert(Node *p,const std::string& key,const std::string& value)
{
    if(!p)return new Node(key,value);
    if(key < p->key)
    {
        p->left = insert(p->left,key,value);
    }
    else if(key==p->key){
        p->value = value;
        return p;
    }
    else
    {
        p->right = insert(p->right,key,value);
    }
    return balance(p);
}

Node* AVLTree::find(Node *p,const std::string& key)
{
    if(!p)
    {
        return nullptr;
    }
    if(key<p->key)
    {
        return find(p->left,key);
    }
    if(key>p->key)
    {
        return find(p->right,key);
    }
    return p;
}

bool AVLTree::get(const std::string& key,std::string& value)
{
    Node* found = find(root,key);

    if(!found)
    {
        return false;
    }

    value = found->value;

    return true;
}

std::string& AVLTree::operator[](const std::string& key)
{
    Node* found = find(root,key);

    if(!found)
    {
        root = insert(root,key,"");
        found = find(root,key);
    }

    return found->value;
}

void AVLTree::clear(Node *p)
{
    if(!p)return;

    clear(p->left);
    clear(p->right);

    delete p;
}

AVLTree::~AVLTree()
{
    clear(root);
}