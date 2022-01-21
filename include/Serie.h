#ifndef SERIE_H
#define SERIE_H
typedef struct Serie {
  int id;
  char nome[30];
  float rankImdb;
} Serie;

Serie criar_serie(int id, char nome[30], float rankImdb);

long get_size_serie();

void print_serie(Serie *self);
#endif
