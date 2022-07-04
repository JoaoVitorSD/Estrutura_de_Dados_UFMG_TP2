#include <string>
class Lexicographical{
    public:
    std::string * order;
    Lexicographical(std::string * _order);
    ~Lexicographical();
    int biggerChar(char a, char b); 
    int biggerWord(std::string a, std::string b); 
};