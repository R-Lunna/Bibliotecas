#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no {
  tp_item info;
  struct tp_no *prox;
}tp_listase;


tp_listase *inicializa_listase() {
	return NULL;
}
	
int listase_vazia(tp_listase *l) {
	if(l==NULL) return 1;
	return 0;
}

// ela irá alocar um espaço na memória;
tp_listase *aloca_listase() { 
	tp_listase *novo_no;
	novo_no = (tp_listase*) malloc(sizeof(tp_listase));
	return novo_no;
}

/* Esse **l é um ponteiro que está apontando para outro 
ponteiro para o endereço de memória original da listase*,
o que está apontando para o NULL */
int insere_listase(tp_listase **l, tp_item e) { 
	tp_listase *novo_no, *atu;

	// aqui está pegando o novo nó e apontando para o NULL;
	novo_no=aloca_listase();

	// Não alocou memória 
	if(novo_no==NULL) return 0; 

	// atribuir os valores para o novo nó;
	novo_no->info= e;
	novo_no->prox=NULL;
	// finaliza o encadeamento do nó

	// se for o primeiro nó entra aqui
	if (listase_vazia(*l)) {
		*l=novo_no;
	} else {
		atu = *l;
		while (atu->prox!=NULL) { 
			// aponta para o ultimo nó
			atu=atu->prox; 
		}
		atu->prox=novo_no;	
	}
		
	return 1;
}

/* Esse **l é um ponteiro que está apontando para outro 
ponteiro para o endereço de memória original da listase*,
o que está apontando para o NULL */
int insere_listase_inicio(tp_listase **l, tp_item e){ 
	tp_listase *novo_no, *atu;
	
	// aqui está pegando o novo nó e apontando para o NULL;
	novo_no=aloca_listase(); 

	// Não alocou memória
	if (novo_no==NULL) return 0; 
	
	// atribuir os valores para o novo nó;
	novo_no->info= e;
	novo_no->prox=NULL;
	// finaliza o encadeamento do nó
	
	// se for o primeiro nó entra aqui
	if (listase_vazia(*l)) {
		*l=novo_no;
	} else {
		// add
		novo_no->prox= *l; 
		// add
		*l=novo_no; 
	}
	
	return 1;
}

int insere_listase_ordem(tp_listase **l, tp_item e) {
	tp_listase *novo_no, *atu, *ant;

	// aqui está pegando o novo nó e apontando para o NULL;
	novo_no = aloca_listase();

	atu = *l;
	ant = *l;

	// Não alocou memória 
	if(novo_no == NULL) return 0; 

	// atribuir os valores para o novo nó;
	novo_no->info = e;
	novo_no->prox = NULL;
	while ((atu != NULL) && (atu->info < novo_no->info)) { 
		
		ant = atu;
		atu = atu->prox;
	}
		
	if (ant == atu) {
		novo_no->prox = ant;
		*l = novo_no;
	} else {
		novo_no->prox = ant->prox;
		ant->prox = novo_no;
	}
		
	return 1;
}

void imprime_listase(tp_listase *l) {
	tp_listase *aux;
	aux=l;
	
	while (aux!=NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
}

int remove_listase(tp_listase **l, tp_item e) {
	tp_listase *ant, *atu;
	atu = *l;
	ant = NULL;
	
	while ((atu!=NULL) && (atu->info!=e)) {
		ant=atu;
		atu=atu->prox;	
	}
	
	// não foi encontrado o elemento
	if (atu==NULL) return 0; 
	
	// se for retirado o primeiro termo
	if (ant==NULL) {
		
		// fazendo a lista apontar para o termo subsequente que foi retirado
		*l=atu->prox; 
	} else {
		
		// fazendo a interligação entre o termo anterior e o termo subsequente ao termo retirado
		ant->prox=atu->prox; 
	}
	
	free(atu);
	atu=NULL;
	
	return 1;
}

tp_listase *busca_listase(tp_listase **l, tp_item e) {
	tp_listase *atu;
	atu=*l;
	
	while((atu!=NULL) && (atu->info!=e)) {
		atu=atu->prox;
	}
	
	if (atu==NULL) return NULL;
	
	return atu;
}

// Verifica se as duas listas são idênticas
int listase_iguais(tp_listase **l1, tp_listase **l2) {
	tp_listase *aux, *aux2;
	
	aux = *l1;
	aux2 = *l2;
	
	if (tamanho_listase(l1) != tamanho_listase(l2)) return 0;
	
	while (aux != NULL) {
		if (aux->info != aux2->info) return 0;
		else {
			aux = aux->prox;
			aux2 = aux2->prox;
		}
	}
	
	return 1;
}

int tamanho_listase(tp_listase **l) {
    int cont=0;
    
    tp_listase *atu;
    atu=*l;
    
    while (atu!=NULL) {
        cont++;
        atu=atu->prox;
    }
    
    return cont;
}

// Função que retorna a quantidade de nós com elementos maiores do que X.
int tamanho_listase_maiorX(tp_listase **l, int x) {
    int cont=0;
    
    tp_listase *atu;
    atu=*l;
    
    while (atu!=NULL) {
    	if (atu->info > x) {
    		cont++;
    		atu = atu->prox;
    	}
        else atu = atu->prox;
    }
    
    return cont;
}

void destroi_listase(tp_listase **l) {
	tp_listase *atu;
	atu=*l;
	
	while (atu!=NULL) {
		*l=atu->prox;
		free(atu);
		atu=*l;
	}
	
	*l=NULL;
}

// destroi somente os números ímpares
void destroi_listase_impar(tp_listase **l) {
	tp_listase *atu, *ant;
	atu = *l;
	ant = NULL;
	
	while (atu != NULL) {	
		if (atu->info % 2 == 0) {
			ant = atu;
			atu = atu->prox;
		} else {
			if (ant == NULL) {
				atu = atu->prox;
				*l = atu;
			} else {
				atu = atu->prox;
				ant->prox = atu;
			}
		}
	}

	if (listase_vazia(*l)) *l = NULL;
}

void listase_circular(tp_listase **l1, tp_listase **l2) {
	tp_listase *last1, *last2;
	
	last1 = *l1;
	last2 = *l2;
	
	while (last1->prox != NULL) {
		last1 = last1->prox;
	}
	
	while (last2->prox != NULL) {
		last2 = last2->prox;
	}
	
	last1->prox = *l2;
	last2->prox = *l1;
	*l2 = *l1;
}

// Retorna o tamanho de uma lista circular.
int tamanho_listase_circular(tp_listase **l) {
	int cont = 1;
	tp_listase *atu, *guard;
	atu = *l;
	guard = *l;
	
	while (guard != atu->prox) {
		atu = atu->prox;
		cont++;
	}
	
	return cont;
}

// Imprime uma lista circular
void imprime_listase_circular(tp_listase *l) {
	tp_listase *aux;
	aux = l;
	
	int cont;
	cont = tamanho_listase_circular(&aux);
	while (cont != 0) {
		printf("%d", aux->info);
		aux = aux->prox;
		cont--;
	}
}

// Divide a lista em duas
int divide_listase(tp_listase **l1, tp_listase **l2, tp_item n) {
	tp_listase *ant, *atu;
	atu = *l1;
	ant = NULL;
	
	while (atu != NULL && atu->info != n) {
		ant = atu;
		atu = atu->prox;
	}
	
	if (atu == NULL) return 0;
	
	*l2 = atu->prox;
	atu->prox = NULL;
	
	return 1;
}

#endif


