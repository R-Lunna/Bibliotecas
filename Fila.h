// Serve para não gerar ambiguidade de biblioteca em tempo de compilação.
#ifndef FILA_H
#define FILA_H

#include <stdio.h>

// Define o tamanho da fila.
#define MAX 200

// Define o tipo primitivo de dados.
typedef char tp_item;

typedef struct {
    tp_item item[MAX];
    int ini, fim;
//  int tam;
} tp_fila;

// Inicializa a fila começando com uma posição anterior à inicial ou seja o final da fila.
void inicializa_fila(tp_fila *f) {
    f->ini = f->fim = MAX-1;
//  f->tam=0;
}

// Verifica se a fila está vazia, quando o início for igual ao fim da fila.
int fila_vazia(tp_fila *f){
    if(f->ini == f->fim) return 1;
    return 0;
}

/* Função auxiliar, caso ele esteja na última possição, 
   me retorne o início, ou seja, 0. Do contrário 
   retorne a próxima posição. */
int proximo (int pos){
    if(pos== MAX-1) return 0;
    return ++pos;
}

// Verifica se a fila está cheia.
int fila_cheia (tp_fila *f){
    if(proximo(f->fim)==f->ini) return 1;
    return 0;
}

int insere_fila (tp_fila *f, tp_item e){
    if(fila_cheia(f)) 
    	//Não foi possívvel adicionar a fila.  
        return 0; 
    f->fim = proximo(f->fim);
    f->item[f->fim]=e;
 //   f->tam++;
    return 1;
}

int remove_fila (tp_fila *f, tp_item *e){
    if(fila_vazia(f))
		//Não foi possível remover da fila. 
        return 0; 
    f->ini = proximo(f->ini);
    *e = f->item[f->ini];
    //f->tam--;
    return 1;
}

/* Função auxiliar que vai remover todos os elemtentos da fila
	por ela ser uma caixa preta */
void imprime_fila (tp_fila f){
    tp_item e;
    while(!fila_vazia(&f)){
        remove_fila(&f, &e);
        printf("[%c] ", e);
    }
}

// Duas opções de código do tamanho_fila.     
int tamanho_fila(tp_fila *f){
	if (fila_vazia(f)) return 0;
	if (f->ini < f->fim) return f->fim - f->ini;
	return MAX - 1 - f->ini + f->fim + 1;
 }

 /*
 int tamanho_fila(tp_fila f){
    int cont=0;
	tp_item e;
    while(!fila_vazia(&f)){
        remove_fila(&f, &e);
        cont++;
    }	
    return cont; 
}
*/
#endif // FILA_H
