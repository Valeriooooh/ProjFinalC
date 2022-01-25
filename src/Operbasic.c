#include "../include/Operbasic.h"
#include "../include/Serie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ficheiro "dados.bin"
FILE *fic;
Serie ser;

void init() {
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
}

// função que pausa o programa?
void pausa() {
  getchar();
  getchar();
  return;
}

void listar() {
  fic = fopen(ficheiro, "rb");
  system("cls");
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
  system("cls");
  printf("Qual o campo pelo qual pretende pesquisar?:"
         "\n[1]-Id da Serie"
         "\n[2]-Serviço de Streaming"
         "\n[3]-Género\n");
  int op;
  scanf("%i", &op);
  switch (op) {
  case 1: {
    int idp;
    printf("Qual o id da serie que pretende pesquisar?: ");
    scanf("%i", &idp);
    fic = fopen(ficheiro, "rb");
    while (fread(&ser, sizeof(Serie), 1, fic)) {
      if (ser.id == idp) {
        print_serie(&ser);
      }
    }
    fclose(fic);
    break;
  }
  case 2: {
    int idp;
    printf("Serviço de Streaming: "
           "\n[1]-Netflix"
           "\n[2]-HBO"
           "\n[3]-Amazon Prime"
           "\n[4]-Disney+"
           "\n[5]-Hulu\n");
    scanf("%i", &idp);
    fic = fopen(ficheiro, "rb");
    while (fread(&ser, sizeof(Serie), 1, fic)) {
      if (ser.idStreaming == idp) {
        print_serie(&ser);
      }
    }
    fclose(fic);
    break;
  }
  case 3: {
    int idp;
    printf("Generos da serie (max: 3): "
           "\n[1]-Ação"
           "\n[2]-Comédia"
           "\n[3]-Animação"
           "\n[4]-Terror"
           "\n[5]-Drama"
           "\n[6]-Ficção-Científica\n");
    scanf("%i", &idp);
    fic = fopen(ficheiro, "rb");
    while (fread(&ser, sizeof(Serie), 1, fic)) {
      if (((ser.generos[0] == idp) || (ser.generos[1] == idp) ||
           (ser.generos[2] == idp))) {
        print_serie(&ser);
      }
    }
    fclose(fic);
    break;
  }
  default: {
    break;
  }
  }
  pausa();
}

void atualizar() {
  printf("Atualizar Serie\n\n");
  int idp;
  printf("Qual o id da serie que pretende pesquisar?: ");
  scanf("%i", &idp);
  fic = fopen(ficheiro, "rb+");
  while (fread(&ser, sizeof(Serie), 1, fic)) {
    if (ser.id == idp) {
      print_serie(&ser);
      printf("\nO que pretende atualizar?:"
             "\n[1]-Nome"
             "\n[2]-Ranking IMDB"
             "\n[3]-Serviço de Streaming"
             "\n[4]-Generos");
      int op;
      scanf("%i", &op);
      switch (op) {
      case 2: {
        float rank;
        printf("\nInsira o ranking: ");
        scanf("%f", &rank);
        ser.rankImdb = rank;
        fseek(fic, -sizeof(Serie), 1);
        fwrite(&ser, sizeof(Serie), 1, fic);
      }
      }
    }
  }
  fclose(fic);
}
