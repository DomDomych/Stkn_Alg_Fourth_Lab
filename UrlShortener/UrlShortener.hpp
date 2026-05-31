#pragma once

#include <string>
#include "tree/tree.hpp"
#include <vector>

class UrlShortener
{
    private:
    AVLTree CodeToUrl;
    AVLTree UrlToCode;

    int count;
    int maxlength;
    std::string gencode(int number);
    public:
    UrlShortener();

    std::string shorten(const std::string& Url);
    std::string getOrig(const std::string& scode);
    std::string getcodebyUrl(const std::string& url);
    bool contains(const std::string& code);
    bool changeUrl(const std::string& code,const std::string& value);
    bool remove(const std::string& code);
    void print()const;
    void printMostPopular() const;
    std::vector<std::pair<std::string,std::string>> find_by_word(const std::string& word);
};