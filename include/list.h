#include "wordCell.h"
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void InsereInicio(Word * word);
    void InsereFinal(Word *item);
    void Insere(Word *item);
    Word** getWords();
    void Imprime();
    void Limpa();
    int tamanho;
    WordCell *primeiro;
    WordCell *ultimo;
};