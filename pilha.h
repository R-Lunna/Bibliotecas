// Serve para não gerar ambiguidade de bibliotecas em tempo de compilação.
#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>

// Define o tamanho da pilha.
#define MAX 200

// Determina qual o tipo de dados da pilha;
typedef char tp_item;

// Dado abstrato do tipo tp_pilha que é uma struct. 	
typedef struct {
	// Armazena o indíce do vetor(pilha).
	int topo;

	// Vetor(pilha) do tipo tp_item.
	tp_item item[MAX];

// Tipo da minha estrutura.
}tp_pilha;

/* Função que inicializa a pilha
ela sempre deve ser inicializada no
programa antes de utilizar a pilha,
para indicar que a mesma está vazia */
void inicializa_pilha(tp_pilha *p) {
	p->topo = -1;	
}

// Função que verifica se a pilha está ou não vazia.
int pilha_vazia(tp_pilha *p) {
	if (p->topo == -1) return 1;
	return 0;
}

// Função que verifica se a pilha está ou não cheia.
int pilha_cheia(tp_pilha *p) {
	if (p->topo == MAX -1) {
		return 1;
	} else {
		return 0;
	}
}

// Função que empilha.
int push(tp_pilha *p, tp_item e) {
	if (pilha_cheia(p) == 1) return 0;
	p->topo++;
	p->item[p->topo] = e;
	return 1;
}

// Função que desempilha.
int pop(tp_pilha *p, tp_item *e) {
	if (pilha_vazia(p)) return 0;
	*e = p->item[p->topo];
	p->topo--;	
	return 1;
}

/* Função que verifica qual elemento está no topo
sem desempilhar.*/
int top(tp_pilha *p, tp_item *e) {
	if (pilha_vazia(p)) return 0;
	*e = p->item[p->topo];
	return 1;
}

// Função que me diz quantos elementos tem na minha pilha.
int altura_pilha(tp_pilha *p) {
	return p->topo +1;	
}

// Função que imprime, desempilhando, uma cópia da minha pilha.
void imprime_pilha(tp_pilha p) {
	tp_item e;
	while (!pilha_vazia(&p)) {
		pop(&p, &e);
		printf("[%c]\n", e);
	}
}

// Fim do if.
#endif
