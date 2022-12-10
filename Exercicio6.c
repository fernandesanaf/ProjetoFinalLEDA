#include <stdio.h>
#include <stdlib.h>


typedef struct {
  char NomeVinho[50];
  char PaisVinho[50];
  char TipoUva[50];
  int  AnoSafra;
} Vinho;

typedef struct Node {
  Vinho *vinho;
  struct Node *prox;
  struct Node *ante;
} Node;

typedef struct {

  Node *head;

  Node *tail;

  int qty;
} Queue;

Queue *initialize_queue() {

  Queue *q = malloc(sizeof(Queue));

  q->head = NULL;
  q->tail = NULL;
  q->qty = 0;

  return q;
}

void LimparInputs() {

  fflush(stdin);
  __fpurge(stdin);
}

int Vazia(Queue *q) {

  return q -> qty == 0;
}

Vinho* AddNovoVinho() {

  Vinho* vinho = malloc(sizeof(Vinho));

  LimparInputs();
  printf("Digite o nome do vinho: \n");
  fgets(vinho -> NomeVinho, 50, stdin);

  LimparInputs();
  printf("Digite o país de origem do vinho: \n");
  fgets(vinho -> PaisVinho, 50, stdin);

  LimparInputs();
  printf("Digite o tipo da uva do vinho: \n");
  fgets(vinho -> TipoUva, 50, stdin);

  LimparInputs();
  printf("Digite o ano da safra do vinho: \n");
  scanf("%d", &vinho -> AnoSafra);

  return vinho;
}


void push(Queue *q, Vinho* vinho) {

  Node *node = malloc(sizeof(Node));
  node -> vinho = vinho;
  node -> prox = NULL;

  if (Vazia(q)) {

    q -> head = node;
    node -> ante = NULL;
  }
  else {

    node-> ante = q -> tail;
    q -> tail -> prox = node;
  }

  q->tail = node;
  q->qty++;
}

void shift(Queue *q) {

  if (Vazia(q)) {

    printf("A fila está vazia!\n");
    return;
  }

  Node *aux = q -> head;

  if (q -> head -> prox != NULL) {

    q -> head = q -> head -> prox;
  }
  else {

    q -> head = NULL;
  }

  q -> qty--;
  free(aux);
}


void MostraVinho(Vinho *vinho) {

  printf("\n");

  printf("Nome do vinho: %s\n", vinho -> NomeVinho);
  printf("País de origem: %s\n", vinho -> PaisVinho);
  printf("Tipo da uva: %s\n", vinho -> TipoUva);
  printf("Safra: %d\n", vinho -> AnoSafra);

  printf("\n");
}

void Mostra5MaisRecentes(Queue *adega) {

  if (Vazia(adega)) {

    printf("Não há vinhos adicionados à \"adega\"!\n");
    return;
  }

  printf("\n5 Vinhos mais recentes: \n");

  Node *tail = adega -> tail;
  int i = 0;

  while (tail && i < 5) {

    MostraVinho(tail -> vinho);
    tail = tail -> ante;
    i++;
  }
}

void Mostra5MaisVelhos(Queue *adega) {

  if (Vazia(adega)) {

    printf("Não há vinhos adicionados à \"adega\"!\n");
    return;
  }
  printf("\nVinhos mais antigos: \n");

  Node *head = adega -> head;
  int i = 0;

  while (head && i < 5) {

    MostraVinho(head -> vinho);
    head = head -> prox;
    i++;
  }
}

void MostraVinhoMaisVelho(Queue *adega) {

  if (Vazia(adega)) {

    printf("A \"adega\" está vazia!\n");
    return;
  }

  MostraVinho(adega -> head -> vinho);
  shift(adega);
}


void MostraVinhoMaisRecente(Queue *adega) {

  if (Vazia(adega)) {

    printf("A \"adega\" está vazia!\n");
    return;
  }

  MostraVinho(adega -> tail -> vinho);
}

void MostraFilaVinho(Queue *q) {

  if (!Vazia(q)) {

    printf("A adega está vazia!\n");
    return;
  }

  Node *head = q -> head;

  while (head) {
    MostraVinho(head -> vinho);
    head = head -> prox;
  }
}


int ValidaOrdemCresce(Queue *q) {

  Node *head = q -> head;

  while (head) {

    if (!head -> prox) {

      break;
    }

    if (head-> vinho -> AnoSafra > head -> prox ->vinho -> AnoSafra) {

      return 0;
    }

    head = head -> prox;
  }

  return 1;
}

void FilaOrdemCresce(Queue *q) {

  while (!ValidaOrdemCresce(q)) {

    Node *head = q -> head;

    while (head) {

      if (!head -> prox) {

        break;
      }

      if (head-> vinho ->AnoSafra > head-> prox -> vinho -> AnoSafra) {

        Vinho *aux = head -> vinho;
        head -> vinho = head -> prox -> vinho;
        head -> prox -> vinho = aux;
      }

      head = head -> prox;
    }
  }
}

void AddVinho(Queue *adega) {

  Vinho *vinho = AddNovoVinho();
  push(adega, vinho);
  FilaOrdemCresce(adega);
}

int main(void) {

  Queue *adega = initialize_queue();
  Queue *vinhosespeciais = initialize_queue();

  while (1) {

    int choice;
    printf("\n\"Sistema de Adega Virtual Ifense! Escolha a opção:\"\n");
    printf("1 - Quero adicionar um vinho!\n");
    printf("2 - Quero ver todos os vinhos!\n");
    printf("3 - Quero ver todos os vinhos na lista especial!\n");
    printf("4 - Quero ver o vinho mais antigo (não especial)!\n");
    printf("5 - Quero guardar o vinho mais recente (ocasião especial) em outra "
           "estrutura\n");
    printf("6 - Quero ver o vinho mais recente (ocasião especial)!\n");
    printf("7 - Quero ver os 5 vinhos mais antigos!\n");
    printf("8 - Quero ver os 5 vinhos mais recentes!\n");
    printf("Insira qualquer outro caractere para sair.\n\n");
    scanf("%d", &choice);


    switch(choice) {
      case 1:

        AddVinho(adega);

      case 2:

        MostraFilaVinho(adega);

      case 3:

        MostraFilaVinho(vinhosespeciais);

      case 4:

        MostraVinhoMaisVelho(adega);

      case 5:

        push(vinhosespeciais, adega -> tail -> vinho);

      case 6:

        MostraVinhoMaisRecente(adega);

      case 7:

        Mostra5MaisVelhos(adega);

      case 8:

        Mostra5MaisRecentes(adega);

      default:
        break;
    }
  }

  printf("\n\nAdega de Vinhos: \n\n");
  MostraVinho(adega);

  printf("\n\nSeleção de Vinhos Especiais: \n\n");
  MostraVinho(vinhosespeciais);

  return 0;
}
