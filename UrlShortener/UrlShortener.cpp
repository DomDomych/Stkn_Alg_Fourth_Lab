#include "UrlShortener.hpp"
#include <string>
#include <iostream>

const std::string alphabet =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789";

std::string UrlShortener::gencode(int number)
{
    std::string code="";

    do
    {
        code = alphabet[number % alphabet.size()]+code;
        number /=alphabet.size();
        number--;
    }while(number>=0);

    return code;
}

UrlShortener::UrlShortener():count(0){}

std::string UrlShortener::shorten(const std::string& Url)
{
    std::string exist;

    if(UrlToCode.get(Url,exist)){
        return exist;
    }

    std::string code = gencode(count);
    count++;

    CodeToUrl[code] = Url;
    UrlToCode[Url] = code;

    return code;
}

std::string UrlShortener::getOrig(const std::string& scode)
{
    std::string Url;

    if(CodeToUrl.get(scode,Url))
    {
        CodeToUrl.increament(scode);
        return Url;
    }

    return "";
}

bool UrlShortener::contains(const std::string& code)
{
    std::string pass;
    return CodeToUrl.get(code,pass);
}

void UrlShortener::print()const
{
    CodeToUrl.print();
    return;
}

void UrlShortener::printMostPopular()
{
    std::string key,value;
    int count;
    if(!CodeToUrl.getMostPopular(key,value,count))
    {
        std::cout<<"Нет Ни Одной Ссылки\n";
        return;
    }
    std::cout<<"Самая Популярная Ссылка:\n"
             <<key<<" -> "<<value<<"| "<<count<<'\n';
    return;
}