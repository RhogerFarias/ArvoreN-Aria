//Arvore N-Aria Dinamica
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

//criação do nó
typedef struct no {
    TIPOCHAVE chave;
    struct no *primFilho;
    struct no *proxIrmao;
} NO;
typedef NO* PONT;

//inicialização
PONT criaNovoNo(TIPOCHAVE ch){
    PONT novo = 
        (PONT)malloc(sizeof(NO));
    novo->primFilho = NULL;
    novo->proxIrmao = NULL;
    novo->chave = ch;
    return(novo);
}

PONT inicializa(TIPOCHAVE ch){
    return(criaNovoNo(ch));
}

//inserção de elementos
bool insere(PONT raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai){
    PONT pai = buscaChave(chavePai,raiz);
    if(!pai) return(false); //Verficando se pai existe
    PONT filho = criaNovoNo(novaChave); //Criação do nó para o filho
    PONT p = pai->primFilho; //Verificamos o primogênito desse pai
    if(!p) pai->primFilho = filho; //Se n houver primogn, o novo nó é o 1 filho
    else{
        while (p->proxIrmao) //caso contrario, vai ao ultimo filho
        p = p->proxIrmao; //colocamos o novo nó como caçula
        p->proxIrmao = filho;
    }
    return(true);
}

//exibição da arvore
void exibirArvore(PONT raiz){
    if(raiz == NULL) return;
    printf("%d(",raiz->chave);
    PONT p = raiz->primFilho;
    while(p){
        exibirArvore(p);
        p = p->proxIrmao;
    }
    printf(")");
}

//busca de elementos
PONT buscaChave(TIPOCHAVE ch, PONT raiz){
    if(raiz == NULL) return NULL;//busca na raiz
    if(raiz->chave == ch) return raiz;
        PONT p = raiz->primFilho; //se n encontrar, olhamos nos filhos
    while(p){
        PONT resp = buscaChave(ch, p);  //para cada filho
        if(resp) return(resp);          //buscamos na subarvore
        p = p->proxIrmao;               //de que ele é raiz
    }
    return (NULL);
}

int main(){
    PONT criaNovoNo = inicializa(8);
}