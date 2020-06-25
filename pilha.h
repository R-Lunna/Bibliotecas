// Serve para n�o gerar ambiguidade de bibliotecas em tempo de compila��o.
#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>

// Define o tamanho da pilha.
#define MAX 200

// Determina qual o tipo de dados da pilha;
typedef char tp_item;

// Dado abstrato do tipo tp_pilha que � uma struct. 	
typedef struct {
	// Armazena o ind�ce do vetor(pilha).
	int topo;

	// Vetor(pilha) do tipo tp_item.
	tp_item item[MAX];

// Tipo da minha estrutura.
}tp_pilha;

/* Fun��o que inicializa a pilha
ela sempre deve ser inicializada no
programa antes de utilizar a pilha,
para indicar que a mesma est� vazia */
void inicializa_pilha(tp_pilha *p) {
	p->topo = -1;	
}

// Fun��o que verifica se a pilha est� ou n�o vazia.
int pilha_vazia(tp_pilha *p) {
	if (p->topo == -1) return 1;
	return 0;
}

// Fun��o que verifica se a pilha est� ou n�o cheia.
int pilha_cheia(tp_pilha *p) {
	if (p->topo == MAX -1) {
		return 1;
	} else {
		return 0;
	}
}

// Fun��o que empilha.
int push(tp_pilha *p, tp_item e) {
	if (pilha_cheia(p) == 1) return 0;
	p->topo++;
	p->item[p->topo] = e;
	return 1;
}

// Fun��o que desempilha.
int pop(tp_pilha *p, tp_item *e) {
	if (pilha_vazia(p)) return 0;
	*e = p->item[p->topo];
	p->topo--;	
	return 1;
}

/* Fun��o que verifica qual elemento est� no topo
sem desempilhar.*/
int top(tp_pilha *p, tp_item *e) {
	if (pilha_vazia(p)) return 0;
	*e = p->item[p->topo];
	return 1;
}

// Fun��o que me diz quantos elementos tem na minha pilha.
int altura_pilha(tp_pilha *p) {
	return p->topo +1;	
}

// Fun��o que imprime, desempilhando, uma c�pia da minha pilha.
void imprime_pilha(tp_pilha p) {
	tp_item e;
	while (!pilha_vazia(&p)) {
		pop(&p, &e);
		printf("[%c]\n", e);
	}
}

// Fim do if.
#endif
