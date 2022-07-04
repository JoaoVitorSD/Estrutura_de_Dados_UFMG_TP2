#include "lexicographical.h"
#include <iostream>
Lexicographical::Lexicographical(std::string * _order){
    order = _order;
}
Lexicographical::~Lexicographical(){
    delete order;
}
int Lexicographical::compareChar(char _a, char _b){
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
    if(a<b){
        return 1;
    }else if(a>b){
        return 0;
    }
    return -1;
}
int Lexicographical::compareWord(std::string a, std::string b){
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
        short result = compareChar(a[i],b[i]);
        if(result==1){
            return 1;
        }else if(result==0){ 
            return 0;
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