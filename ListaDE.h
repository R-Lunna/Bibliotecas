#ifndef LISTADE_H
#define LISTADE_H
#include <stdio.h>
#include <stdlib.h>
typedef int tp_item; 
typedef struct tp_no_aux {   
  tp_item info;   
  struct tp_no_aux *ant;   
  struct tp_no_aux *prox;   
} tp_no; 

typedef struct {   
  tp_no *ini;   
  tp_no *fim;   
//  int tamanho;   
} tp_listad;


tp_listad *inicializa_listad (){
   tp_listad *lista=(tp_listad*) malloc(sizeof(tp_listad));   
   lista->ini = NULL;   
   lista->fim = NULL;   
 // lista->tamanho = 0;   
   return lista;
}  

tp_no *aloca() {
	tp_no* pt;
	pt=(tp_no*) malloc(sizeof(tp_no));
	return pt;
}



int insere_listad_no_fim (tp_listad *lista, tp_item e){   
  tp_no *novo;   
  novo=aloca();
  if (!novo) return 0;
  novo->info = e;  
  if ( (lista->ini == NULL) && (lista->fim == NULL) ) { //Se for o primeiro elemento da lista
     novo->prox = NULL;   
     novo->ant = NULL; 
     lista->ini = lista->fim = novo;
     }  
  else {
     novo->prox = NULL;   
     novo->ant = lista->fim; 
     lista->fim->prox = novo;
     lista->fim = novo;
     }  
  //lista->tamanho++;   
  return 1;   
}        

void imprime_listad(tp_listad *lista, int ordem) {
     tp_no *atu;
     
     switch (ordem) {
        case 1: atu = lista->ini;
                while (atu != NULL) {
                   printf("%d ", atu->info);
                   atu=atu->prox;           
                   }
                break;   
        case 2: atu = lista->fim;
                while (atu != NULL) {
                   printf("%d ", atu->info);
                   atu=atu->ant;           
                   }
                break;   
        default: printf("codigo invalido");        
     }
     printf("\n");
}

int remove_listad (tp_listad *lista, tp_item e){   
  tp_no *atu;
  atu = lista->ini;
  while ( (atu != NULL) && (atu->info != e) ) { 
        atu=atu->prox;}
  if ( atu == NULL) return 0;  
  if (lista->ini == lista->fim) { //Se o for o unico elemento da lista
      lista->ini = lista->fim = NULL; }
  else {   
   if (lista->ini == atu) {  //Se for o primeiro elemento da lista
      lista->ini = atu->prox;
      atu->prox->ant = NULL;
      }  
   else {
      if (lista->fim == atu) { // se for o �ltimo n� da lista
       lista->fim = atu->ant;
       atu->ant->prox = NULL;              
       }
      else {
        atu->prox->ant = atu->ant;   
        atu->ant->prox = atu->prox;
        } 
      }
     }   
   free(atu);  
  //lista->tamanho--;   
  return 1;   
}        

tp_no * busca_listad (tp_listad *lista, tp_item e){   
  tp_no *atu;
  atu = lista->ini;
  while ( (atu != NULL) && (atu->info != e) ) { 
        atu=atu->prox;}
  return atu;
}        

tp_listad * Destroi_listad (tp_listad *lista){   
  tp_no *atu;
  atu = lista->ini;
  while (atu != NULL)  { 
        lista->ini = atu->prox;
        free(atu);
		}
  free(lista);
  return NULL;
}  
#endif

