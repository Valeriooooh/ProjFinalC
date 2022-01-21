#include "../include/Serie.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ficheiro "dados.bin"

FILE *fic;
Serie ser;

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

void inserir() {
  fic = fopen(ficheiro, "ab");
  int n;
  printf("quantos registos pretende inserir?: ");
  scanf("%i", &n);
  for (int i = 1; i <= n; i++) {
    ser = criar_serie_gui();
    fwrite(&ser, sizeof(Serie), 1, fic);
  }
}

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

  char linha[128];
  long salto = get_size_serie;
  fic = fopen("dados.bin", "ab");
  if (fic == NULL) {
    printf("Erro ao abrir ficheiro\n");
    getchar();
    fclose(fic);
    exit(0);
  }
  fclose(fic);
  fflush(stdin);
  system("cls");
  char op;
  printf("Deseja Inserir registos?[s/N]: ");
  scanf("%c", &op);
  if (op != 's' && op != 'S') {
    printf("Sair\n");
  }
  inserir();

  /* while (1) { */
  /*   escolha(menu()); */
  /*   return 0; */
  /* } */
}
