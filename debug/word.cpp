#include "wordCell.h"
bool validLetter(char c){
    if(c>=65&&c<=90)
        return true;
    if(c>=97&& c<=122)
        return true;
    return false;
}
std::string tolower(std::string word){
    std::string aux="";
    for(int i =0;i<word.length();i++){
        if(validLetter(word.at(i))){
            if(word.at(i)<=90){
            word[i]=word.at(i)+ 32;
            }
            aux.append(word.substr(i,1));
        }
    }
    return aux;
}
Word::Word(std::string _term){
    term = tolower(_term);
    times = 1;
}
Word  & Word::operator=(const Word &a){
    term = a.term;
    times = a.times;
}
bool Word::operator==(const Word &a){
    return term == a.term;
}
void Word::increment(){
    times++;
}