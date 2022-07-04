#include "lexicographical.h"
#include <iostream>
Lexicographical::Lexicographical(std::string * _order){
    order = _order;
}
Lexicographical::~Lexicographical(){
    delete order;
}
int Lexicographical::biggerChar(char _a, char _b){
    short founds =0;
    //para não percorrer todo o vetor sempre;
    short a,b;
    for(int i=0;i<26&&(founds!=2);i++){
        if(order->at(i)==_a){
            a=i;
            founds++;
        }
        if(order->at(i)==_b){
            b=i;
            founds++;
        }
    }
    if(founds<2){
        if(_a>_b){
        return 0;
    }else if(_a<_b){
        return 1;
    }
    return -1;
    }
    if(a>b){
        // a posicao de a vem depois da posicao de b
        return 0;
    }else if(a<b){
        return 1;
    }
    return -1;
}
int Lexicographical::biggerWord(std::string a, std::string b){
    short menor;
    bool iguais=false;;
    if(a.length()<b.length()){
        menor = a.length();
    } else if(a.length()>b.length()){
        menor = b.length();
    }else{
        menor = b.length();
        iguais = true;
    }
    for(int i=0;i<menor;i++){
        short result = biggerChar(a[i],b[i]);
        if(result>=0){
            return result;
        }
    }
    if(iguais){
        return -1;
    }
    if(menor==a.length()){
        return 1;
    }
    return 0;
}