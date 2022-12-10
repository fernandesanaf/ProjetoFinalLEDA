// 3) (valor 1,0) Escreva um programa que crie duas pilhas sequenciais numéricas
// ordenadas crescentemente a partir do topo. Transfira os elementos dessas pilhas
// para uma terceira pilha, inicialmente vazia, de modo que ela fique ordenada
// decrescentemente com o maior valor no topo.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
int dado;
struct Stack* next;
}; typedef struct Stack stack;

void Iniciar(stack** s){
	*s = NULL;
}

bool Vazio(stack* s){
	if(s==NULL){
		return true;
	}
	return false;
}

void Inserir(stack** s, int x){
	 stack* p = (struct stack*) calloc(1, sizeof(*p));

	if(p ==NULL){
		fprintf(stderr, "ERRO");
		return;
	}
	p->dado = x;
	p->next =*s;
	*s=p;
}

int Retirar(stack** s){
	int x;
	struct stack*aux;

	x=(*s)->dado;
	aux = *s;
	(*s) = (*s)->next;
	free(aux);

	return x;
}

int Topo(stack* s){
	return(s-> dado);
}

int OrdenarDecre(stack** s, int x){
	if(Vazio(*s) , x > Topo(*s)){
		Inserir(s, x);
    return;
	}
	 int aux = Retirar(s);
  OrdenarDecre(s, x);
      
  Inserir(s, aux);
}

void OrdenarCres(stack** s, int x){
	if(Vazio(*s) , x < Topo(*s)){
		Inserir(s, x);
		return;
	}
	int aux = Retirar(s);
	OrdenarCres(s,x);

	Inserir(s, aux);
}

void OrdenarPilhaDecre(struct stack** s){
	int x;
	if(!Vazio(*s)){
		int o =Retirar(s);
		OrdenarPilhaDecre(s);
		OrdenarDecre(s,x);
	}
}

void OrdernarPilhaCres(struct stack** s){
	int x;

	if(!Vazio(*s)){
		int o = Retirar(s);
		 OrdernarPilhaCres(s);
		OrdenarCres(s,x);
	}
}

void MostrarPilha(stack* s){
	while (s){
		printf("%d", s->dado);
		s = s->next;
	}
	printf("\n");
}

int main(void){
	stack* pilha1;
  stack* pilha2;
   stack* pilha3;
	int tam1, tam2, i = 0;
	int value;

	//1
	printf("Digite o tamanho da primeira pilha: ");
  scanf("%d", tam1);
	Iniciar(&pilha1);

	while(i<tam1){
		 printf("Digite um valor para inserir na pilha: ");
    scanf("%d", &value);
    Inserir(&pilha1, value);
		i++;
	}
	OrdernarPilhaCres(&pilha1);
	 printf("\n");

	
  printf("Elementos da Primeira Pilha Ordenados:\n");
  MostrarPilha(pilha1);

	//2
	printf("Digite o tamanho da primeira pilha: ");
  scanf("%d", tam2);
	i = 0;
	Iniciar(&pilha2);

	while(i<tam2){
		 printf("Digite um valor para inserir na pilha: ");
    scanf("%d", &value);
    Inserir(&pilha2, value);
		i++;
	}
	OrdernarPilhaCres(&pilha2);
	 printf("\n");

  printf("Elementos da Primeira Pilha Ordenados:\n");
  MostrarPilha(pilha2);

	Iniciar(&pilha3);
	 stack* aux1 = pilha1;

	for (i = 0; i < tam1; i++) {
    value = aux1 -> dado;
    aux1 = aux1 -> next;
    Inserir(&pilha3, value);
  }

	 stack* aux2 = pilha2;

	for (i = 0; i < tam2; i++) {
    value = aux2 -> dado;
    aux2 = aux2 -> next;
    Inserir(&pilha3, value);
  }

	OrdernarPilhaCres(&pilha3);
	 printf("\n");

	printf("Elementos da Nova Pilha depois do Sort(Ordem Crescente):\n");
  MostrarPilha(pilha3);

  OrdenarPilhaDecre(&pilha3);
  printf("\nElementos da Nova Pilha depois do Sort(Ordem Decrescente):\n");
  MostrarPilha(pilha3);

	return 0;
}
