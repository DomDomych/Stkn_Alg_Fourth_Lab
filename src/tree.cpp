#include "tree.hpp"
#include <string>

Node::Node(const std::string& key,const std::string& value):key(key),
                                                            value(value)
                                                            left(nullptr),
                                                            right(nullptr),
                                                            h(1){};
                                                            

