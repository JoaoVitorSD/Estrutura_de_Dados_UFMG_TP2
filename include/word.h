#include <string>
#include <iostream>
class Word{
    public:
    std::string term;
    int times;
    Word(){};
    Word(std::string _term);
    Word & operator = (const Word &a);
    bool operator == (const Word &a);
    void increment();
    void print();
    };