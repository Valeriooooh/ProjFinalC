
#include "../include/Serie.h"
#include <stdio.h>

void print_serie(Serie *self) {
  printf("Id: %i\n", self->id);
  printf("Nome: %s\n", self->nome);
  printf("Ranking IMDB: %.1f\n", self->rankImdb);
}

Serie criar_serie(int id, char *nome, float rankImdb) {
  Serie self = {id, *nome, rankImdb};
  return self;
}
