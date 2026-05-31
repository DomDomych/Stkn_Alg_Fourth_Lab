#include "tree.hpp"
#include <iostream>
#include <vector>

std::vector<int> prefixfunction(const std::string s)
{
    std::vector<int> pi(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }

    return pi;
}

Node::Node(const std::string& key,const std::string& value):
        key(key),                                               
        value(value),                                              
        left(nullptr),                                            
        right(nullptr),                                                         
        h(1),
        count(0)
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
void AVLTree::print(Node *p,int& number)const
{
    if(!p)return;
    print(p->left,number);
    std::cout<<number<<". "<<p->key<<"->"<<p->value<<' '<<p->count<<'\n';
    number++;
    print(p->right,number);
}

void AVLTree::print()const
{
    int number = 1;
    print(root,number);
}

void AVLTree::increment(const std::string& key)
{
    Node* found = find(root,key);

    if(found)
    {
        found->count++;
    }
    return;
}
Node* AVLTree::MostPopular(Node *p,Node *best)const
{
    if(!p)return best;

    if(!best || p->count > best->count)
    {
        best = p;
    }

    best = MostPopular(p->left,best);
    best = MostPopular(p->right,best);

    return best;
}
bool AVLTree::getMostPopular(std::string&key,std::string& value,int& count)
{
    Node* best = MostPopular(root,nullptr);

    if(!best)return false;

    key = best->key;
    value = best->value;
    count = best->count;

    return true;
}

bool AVLTree::kmp(const std::string& value,const std::string& word)
{
    if(word.empty())return false;

    std::vector<int> pi = prefixfunction(word);

    int j=0;

    for(int i=0;i<value.size();i++)
    {
        while(j>0 && value[i]!=word[j])
        {
            j = pi[j-1];
        }

        if(value[i]==word[j])
        {
            j++;

        }

        if(j==word.size())
        {
            return true;
        }
    }
    return false;
}

AVLTree::~AVLTree()
{
    clear(root);
    root = nullptr;
}