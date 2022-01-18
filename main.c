#include <stdio.h>

struct Serie {
  int id;
  char nome[30];
  struct Serie *p;
};

struct Serie *head = NULL;
struct Serie *atual = NULL;

int menu() {
  int op;
  do {
    printf("\n\tMenu :");
    printf("\n\n[1] - Listar Series");
    printf("\n[2] - Inserir Serie");
    printf("\n[3] - Remover Serie");
    printf("\n[4] - Pesquisar Series");
    printf("\n[5] - Atualizar Series");
    printf("\n[0] - Sair\n");
    scanf("%i", &op);
    fflush(stdin);
  } while ((op < 1) || (op > 5));
  return op;
}

int main() {
  int opmenu = menu();
  return 0;
}
