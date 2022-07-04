#include <iostream>
#include "lexicographical.h"
#include "list.h"
void swap(Word *A, Word *B){
    Word c = *A; 
    *A = *B;
    *B = c;
    }
int main(){
    std::string * order = new std::string();
    char letter;
    std::string trash;
    std::cin>>trash;
    for(int i = 0;i<26;i++){
        std::cin>>letter;
        while(letter==' '){
            std::cin>>letter;
        }
        order->push_back(letter+=32);
    }
    std::cin>>trash;
    Lexicographical * lexicographical = new Lexicographical(order);
    std::string aux;
    LinkedList * list = new LinkedList();
    while(std::cin>>aux){
        list->Insere(new Word(aux));
    }
    Word ** words = list->getWords();
    int size = list->tamanho;
    for(int i = 0;i<list->tamanho;i++){
        for(int u=list->tamanho-1;u>i;u--){
            if(lexicographical->biggerWord(words[u-1]->term,words[u]->term)==0){
            swap(words[u-1],words[u]);
            }
          }
      }
    for(int i = 0;i<list->tamanho;i++){
        words[i]->print();
    }
    delete list;
    delete words;
    delete lexicographical;
    std::cout <<"#FIM"<<std::endl;
    return 0;
}

