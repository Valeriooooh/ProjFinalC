#include "../include/Serie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_serie(Serie *self) {
  printf("\n\nId: %i\n", self->id);
  printf("Nome: %s", self->nome);
  printf("Ranking IMDB: %.1f\n", self->rankImdb);
  printf("Serviço de Streaming: ");
  switch (self->idStreaming) {
  case 1:
    printf("Netflix");
    break;
  case 2:
    printf("HBO");
    break;
  case 3:
    printf("Amazon Prime");
    break;
  case 4:
    printf("Disney+");
    break;
  case 5:
    printf("Hulu");
    break;
  default:
    printf("Indefinido");
    break;
  }
  printf("\nGeneros: ");
  for (int i = 0; i < 3; i++) {
    switch (self->generos[i]) {
    case 1:
      printf("Ação");
      break;
    case 2:
      printf("Comédia");
      break;
    case 3:
      printf("Animação");
      break;
    case 4:
      printf("Terror");
      break;
    case 5:
      printf("Drama");
      break;
    case 6:
      printf("Ficção-Científica");
      break;
    default:
      break;
    }
    if ((self->generos[i + 1] != 0) && (i < 2)) {
      printf(", ");
    }
  }
  printf("\n------------------------------------------------");
}

long get_size_serie() { return (long)(sizeof(Serie)); }

Serie criar_serie(int id, char nome[30], float rankImdb, int idStr,
                  int gen[3]) {
  Serie self = {
      .id = id,
      .rankImdb = rankImdb,
      .idStreaming = idStr,
      .generos = {gen[0], gen[1], gen[2]},
  };
  strcpy(self.nome, nome);
  return self;
}

Serie criar_serie_gui() {
  int id, idStreaming, gen[3];
  char nome[30];
  float rankImdb;
  system("cls");
  fflush(stdin);
  printf("\n\nId da  serie: ");
  scanf("%i", &id);
  getchar();
  printf("Nome da  serie: ");
  fgets(nome, 30, stdin);
  printf("Ranking da  serie: ");
  scanf("%f", &rankImdb);
  printf("Id da plataforma: "
         "\n[1]-Netflix"
         "\n[2]-HBO"
         "\n[3]-Amazon Prime"
         "\n[4]-Disney+"
         "\n[5]-Hulu\n");
  scanf("%i", &idStreaming);
  printf("Generos da serie (max: 3): "
         "\n[1]-Ação"
         "\n[2]-Comédia"
         "\n[3]-Animação"
         "\n[4]-Terror"
         "\n[5]-Drama"
         "\n[6]-Ficção-Científica"
         "\n[0]-Nulo\n");
  scanf("%i%i%i", &gen[0], &gen[1], &gen[2]);
  return criar_serie(id, nome, rankImdb, idStreaming, gen);
}
