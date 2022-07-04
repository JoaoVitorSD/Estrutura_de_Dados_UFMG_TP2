#include <string>
class Lexicographical{
    public:
    std::string * order;
    Lexicographical(std::string * _order);
    ~Lexicographical();
    int compareChar(char a, char b); 
    int compareWord(std::string a, std::string b); 
};