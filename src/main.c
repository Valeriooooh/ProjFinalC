#include "../include/Serie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// função que pausa o programa?
void pausa() {
  getchar();
  getchar();
  return;
}

void listar() {
  fic = fopen(ficheiro, "rb");
  while (fread(&ser, sizeof(Serie), 1, fic)) {
    print_serie(&ser);
  }
  fclose(fic);
  pausa();
}

// função que abre o ficheiro
// e insere os registos
void inserir() {
  fic = fopen(ficheiro, "ab");
  int n;
  printf("quantos registos pretende inserir?: ");
  scanf("%i", &n);
  for (int i = 1; i <= n; i++) {
    ser = criar_serie_gui();
    fwrite(&ser, sizeof(Serie), 1, fic);
  }
  fclose(fic);
}

void eliminar() {
  int idp;
  printf("Qual o id da serie que pretende eliminar: ");
  scanf("%i", &idp);
  fic = fopen(ficheiro, "rb");
  FILE *ftemp;
  ftemp = fopen("dados.temp", "wb+");
  while (fread(&ser, sizeof(Serie), 1, fic)) {
    if (ser.id != idp) {
      fwrite(&ser, sizeof(Serie), 1, ftemp);
    }
  }
  fclose(fic);
  fclose(ftemp);
  ftemp = fopen("dados.temp", "rb");
  fic = fopen(ficheiro, "wb+");
  while (fread(&ser, sizeof(Serie), 1, ftemp)) {
    fwrite(&ser, sizeof(Serie), 1, fic);
  }
}

void pesquisar() {
  int idp;
  printf("Qual o id da serie que pretende pesquisar?: ");
  scanf("%i", &idp);
  fic = fopen(ficheiro, "rb");
  while (fread(&ser, sizeof(Serie), 1, fic)) {
    if (ser.id == idp) {
      print_serie(&ser);
    }
  }
  pausa();
}

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
  while (1) {
    escolha(menu());
  }
}
