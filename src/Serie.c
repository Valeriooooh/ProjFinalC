#include "../include/Serie.h"
#include <stdio.h>

void print_serie(Serie *self) {
  printf("Id: %i\n", self->id);
  printf("Nome: %s\n", self->nome);
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
    printf("Netflix");
    break;
  case 5:
    printf("Hulu");
    break;
  default:
    printf("Indefinido");
    break;
  }
}

long get_size_serie() { return (long)(sizeof(Serie)); }

Serie criar_serie(int id, char *nome, float rankImdb, int idStreaming) {
  Serie self = {id, *nome, rankImdb, idStreaming};
  return self;
}

Serie criar_serie_gui() {
  int id, idStreaming;
  char nome[30];
  float rankImdb;

  fflush(stdin);
  printf("id da  serie: ");
  scanf("%i", &id);

  getchar();
  printf("Nome da  serie: ");
  fgets(nome, 30, stdin);

  printf("Ranking da  serie: ");
  scanf("%f", &rankImdb);

  printf("id da plataforma: ");
  scanf("%i", &idStreaming);

  return criar_serie(id, nome, rankImdb, idStreaming);
}
