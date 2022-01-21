#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Serie *head = NULL, *atual = NULL;

int menu() {
  int op, s;
  do {
    /* system("clear"); */
    system("cls");
    op = 0, s = 0;
    fflush(stdin);
    printf("\n\tMenu :");
    printf("\n\n[1] - Listar Series");
    printf("\n[2] - Inserir Serie");
    printf("\n[3] - Remover Serie");
    printf("\n[4] - Pesquisar Series");
    printf("\n[5] - Atualizar Series");
    printf("\n[0] - Sair\n");
    fscanf(stdin, "%i", &op);
  } while (((op < 0) || (op > 5)));

  return op;
}

void pausa() {
  getchar();
  getchar();
  return;
}

void listar() {}

void inserir() {}

void eliminar() { printf("eliminar"); }

void pesquisar() { printf("pesquisar"); }

void atualizar() { printf("atualizar"); }

void escolha(int n) {
  switch (n) {
  case 1:
    listar();
    break;
  case 2:
    inserir();
    break;
  case 3:
    eliminar();
    break;
  case 4:
    pesquisar();
    break;
  case 5:
    atualizar();
    break;
  default:
    exit(0);
    break;
  }
}

int main() {

  FILE *fic = fopen("./bin/dados.bin", "ab");
  char linha[128];

  if (fic == NULL) {
    printf("Erro ao abrir ficheiro\n");
    getchar();
    exit(1);
    fclose(fic);
    inserir();
  }

  /* while (1) { */
  /*   escolha(menu()); */
  /*   return 0; */
  /* } */
}
