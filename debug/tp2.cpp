#include <iostream>
#include "lexicographical.h"
#include "list.h"
void Particao(int Esq, int Dir,
int *i, int *j, Word **A,Lexicographical* &l)
{
    Word *x, *w;
    *i = Esq; *j = Dir;
    std::cout <<*i<<" "<<*j<<" ";
    x = A[(*i + *j)/2];
     do{
         while (x->term<A[*i]->term) (*i)++;
         while (x->term<A[*j]->term) (*j)--;
         if (*i <= *j){
              *w = *A[*i]; *A[*i] = *A[*j]; *A[*j] = *w;
             (*i)++; (*j)--;
         }
     }while (*i <= *j);
}
void Ordena(int Esq, int Dir, Word **A,Lexicographical *&l)
{ 
    int i,j;
Particao(Esq, Dir, &i, &j, A,l);
if (Esq < j) Ordena(Esq, j, A,l);
if (i < Dir) Ordena(i, Dir, A,l);
}
void QuickSort(Word **A, int n, Lexicographical* &l)
{
Ordena(0, n-1, A,l);
}
int main(){
    std::string * order = new std::string();
    char letter;
    std::string trash;
    std::cin>>trash;
    for(int i = 0;i<26;i++){
        std::cin>>letter;
        order->push_back(letter);
    }
    std::cin>>trash;
    Lexicographical * lexicographical = new Lexicographical(order);
    std::string aux;
    LinkedList * list = new LinkedList();
    while(std::cin>>aux){
        if(aux=="STOP"){
            break;
        }
        list->Insere(new Word(aux));
    }
    Word ** words = list->getWords();
    int size = list->tamanho;

    QuickSort(words,size-1,lexicographical);
    for(int i = 0;i<list->tamanho;i++){
        std::cout<<words[i]->term<<" "<<words[i]->times<<std::endl;
    }
    delete list;
    delete words;
    delete lexicographical;
    return 0;
}