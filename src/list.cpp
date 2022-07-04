#include "list.h"
#include <iostream>
LinkedList::LinkedList(){
    primeiro = new WordCell();
        ultimo = primeiro;
}
LinkedList::~LinkedList()
{
    Limpa();
    delete primeiro;
}
void LinkedList::InsereFinal(Word * word){
    WordCell * cell = new WordCell();
    cell->word = word;
    ultimo->next = cell;
    ultimo = cell;
    tamanho++;
}
void LinkedList::Insere(Word * word){
    if(word->term.length()==0){
        return;
    }
    WordCell * aux = primeiro->next;
    while(aux!=nullptr){
        if(*word==*aux->word){
            aux->word->increment();
            return;
        }
        aux = aux->next;
    }
    InsereFinal(word);
}
void LinkedList::Limpa(){
    WordCell * aux = primeiro->next;
    while(aux !=nullptr){
        primeiro->next = aux->next;
        delete aux;
        aux = primeiro->next;
    }
    ultimo = primeiro;
    tamanho = 0;
}
Word ** LinkedList::getWords(){
    WordCell * aux = primeiro->next;
    Word ** words = new Word*[tamanho];
    for(int i = 0;aux!=nullptr;i++){
        words[i] = aux->word;
        aux = aux->next;
    }
    return words;
}
void LinkedList::Imprime(){
    WordCell * aux = primeiro->next;
    while(aux !=nullptr){
        std::cout<< aux->word->term<<" "<<aux->word->times<<std::endl;
        aux = aux->next;
    }
}