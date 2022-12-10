// 2) (valor 1,5) Escreva uma biblioteca que implemente uma solução do tipo fila para as
// seguintes estruturas:
// struct Node {
// int number;
// Node next;
// };
// struct Queue {
// Node head; //Nó inicial da fila
// Node tail; //Nó final da fila
// /* Determina a quantidade máxima de itens que a fila pode comportar */
// int max_items;
// /* Indica a quantidade de elementos presentes na fila */
// int qty;
// };
// Em seguida, implemente métodos para:
// - Retornar a quantidade de elementos contidos na fila
// - Verificar se a fila está cheia
// - Verificar se a fila está vazia
// - Verificar se um elemento está presente na fila
// - Exibir os elementos presentes na fila
// - Inserir um elemento na fila
// - Retirar um elemento da fila

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node* next;
}; typedef struct Node node;

struct Queue {
    struct Node* head; //Nó inicial da fila
    struct Node* tail; //Nó final da fila
    
    /* Determina a quantidade máxima de itens que a fila pode comportar */
    int max_items;

    /* Indica a quantidade de elementos presentes na fila */
    int qty;
}; typedef struct Queue queue;


int ReturnQty(queue* q){
	return q -> qty;
}

int Cheia(queue* q){
	int ConfereCheia = 0;

	if(q -> qty == q -> max_items){
		ConfereCheia = 1;
	}
	if(ConfereCheia == 1){
		printf("Fila Cheia");
	} else{
			printf("Fila não está Cheia");
	}
	return ConfereCheia;
}

int Vazia(queue * q){
	int ConfereVazia = 0;
	if (ConfereVazia == 1){
		printf("Fila Vazia");
	} else{
		printf("Fila não está Vazia");
	}
	return ConfereVazia;
}

void Buscar(queue* q, int value){
	node* aux = q -> head;
	int valida = 0;

	if(Vazia(q)){
		printf("FIla Vazia");
	} else{
		while(aux -> next){
			if(aux -> number == value){
				valida = 1;
			}
			aux = aux -> next;
		}

		if(valida == 1){
			printf("Alvo Encontrado");
		} else{
			printf("Alvo %d Não Encontrado", value);
		}
	}
}

void Exibe(queue* q){
	node* aux = q -> head;

	for(int i; i < q -> qty; i++){
		printf("%d", aux -> number);
	}
	printf("\n");
}

void Insere(queue* q, int item){

	if(ConfereCheia(q)){
		printf("Fila Cheia\n");
	} else{
		node* aux;
		struct Node* novo = (struct Node*) calloc(1, sizeof(node));
		novo -> number = item;
		novo -> next = NULL;
		if(q == NULL){
			q -> head -> number = novo -> number;
			q -> tail -> number = novo -> number;
		} else{
			aux = q -> head;
			while(aux -> next){
				aux = aux -> next;
			}
			aux -> next = novo;
		}
		q -> qty++;
		printf("Valor Inserido na Fila\n");
	}
}

void Retira(queue* q){
	node remove;

	if(Vazia(q)){
		printf("Fila Vazia");
	}else{
		queue *remove = q->head;
		q->head = remove->head;
		q -> qty--;
		return remove;
}}
 
