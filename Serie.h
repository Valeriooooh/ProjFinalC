#ifndef SERIE_H
#define SERIE_H
typedef struct Serie {
  int id;
  char nome[30];
  float rankImdb;
} Serie;

Serie criar_serie(int id, char nome[30], float rankImdb);

void print_serie(Serie *self);
#endif
