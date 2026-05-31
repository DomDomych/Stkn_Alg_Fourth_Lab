#pragma once

#include <string>
#include "tree/tree.hpp"


class UrlShortener
{
    private:
    AVLTree CodeToUrl;
    AVLTree UrlToCode;

    int count;

    std::string gencode(int number);

    public:
    UrlShortener();

    std::string shorten(const std::string& Url);
    std::string getOrig(const std::string& scode);
    bool contains(const std::string& code);
    void print()const;
    void printMostPopular();
};